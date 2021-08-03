/*
 * stack.h
 *
 *  Created on: Aug 2, 2021
 *      Author: andry
 */

//----------------------------------------------------------------------------
#ifndef STACK_H_
#define STACK_H_
//----------------------------------------------------------------------------
#include <iostream>
using namespace std;
//----------------------------------------------------------------------------
#define T int
//----------------------------------------------------------------------------
struct TStack
{
  T *S;
  int top = -1;
  int cnt = 0;
  int size = 0;
};
//----------------------------------------------------------------------------
TStack* getStack(const int aSize);
void freeStack(TStack* pStack);
bool push(TStack* pStack,T d);
T pop(TStack* pStack);
//----------------------------------------------------------------------------
#endif /* STACK_H_ */
//----------------------------------------------------------------------------