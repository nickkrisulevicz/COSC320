//Nick Krisulevicz
//Lab 03
//lab03_02.cpp
//02/22/2022

#include <iostream>
#include "d_tnodel.h"
#include "max.h"
using namespace std;


int main() 
{

  tnode<int> *root, *a, *b, *c, *d, *e;

  a = new tnode<int>(5);
  b = new tnode<int>(48);
  c = new tnode<int>(12);
  d = new tnode<int>(40, a, (tnode<int> *)NULL);
  e = new tnode<int>(15, b, c);
  root = new tnode<int>(35, d, e);

  int max = maxValue(root);
  cout << "Max Value in Tree is: " << max << endl;
 
  displayTree(root, 3);
}
