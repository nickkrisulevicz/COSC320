//Nick Krisulevicz
//Lab 03
//lab03_01.cpp
//02/22/2022

#include <iostream>
#include "countOneChild.h"
#include "d_tnodel.h"
using namespace std;

int main() 
{

  tnode<char> *root, *b, *c, *d, *e, *f, *g;
  g = new tnode<char> ('G');
  e = new tnode<char> ('E', (tnode <char> *)NULL, g);
  f = new tnode<char> ('F');
  c = new tnode<char> ('C', e, f);
  d = new tnode<char> ('D');
  b = new tnode<char> ('B', d, (tnode <char> *)NULL);
  root = new tnode<char> ('A', b, c);

  int count = 0;
  countOneChild(root, count);
  cout << "One child total count: " << count << endl;

  displayTree(root, 3);

}
