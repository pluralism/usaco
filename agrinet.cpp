#include <fstream>
using std::ifstream;
using std::ofstream;

#define MAX 100

//It would be better to use vectors
int distance[MAX][MAX];
int connections[MAX];

int main(int argc, char *argv[])
{
    int N, total = 0, min, no;
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");

    fin >> N;

    connections[0] = 1;

    //Fill the N x N matrix
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            fin >> distance[i][j];
        }
    }


    for(int j = 1; j < N; j++)
    {
        min = 0;

        for(int k = 0; k < N; k++)
        {
            for(int l = 0; l < N; l++)
            {
                if(distance[k][l] && connections[k] && !connections[l])
                {
                    if(distance[k][l] < min || min == 0)
                    {
                        min = distance[k][l];
                        no = l;
                    }
                }
            }
        }
        total += min;
        connections[no] = 1;
    }

    fout << total;

    return 0;
}
