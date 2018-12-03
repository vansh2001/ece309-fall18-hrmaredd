#include <stdio.h>
#include<string>
#include <iostream>
#include "IntInf.h"

using namespace std;
using namespace ece309;

int main() {
printf("IntInf program ran succesfull....\n");
IntInf A;
IntInf C;
IntInf B;

B.neg_inf = false;
B.pos_inf = true;
B.num = 0;
A=B;
(A.neg_inf) ? printf("A.neg_inf true. ") : printf("A.neg_inf false. ");
(A.pos_inf) ? printf("A.pos_inf true. ") : printf("A.pos_inf false. ");
printf("A.num: %d ", A.num);
printf("\"operator=\" works\n");

A.pos_inf = false;
B.neg_inf = false;
B.pos_inf = false;
B.num = 2;
C= A+B;
(B.pos_inf) ? printf("B.pos_inf true. ") : printf("B.pos_inf false. ");
printf("C.num: %d ", C.num);
printf("\"operator+\" works\n");

B.neg_inf = false;
B.pos_inf = false;
B.num = 8;
C= A-B;
(C.neg_inf) ? printf("C.neg_inf true. ") : printf("C.neg_inf false. ");
printf("C.num: %d ", C.num);
printf("\"operator-\" works\n");

A.num = 1;
C = A*B;
(C.neg_inf) ? printf("C.neg_inf true. ") : printf("C.neg_inf false. ");
printf("C.num: %d ", C.num);
printf("\"operator*\" works\n");

A.num = 8;
B.num = 2;
C=A/B;
(C.neg_inf) ? printf("c.neg_inf true. ") : printf("C.neg_inf false. ");
printf("C.num: %d ", C.num);
printf("\"operator/\" works\n");

C=A==B;
(C.num) ? printf("C.num_inf true. ") : printf("C.pos_inf false. ");
printf("\"operator==\" works\n");

A.pos_inf = true;
B.neg_inf = true;
C=A>B;
(C.num) ? printf("C true. ") : printf("C false. ");
printf("\"operator> \" works\n");

A.pos_inf = true;
B.neg_inf = false;
C=A<B;
(C.num) ? printf("C true. ") : printf("C false. ");
printf("\"operator< \" works\n");

  return 0;
}
