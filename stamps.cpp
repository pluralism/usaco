#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using std::endl;
using std::vector;
using std::sort;
using std::ifstream;
using std::ofstream;



int main(int argc, char *argv)
{
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");
    vector<int> stamps;
    int N, K, total = 0;

    //K � o maximo de selos que podemos usar e N � o numero de valores
    fin >> K >> N;


    //Adicionar a um vector o valor de cada selo
    for(int i = 0; i < N; i++)
    {
        int temp;
        fin >> temp;
        stamps.push_back(temp);
    }

    //Ordenar os valores no vector
    sort(stamps.begin(), stamps.end());

    //Valor m�ximo que podemos fazer: ultimo elemento do vector x K(n�mero de selos)
    int max = stamps.back() * K;
    vector<int> minStamps(max, -1);

    //Para se fazer 0 n�o existem possibilidades(0)
    minStamps[0] = 0;

    //Analisar cada um dos valores..
    for(int i = 1; i <= max; i++)
    {
        //Analisar cada um dos selos..
        for(int j = 0; j < N; j++)
        {
            //Se o valor que estamos agora a analisar for menor do que o selo actual ent�o n�o faz
            //sentido continuar...
            if(i < stamps[j])
                continue;


            if(minStamps[i] > minStamps[i - stamps[j]] + 1)
                minStamps[i] = minStamps[i - stamps[j]] + 1;
        }
    }

    for(int i = 1; i <= max; i++)
    {
        //Se o n�mero minimo de selos necess�rio para o valor i for menor que o limite de selos ent�o adicionar a total
        if(minStamps[i] < K)
            total++;

    }

    fout << total - 2 << endl;

    return 0;
}
