/*
ID: andrepd1
PROG: palsquare
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
    string possibledigits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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

    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    string s, j;
    int B, C;

    fin >> B;

    for(int i = 1; i <= 300; i++)
    {
        C = i * i;
        s = tobase(i, B);
        j = tobase(C, B);
        if(isPalindromic(j))
            fout << s << " " << j << endl;
    }

    return 0;
}
