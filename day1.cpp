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


void part1(){
    //initialize variables
    ifstream input("day1-1.txt");
    vector<int> list1;
    vector<int> list2;
    string line;
    string first;
    string second;

    //parse input file into vectors
    while(getline(input, line)){
        stringstream s(line);
        s >> first;
        s >> second;
        list1.push_back(stoi(first));
        list2.push_back(stoi(second));
    }    

    //sort vectors
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    
    //find the differences in each pair
    int total = 0;
    for(int i = 0; i < list1.size(); i++){
        int difference = list1[i] - list2[i];
        if (difference < 0)
            difference = difference * -1;
        total += difference;
    }
    cout << total << endl;
}

int main(){
    
    part1();
    return 0;
}