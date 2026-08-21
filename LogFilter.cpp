#include "LogFilter.h"


std::vector<LogEntry> filterBySeverity( const std::vector<LogEntry>& entries, const std::string& severity) 
{ 
	std::vector<LogEntry> filteredBySeverity; 
	for (const auto& eachRow : entries) { 
		if(eachRow.getSeverity() == severity) 
			{ filteredBySeverity.push_back(eachRow); 
		}
	}
return filteredBySeverity;
}

std::vector<LogEntry> filterByDate( const std::vector<LogEntry>& entries, const std::string& date) {
	std::vector<LogEntry> filteredByDate; 
	for (const auto& eachRow : entries) { 
		if(eachRow.getDate() == date) 
			{ filteredByDate.push_back(eachRow); 
		}
	}
	return filteredByDate;
}

std::vector<LogEntry> filterByWord( const std::vector<LogEntry>& entries, const std::string& word) {
	std::vector<LogEntry> filteredByWord; 
	for (const auto& eachRow : entries) {				
		if(eachRow.getMessage().find(word) != std::string::npos) 
		{ 
			filteredByWord.push_back(eachRow); 
		}
	}
	return filteredByWord;
}
