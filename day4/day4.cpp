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

    if((i < 3) && (dx == -1))
        return 0;
    if((i > input.size() - 4) && (dx == 1))
        return 0;
    if((j < 3) && (dy == -1))
        return 0;
    if((j > input[0].size() - 4) && (dy == 1))
        return 0;

    if(input[i][j] == 'X')
                if(input[i + dx][j + dy] == 'M')
                    if(input[i + (2*dx)][j + (2*dy)] == 'A')
                        if(input[i+ (3*dx)][j + (3*dy)] == 'S')
                            return 1;
    return 0;
}

int check2(const vector<vector<char>> &input, int i, int j){
        if(input[i][j] == 'A')
            if(((input[i-1][j-1] == 'M') && (input[i+1][j+1] == 'S')) || ((input[i-1][j-1] == 'S') && (input[i+1][j+1] == 'M')))
                if(((input[i-1][j+1] == 'M') && (input[i+1][j-1] == 'S')) || ((input[i-1][j+1] == 'S') && (input[i+1][j-1] == 'M')))
                    return 1;
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

int part2(vector<vector<char>> input){
    int result = 0;

    for(int i=1; i<input.size()-1; i++){
        for(int j=1; j < input[0].size()-1; j++){
            result += check2(input, i, j);
        }
    }

    return result;
}

int main(){
    //vector<vector<char>> test{{'x','m','a','s','x'}, {'1','2','x','m','a','s','3'},{'s','a','m','x'},{'x','s'},{'m','a'},{'a','m'},{'s','x'}};
    vector<vector<char>> test = parseInput("day4test.txt");
    vector<vector<char>> input = parseInput("day4.txt");
    //printInput(input);
    cout << part1(input) << endl;
    cout << part2(input) << endl;
    return 0;
}