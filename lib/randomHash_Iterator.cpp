#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

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

 IntegerSetHT::iterator::iterator(int s, int *l) {
  passed_size = s;
  passed_table= l;
  for(index = 0; index < passed_size ; index++) {
  if(passed_table[index] >= 0) { break; }
  }
}

int IntegerSetHT::iterator::getInt() {
  return passed_table[index];
}

void IntegerSetHT::iterator::increment() {

  index++;
  for(; index < passed_size; index++) {
   if(passed_table[index] >= 0) { break; }
  }
}

bool IntegerSetHT::iterator::end() {
  //printf("end called");
    if( index <  passed_size) { return false; }
    else return true;
}

// can only hold positive integers
IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
  probeDistance = 10;
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
    IntegerSetHT set(100);
    set.insert(5);
    set.insert(99);
    set.insert(0);

   IntegerSetHT::iterator sit = set.begin();
    while(!sit.end())
    {
      printf("%d", sit.getInt());
      sit.increment();
    }
  printf("\n");
  return 0;
}
