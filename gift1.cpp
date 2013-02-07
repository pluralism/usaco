/*
ID: andrepd1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

//Each struct represents one friend
struct Friend
{
    //Each friend has a name and a given amount of money
    string name;
    int amount;
};


Friend *findFriend(Friend *pointer, string name)
{
    int i = 0;

    while(pointer[i].name != name)
        i++;

    if(pointer[i].name == name)
        return &pointer[i];
}

int main(int argc, char *argv[])
{
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    string name, receiver;
    int NP; //This variable represents the number of friends
    int totalMoney, numberOfPeople, divided, extra;
    Friend *giving, *receiving;

    //Read the number of friends from the file gift1.in
    fin >> NP;

    //Dynamic allocating memory with NP friends
    Friend *friends = new Friend[NP];

    //Then in the next NP + 1 lines read the name of each friend
    for(int i = 0; i < NP; i++)
    {
        //Read the name of each friend
        fin >> friends[i].name;
        friends[i].amount = 0;
    }

    for(int i = 0; i < NP; i++)
    {
        fin >> name; //Read the name of the friend that is distributing the money
        //Find that friend
        giving = findFriend(friends, name); //Now we know who is giving the money

        //Then we need to read the money he/she is giving and for how many people he/she is distributing it
        fin >> totalMoney >> numberOfPeople;
        //He/she'll give totalMoney/numberOfPeople for each of them
        if(divided = numberOfPeople)
            divided = totalMoney / numberOfPeople;
        else
            divided = 0;

        if(extra = numberOfPeople)
            extra = totalMoney % numberOfPeople;
        else
            extra = totalMoney;
        if(divided > 0)
        {
            //Withdraw the money from the person who is giving
            giving->amount += extra - totalMoney;
        }

        for(int i = 0; i < numberOfPeople; i++)
        {
            //Read the name of the person to add the money
            fin >> receiver;
            //Fint that person
            receiving = findFriend(friends, receiver);
            receiving->amount += divided;
        }
    }

    for(int i = 0; i < NP; i++)
    {
        fout << friends[i].name << " " << friends[i].amount << endl;
    }

    //Never forget to delete the allocated memory(use delete[] because we used new[])
    delete[] friends;

    return 0;
}
