#include <sstream>
#include <iostream>
#include "Hash.h"

using namespace std;

int main(int argc,char **argv) {
	// read the number of buckets
	int bNo; cin >> bNo;
	Hash table(bNo);

  // Using a fixed size buffer for reading content is not always safe, 
  // but ok here because we know how our input has to be:
  char line[100];

  // Main loop
  while ( std::cin.getline(line,100) ) {
    string str(line);
    if ( str.size()==0 ) continue; 
    if ( str[0]=='e' ) return 0;

		// Use cerr if you want to always print to the console, because cout
		// will be redirected to the output file when calling the Grade05 script:
	  // cerr<<line<<endl;

    if ( str.substr(0,1)=="o" ) {
			table.Print();
			cout << "++++++++++++++++++++" << endl;
		}
    else {
			int key;
		  stringstream convert_stm(str.substr(2, str.size()-1));
		  if ( !(convert_stm>>key) ) key = -1;

		  if (str.substr(0,1) == "i") {
				table.Insert(key);
			}
		  else {
				if (str.substr(0,1) == "d") {
					bool ret = table.Delete(key);
					if (true == ret) cout << key << " : DELETED" << endl;
					else cout << key << " : DELETE FAILED" << endl;

					cout << "++++++++++++++++++++" << endl;
				}
				else if (str.substr(0,1) == "s") {
					int b, p;
					bool ret = table.Search(key, b, p);
					if (true == ret) cout << key << " : FOUND AT " << b << "," << p << endl;
					else cout << key << " : NOT FOUND" << endl;

					cout << "++++++++++++++++++++" << endl;
				}
			}	
	  }
	}	
    
  return 0;
}

