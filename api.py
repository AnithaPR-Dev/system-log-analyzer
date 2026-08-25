from fastapi import FastAPI
import sqlite3

app = FastAPI()

@app.get("/logs")
def get_logs(severity: str | None = None):
    connection = sqlite3.connect("logs.db")
    connection.row_factory = sqlite3.Row
    cursor = connection.cursor()

    if severity:
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
    connection = sqlite3.connect("logs.db")
    connection.row_factory = sqlite3.Row
    cursor = connection.cursor()

    cursor.execute(
        "SELECT * FROM logs WHERE id = ?",
        (log_id,)
    )

    row = cursor.fetchone()

    connection.close()

    if row:
        return dict(row)

    return {"message": "Log not found"}
