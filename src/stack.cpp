/*
 * stack.cpp
 *
 *  Created on: Aug 2, 2021
 *      Author: andry antonenko
 */
//----------------------------------------------------------------------------
#include "stack.h"
//----------------------------------------------------------------------------
TStack* getStack(const int aSize)
{
  TStack* pStack = nullptr;
  try{
    pStack = new TStack;

    if(pStack != nullptr)
    {
      pStack->size = aSize;
      pStack->cnt = 0;
      pStack->top = -1;
      pStack->S = new T[aSize];
    }
  }
  catch (const std::exception&) {
    cout << "No memory allocated." << endl;
  }
  return pStack;
}

void freeStack(TStack* pStack)
{
  if(pStack->S != nullptr)
    delete pStack->S;
  if(pStack != nullptr)
  {
    delete pStack;
    pStack = nullptr;
  }
}

bool push(TStack* pStack,T d)
{
  if(pStack->cnt == pStack->size)
  {
    cout << "Stack overflow." << endl;
    return false;
  }
  pStack->S[++pStack->top] = d;
  pStack->cnt++;
  return true;
}

T pop(TStack* pStack)
{
  if(pStack->cnt == 0)
  {
    cout << "Stack empty." << endl;
    return 0;
  }
  int d = pStack->S[pStack->top--];
  pStack->cnt--;
  return d;
}
//----------------------------------------------------------------------------



