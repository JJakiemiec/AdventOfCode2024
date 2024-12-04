//Jacob Jakiemiec
//advent of code day 3
//12-3-24

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
#include <regex>
using std::regex;
using std::smatch;
using std::regex_search;


vector<string> parseFile(string file){
    ifstream f(file);
    vector<string> input;
    string line;

    while(getline(f, line)){
        input.push_back(line);
    }
    return input;
}

int mulResult(string mul){
    regex reg("\\d{1,3}");
    smatch m;
    vector<int> values;

    while(regex_search(mul, m, reg)){
        values.push_back(stoi(m.str()));
        mul = m.suffix();
    }
    return values[0] * values[1];
}


int lineTotal(string line){
    regex reg("mul\\(\\d{1,3},\\d{1,3}\\)");
    smatch m;
    int result = 0;

    while(regex_search(line, m, reg)){
        result += mulResult(m.str());
        line = m.suffix();
        }

    return result;
}


int part1(vector<string> input){
    int result = 0;
    for(string line: input){
        result += lineTotal(line);
    }

    return result;
}


int main(){
    vector<string> input = parseFile("day3.txt");
    vector<string> test {"mul(1,2)heyyyymul(2,4) don't plesase mul(333,333)mul1mul(7)"};
    cout << part1(test) << endl;


    return 0;
}