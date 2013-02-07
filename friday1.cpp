#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


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
    vector<int> days(7, 0);

    cout << "Enter the number of years: ";
    cin >> N;


    for(int i = 1900; i < 1900 + N; i++)
    {
        if(isLapYear(i))
            months[1] = 29;
        else
            months[1] = 28;

        for(int j = 0; j < 12; j++)
        {
            days.at(a % 7)++;
            a += months[j];
        }
    }

    for(int i = 0; i < 7; i++)
    {
        cout << days.at((i + 6) % 7) << endl;
    }

    return 0;
}
