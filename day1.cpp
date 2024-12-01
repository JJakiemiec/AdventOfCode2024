//Jacob Jakiemiec
//advent of code day 1
//12-1-2024

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


pair<vector<int>, vector<int>> parseList(){
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
        s >> first >> second;
        list1.push_back(stoi(first));
        list2.push_back(stoi(second));
    }    

    //sort vectors
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    
    return make_pair(list1, list2); 
}

//objective:
// 1: find difference between sorted pairs
// 2: add up total differences
void part1(vector<int> list1, vector<int> list2){
    int total = 0;
    for(int i = 0; i < list1.size(); i++){
        int difference = list1[i] - list2[i];
        if (difference < 0)
            difference = difference * -1;
        total += difference;
    }
    cout << total << endl;
}


//objective:
// 1: find how many times a number in the first list appears in the second
// 2: multiply frequency by the number in the first list
// 3: add up totals
void part2(vector<int> list1, vector<int> list2){
    int total = 0;
    for(int i: list1){
        int count = 0;
        for(int j: list2){
            if(i == j){
                count++;
            }
        }
        total += i * count;
    }
    cout << total << endl;


}

int main(){
    pair<vector<int>, vector<int>> lists = parseList();
    part1(lists.first, lists.second);
    part2(lists.first, lists.second);
    return 0;
}