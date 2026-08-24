#include "LogExporter.h"
#include <iostream>
#include <fstream>

void exportToJson (const std::vector<LogEntry>& entries, const std::string& fileName) 
{
	std::ofstream outFile(fileName);
	if(!outFile)
	{
		std::cout << "Could not open output file" << std::endl;
		return;
	}
	outFile << "[" << std::endl;
	for(size_t i = 0; i < entries.size(); i++)
	{
		const auto& entry = entries[i];
		outFile << "{" << std::endl;
		outFile << "\"date\": \"" << entry.getDate()  << "\"," << std::endl;
		outFile << "\"time\": \"" << entry.getTime()  << "\"," << std::endl;
		outFile << "\"severity\": \"" << entry.getSeverity()  << "\"," << std::endl;
		outFile << "\"message\": \"" << entry.getMessage()  << "\"" << std::endl;
		outFile << "}";
		
		if (i != entries.size()-1){
		outFile << "," ;}

	}
	outFile << std::endl << "]" << std::endl;
}