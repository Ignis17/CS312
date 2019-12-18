#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector <string> dictionary;

void dictGenerator(string filename){
	ifstream inputFile;
  inputFile.open(filename);
	string line;
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

// result store the current prefix with spaces
// between words
void output(string str, int n, string result)
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
			}
				output(str.substr(i, n-i), n-i,
								result + prefix + " ");
		}
	}
}


// Function to determine if string can be segmented into a space-separated
// sequence of one or more dictionary words
bool wordBreak(vector<string> const &dict, string str, vector<int> &lookup, string result)
{
	// n stores length of current substring
	int n = str.size();

	// return true if we have reached the end of the string
	if (n == 0)
		return true;

	// if sub-problem is seen for the first time
	if (lookup[n] == -1)
	{
		// mark sub-problem as seen (0 initially assuming string
		// can't be segmented)
		lookup[n] = 0;

		for (int i = 1; i <= n; i++)
		{
			// consider all prefixes of current string
			string prefix = str.substr(0, i);

			// if prefix is found in dictionary, then recur for suffix
			if (find(dict.begin(), dict.end(), prefix) != dict.end() && wordBreak(dict,str.substr(i), lookup, result + prefix + " "))
			{
				// return true if the string can be segmented
				return lookup[n] = 1;
			}
		}
	}
	return lookup[n];
}

// Word Break Problem
int main(){
	string str;
	dictGenerator("english-words.txt");
	cout << "Enter a string:\n";
	cin >> str;

	transform(str.begin(), str.end(), str.begin(), ::tolower);
	vector<int> lookup(str.length() + 1, -1);

	if(wordBreak(dictionary, str, lookup, "")){
		output(str,str.length(), "");
	}

	vector<int> values(10000);
  // Generate Random values
  auto f = []() -> int { return rand() % 10000; };

  // Fill up the vector
  generate(values.begin(), values.end(), f);

  // Get starting timepoint
  auto start = high_resolution_clock::now();

  // Call the function, here sort()
  sort(values.begin(), values.end());

  // Get ending timepoint
  auto stop = high_resolution_clock::now();

  // Get duration. Substart timepoints to
  // get durarion. To cast it to proper unit
  // use duration cast method
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time taken by function: " << (duration.count()/1e+6) << " seconds" << endl;

	return 0;
}
