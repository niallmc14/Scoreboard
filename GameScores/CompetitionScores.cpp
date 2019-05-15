/*
 * CompetitionScores.cpp
 *
 *      Author: niall
 */

#include "CompetitionScores.h"

CompetitionScores::CompetitionScores(const int max_entries) :
		num_entries(0), max_entries(max_entries) {
	this->entries = new CompetitionEntry[max_entries];
}

CompetitionScores::~CompetitionScores() {
	delete[] this->entries;
}

/*
 void CompetitionScores::insert(const CompetitionEntry& new_entry) {
 // first thing is to increase the num_entries, if allowed
 // if the new_entry is the lowest score, put it at the end of the list
 //
 // start at the end of the list and work back, the main while loop
 // should look something like this:
 //
 //   while (i >= 0 && new_entry > entries[i]) {
 //
 // this is using the overloaded "CompetitionEntry::operator>()"
 //
 // final step is to assign the entry at the right place
 }
 */
void CompetitionScores::insert(const CompetitionEntry& new_entry) {

	if (num_entries == max_entries) {
		if (new_entry <= this->entries[max_entries - 1]) {
			return;
		}
	} else {
		num_entries++;
	}

	int i = num_entries - 2;
	while (i >= 0 && new_entry > entries[i]) {
		entries[i + 1] = entries[i]; // shift right if smaller
		--i;
	}
	entries[i + 1] = new_entry;
	return;
}

CompetitionEntry CompetitionScores::remove(int index) {
	if ((index < 0) || (index > num_entries)) {
		// might be better to throw an exception here, but we will just reutrn a default object
		return CompetitionEntry();
	}
	CompetitionEntry e = this->entries[index];
	for (int j = index + 1; j < num_entries; ++j) {
		this->entries[j - 1] = entries[j];
	}
	--num_entries;
	return e;
}

ostream& operator<<(ostream& os, const CompetitionScores& c) {
	os << "Top " << c.max_entries << " Competition Entry Scores" << endl
			<< endl;
	 os << setfill(' ') << left << setw(3) << "i"
			 << setfill(' ') << setw(15) << left << "name"
				<< setfill(' ') << right << setw(8) << "%"
				<< setfill(' ') << setw(8) << "t"
				<< right << setfill(' ') << setw(7) << "score" << endl;
	for (int i = 0; i < c.max_entries; ++i) {
		os << setw(2) << i << " " << c.entries[i] << endl;
	}
	return os;
}
