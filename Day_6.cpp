#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    vector<vector<string>>grid;
    ifstream inputFile("Day_6.txt"); 
    string line; 
    while (getline(inputFile, line)) { 
        vector<string> row; 
        string word; 
        istringstream stream(line); 
        while (stream >> word) { 
            row.push_back(word); 
        } 
        grid.push_back(row); 
    } 
    inputFile.close();
    
}