# System Log Analyzer

A multi-language system log analysis project built with C++, Python, SQLite, and FastAPI.

The application parses and validates system log files using C++, exports valid log entries to JSON, stores them in SQLite using Python, and exposes the stored logs through a REST API.

## Architecture

sample.log
    |
    v
C++ Log Parser
    |
    v
LogEntry objects
    |
    v
JSON Exporter
    |
    v
logs.json
    |
    v
Python
    |
    v
SQLite Database
    |
    v
FastAPI REST API

## Features

- Parses system log files using C++
- Validates log and date formats
- Uses an object-oriented `LogEntry` model
- Filters logs by severity, date, and message content
- Uses STL algorithms and lambda expressions for filtering
- Exports parsed logs to JSON
- Loads JSON data using Python
- Stores logs in SQLite
- Prevents duplicate database entries
- Supports SQL filtering and aggregation
- Provides REST API endpoints using FastAPI
- Validates API query parameters
- Returns appropriate HTTP 400 and 404 responses

## REST API

### Get all logs

GET /logs

### Filter logs by severity

GET /logs?severity=ERROR

Supported severity values:

INFO, WARNING, ERROR, DEBUG, CRITICAL

### Get log by ID

GET /logs/{log_id}

Example:

GET /logs/1

## Technologies

- C++ — parsing, validation, OOP, STL algorithms and filtering
- Python — JSON processing and database integration
- SQLite — persistent log storage and SQL queries
- FastAPI — REST API
- JSON — data exchange between C++ and Python
- Git/GitHub — version control

## Project Structure

system-log-analyzer/
├── LogEntry.h
├── LogEntry.cpp
├── LogParser.h
├── LogParser.cpp
├── LogFilter.h
├── LogFilter.cpp
├── LogExporter.h
├── LogExporter.cpp
├── main.cpp
├── log_analyzer.py
├── api.py
├── sample.log
├── .gitignore
└── README.md

## Requirements

- Visual Studio 2022 with C++ Build Tools
- Python 3
- SQLite (included with Python)

Python dependencies, including FastAPI and Uvicorn, are listed in `requirements.txt`.

## How to Run

### 1. Install Python Dependencies

```cmd
python -m pip install -r requirements.txt
```

### 2. Compile the C++ Application

Open the Visual Studio x64 Native Tools Command Prompt and run:

```cmd
cl /EHsc main.cpp LogEntry.cpp LogParser.cpp LogFilter.cpp LogExporter.cpp
```

### 3. Run the Log Analyzer

```cmd
main.exe sample.log
```

The C++ application parses and validates the log file, supports interactive filtering, and generates `logs.json`.

### 4. Load Logs into SQLite

```cmd
python log_analyzer.py
```

This reads `logs.json` and stores the log entries in `logs.db`. Duplicate entries are ignored.

### 5. Start the REST API

```cmd
python -m uvicorn api:app --reload
```

The API will be available at:

`http://127.0.0.1:8000`

Interactive Swagger documentation:

`http://127.0.0.1:8000/docs`

### 6. Test the API

Get all logs:

```text
GET /logs
```

Filter by severity:

```text
GET /logs?severity=ERROR
```

Get a log by ID:

```text
GET /logs/1
```

## Current Status

Core log parsing, filtering, JSON export, SQLite persistence, and REST API functionality are implemented.

Additional testing and project polish are in progress.
