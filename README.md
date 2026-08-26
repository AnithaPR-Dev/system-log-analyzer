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

## Current Status

Core log parsing, filtering, JSON export, SQLite persistence, and REST API functionality are implemented.

Additional testing and project polish are in progress.
