#ifndef LOGEXPORTER_H
#define LOGEXPORTER_H

#include <string>
#include <vector>
#include "LogEntry.h"

void exportToJson(const std::vector<LogEntry>& entries, const std::string& fileName);

#endif