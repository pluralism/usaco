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
    //Come�ar a ler na �ltima linha
    for(int i = R; i >= 1; i--)
    {
        //Ler cada um dos n�meros(colunas)
        for(int j = 0; j < i; j++)
        {
            //O valor do n�mero que est� em cima e o valor maior entre os dois que est�o na linha abaixo
            triangle[i - 1][j] += max(triangle[i][j], triangle[i][j + 1]);
        }
    }

    //Como i est� sempre a diminuir o valor m�ximo est� armazenado na primeira posi��o
    fout << triangle[0][0] << endl;

    return 0;
}
