#ifndef INTARRAY_H
#define INTARRAY_H

#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;

class IntArray
{
private:
   int *array;
   int length;
public:
   IntArray(const char* str);
   IntArray(int size, int val);
   int& operator[](int index);
   IntArray& operator+=(const IntArray &rhs);
   IntArray operator+(const IntArray &rhs) const;
   IntArray operator-(const IntArray &rhs) const;
   IntArray operator*(int x) const;
   IntArray operator/(int x) const;
   IntArray operator<<(int count) const;
   operator char*() const;
   operator int() const;
   void set(int index, int val);
   int get(int index);
   int getLength();
};

#endif //INTARRAY_H
