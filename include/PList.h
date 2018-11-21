#include <iostream>
#include <string>
using namespace std;

class Object{
public:
  virtual void print(){ printf("object!\n");  };
};

//Integer Object
class Integer: public Object {
public:
  int data;
  Integer(int x):data(x){}
  void print(){
    printf("%d\n", data);
  }

};
//Doubles Object
class Doubles: public Object {
public:
  double data;
  Doubles(double x):data(x){}
  void print() {
     printf("%f\n", data);
  }
};
//Double Strings
class Strings: public Object {
public:
  char* data;
  Strings(char *x): data(x){}
  void print() {
    printf("%s\n", data);
  }
};

//List created here
class PList {
private:
  class ListNode { //Node Created
  private:
    ListNode *next;
    Object *data; //Moved to Public bc of access errors
  public:
    ListNode (Object *input, ListNode *n_value = NULL){
    data = input;
    next = n_value;
    }
    Object* getItem(){
      return data;
    }
    ListNode* getNext(){
      return next;
    }
    void setNext(ListNode *e){ next = e; }
  };

public:
  ListNode *head;
  ListNode *tail;
  PList(){
    head = NULL;
    tail = NULL;
  }
  class iterator {
  public:
    ListNode *node;
    iterator(ListNode *n = NULL){
      node = n;
    }
    Object* getItem() { return node->getItem();}
    void increment() { node = node->getNext(); }
    bool end() { return node==NULL; }
  };

  iterator begin();
  void append(Object *a);
  void removeAfter(iterator it);
  void insertAfter(iterator it, Object *a);

};
