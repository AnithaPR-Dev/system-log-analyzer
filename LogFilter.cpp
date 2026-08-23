#include "LogFilter.h"
#include <iterator>
#include <algorithm>


	std::vector<LogEntry> filterBySeverity( const std::vector<LogEntry>& entries, const std::string& severity) 
	{ 
		std::vector<LogEntry> filteredBySeverity; 
		std::copy_if(entries.begin(), entries.end(), std::back_inserter(filteredBySeverity), 
			[&severity](const LogEntry& entry) {
				return entry.getSeverity() == severity;
			});		
		
	return filteredBySeverity;
	}

	std::vector<LogEntry> filterByDate( const std::vector<LogEntry>& entries, const std::string& date) {
		std::vector<LogEntry> filteredByDate; 
		std::copy_if(entries.begin(), entries.end(), std::back_inserter(filteredByDate),
			[&date](const LogEntry& entry) {
				return entry.getDate() == date;
			});
		
		return filteredByDate;
	}

	std::vector<LogEntry> filterByWord( const std::vector<LogEntry>& entries, const std::string& word) {
		std::vector<LogEntry> filteredByWord; 
		std::copy_if(entries.begin(), entries.end(), std::back_inserter(filteredByWord),
			[&word](const LogEntry& entry) {
				return entry.getMessage().find(word) !=std::string::npos;
			});
			
		return filteredByWord;
	}
