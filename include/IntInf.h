#include <stdio.h>
#include<string>
#include <iostream>
namespace ece309 {

class IntInf{
public:
  bool pos_inf;
  bool neg_inf;
  int num;
  IntInf(int x=0, bool inf=false, bool neg_inf=false);
  IntInf operator=(const IntInf &rhs);
  IntInf operator=(int val);
  IntInf operator+(const IntInf &rhs) const;
  IntInf operator-(const IntInf &rhs) const;
  IntInf operator*(const IntInf &rhs) const;
  IntInf operator/(const IntInf &rhs) const;
  bool operator==(const IntInf &rhs) const;
  bool operator>(const IntInf &rhs) const;
  bool operator<(const IntInf &rhs) const;
};
}
