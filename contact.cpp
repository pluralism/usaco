#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
using std::endl;
using std::map;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

//Um padrão é constituido pelo padrão e o número de ocurrencias de cada um
struct Pattern
{
    string pattern;
    int occurrences;
};



bool operator <(Pattern p1, Pattern p2)
{
    /**
      Lines that list the N highest frequencies (in descending order of frequency)
      along with the patterns that occur in those frequencies. Order those patterns
      by shortest-to-longest and increasing binary number for those of the same frequency.
      If fewer than N highest frequencies are available, print only those that are.
      */

       if (p1.occurrences != p2.occurrences)
             return p1.occurrences > p2.occurrences;
       if (p1.pattern.length() != p2.pattern.length())
             return p1.pattern.length() < p2.pattern.length();
       return p1.pattern < p2.pattern;
}

vector<Pattern> getPatterns(int A, int B, string sequence)
{
    //Vector que contém todos os padrões possiveis
    vector<Pattern> patterns;

    //Mapa que armazena o padrão e a quantidade de vezes que se repete(temporariamente)
    map<string, int> tempPattern;
    //O padrão temporário que vamos utilizar para adicionar outros ao vector "patterns"
    Pattern temp;
    //Tamanho da string "sequence"
    int len = sequence.length();

    //Analisar toda a sequencia...
    for(int i = 0; i < len; i++)
    {
        //A sequencia tem que estar entre A e B...
        for(int j = A; j <= B; j++)
        {
            //Nao podemos ler para lá da sequencia, restringuir até "len"
            if(i + j <= len)
            {
                //Então podemos adicionar a substring ao mapa
                tempPattern[sequence.substr(i, j)]++;
            }
        }
    }

    //Adicionar todos os elementos ao vector
    for(map<string, int>::iterator it = tempPattern.begin(); it != tempPattern.end(); it++)
    {
        temp.pattern = it -> first;
        temp.occurrences = it -> second;
        patterns.push_back(temp);

        //Ordenar os padrões na ordem pedida
        sort(patterns.begin(), patterns.end());
    }


    return patterns;
}


int main(int argc, char *argv[])
{
    int A, B, N;
    string temp, final = "";
    ifstream fin("contact.in");
    ofstream fout("contact.out");

    fin >> A >> B >> N;
    fin.get();

    while(getline(fin, temp))
        final += temp;

    vector<Pattern> orderedPatterns = getPatterns(A, B, final);


    for(int i = 0; i < orderedPatterns.size() &&  i < N; i++)
    {
        fout << orderedPatterns[i].occurrences << endl;
        fout << orderedPatterns[i].pattern << endl;
    }

    return 0;
}
