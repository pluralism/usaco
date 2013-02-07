#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

vector<string> temp;
vector<string> next;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

//Função principal que verifica se a soma de uma dada string é 0
bool isZero(string what)
{
    int total = 0, temp = 0, sign = 1;

    for(int i = 0; i < what.size(); i++)
    {
        switch(what[i])
        {
        case '+':
            total += sign * temp;
            sign = 1;
            temp = 0;
        break;

        case '-':
            total += sign * temp;
            sign = -1;
            temp = 0;
        break;

        case ' ': break; //Do anything

        default:
            temp = temp * 10 + what[i] - '0';
        }
    }

    total += sign * temp;

    return total == 0;
}


bool checkString(int N, string s)
{
    int digits = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if(isdigit(s[i]))
            digits++;
    }

    if(N == digits)
        return true;


    return false;
}


void getSums(int N, int L = 0)
{
    int J = L + 1;
    char operations[] = {
        '+',
        '-',
        ' '
    };

    if(N == L)
    {
        for(vector<string>::const_iterator it = temp.begin(); it != temp.end(); it++)
        {
            if(isZero(*it) && checkString(N, *it))
                fout << *it << endl;
        }
    } else
    {
        if(L == 0)
            temp.push_back("1");
        else
        {
            vector<string>::const_iterator it;

            for(it = temp.begin(); it != temp.end(); it++)
            {
                for(int i = 0; i < 3; i++)
                {
                    next.push_back(*it + operations[i] + (char)(J + '0'));
                }
            }
            temp = next;
        }
        getSums(N, L + 1);
    }
}


int main(int argc, char *argv[])
{
    int N;

    //O tamanho da sequencia
    fin >> N;


    getSums(N);


    return 0;
}
