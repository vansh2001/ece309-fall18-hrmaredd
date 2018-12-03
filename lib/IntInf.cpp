#include <stdio.h>
#include<string>
#include <iostream>
#include "IntInf.h"

namespace ece309 {

IntInf::IntInf(int x, bool inf, bool neg_inf):num(x){}

IntInf IntInf::operator=(const IntInf &rhs) {
  pos_inf = rhs.pos_inf;
  neg_inf = rhs.neg_inf;
  num = rhs.num;

 return 0;
}
IntInf IntInf::operator=(int val) {
  pos_inf = false;
  pos_inf = false;
  num = val;

  return 0;
}

IntInf IntInf::operator+(const IntInf &rhs) const{
  IntInf result;
  if(pos_inf) result.pos_inf =true;
  else if(neg_inf) result.neg_inf = true;
  else if(rhs.pos_inf) result.pos_inf = true;
  else if(rhs.neg_inf) result.neg_inf = true;
  else {
    result.num = num + rhs.num;
  }
  return result;
}


IntInf IntInf::operator-(const IntInf &rhs) const{
  IntInf result;
  if(pos_inf) result.pos_inf = true;
  else if(neg_inf) result.neg_inf = true;
  else if(rhs.pos_inf) result.pos_inf = true;
  else if(rhs.neg_inf) result.neg_inf = true;
  else {
    result.num = num - rhs.num;
  }
  return result;
}

IntInf IntInf::operator*(const IntInf &rhs) const{
  IntInf result;
  if(pos_inf) {
    if(rhs.neg_inf) result.neg_inf = true;
    else result.pos_inf = true;
  }
  else if(neg_inf){
    if(rhs.pos_inf) result.neg_inf = true;
    else result.neg_inf = true;
  }
  else {
    result.num = num * rhs.num;
  }
  return result;
}
IntInf IntInf::operator/(const IntInf &rhs) const{
  IntInf result;
  if(num == 0) result.num = 0;
  else if(rhs.num == 0) printf("undefined");
  else if(pos_inf) {
    if(rhs.neg_inf) result.neg_inf = true;
    else result.pos_inf = true;
  }
  else if(neg_inf){
    if(rhs.pos_inf) result.neg_inf = true;
    else result.neg_inf = true;
  }
  else {
    result.num = num / rhs.num;
  }
  return result;
}
bool IntInf::operator==(const IntInf &rhs) const{
  if(num == rhs.num){
    return false;
  } else return true;
}
bool IntInf::operator>(const IntInf &rhs) const{
    if(rhs.pos_inf) return false;
    else return true;
}
bool IntInf::operator<(const IntInf &rhs) const{
  if(rhs.pos_inf) return true;
  else return false;
}
}
