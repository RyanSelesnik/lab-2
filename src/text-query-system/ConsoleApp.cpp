#include <iostream>
#include <vector>
#include "Word.h"
#include "Line.h"
#include "Paragraph.h"
#include "FileReader.h"

using namespace std;

int main(){
	// read from user-specified file
	string file = "";
	cout << "Enter a file name: ";
	cin >> file;
	FileReader fr{ file };
	auto paragraph = Paragraph{};
	fr.readFileInto(paragraph);

	// search
	string search_word = "";
	while (true) {
		cout << "Please enter a word to search for or ""."" to quit: ";
		cin >> search_word;
		if (search_word == ".") return 0;

		tuple<bool, vector<int>> search_results = paragraph.contains(search_word);
		bool found = get<0>(search_results);
		if (!found) {
			cout << "Word not found " << endl;
			continue;
		}

		// print out lines
		vector<int> lines_containing_search_word = get<1>(search_results);
		cout << "Word found:" << endl;
		for (int line_num : lines_containing_search_word)
			cout << "line " << line_num << endl;
	}
}