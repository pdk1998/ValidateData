#include "ValidateData.h"
#include <fstream>
#include <iostream>
#include<ctype.h>
#include<string.h>

using namespace std;

//ValidateData::ValidateData()

ValidateData::ValidateData(string filePath)
{
    string line;
    ifstream annotatedFileContents(filePath);
    int rowsRead = 0;
    int row = 0;
    while (getline (annotatedFileContents, line)) {
        if(line[0] == '#')
            continue;
        int i = 0, digsRead = 0;
        int val;
        while(i < 18 && digsRead < 9){
            char ch = line[i];
            if(isdigit(ch)){
                digsRead += 1;
                val = int(ch) - 48;
                grid[row].push_back(val);
                cout<<val<<" ";
            }
            else if(ch != ' '){
                cout<<"Wrong input"<<endl;
                return;
            }
            i = i + 1;
        }
        if(digsRead == 9)
            rowsRead += 1;
        cout<<endl;
        row += 1;
    }
}
bool ValidateData::isComplete(){
    for(int i = 0; i < 9 ; i++){
        for(int j = 0; j < 9; j++){
            cout<<grid[i][j]<<" ";
            if(grid[i][j] == 0)
                return false;
        }
        cout<<endl;
    }
    return true;
}

bool ValidateData::isValid(){
    int res1[10] = {0};
    int res2[10] = {0};
    int res3[10] = {0};
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(res1[grid[i][j]] != 0) return false;
            else res1[grid[i][j]] = 1;
            if(res2[grid[j][i]] != 0) return false;
            else res2[grid[j][i]] = 1;
        }
        memset(res1, 0, 10 * sizeof(int));
        memset(res2, 0, 10 * sizeof(int));
    }
    int m = 0, n = 0;
    while(m < 7 && n < 7){
        for(int i = m; i < m+3; i++){
            for(int j = n; j < n+3; j++){
                if(res3[grid[i][j]] != 0) return false;
                else res3[grid[i][j]] = 1;
            }
        }
        m += 3;
        if(m == 6 && n <= 6){
            m = 0;
            n += 3;
        }
        memset(res3, 0, 10 * sizeof(int));
    }
    return true;
}


ValidateData::~ValidateData()
{
}

int main(){
    ValidateData* vdata = new ValidateData("input-1.txt");
    vdata->isComplete();
    vdata->isValid();
    return 0;
}
