#include <stdio.h>
#include <string>
#include <iostream>


// IntegerSet abstract base class to demonstrate hash table concepts
class IntegerSet {
protected:
   int size;
   int hash(int key) const { return (key * (457662)) % size; }
public:
   IntegerSet(int htsize):size(htsize) {}
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
protected:
  int *table;
  int probeDistance;
  const int empty_since_start = -2;
  const int empty_after_removal = -1;
public:
  int c = 0; //Collisions
  int f = 0; //Fails
   IntegerSetHT(int htsize);
   virtual bool insert(int) override;
   virtual bool search(int) const override;
   virtual void remove(int) override;

class iterator {
  int passed_size;
  int *passed_table;
  int index;
public:
  iterator (int s, int *l);
  int getInt();
  void increment();
  bool end();

  };
  iterator begin() { return iterator(size, table); }
};
