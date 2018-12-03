#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
namespace ece309 {

// IntegerSet abstract base class to demonstrate hash table concepts
class IntegerSet {
protected:
   int size;
   int hash(int key) const {
     if (((key * (457662)) % size) < 0) {

       return -((key * (457662)) % size);
     }
     return ((key * (457662)) % size);
     }
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

};


// can only hold positive integers
IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
  probeDistance = 20;
   table = new int[size];
   for(int i=0; i<size; i++)
      table[i] = empty_since_start;  // -1 means empty
}

bool IntegerSetHT::insert(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( bucketsProbed++ < probeDistance )  // bucketsProbed less than probeDistance
  {
   if ( table[index] < 0 )
   {
     // if the entry is not being used, put the
    // data there
     table[ index ] = data;
     cout << "# of c = " <<  c << "\n";
     cout << "# of f = " <<  f << "\n";

     return true;
   }
   if(bucketsProbed == 2) {
     c++;
   }
   index = (index+1) % size;
  }
  // otherwise give up
  f++;
  cout << "Number of c = " <<  c << "\n";
  cout << "Number of f = " <<  f << "\n";

   return false;
}

bool IntegerSetHT::search(int data) const
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     return true;
   }
   index = (index+1) % size;
  }

  // data can only be in one location, check it
  return false;
}

void IntegerSetHT::remove(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     table[index] = empty_after_removal;
     //return;
   }
   index = (index+1) % size;
  }
}

int main() {
  IntegerSetHT set(1000);
  srand(time(NULL));
  int count=0;

  for(int i = 0; i < 500; i++)
  {

    int r = rand();
    set.insert(r);
    count++;

  }
  return 0;
}
}
