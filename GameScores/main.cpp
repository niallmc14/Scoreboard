/*
 * main.cpp
 *
 *    Author: niall
 */


#include "CompetitionEntry.h"
#include "CompetitionScores.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

CompetitionEntry entries[] = { CompetitionEntry("Marcia", 18.862, 696.71),
			CompetitionEntry("Sonja", 59.065, 311.409), CompetitionEntry(
					"Terese", 61.699, 209.447), CompetitionEntry("Raymond",
					25.513, 646.948), CompetitionEntry("Kayla", 96.82, 824.682),
			CompetitionEntry("Polly", 100, 904.269), CompetitionEntry("Sean",
					85.836, 642.485), CompetitionEntry("Darin", 85.219,
					548.012), CompetitionEntry("Gene", 80.93, 825.061),
			CompetitionEntry("Alexis", 93.092, 630.751), CompetitionEntry(
					"Miriam", 23.622, 562.063), CompetitionEntry("Adelia",
					26.683, 574.091), CompetitionEntry("Rickey", 96.315,
					265.823), CompetitionEntry("Sharolyn", 79.972, 476.465),
			CompetitionEntry("Susy", 77.804, 948.933), CompetitionEntry(
					"Nieves", 62.386, 545.571), CompetitionEntry("Vanda",
					66.205, 519.651), CompetitionEntry("Kelly", 42.558,
					191.979), CompetitionEntry("Kiley", 70.247, 463.804),
			CompetitionEntry("Delma", 78.13, 617.207), CompetitionEntry(
					"Violeta", 74.646, 564.064), CompetitionEntry("Willia",
					42.041, 855.036), CompetitionEntry("Scarlet", 51.666,
					685.314), CompetitionEntry("Ila", 61.063, 418.473),
			CompetitionEntry("Wava", 73.397, 777.344), CompetitionEntry("Peggy",
					100, 886.488), CompetitionEntry("Dori", 60.403, 833.13),
			CompetitionEntry("Kathryne", 27.957, 267.817), CompetitionEntry(
					"Cami", 85.711, 820.579), CompetitionEntry("Lorita", 35.691,
					808.558), CompetitionEntry("Svetlana", 47.323, 769.2),
			CompetitionEntry("Richard", 65.076, 206.145), CompetitionEntry(
					"Wendell", 100, 769.142), CompetitionEntry("Victor", 34.474,
					814.963), CompetitionEntry("Armida", 52.223, 553.346),
			CompetitionEntry("Sharyl", 35.968, 695.027), CompetitionEntry(
					"Patty", 53.613, 621.841), CompetitionEntry("Otilia",
					44.831, 782.779), CompetitionEntry("Mathew", 100, 757.392),
			CompetitionEntry("Amina", 100, 523.926), CompetitionEntry("Joslyn",
					84.359, 556.886), CompetitionEntry("Tiffani", 28.087,
					924.209), CompetitionEntry("Peg", 65.267, 997.479),
			CompetitionEntry("Anika", 55.101, 851.774), CompetitionEntry(
					"Caroline", 72.585, 977.793), };

void part_a(){
	int max_entries = 10;
	CompetitionScores scoretable(max_entries);

	for (auto entry : entries) {
		scoretable.insert(entry);
	}

	cout << scoretable << endl;
}

void part_b(){

	int max_entries = 10;
	CompetitionScores scoretable(max_entries);

	ifstream in("data/entries.txt");

	while(in){
		string line;
		getline(in, line);
		istringstream iss(line);
		string command;
		iss>> command;

		if(command == "insert"){
			string name;
			double percentage, time;
			iss >> name >> percentage >> time;
			scoretable.insert(CompetitionEntry(name, percentage, time));
		}else if(command == "remove"){
			int index;
			iss >> index;
			scoretable.remove(index);
		}
	}

	cout<< scoretable;
}

int main(void){

	part_a();
	part_b();

	return 0;
}
