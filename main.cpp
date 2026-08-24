#include <iostream>
#include "LogEntry.h"
#include "LogParser.h"
#include "LogFilter.h"
#include "LogExporter.h"

int main(int argc, char* argv[])
{
	// Validate command-line arguments.
    // argv[0] contains the executable name and argv[1] should contain
    // the path to the log file.
	if (argc < 2) {
		std::cout << "Usage: main.exe <logfile>" << std::endl;
		return 1;
	}
	   
	// Parse the supplied log file and store all valid log entries.
	auto result = fileParser(argv[1]);
	exportToJson(result, "logs.json");
	
	// Get filtering criteria from the user.
	std::string filterSeverity, filterDate, filterMessage;
	std::cout << "Type the Severity to be filtered : " ;		
	std::cin >>  filterSeverity ;
	std::cout << std::endl;
	std::cout << "Type the Date of the log infos to be filtered : ";
	std::cin >> filterDate ;	
	std::cout << std::endl;	
	std::cout << "Type the word to be searched in the Log file : " ;
	std::getline(std::cin >> std::ws, filterMessage);
	
	auto extractedOutput = filterBySeverity(result,filterSeverity);
	auto dateFiltered = filterByDate(extractedOutput, filterDate);
	auto searchByWord = filterByWord(dateFiltered, filterMessage);
	
	//map<std::string,int> severityCount;	
	// Search through all parsed log entries and display matching entries.
	for (const auto& entry : searchByWord) {
			entry.getDisplay();	
		//severityCount[entry.getSeverity()]++;
	}
	// Report when the complete search finishes without finding a match
	if (searchByWord.empty()) {
			std::cout << "No matching log entries found" << std::endl;
		}
	
		
	// Severity statistics - currently disabled.
    // Can be re-enabled when overall severity counts are required.	
	/* for (const auto& state : severityCount) {
		std::cout << state.first << " : " << state.second << std::endl;
	} */

    return 0;
}