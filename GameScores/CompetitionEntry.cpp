/*
 * CompetitioneEntry.cpp
 *
 *      Author: niall
 */

#include "CompetitionEntry.h"

CompetitionEntry::CompetitionEntry(const string& name, const double& percentage_complete, const double& time_elapsed) :
	name(name), percentage_complete(percentage_complete), time_elapsed(time_elapsed){
	// TODO Auto-generated constructor stub

}

CompetitionEntry::~CompetitionEntry() {
	// TODO Auto-generated destructor stub
}

bool CompetitionEntry::operator<(const CompetitionEntry& d) const {
	return (this->get_score() < d.get_score());
}

ostream& operator<<(ostream& os, const CompetitionEntry& v) {
	return os << setw(15) << left << v.name << " "
			<< right << fixed << setprecision(2) << setw(7) << v.percentage_complete << " " << setw(7) << v.time_elapsed
			<< right << fixed << setprecision(3) << setw(7) << v.get_score();
			;
}
