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

bool isSafe(vector<int> report){
    bool increasing = true;
    if(report[0] > report[1])
        increasing = false;
    for(int i = 0; i < report.size() - 1; i++){
            if(increasing)
                if(report[i] >= report[i + 1] || (report[i+1] - report[i] > 3))
                    return false;
            if(!increasing)
                if(report[i] <= report[i + 1] || (report[i] - report[i+1] > 3))
                    return false;

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

bool isRemovedSafe(vector<int> report){
    bool isPermSafe = false;
        for(int i=0;i<report.size();i++){
            vector<int> perm;
            for(int j = 0; j < report.size();j++){
                if(i!=j){
                    perm.push_back(report[j]);
                }
            }
            for (int a: perm){
                cout << a << ",";
            }
            cout << endl;
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
    vector<int> test1 = {1,2,3,4};
    vector<int> test2 = {4,3,2,1};
    vector<int> test3 = {1,4,7,10};
    vector<int> test4 = {10, 7, 4, 1};
    vector<int> test5 = {1,2,4,3};
    vector<int> test6 = {4,3,1,2};
    vector<int> test7 = {1, 5, 10, 15};
    vector<int> test8 = {15, 10, 5, 1};
    vector<int> test9 = {10, 4, 1};
    //cout << true << endl;
    //cout << isSafe(test1) <<isSafe(test2) <<isSafe(test3) <<isSafe(test4) <<isSafe(test5) <<isSafe(test6) <<isSafe(test7) <<isSafe(test8) << endl;
    //cout << isSafe(test1)<<endl;
    //cout << part1(list) << endl;
    //vector<vector<int>> t = {test1, test2, test3, test4, test5, test6, test7, test8};
    //vector<vector<int>> t = {test9};
    //cout << part2(t) << endl;
    cout << isRemovedSafe(test9) << endl;
    cout << part2(list) << endl;
    cout << part1(list) << endl;
    return 0;
}