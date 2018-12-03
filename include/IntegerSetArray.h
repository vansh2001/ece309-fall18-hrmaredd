#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
namespace ece309 {

class IntegerSet {
protected:
   int size;
   int hash(int key) const { return (key * 997) % size; }
public:
   IntegerSet(int htsize):size(htsize) {}
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};

class IntegerSetArray: public IntegerSet {
protected:
  int *table;
public:
  int filled;
  IntegerSetArray(int x);
  virtual bool insert(int) override;
  virtual bool search(int) const override;
  virtual void remove(int) override;
};
}
