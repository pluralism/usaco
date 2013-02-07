#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;


int main(int argc, char *argv[])
{
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");

    int V, G;
    vector<int> minimum_requirements;
    vector<vector<int> > vitamin_quantity;

    //The number of types of vitamins
    fin >> V;

    for(int i = 0; i < V; i++)
    {
        int temp;
        fin >> temp;
        minimum_requirements.push_back(temp);
    }

    //The number of types of feeds
    fin >> G;

    for(int i = 0; i < G; i++)
    {
        vector<int> vitamin;

        for(int j = 0; j < V; j++)
        {
            int temp;
            fin >> temp;
            vitamin.push_back(temp);
        }
        vitamin_quantity.push_back(vitamin);
    }

    return 0;
}
