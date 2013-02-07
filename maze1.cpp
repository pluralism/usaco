#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;
using std::make_pair;
using std::ifstream;
using std::ofstream;
using std::vector;


int minimal(vector<string> maze)
{
    //Vector que armazena as saídas disponiveis
    vector<pair<int, int> > exit;
    int n = maze[0].size();

    //Podemos começar por analisar a primeira linha
    for(int i = 0; i < n; i++)
    {
        //Se encontrar-mos um espaço então existe uma saída...
        if(maze[0][i] == ' ')
        {
            //Logo podemos criar um ponto como marcação
            exit.push_back(make_pair(1, i));
        }
    }

    //Fazer a mesma coisa para a última linha
    for(int i = 0; i < n; i++)
    {
        if(maze[maze.size() - 1][i] == ' ')
        {
            exit.push_back(make_pair(maze.size() - 2, i));
        }
    }

    //Analisar agora cada uma das duas laterais
    for(int i = 0; i < maze.size(); i++)
    {
        //Se encontrar um espaço numa das laterais
        if(maze[i][0] == ' ')
        {
            //Adicionar o valor ao vector das saídas
            exit.push_back(make_pair(i, 1));
        }
    }

    //Analisar a lateral direita
    for(int i = 0; i < maze.size(); i++)
    {
        if(maze[i][maze[i].size() - 1] == ' ')
        {
            exit.push_back(make_pair(i, maze[i].size() - 2));
        }
    }
}



int main(int argc, char *argv[])
{
    ifstream fin("maze1.in");
    ofstream fout("maze1.out");
    //Variaveis que armazenam o comprimento/altura do labirinto
    int W, H;
    //Vector que armazena o formato do labirinto
    vector<string> maze;

    //Ler a altura e comprimento
    fin >> W >> H;
    fin.get();

    //Fazer a leitura do labirinto e adicionar cada linha a um vector
    for(int i = 0; i < 2 * W + 1; i++)
    {
        string s;
        getline(fin, s);

        maze.push_back(s);
    }

    fout << minimal(maze) << endl;

    return 0;
}
