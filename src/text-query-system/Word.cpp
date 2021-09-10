// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
#include <algorithm>
#include <iterator>
#include <functional>
#include <execution>

Word::Word(const string& word): word_{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	auto noLetters = true;
	for (auto ch : word_) {
		if (isspace(ch)) throw WordContainsSpace{};
		if (isalpha(ch)) noLetters = false;
	}
	if (noLetters) throw WordContainsNoLetters{};

	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
// returns true if the words are the same, ignoring case
// else returns false
bool Word::operator==(const Word& rhs) const
{
	// copy excluding punctuation
	auto str1 = ""s, str2 = ""s;
	std::remove_copy_if(word_.begin(), word_.end(), 
		std::back_inserter(str1),           
		std::ispunct
	);
	std::remove_copy_if(rhs.word_.begin(), rhs.word_.end(),
		std::back_inserter(str2),         
		std::ispunct
	);

	if (str1.length() != str2.length())
		return false;

	for (auto i = 0; i < str1.length(); i++) {
		if (toupper(str1[i]) != toupper(str2[i]))
			return false;
	}
		return true;
}

bool Word::isQueryable() const
{
	auto numLetters = 0;
	for (auto ch : word_) {
		if (isalpha(ch)) numLetters++;
	}
	return numLetters >= MIN_SIZE_FOR_QUERY_;
}
