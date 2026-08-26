#ifndef LOGFILTER_H
#define LOGFILTER_H

#include "LogEntry.h"
#include <vector>
#include <string>

std::vector<LogEntry> filterBySeverity( const std::vector<LogEntry>& entries, const std::string& severity); 
std::vector<LogEntry> filterByDate( const std::vector<LogEntry>& entries, const std::string& date); 
std::vector<LogEntry> filterByWord( const std::vector<LogEntry>& entries, const std::string& word);

#endif
