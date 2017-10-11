#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Hash.h"

using namespace std;


/****************************************************************
 * CONSTRUCTOR
 ****************************************************************/
Hash::Hash(int _bNo) {
	//size not determined until this moment, so the table has to be the right size
	table.resize(_bNo);
}

/****************************************************************
 * DESTRUCTOR
 ****************************************************************/
Hash::~Hash() {
	table.clear();
}

void Hash::Insert(int toInsert) {
	int key;
	key = toInsert % table.size();
	table.at(key).push_front(toInsert);
}

bool Hash::Delete(int toDelete) {
	int deleted = 0;
	int size = 0;
	for (int i = 0; i < table.size(); i++){
		list<int> temp;
		while (!table.at(i).empty()){
			if (table.at(i).front() != toDelete || (deleted == 1)){
				temp.push_back(table.at(i).front());
				table.at(i).pop_front();
			}
			else if ((table.at(i).front() == toDelete) && (deleted != 1)){
				deleted = 1;
				table.at(i).pop_front();
			}
		}
		table.at(i) = temp;
		temp.clear();
	}
	if (deleted == 1)
		return true;
	else
		return false;
}

bool Hash::Search(int key, int& _bucket, int& _pos) {
	bool found = false;
	int pos = 0;
	int size = 0;
	for (int i = 0; i < table.size(); i++){
		pos = 0;
		list<int> temp = table.at(i);
		while (!temp.empty()){
			if (temp.front() == key && found != true){
				found = true;
				_bucket = i;
				_pos = pos;
			}
			pos++;
			temp.pop_front();
		}
		temp.clear();
	}
	if (found == true)
		return true;
	else
		return false;
}

void Hash::Print() {
	for (int i = 0; i < table.size(); i++){
		list<int> temp = table.at(i);
		cout << i << " : ";
		int size = table.at(i).size();
		while (!temp.empty()){
			cout << temp.front();
			temp.pop_front();
			if (!temp.empty())
				cout << "->";
		}
		cout << endl;
		temp.clear();
	}
}

