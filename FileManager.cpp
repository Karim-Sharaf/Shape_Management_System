#include "FileManager.h"
#include <fstream>
#include <iostream>

using namespace std;

void FileManager::SaveResult(const string& username, const string& result) {
    ofstream outFile;
    outFile.open("history.txt", ios::app);
    if (outFile.is_open()) {
        outFile << username << ": " << result << endl;
        outFile.close();
    }
    else {
        cout << "Unable to open file for writing.\n";
    }
}

int FileManager::LoadPreviousCalculations(const string& username, string results[], int maxSize = 50) {
    ifstream inFile;
    inFile.open("history.txt");
    string line;
    int count = 0;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            if (line.find(username + ":") == 0) {
                if (count < maxSize) {
                    results[count++] = line;
                }
                else {
                    break;
                }
            }
        }
        inFile.close();
    }
    else {
        cout << "Unable to open file for reading.\n";
    }

    return count; 
}