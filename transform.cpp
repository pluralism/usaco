/*
ID: andrepd1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;


template<class T>
bool compareMatrixes(vector<T> a, vector<T> b)
{
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a.size(); j++)
        {
            if(a[i][j] != b[i][j])
                return false;
        }
    }

    return true;
}


template<class T>
vector<T> rotate90(vector<T> a)
{
    vector<T> temp = a;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a.size(); j++)
        {
            temp[j][a.size() - i - 1] = a[i][j];
        }
    }

    return temp;
}


template<class T>
vector<T> rotate180(vector<T> a)
{
    return rotate90(rotate90(a));
}


template<class T>
vector<T> rotate270(vector<T> a)
{
    return rotate180(rotate90(a));
}


template<class T>
vector<T> reflect(vector<T> a)
{
    vector<T> temp = a;

    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a.size(); j++)
        {
            temp[i][j] = a[i][a.size() - j - 1];
        }
    }

    return temp;
}


template<class T>
vector<T> combine90(vector<T> a)
{
    return rotate90(reflect(a));
}


template<class T>
vector<T> combine180(vector<T> a)
{
    return rotate180(reflect(a));
}


template<class T>
vector<T> combine270(vector<T> a)
{
    return rotate270(reflect(a));
}

template<class T>
int solvePuzzle(vector<T> a, vector<T> b)
{
    if(compareMatrixes(b, rotate90(a)))
       return 1;
    if(compareMatrixes(b, rotate180(a)))
        return 2;
    if(compareMatrixes(b, rotate270(a)))
        return 3;
    if(compareMatrixes(b, reflect(a)))
        return 4;
    if(compareMatrixes(b, combine90(a)) || compareMatrixes(b, combine180(a)) || compareMatrixes(b, combine270(a)))
        return 5;
    if(compareMatrixes(b, a))
        return 6;

    return 7;
}



int main(int argc, char *argv[])
{
    int N;
    vector<string> first; //For lines 2...N+1
    vector<string> second; //For lines N+2...2*N+1
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    //Read the size of the matrix
    fin >> N;

    for(int i = 0; i < N; i++)
    {
        string s;
        fin >> s;
        first.push_back(s);
    }

    for(int i = 0; i < N; i++)
    {
        string s;
        fin >> s;
        second.push_back(s);
    }

    fout << solvePuzzle(first, second) << endl;

    return 0;
}
