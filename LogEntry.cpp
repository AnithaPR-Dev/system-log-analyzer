#include <iostream>
#include "LogEntry.h"

// Initializes a log entry with the parsed date, time, severity, and message.
LogEntry::LogEntry(std::string d, std::string t, std::string s, std::string m)
    : date(d), time(t), severity(s), message(m)
{
}

// Returns the severity level of this log entry.
std::string LogEntry::getSeverity() const
{
    return severity;
}

// Returns the date of this log entry.
std::string LogEntry::getDate() const
{
    return date;
}

// Displays the complete log entry in its original readable format.
void LogEntry::getDisplay() const
{
    std::cout << date << " "
              << time << " "
              << severity << " "
              << message << std::endl;
}