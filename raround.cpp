#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ostringstream;
using std::stringstream;
using std::ofstream;
using std::ifstream;


bool acceptNumber(int number)
{
    vector<int> numbers(255, 0);
    string n = static_cast<ostringstream*>(&(ostringstream() << number))->str();

    for(int i = 0; i < n.length(); i++)
    {
        numbers[n[i]]++;

        if(numbers[n[i]] > 1)
            return false;
    }

    return true;
}


bool isRunAround(int number)
{
    int j = 0;
    string n = static_cast<ostringstream*>(&(ostringstream() << number))->str();
    int cur = n[j] - '0';
    stringstream s;

    for(int i = 0; i < n.length(); i++)
    {
        if(j + cur >= n.length())
        {
            cur = (n[(j + n[j] - '0') % n.length()]) - '0';
            s << cur;
            j = n.find_first_of(s.str());
            s.str(string());
        } else {
            cur = n[(j + n[j] - '0')] - '0';
            s << cur;
            j = n.find_first_of(s.str());
            s.str(string());
        }

        if(i == n.length() - 1)
        {
            if(n[0] - '0' == cur)
                return true;
            else
                return false;
        }
    }
}


int main(int argc, char *argv[])
{
    ifstream fin("around.in");
    ofstream fout("around.out");
    int N;

    fin >> N;
    N++;

    while(!isRunAround(N))
        N++;

    fout << N << endl;

    return 0;
}
