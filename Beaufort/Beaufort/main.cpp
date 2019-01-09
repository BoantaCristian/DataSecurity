#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string encrypt(string sirulNecriptat, string cheia)
{
	string sirulCriptat(sirulNecriptat.length(), ' ');
	for (int i = 0; i < sirulNecriptat.size(); i++)
		sirulCriptat[i] = 'A' + ((cheia[i] - sirulNecriptat[i]) + 26) % 26;
	return sirulCriptat;
}

string decrypt(string sirulCriptat, string cheia)
{
	string sirulDecriptat(sirulCriptat.length(), ' ');
	for (int i = 0; i < sirulCriptat.size(); i++)
		sirulDecriptat[i] = 'A' + ((cheia[i] - sirulCriptat[i]) + 26) % 26;
	return sirulDecriptat;
}

int main()
{
	string sirulNecriptat;
	cout << "Unencrypted string: ";
	getline(cin, sirulNecriptat);
	transform(sirulNecriptat.begin(), sirulNecriptat.end(), sirulNecriptat.begin(), ::toupper);
	cout << "Key: ";
	string cheia;
	getline(cin, cheia);
	transform(cheia.begin(), cheia.end(), cheia.begin(), ::toupper);
	while (cheia.length() < sirulNecriptat.length())
		cheia += cheia;
	string sirulCriptat = encrypt(sirulNecriptat, cheia);
	cout << "Crypted string : " << sirulCriptat << "\n";
	cout << "Decrypted string : " << decrypt(sirulCriptat, cheia);
	return 0;
}
