#include <stdio.h>
#include <string.h>
#include "IntArray.h"
using namespace std;

IntArray::IntArray(int le, int val=0):length(le) {
    array = new int[le];
    for(int i=0; i<le; i++)
        array[i] = val;
}

IntArray::IntArray(const char* str){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    array = new int[i];
    for(int j = 0; j < i; j++) {
        array[j] = str[j];
    }
}

int& IntArray::operator[](int index) {
    return array[index];
}

IntArray& IntArray::operator+=(const IntArray &rhs){
//        int lent = length < rhs.length ? length : rhs.length;
    int l;
    if(length < rhs.length) {
        l = length;
    } else {
        l = rhs.length;
    }
    for(int i = 0; i < l; i++ ){
        array[i] += rhs[i];
    }
    return *this;
}

IntArray IntArray::operator + (const IntArray &rhs) const {
    IntArray result(length); // make object to hold return value,
    // make long enough to hold this object’s data
    int i=0;
    for(i=0; i<length && i<rhs.length; i++) {
        result.array[i] = array[i] + rhs.array[i];
    }
    for(;i<length;i++) {// if rhs.length is shorter, copy rest of array
        result.array[i] = array[i];
    }
    return result;
}

IntArray IntArray::operator-(const IntArray &rhs) const {
    IntArray temp(length, 0);
    int len;

    if(length < rhs.length) {
        len = length;
    } else {
        len = rhs.length;
    }
    for(int i = 0; i < len; i++){
        temp.array[i] = array[i] - rhs.array[i];
    }
    return temp;
}

IntArray IntArray::operator*(int x) const {
    IntArray result = *new IntArray(length); // make object to hold return value

    // multiply each element of rhs by lhs
    for(int i=0; i<length; i++) {
        result[i] = array[i] * x;
    }
    return result;
}

IntArray IntArray::operator/(int x) const {
    IntArray temp(length, 0);
    for(int k = 0; k < length; k++){
        temp[k] = array[k] / x;
    }
    return temp;
}

IntArray IntArray::operator<<(int count) const {
    IntArray temp = *new IntArray(length, 0);
    count %= length;

    for(int j = 0; j < temp.length; j++){

        int nIndex = j - count;
        if(j - count < 0){
            nIndex = length - 1 - j;
        } else {
            nIndex = j - count;
        }
        temp[j] = array[nIndex];
     }
    return temp;
}

IntArray::operator char*() const {

    char* temp;
    temp = new char[length];
    for(int i = 0; i < length; i++) {
        if((array[i] < 0) || (array[i] > 255)){
            temp[i] = ' ';
        } else if(array[i] == 0) {
            temp[i] = '\0';
        } else {
            temp[i] = char(array[i]);
        }
    }
    return temp;
}

IntArray::operator int() const {
    int sum = 0;
    for(int i = 0; i < length; i++){
        sum += array[i];
    }
    return sum / length;
}

void IntArray::set(int index, int val) {
    array[index] = val;
}

int IntArray::get(int index) {
    return array[index];
}

int IntArray::getLength() { return length; }
