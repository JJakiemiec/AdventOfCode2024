//Jacob Jakiemiec
//advent of code day 4
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

vector<vector<char>> parseInput(string file){
    vector<vector<char>> input;
    ifstream f(file);
    string line;

    while(getline(f, line)){
        vector<char> c(line.begin(), line.end());
        input.push_back(c);
    }
    return input;
}

void printInput(vector<vector<char>> input){
    for(vector<char> i: input){
        for(char j: i){
            cout << j;
        }
        cout << endl;
    }

}

int check(const vector<vector<char>> &input, int i, int j, int dx, int dy){
    //TODO
    //fix bounds issue
    if(i > input.size() - (3 * dx) || j > input[0].size() - (3 * dy))
        return 0;

    if(input[i][j] == 'x')
                if(input[i + dx][j + dy] == 'm')
                    if(input[i + (2*dx)][j + (2*dy)] == 'a')
                        if(input[i+ (3*dx)][j + (3*dy)] == 's'){
                            cout << "YES" << endl;
                            return 1;
                        }
    return 0;
}

int part1(vector<vector<char>> input){
    int result = 0;

    for(int i=0; i<input.size(); i++){
        for(int j=0; j < input[0].size(); j++){
            result += check(input, i, j, 0, 1);
            result += check(input, i, j, 0, -1);
            result += check(input, i, j, 1, 0);
            result += check(input, i, j, -1, 0);
            result += check(input, i, j, 1, 1);
            result += check(input, i, j, 1, -1);
            result += check(input, i, j, -1, 1);
            result += check(input, i, j, -1, -1);
        }
    }

    return result;
}

int main(){
    //vector<vector<char>> test{{'x','m','a','s','x'}, {'1','2','x','m','a','s','3'},{'s','a','m','x'},{'x','s'},{'m','a'},{'a','m'},{'s','x'}};
    vector<vector<char>> test = parseInput("day4test.txt");
    vector<vector<char>> input = parseInput("day4.txt");
    //printInput(input);
    cout << part1(test) << endl;
    return 0;
}