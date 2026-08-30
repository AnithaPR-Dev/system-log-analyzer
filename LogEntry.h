#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>

// Represents a single parsed log entry.
class LogEntry
{
private:
    std::string date;
    std::string time;
    std::string severity;
    std::string message;

public:
    // Creates a log entry with the supplied log information.
    LogEntry(std::string d, std::string t,
             std::string s, std::string m);

    // Returns the severity level of the log entry.
    std::string getSeverity() const;

    // Returns the date of the log entry.
    std::string getDate() const;

    // Displays the complete log entry.
    void getDisplay() const;
	
	//Returns the message info of the log entry
	std::string getMessage() const ;
	
	// Returns the time info of the log entry
	std::string getTime() const;
};

#endif