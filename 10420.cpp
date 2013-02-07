#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;


int main(int argc, char *argv[])
{
    int N;
    map<string, int> mm;

    cin >> N;
    cout << endl;

    for(int i = 0; i < N; i++)
    {
        string country;
        string name;

        cin >> country;
        getline(cin, name);

        mm[country]++;
    }

    for(map<string, int>::iterator it = mm.begin(); it != mm.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
