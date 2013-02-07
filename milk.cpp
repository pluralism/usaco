#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::sort;


struct Farmer
{
    int price;
    int amount;
};


bool cheapFunction(const Farmer &first, const Farmer &second)
{
    return first.price < second.price;
}


int main(int argc, char *argv[])
{
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int M, N, total = 0;

    //Read the values M and N
    fin >> N >> M;
    Farmer *farmers = new Farmer[M];

    for(int i = 0; i < M; i++)
    {
        fin >> farmers[i].price >> farmers[i].amount;
    }

    sort(farmers, farmers + M, cheapFunction);

    for(int i = 0; i < M && N > 0; i++)
    {
        int quantity = std::min(N, farmers[i].amount);
        total += farmers[i].price * quantity;
        N -= quantity;
    }

    fout << total << endl;


    delete[] farmers;

    return 0;
}
