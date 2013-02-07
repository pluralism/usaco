/*
ID: andrepd1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

int calculate_product(string &s)
{
	int p = 1;
	
	for(int i = 0; i < s.length(); i++)
	{
		p *= (s[i] - 'A') + 1;
	}
	
	return p;
}

void toUpper(string &s)
{
	for(int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
}


int main(int argc, char *argv[])
{
	ifstream fin("ride.in");
	ofstream fout("ride.out");
	string group_name, comet_name;
	
	fin >> group_name >> comet_name;
	toUpper(group_name);
	toUpper(comet_name);
	
	if(calculate_product(group_name) % 47 == calculate_product(comet_name) % 47)
		fout << "GO\n";
	else
		fout << "STAY\n";
	
	return 0;
}
