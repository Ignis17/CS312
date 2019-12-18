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

// Function to segment given string into a space-separated
// sequence of one or more dictionary words
void wordBreak(vector<string> const &dict, string str, string out)
{
	// if we have reached the end of the string,
	// print the output string
	if (str.size() == 0)
	{
		cout << out << endl;
	}

	for (int i = 1; i <= str.size(); i++)
	{
		// consider all prefixes of current string
		string prefix = str.substr(0, i);

		// if the prefix is present in the dictionary, add prefix to the
		// output string and recur for remaining string
		if (find(dict.begin(), dict.end(), prefix) != dict.end())
			wordBreak(dict, str.substr(i), out + " " + prefix);
	}
}

// Word Break Problem
int main()
{
	string str;
	vector<int> values(10000);
	vector<int> lookup(str.length() + 1, -1);
	dictGenerator("english-words.txt");
	// lookup[i] stores if substring str[n-i..n) can be segmented or not
	cout << "Enter a string:\n";
	cin >> str;
	//
	transform(str.begin(), str.end(), str.begin(), ::tolower);

	wordBreak(dictionary, str, "");

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
