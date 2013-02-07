#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

ifstream fin("frac1.in");
ofstream fout("frac1.out");

void doIt(int N, int num1, int den1, int num2, int den2)
{
    if(den1 + den2 > N)
        return;

    doIt(N, num1, den1, num1 + num2, den1 + den2); //Left side
    fout << num1 + num2 << "/" << den1 + den2 << " ";
    doIt(N, num1 + num2, den1 + den2, num2, den2); //Right side
}


int main(int argc ,char *argv[])
{
    int N;

    fin >> N;

    doIt(N, 0, 1, 1, 1);

    return 0;
}
