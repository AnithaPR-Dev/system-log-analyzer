#include "LogParser.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Reads the given log file, validates each line, converts valid lines
// into LogEntry objects, and returns all successfully parsed entries.
std::vector<LogEntry> fileParser(const std::string& fileName)
{
    std::vector<LogEntry> entries;

    // Attempt to open the log file provided by the caller.
    std::ifstream fileObj(fileName);

    if (!fileObj)
    {
        std::cout << "File could not be opened" << std::endl;
        return entries;
    }

    std::cout << "File opened successfully" << std::endl;

    std::string line, date, time, severity, message;

    // Process the log file one line at a time.
    while (std::getline(fileObj, line))
    {
        // Ignore empty lines without treating them as malformed logs.
        if (line.empty())
        {
            continue;
        }

        // Convert the current line into a stream so individual
        // fields can be extracted.
        std::stringstream iss(line);

        // A valid log must contain at least date, time, and severity.
        if (!(iss >> date >> time >> severity))
        {
            std::cout << "Invalid log format. Skipping entry" << std::endl;
            continue;
        }

        // Perform basic YYYY-MM-DD date-format validation.
        if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        {
            std::cout
                << "Invalid Date Format found in Log. Proceeding with the next"
                << std::endl;
            continue;
        }

        // Everything remaining after severity is treated as the log message.
        // std::ws removes leading whitespace before getline reads the message.
        std::getline(iss >> std::ws, message);

        // Create a structured LogEntry and store it in the result collection.
        LogEntry entry(date, time, severity, message);
        entries.push_back(entry);
    }

    fileObj.close();

    return entries;
}