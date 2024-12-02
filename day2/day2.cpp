//Jacob Jakiemiec
//advent of code day 2
//12-2-2024

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::stoi;
#include <fstream>
using std::ifstream;
using std::getline;
#include <sstream>
using std::stringstream;
#include <algorithm>
using std::sort;
#include <utility>
using std::pair;

//converts the text file into a 2 dimensional int vector
vector<vector<int>> parseFile(string file){
    ifstream input(file);
    string line;
    vector<vector<int>> parsedInput;

    while(getline(input, line)){
        stringstream s(line);
        string currentNumber;
        vector<int> currentReport;
        while(s >> currentNumber){
            currentReport.push_back(stoi(currentNumber));
        }
        parsedInput.push_back(currentReport);
    }

    return parsedInput;
}

//tests to see if a single report is safe
bool isSafe(vector<int> report){
    bool increasing = true;
    if(report[0] > report[1])
        increasing = false;
    for(int i = 0; i < report.size() - 1; i++){
            if(increasing){
                if(report[i] >= report[i + 1] || (report[i+1] - report[i] > 3))
                    return false;
            }
            else{
                if(report[i] <= report[i + 1] || (report[i] - report[i+1] > 3))
                    return false;
            }
        }
    return true;
}

int part1(vector<vector<int>> input){
    int count = 0;
    for (vector<int> report: input){
        if(isSafe(report)){
            count++;
        }
    }
    return count;
}

//tests all permutations of removing one file from a report
//if any one is safe, then returns true
bool isRemovedSafe(vector<int> report){
    bool isPermSafe = false;
        for(int i=0;i<report.size();i++){
            vector<int> perm;
            for(int j = 0; j < report.size();j++){
                if(i!=j){
                    perm.push_back(report[j]);
                }
            }
            isPermSafe = isSafe(perm);
            if (isPermSafe)
                return true;
        }
    return false;
}

int part2(vector<vector<int>> input){
    int count = 0;
    for(vector<int> report: input){ 
        if(isRemovedSafe(report)){
            count++;
        }
    }
    return count;
}

int main(){
    vector<vector<int>> list = parseFile("day2-1.txt");
    cout << part1(list) << endl;
    cout << part2(list) << endl;
    return 0;
}