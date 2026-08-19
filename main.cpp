#include <iostream>
#include <fstream>
#include<sstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ifstream fileObj("sample.log");

    if (!fileObj)
    {
        cout << "File could not be opened" << endl;
        return 1;
    }

    cout << "File opened successfully" << endl;

	string line, date, time, level;
	int infoCounter = 0, warningCounter = 0, errorCounter =0;
	map<string,int> severityCount;
	
	while(getline(fileObj,line)){
		cout << line << endl;
		istringstream iss(line);
		iss >> date >> time >> level;
		severityCount[level]++;
	/* if (level == "INFO") {
		infoCounter++;
	}
	else if (level == "WARNING")
	{
		warningCounter++;
	}
	else if (level == "ERROR")
	{
		errorCounter++;
		} */
	}
	for (const auto entry : severityCount) {
	cout << entry.first << " : " << entry.second << endl; 
	}
	//cout << "INFO : " << infoCounter << endl << "WARNING : " << warningCounter << endl << "ERROR : " << errorCounter << endl;
	
	fileObj.close();

    return 0;
}