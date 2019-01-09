#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string encrypt(string unencryptedString, string key)
{
	string encryptedString(unencryptedString.length(), ' ');
	for (int i = 0; i < unencryptedString.size(); i++)
		encryptedString[i] = 'A' + ((key[i] - unencryptedString[i]) + 26) % 26;
	return encryptedString;
}

string decrypt(string encryptedString, string key)
{
	string decryptedString(encryptedString.length(), ' ');
	for (int i = 0; i < encryptedString.size(); i++)
		decryptedString[i] = 'A' + ((key[i] - encryptedString[i]) + 26) % 26;
	return decryptedString;
}

int main()
{
	string unencryptedString;
	cout << "Unencrypted string: ";
	getline(cin, unencryptedString);
	transform(unencryptedString.begin(), unencryptedString.end(), unencryptedString.begin(), ::toupper);
	cout << "Key: ";
	string key;
	getline(cin, key);
	transform(key.begin(), key.end(), key.begin(), ::toupper);
	while (key.length() < unencryptedString.length())
		key += key;
	string encryptedString = encrypt(unencryptedString, key);
	cout << "Uncrypted string : " << encryptedString << "\n";
	cout << "Decrypted string : " << decrypt(encryptedString, key);
	return 0;
}
