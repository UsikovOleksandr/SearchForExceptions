#include "Header.h"

bool func(const pair<char, int>& entry1, const pair<char, int>& entry2)
{
	return (entry1.first == entry2.first);
}

void outputVerse(vector<string> verse)
{
	ofstream fout("result.txt");
	cout << "Started text:\n\t";
	fout << "Started text:\n\t";
	copy(verse.begin(), verse.end(), ostream_iterator<string>(cout, "\n\t"));
	copy(verse.begin(), verse.end(), ostream_iterator<string>(fout, "\n\t"));
	fout.close();
}

void outputVectorLetters(vector<string> vectorLetters)
{
	ofstream fout("result.txt");
	cout << "\nLetters:";
	fout << "\nLetters:";
	copy(vectorLetters.begin(), vectorLetters.end(), ostream_iterator<string>(cout, "\n\t"));
	copy(vectorLetters.begin(), vectorLetters.end(), ostream_iterator<string>(fout, "\n\t"));
	fout.close();
}

void outputExceptions(set<string> exceptions)
{
	ofstream fout("result.txt");
	cout << "\nException words: ";
	fout << "\nException words: ";
	copy(exceptions.begin(), exceptions.end(), ostream_iterator<string>(cout, " "));
	copy(exceptions.begin(), exceptions.end(), ostream_iterator<string>(fout, " "));
	cout << endl;
	fout << endl;
	fout.close();
}

void outputFoundedException(vector<string> text, size_t j)
{
	ofstream fout("result.txt");
	cout << "\nException word: " << text[j];
	fout << "\nException word: " << text[j];
	fout.close();
}

void outputWords(multimap<string, int> text, vector<string> vectorLetters)
{
	ofstream fout("result.txt", ios_base::app);
	cout << "\nResult words:";
	fout << "\nResult words:";
	for (multimap<string, int>::iterator it = text.begin(); it != text.end(); it++)
	{
		cout << "\n\t" << it->first << " " << it->second << " / " << 125;
		fout << "\n\t" << it->first << " " << it->second << " / " << 125;
	}
	cout << endl;
	fout << endl;
	fout.close();
}
