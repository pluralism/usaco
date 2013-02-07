#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using std::endl;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::max;


int main(int argc, char *argv[])
{
    int R;
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    vector<vector<int> > triangle;

    fin >> R;

    for(int i = 0; i < R; i++)
    {
        vector<int> values;

        for(int j = 0; j <= i; j++)
        {
            int temp;
            fin >> temp;
            values.push_back(temp);
        }
        triangle.push_back(values);
    }

    R--;
    //Começar a ler na última linha
    for(int i = R; i >= 1; i--)
    {
        //Ler cada um dos números(colunas)
        for(int j = 0; j < i; j++)
        {
            //O valor do número que está em cima e o valor maior entre os dois que estão na linha abaixo
            triangle[i - 1][j] += max(triangle[i][j], triangle[i][j + 1]);
        }
    }

    //Como i está sempre a diminuir o valor máximo está armazenado na primeira posição
    fout << triangle[0][0] << endl;

    return 0;
}
