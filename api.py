from fastapi import FastAPI
import sqlite3
from fastapi import FastAPI, HTTPException

app = FastAPI()

DATABASE = "logs.db"
def get_connection():
    connection = sqlite3.connect(DATABASE)
    connection.row_factory = sqlite3.Row
    return connection

@app.get("/logs")
def get_logs(severity: str | None = None):
    connection = get_connection()
    cursor = connection.cursor()
    
    allowed = {"INFO", "WARNING", "ERROR", "DEBUG", "CRITICAL"}
    if severity:
        if severity and severity not in allowed:
            raise HTTPException(
                status_code=400,
                detail="Invalid severity"
                )
        cursor.execute(
            "SELECT * FROM logs WHERE severity = ?",
            (severity,)
        )
    else:
        cursor.execute("SELECT * FROM logs")
    rows = cursor.fetchall()

    connection.close()

    return [dict(row) for row in rows]
 
@app.get("/logs/{log_id}")
def get_log(log_id: int):
    connection = get_connection()
    cursor = connection.cursor()

    cursor.execute(
        "SELECT * FROM logs WHERE id = ?",
        (log_id,)
    )

    row = cursor.fetchone()

    connection.close()

    if row:
        return dict(row)

    raise HTTPException(
    status_code=404,
    detail="Log not found")
