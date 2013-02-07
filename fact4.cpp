#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;



int main(int argc, char *argv[])
{
    ifstream fin("fact4.in");
    ofstream fout("fact4.out");
    int N, i = 1;

    fin >> N;

    for(int f = 1; f <= N; f++)
    {
        i *= f;

        while(i % 10 == 0) i /= 10;
    }

    fout << i % 10;

    return 0;
}
