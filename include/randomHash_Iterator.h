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
