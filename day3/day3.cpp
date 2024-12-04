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
#include <sstream>
using std::stringstream;
#include <algorithm>
using std::sort;
#include <utility>
using std::pair;


vector<string> parseFile(string file){
    ifstream f(file);
    vector<string> input;
    string line;

    while(getline(f, line)){
        input.push_back(line);
    }
    return input;
}

int part1(vector<string> input){

    return 0;
}



int main(){
    
    return 0;
}