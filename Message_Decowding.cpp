#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::map;
using std::endl;


int main(int argc, char *argv[])
{
	map<char, char> associa_letra;
	string decryption_key;
	string message;
	int len;
	
	cin >> decryption_key >> message;
	
	len = decryption_key.length();
	
	for(int i = 0; i < len; i++)
	{
		associa_letra[((int) 97 + i)] = decryption_key[i];
	}
	
	for(int i = 0; i < message.length(); i++)
	{
		if(message[i] != ' ')
			message[i] = associa_letra[message[i]];
	}
	cout << message << endl;
	return 0;
}