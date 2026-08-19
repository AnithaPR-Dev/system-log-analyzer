#include <iostream>
#include <fstream>
#include<sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class LogEntry {
	private: 
		string date;
		string time;
		string severity;
		string message;
	public:
		LogEntry(string d, string t, string s, string m):date(d),time(t),severity(s),message(m) {}
		string getSeverity() const{
			return severity;
		}
		string getDate() const {
			return date;
		}
		void getDisplay() const{
			cout << date << " " << time << " " << severity << " " << message << endl;
		}
};

vector<LogEntry> fileParser (const string& fileName) {
	vector<LogEntry> entries;
	ifstream fileObj(fileName);
	if(!fileObj)
	{
		cout << "File could not be opened" << endl;
		return entries;
	}
	cout << "File opened successfully" << endl;
	
	string line, date, time, severity, message;
	
	while(getline(fileObj,line)) {
		//cout << line << endl;
		istringstream iss(line);
		iss >> date >> time >> severity;
		getline(iss >> ws,message);
		LogEntry entry(date,time,severity,message);
		entries.push_back(entry); 
	} 
	fileObj.close();
	
	return entries;
}

int main()
{
    
	auto result = fileParser("sample.log");
	string filterSeverity, filterDate;
	cout << " Type the Severity to be filtered : " ;		
	cin >>  filterSeverity ;
	cout << endl;
	cout << "Type the Date of the log infos to be filtered : ";
	cin >> filterDate ;	
	cout << endl;
	
	//map<string,int> severityCount;
	bool matchFound = false;
	for (const auto& entry : result) {
		if (entry.getSeverity() == filterSeverity && entry.getDate() == filterDate) {
			entry.getDisplay();
			matchFound = true;
		}		
		//severityCount[entry.getSeverity()]++;
	}
	if (!matchFound) {
			cout << "No matching log entries found" << endl;
		}
	/* for (const auto& state : severityCount) {
		cout << state.first << " : " << state.second << endl;
	} */

    return 0;
}