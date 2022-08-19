#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <vector>
#include <windows.h>
#include "Header.h"

using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<string> verse;
	ifstream read("text1.txt");	//read main text
	if (!read) {
		cout << "File not found" << endl;
		return 1;
	}
	while (!read.eof()) {
		string str;
		getline(read, str);
		if (read) verse.push_back(str);
	}
	read.close();

	outputVerse(verse); //output

	vector<string> vectorLetters;
	ifstream read2("letters.txt"); //read letters from file
	if (!read2) {
		cout << "File not found" << endl;
		return 1;
	}
	while (!read2.eof()) {
		string str;
		getline(read2, str);
		if (read2) vectorLetters.push_back(str);
	}
	read2.close();

	outputVectorLetters(vectorLetters);//output

	set<string> exceptions;
	ifstream read1("except.txt"); //read exceptions from file
	while (!read1.eof())
	{
		string str;
		read1 >> str;
		if (read1) exceptions.insert(str);
	}
	read1.close();

	outputExceptions(exceptions); //output

	//Block for finding exceptions(from the list in a text file) in the text

	for (int i = 0; i < verse.size(); ++i) {
		string del = " ";
		int previous = 0;
		int next;
		string word = verse[i];
		vector<string> text;

		while ((next = word.find(del, previous)) != string::npos) {
			text.push_back(word.substr(previous, next - previous));
			previous = next + 1;
		}

		for (int i1 = 0; i1 < text.size(); ++i1) {
			if (exceptions.find(text[i1]) != exceptions.end()) {
				outputFoundedException(text, i1); //output
				continue;
			}
		}
	}

	//Block for finding letters(from the list in a text file) in the text

	multimap<string, int> pair2;
	vector<int> count_all;
	for (int i = 0; i < vectorLetters.size(); ++i) {
		for (int i = 0; i < verse.size(); ++i) {
			string del = " ";
			int previous = 0;
			int next;
			vector<string> letters;
			string str = verse[i];
			int count = 0;
			if (i < vectorLetters.size()) {
				size_t found = str.find_first_of(vectorLetters[i]);
				while (found != string::npos)
				{
					count++;
					found = str.find_first_of(vectorLetters[i], found + 1); //continue searching
				}
			}
			count_all.push_back(count);
		}
		pair2.insert(make_pair(vectorLetters[i], count_all[i]));
	}

	outputWords(pair2, vectorLetters); //output

	return 0;


}
