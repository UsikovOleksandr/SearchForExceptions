#ifndef F_H
#define F_H
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

bool func(const pair<char, int>& entry1, const pair<char, int>& entry2);
void outputVerse(vector<string> verse);
void outputExceptions(set<string> exceptions);
void outputFoundedException(vector<string> text, size_t j);
void outputVectorLetters(vector<string> vectorLetters);
void outputWords(multimap<string, int> text, vector<string> vectorLetters);

#endif
