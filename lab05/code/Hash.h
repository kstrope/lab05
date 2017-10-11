
#ifndef HASH_H
#define HASH_H

#include <list>
#include <vector>

using namespace std;


class Hash {
  // Public Functions/Variables
  public:
    Hash(int _bNo);  // Constructor
    virtual ~Hash(); // Destructor

    void Insert(int toInsert);

		// return true if the key is deleted; false, if there is no such key
    bool Delete(int toDelete);

		// return true if key is found and corresponding position; false, otherwise
		bool Search(int key, int& _bucket, int& _pos);
		
    void Print();

  // Private Functions/Variables
  private:
		int bNo;
		vector < list < int > > table;
};

#endif

