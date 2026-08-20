#ifndef LOGPARSER_H
#define LOGPARSER_H

#include <string>
#include <vector>
#include "LogEntry.h"

// Reads and parses valid log entries from the specified file.
// Invalid or malformed entries are skipped.
std::vector<LogEntry> fileParser(const std::string& fileName);

#endif