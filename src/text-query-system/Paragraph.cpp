// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
	paragraph_.push_back(line);
}

tuple<bool, vector<int>> Paragraph::contains(const Word& search_word) const
{
	bool found = false;
	vector<int> lines_containing_search_word;

	// Line::contains would handle this case, but it would be inefficient
	if (!search_word.isQueryable()) return tuple{ found, lines_containing_search_word };
	
	for (auto i = 0u; i < paragraph_.size(); i++) {
		if (paragraph_[i].contains(search_word)) {
			found = true;
			lines_containing_search_word.push_back(i + 1); // note: line number = index + 1
		}
	}
	return {found, lines_containing_search_word};
}