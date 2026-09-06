# System Log Analyzer

**A multi-language system log analysis project built with C++, Python, SQLite, FastAPI, and LLM integration.**

The application parses and validates system log files using C++, exports valid log entries to JSON, stores them in SQLite using Python, and exposes the stored logs through a FastAPI REST API. It also integrates an LLM to analyze individual log entries and provide explanations, possible causes, and recommended troubleshooting actions.

## Architecture

```text
System Log File
      |
      v
C++ Parser / Validation / Filtering
      |
      v
JSON Export (logs.json)
      |
      v
Python Import
      |
      v
SQLite Database (logs.db)
      |
      v
FastAPI REST API
      |
      v
LLM Log Analysis
```

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
- Provides LLM-based log analysis through the OpenAI API
- Generates explanations, possible causes, and troubleshooting recommendations
- Reads the API key securely from an environment variable
- Handles unavailable LLM quota with HTTP 503
- Uses pytest and FastAPI TestClient for automated API testing
- Mocks external LLM calls during automated tests
- Uses GitHub Actions for continuous integration
- Automatically compiles the C++ application and runs Python tests on pushes and pull requests

## REST API

The FastAPI service provides endpoints for retrieving and analyzing logs.

| Method | Endpoint | Description |
|--------|----------|-------------|
| GET | `/logs` | Retrieve all logs |
| GET | `/logs?severity=ERROR` | Filter logs by severity |
| GET | `/logs/{log_id}` | Retrieve a specific log |
| POST | `/analyze/{log_id}` | Analyze a log using an LLM |

The analysis endpoint sends the selected log's severity, message, date, and time to the LLM and returns:

- Explanation of the log entry
- Possible causes
- Recommended troubleshooting or corrective actions

## Technologies

- C++ — parsing, validation, OOP, STL algorithms and filtering
- Python — JSON processing, database integration, API and LLM integration
- SQLite / SQL — persistent log storage and querying
- FastAPI — REST API development
- OpenAI API — LLM-based log analysis
- JSON — data exchange between C++ and Python
- pytest / FastAPI TestClient — automated API testing
- Git / GitHub — version control
- GitHub Actions — continuous integration

## Project Structure


```text
system-log-analyzer/
├── .github/
│   └── workflows/
│       └── ci.yml
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
├── test_api.py
├── requirements.txt
├── sample.log
├── .gitignore
└── README.md
```

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

### 5. Configure the OpenAI API Key

Set the API key as an environment variable:

```cmd
set OPENAI_API_KEY=your_api_key_here
```

The API key is read from the environment and should not be committed to source control.

### 6. Start the REST API

```cmd
python -m uvicorn api:app --reload
```

The API will be available at:

`http://127.0.0.1:8000`

Interactive Swagger documentation:

`http://127.0.0.1:8000/docs`

### 7. Test the API

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

Analyze a log using the LLM:

```text
POST /analyze/3
```

## Automated Testing

The REST API is tested using pytest and FastAPI TestClient.

The test suite covers log retrieval, severity filtering, invalid requests, missing logs, and the LLM analysis endpoint.

External OpenAI API calls are mocked during automated testing, keeping the tests independent of API credits and external service availability.

Run the tests locally with:

```cmd
python -m pytest test_api.py -v
```

## Continuous Integration

GitHub Actions runs automatically on pushes and pull requests.

The CI pipeline:

1. Checks out the repository.
2. Compiles the C++ application on Ubuntu using `g++`.
3. Installs the Python dependencies.
4. Runs the pytest API test suite.

## Current Status

The core System Log Analyzer project is complete.

Implemented functionality includes C++ log parsing, validation and filtering, JSON export, Python-based SQLite persistence, FastAPI REST endpoints, LLM-based log analysis, automated API testing with mocked external API calls, and GitHub Actions continuous integration.

Live LLM analysis requires a configured OpenAI API key with available API credits.
