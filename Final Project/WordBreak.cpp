// A recursive program to print all possible
// partitions of a given string into dictionary
// words
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector <string> dictionary;
// Prototypes:
void wordBreakUtil(string str, int size, string result);

void dictGenerator(string filename){
	ifstream inputFile;
  inputFile.open(filename);
	string line;
	vector<string> tokens;
  if (inputFile.is_open()){
		while (inputFile >> line){
			dictionary.push_back(line);
			}
		}
	inputFile.close();
}

int dictionaryContains(string &word)
{
	for (int i = 0; i < dictionary.size(); i++)
		if (dictionary[i].compare(word) == 0)
			return true;
	return false;
}

// Prints all possible word breaks of given string
void wordBreak(string str)
{
	// last argument is prefix
	wordBreakUtil(str, str.size(), "");
}

// result store the current prefix with spaces
// between words
void wordBreakUtil(string str, int n, string result)
{
	//Process all prefixes one by one
	for (int i=1; i<=n; i++)
	{
		//extract substring from 0 to i in prefix
		string prefix = str.substr(0, i);

		// if dictionary conatins this prefix, then
		// we check for remaining string. Otherwise
		// we ignore this prefix (there is no else for
		// this if) and try next
		if (dictionaryContains(prefix))
		{
			// if no more elements are there, print it
			if (i == n)
			{
				// add this element to previous prefix
				result += prefix;
				cout << result << endl; //print result
				return;
			}
			wordBreakUtil(str.substr(i, n-i), n-i,
								result + prefix + " ");
		}
	}
}

int main()
{
	string user;
	dictGenerator("english-words.txt");
	cout << "Enter a string:\n";
	cin >> user;
  wordBreak(user);
	return 0;
}
