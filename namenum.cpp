/*
ID: andrepd1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::multimap;
using std::pair;
using std::make_pair;
using std::ios;
using std::vector;

int main(int argc, char *argv[])
{
    ifstream fin("namenum.in");
    ifstream dict("dict.txt");
    ofstream fout("namenum.out");
    multimap<char, char> dictionary;
    vector<string> possibleWords;
    string word;

    typedef multimap<char, char>::iterator iterator;
    dictionary.insert(make_pair<char, char>('2', 'A'));
    dictionary.insert(make_pair<char, char>('2', 'B'));
    dictionary.insert(make_pair<char, char>('2', 'C'));

    dictionary.insert(make_pair<char, char>('3', 'D'));
    dictionary.insert(make_pair<char, char>('3', 'E'));
    dictionary.insert(make_pair<char, char>('3', 'F'));

    dictionary.insert(make_pair<char, char>('4', 'G'));
    dictionary.insert(make_pair<char, char>('4', 'H'));
    dictionary.insert(make_pair<char, char>('4', 'I'));

    dictionary.insert(make_pair<char, char>('5', 'J'));
    dictionary.insert(make_pair<char, char>('5', 'K'));
    dictionary.insert(make_pair<char, char>('5', 'L'));

    dictionary.insert(make_pair<char, char>('6', 'M'));
    dictionary.insert(make_pair<char, char>('6', 'N'));
    dictionary.insert(make_pair<char, char>('6', 'O'));

    dictionary.insert(make_pair<char, char>('7', 'P'));
    dictionary.insert(make_pair<char, char>('7', 'R'));
    dictionary.insert(make_pair<char, char>('7', 'S'));

    dictionary.insert(make_pair<char, char>('8', 'T'));
    dictionary.insert(make_pair<char, char>('8', 'U'));
    dictionary.insert(make_pair<char, char>('8', 'V'));

    dictionary.insert(make_pair<char, char>('9', 'W'));
    dictionary.insert(make_pair<char, char>('9', 'X'));
    dictionary.insert(make_pair<char, char>('9', 'Y'));


    string number;
    fin >> number;


    pair<iterator, iterator> b = dictionary.equal_range(number[0]);

    for(iterator it = b.first; it != b.second; it++)
    {
        while(dict >> word)
        {
            if(word[0] == it->second)
                possibleWords.push_back(word);
        }
        dict.clear();
        dict.seekg(0, ios::beg);
    }


    for(int i = 1; i < number.length(); i++)
    {
        for(int j = 2; j <= 9; j++)
        {
            if(j != number[i] - '0')
            {
                pair<iterator, iterator> c = dictionary.equal_range('0' + j);

                for(iterator it = c.first; it != c.second; it++)
                {
                    for(vector<string>::iterator it2 = possibleWords.begin(); it2 != possibleWords.end();)
                    {
                        string t = *it2;
                        if(t[i] == it->second || t[i] == 'Q' || t[i] == 'Z')
                            it2 = possibleWords.erase(it2);
                        else
                            it2++;
                    }
                }
            }
        }
    }

    if(!possibleWords.empty())
    {
        for(vector<string>::iterator it = possibleWords.begin(); it != possibleWords.end();)
        {
            string t = *it;

            if(t.length() != number.length())
                it = possibleWords.erase(it);
            else
            {
                fout << t << endl;
                it++;
            }
        }

    } else
        fout << "NONE" << endl;

    return 0;
}
