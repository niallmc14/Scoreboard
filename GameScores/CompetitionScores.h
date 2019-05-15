/*
 * CompetitionScores.h
 *
 *      Author: niall
 */

#ifndef COMPETITIONSCORES_H_
#define COMPETITIONSCORES_H_

#include "CompetitionEntry.h"

class CompetitionScores {
public:
	CompetitionScores(const int max_entries = 10);
	virtual ~CompetitionScores();

	void insert(const CompetitionEntry& e);
	CompetitionEntry remove(int index);

	friend ostream& operator<<(ostream& os, const CompetitionScores& s);

private:
	int num_entries;
	int max_entries;
	CompetitionEntry *entries;
};

#endif /* COMPETITIONSCORES_H_ */
