/*
ID: andrepd1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::reverse;
using std::ifstream;
using std::ofstream;

string tobase(int number, int base)
{
    string possibledigits = "0123456789ABCDEFGHIJ";
    string result = "";

    while(number > 0)
    {
        result += possibledigits[number % base];
        number /= base;
    }

    reverse(result.begin(), result.end());

    return result;
}


bool isPalindromic(string s)
{
    for(int i = 0; i < s.size() / 2; i++)
    {
        if(s[i] != s[s.size() - i - 1])
            return false;
    }

    return true;
}



int main(int argc, char *argv[])
{

    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int N, S, bases = 0;

    fin >> N >> S;

    for(int i = S + 1, n = 0; n < N; i++)
    {
        for(int j = 2; j <= 10; j++)
        {
            if(isPalindromic(tobase(i, j)))
                bases++;

            if(bases >= 2)
            {
                n++;
                fout << i << endl;
                break;
            }
        }
        bases = 0;
    }

    return 0;
}
