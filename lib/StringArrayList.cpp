#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
namespace ece309 {


class StringArrayList {

public:

  string *array;
  int counter;
  int size;

  StringArrayList(int s = 0) {
    size = s;
    counter = 0;
    array = new string[size];

    cout << "Array list loaded" << endl;
  }

void push_back(string input) {
  string storeArray = input;
  array[counter] = input;
  counter++;
  if (counter == size) {
    //allocate new storeArray
    string *array2 = new string[size * 2];
    //copy everything
    for (int i = 0; i < size; i++) {
      array2[i] = array[i];
    }
    //delete old array
    delete[] array;
    array = array2;
    //size = size*2
    size = size * 2;
  }
  cout << "push back worked" << endl;
}

string get(int n) {
  string copy;
  copy = array[n];

  return copy;
}

int length() {
  return counter;
}

string remove_front() {
  string copy2 = array[0];
  for(int j = 0; j < counter; j++) {
    array[j] = array[j+1];
  }
  return copy2;
}

~StringArrayList() {
    delete[] array;
}
};
}

int main() {

  StringArrayList r = StringArrayList(5);  //initial size
  r.push_back("Hello");
  r.push_back("What");
  r.push_back("is");
  r.push_back("your");
  r.push_back("name?");

  cout << "nth item " << r.get(3) << endl;
  cout << "nth item " << r.get(1) << endl;
  cout << "# of item " << r.length() << endl;
  cout << "deleted of item " << r.remove_front() << endl;
  cout << "nth item " << r.get(0) << endl;

  // StringArrayList s;
  // s.cool = 10;
  //
  // StringArrayList s(10);
  // s.push_back();


  return 0;
}
