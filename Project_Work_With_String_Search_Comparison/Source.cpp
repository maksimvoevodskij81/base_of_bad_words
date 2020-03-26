#include <iostream>
#include <conio.h>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
void init();
void show_words();
void check();
bool find(string text, string word);
void add_word();
int count_of_words = 2;
string* database = nullptr;

void main()
{
	short the_choice = 0;
	bool flag = true;
	init();
	cout << "\tenter '1' for check text  \n"
		"\tenter '2' for add bed word\n "
		"\tenter '3' for exit \n "
		"\tenter '4' for show bed word \n ";
	while (flag)
	{
		cin >> the_choice;
		switch (the_choice)
		{
		case 1:
			check();
			break;
		case 2:
			add_word();
			break;
		case 3:
			cout << " Bye !\n";
			flag = false;
			break;
		case 4:
			show_words();
			break;
		default:
			cout << " choose an item from the menu !!!\n";
			break;
		}
	}

	system("pause >> NUL");
}
void init()
{
	database = new string[count_of_words]; // 5
	database[0] = "XXX";
	database[1] = "viagra";
	transform(database[0].begin(), database[0].end(), database[0].begin(), tolower);
	transform(database[1].begin(), database[1].end(), database[1].begin(), tolower);
}
void show_words()
{
	for (int i = 0; i < count_of_words; i++)
	{
		cout << i + 1 << ") " << database[i] << "\n";
	}
	cout << "\n";
}
bool find(string text, string word)
{
	int p = text.find(word);
	//cout << p << "\n";
	if (p == -1)
		return false;

	return true;
}
void check()
{
	string text;
	cout << "Please, enter some phrase without space: ";
	cin >> text; // text
	transform(text.begin(), text.end(), text.begin(), tolower);
	bool spam = false;
	for (int i = 0; i < count_of_words; i++)
	{
		if (find(text, database[i]))
		{
			spam = true;
			break;
		}
	}

	if (spam) cout << "SPAM!\n";
	else cout << "NOT SPAM!\n";
}
void add_word()
{
	string* temp = new string[count_of_words + 1];
	for (int i = 0; i < count_of_words; i++)
	{
		temp[i] = database[i];
	}

	cout << "Enter new bad word: ";
	string word;
	cin >> word;
	transform(word.begin(), word.end(), word.begin(), tolower);
	temp[count_of_words++] = word;

	delete[] database;
	database = temp;

}