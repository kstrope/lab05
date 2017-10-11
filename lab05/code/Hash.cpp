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
	list<int> temp;
	bool deleted = false;
	int size = 0;
	for (int i = 0; i < table.size(); i++){
		while (!table.at(i).empty()){
			if (table.at(i).front() != toDelete){
				temp.push_front(table.at(i).front());
				table.at(i).pop_front();
			}
			else if (table.at(i).front() == toDelete){
				deleted = true;
				table.at(i).pop_front();
			}
		}
		while (!temp.empty()){
			table.at(i).push_front(temp.front());
			temp.pop_front();
		}
	}
	if (deleted == true)
		return true;
	else
		return false;
}

bool Hash::Search(int key, int& _bucket, int& _pos) {
	list<int> temp;
	bool found = false;
	int pos = 0;
	int size = 0;
	for (int i = 0; i < table.size(); i++){
		pos = 0
		while (!table.at(i).empty()){
			if (table.at(i).front() == key){
				found = true;
				_bucket = i;
				_pos = pos;
			}
			temp.push_front(table.at(i).front());
			table.at(i).pop_front();
		}
		while (!temp.empty()){
			table.at(i).push_front(temp.front());
			temp.pop_front();
		}
	}
	if (found == true)
		return true;
	else
		return false;
}

void Hash::Print() {
	list<int> temp;
	for (int i = 0; i < table.size(); i++){
		cout << i << " : ";
		while (!table.at(i).empty()){
			if (i < (table.size()-1))
				cout << table.at(i).front() << "->";
			else if (i == (table.size()-1))
				cout << table.at(i).front() << endl;
			temp.push_front(table.at(i).front());
			table.at(i).pop_front();
		}
		while (!temp.empty()){
			table.at(i).push_front(temp.front());
			temp.pop_front();
		}
	}
}

