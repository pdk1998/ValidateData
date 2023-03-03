#ifndef VALIDATEDATA_H
#define VALIDATEDATA_H
#include <vector>
#include <string>
#include<iostream>

using namespace std;

class ValidateData
{
    public:
        ValidateData();
        ValidateData(string filePath);
        bool isComplete();
        bool isValid();
        virtual ~ValidateData();

    protected:

    private:
        vector<vector<int>> grid;
};


#endif // VALIDATEDATA_H
