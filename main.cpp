#include<iostream>
#include "Company.h"
#include <string>
using namespace std;

int main()
{
    Company myCompany;
    string fileName = myCompany.getInputFile();
    myCompany.OutputData();
};
