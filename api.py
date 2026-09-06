import os
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")

import sqlite3
from fastapi import FastAPI, HTTPException
from openai import OpenAI, RateLimitError

app = FastAPI()

DATABASE = "logs.db"
client = OpenAI(api_key=OPENAI_API_KEY)

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
        if severity not in allowed:
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
    
@app.post("/analyze/{log_id}")
def analyze_log(log_id: int):
    connection = get_connection()
    cursor = connection.cursor()

    cursor.execute(
        "SELECT * FROM logs WHERE id = ?",
        (log_id,)
    )

    row = cursor.fetchone()
    connection.close()

    if not row:
        raise HTTPException(
            status_code=404,
            detail="Log not found"
        )

    prompt = f"""
        Analyze the following system log entry:

        Severity: {row['severity']}
        Message: {row['message']}
        Date: {row['date']}
        Time: {row['time']}

        Explain:
        1. What the log entry means.
        2. The possible causes.
        3. Recommended troubleshooting or corrective actions.
        """

    try:
        response = client.responses.create(
            model="gpt-5.6-luna",
            input=prompt    
        )

        return {"analysis": response.output_text}

    except RateLimitError:
        raise HTTPException(
            status_code=503,
            detail="LLM service unavailable: API quota exhausted"
        )