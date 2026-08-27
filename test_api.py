import api
from fastapi.testclient import TestClient
from api import app
import sqlite3
import pytest
import os

@pytest.fixture(autouse=True, scope="module")
def setup_test_database():
    connection = sqlite3.connect("test_logs.db")
    cursor = connection.cursor()
   
    test_entries = [
        ("2026-08-18", "10:15:23", "INFO", "Test system started"),
        ("2026-08-18", "10:16:05", "WARNING", "Test disk warning"),
        ("2026-08-18", "10:17:42", "ERROR", "Test database error")
    ]

    cursor.execute("""
        CREATE TABLE IF NOT EXISTS logs (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            date TEXT,
            time TEXT,
            severity TEXT,
            message TEXT,
            UNIQUE(date, time, severity, message)
        )
    """)
    cursor.executemany("""
        INSERT OR IGNORE INTO logs (date, time, severity, message)
        VALUES (?, ?, ?, ?)
        """,
        test_entries
    )
    connection.commit()
    connection.close()
    
    yield

    # if os.path.exists("test_logs.db"):
        # os.remove("test_logs.db")
    
api.DATABASE = "test_logs.db"
client = TestClient(app)

def test_get_logs():
    response = client.get("/logs")
    assert response.status_code == 200
    
    data = response.json()
    assert isinstance(data, list)
    
def test_filter_logs_by_severity():
    response = client.get("/logs?severity=ERROR")
    assert response.status_code == 200
    
    data = response.json()
    
    assert len(data) > 0
    for log in data:
        assert log["severity"]=="ERROR"
        
def test_logs_by_severity():
    response = client.get("/logs?severity=INFO")
    assert response.status_code == 200
    
    data = response.json()
    
    assert len(data) > 0
    for log in data:
        assert log["severity"]=="INFO"
   
def test_invalid_severity():
    response = client.get("/logs?severity=IMFO")
    assert response.status_code == 400

def test_log_not_found():
    response = client.get("/logs/999")
    assert response.status_code == 404
    