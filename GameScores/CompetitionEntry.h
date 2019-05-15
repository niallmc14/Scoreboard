/*
 * CompetitioneEntry.h
 *
 *      Author: niall
 */

#ifndef COMPETITIONENTRY_H_
#define COMPETITIONENTRY_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class CompetitionEntry {
public:
	CompetitionEntry(const string& name = "", const double& percentage_complete = 0, const double& time_elapsed = 0);
	virtual ~CompetitionEntry();

	double get_score() const{
		return 0.5*(this->percentage_complete + this->time_elapsed/1000);
	}

	bool operator<(const CompetitionEntry& d) const;

	bool operator>(const CompetitionEntry& d) const {
		return d < (*this);
	}
	bool operator<=(const CompetitionEntry& d) const {
		return !(d < (*this));
	}
	bool operator>=(const CompetitionEntry& d) const {
		return !((*this) < d);
	}

	bool operator==(const CompetitionEntry& d) const ;

	friend ostream& operator<<(ostream& os, const CompetitionEntry& e);

private:
	string name;
	double percentage_complete;
	double time_elapsed;
};

#endif /* COMPETITIONENTRY_H_ */
