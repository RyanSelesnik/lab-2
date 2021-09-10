// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
#include <sstream>
#include <algorithm>

Line::Line(const string& line)
{
	// for extracting words.
	istringstream ss(line);
	string temp = ""s;
	while (ss >> temp) {
		line_.push_back(temp);
	}	
}

bool Line::contains(const Word& search_word) const
{
	// returns true if the search word is queryable AND line contains it. Returns false otherwise. Ignores case
	// check queryable
	if (!search_word.isQueryable())
		return false;

	// note: std::find uses the == operator. We have overloaded the == operator to ignore case
	
	// Exercise 5.3: if multiple instances occurred in one line, this method would still return true
	// i.e. this implementation only tells the client whether the line contains the word or not, and is unaffected
	// by the number of instances.
	// To support this properly, another pubic member function would have to be added to Line
	// e.g int Line::count_instances(const word& search_word)
	// One should not change the return type of the existing method because that could affect other client code

	auto it = std::find(line_.begin(), line_.end(), search_word);
	return (it >= line_.begin() && it < line_.end());
	// we could just return (it != line_.end()) 
	// but that would still return true if the iterator somehow went out of bounds
}
