/*
ID: andrepd1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

bool isLapYear(int year)
{
    if((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
        return true;
    else
        return false;
}

int main(int argc, char *argv[])
{
    int N, a = 13;
    int months[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
    int days[7] = {0};
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    fin >> N;

    N += 1900;

    //Iterating over all the years
    for(int i = 1900; i < N; i++)
    {
        //Check whether this is leap year or not
        if(isLapYear(i))
            months[1] = 29;
        else
            months[1] = 28;

        //Iterating over all months
        for(int j = 0; j < 12; j++)
        {
            days[a % 7]++;
            a += months[j];
        }
    }

    for(int i = 0; i < 7; i++)
    {
        fout << days[(i + 6) % 7];
        if(i != 6)
            fout << " ";
        else
            fout << endl;
    }

    return 0;
}
