//Nick Krisulevicz
//Lab 03
//max.h
//02/22/2022

#ifndef MAX
#define MAX
#include "d_tnode.h"


template <typename T>
int maxValue(tnode<T> *t) 
{
  int maxVal = 0;
  if (t != NULL) 
  { 
    maxVal = t->nodeValue;
    int leftV = maxValue(t->left);
    int rightV = maxValue(t->right);
    if (leftV > maxVal) 
    {
      maxVal = leftV;
    }
    if (rightV > maxVal) 
    {
      maxVal = rightV;
    }
  }
  return maxVal;
};

#endif
