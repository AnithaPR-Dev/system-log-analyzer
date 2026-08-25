import json
import sqlite3

with open("logs.json", "r") as file:
    entries = json.load(file)

connection = sqlite3.connect("logs.db")
cursor = connection.cursor()

cursor.execute (
    """CREATE TABLE IF NOT EXISTS logs (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    date TEXT,
    time TEXT,
    severity TEXT,
    message TEXT,
    UNIQUE(date, time, severity, message)    )"""
)
for entry in entries:
    cursor.execute(
        """
        INSERT OR IGNORE INTO logs (date, time, severity, message)
        VALUES (?, ?, ?, ?)
        """,
        (
            entry["date"],
            entry["time"],
            entry["severity"],
            entry["message"]
        )
    )
connection.commit()
cursor.execute("SELECT * FROM logs")

rows = cursor.fetchall()

for row in rows:
    print(row)

# cursor.execute(
    # "SELECT * FROM logs WHERE severity = ?",
    # ("ERROR",)
# )

# rows = cursor.fetchall()

# for row in rows:
    # print(row)
    
# cursor.execute("""
    # SELECT severity, COUNT(*)
    # FROM logs
    # GROUP BY severity
# """)

# rows = cursor.fetchall()

# for row in rows:
    # print(row)
cursor.execute("SELECT COUNT(*) FROM logs")
print("Total rows:", cursor.fetchone()[0])

connection.close()
