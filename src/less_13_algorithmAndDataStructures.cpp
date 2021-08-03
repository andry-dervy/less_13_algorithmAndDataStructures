//============================================================================
// Name        : less_13_algorithmAndDataStructures.cpp
// Author      : andry antonenko
// IDE         : Eclipse IDE
// Description : lesson 13 of the algorithms and data structures course
//============================================================================

#include <iostream>

#include "stack.h"
//----------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------
//#define NDEBUG
#include <cassert>
//----------------------------------------------------------------------------
/*
1. Реализовать обход в глубину с использованием стека.
*/

const int n = 6;
int matrix[n][n] = {
    {0,1,1,0,0,0},
    {0,0,0,1,1,1},
    {0,0,0,0,0,1},
    {1,0,0,0,0,0},
    {0,0,1,0,0,0},
    {0,0,0,0,1,0},
};

int visited[n] = {0};

void resetVisited()
{
  for(int i = 0; i < n; i++)
  {
    visited[i] = 0;
  }
}

void depthTraversRecurse(int st)
{
  assert(st < n);

  cout << st << " ";
  visited[st] = 1;
  for(int r = 0; r < n; r++)
    if(matrix[st][r] == 1 && !visited[r])
      depthTraversRecurse(r);
}

void depthTraversStack(int st)
{
  assert(st < n);

  TStack *stack = getStack(n*n);
  int r;
  push(stack,st);
  while(stack->cnt != 0)
  {
    r = pop(stack);
    cout << r << " ";
    visited[r] = 1;
    for(int i = n-1; i >= 0; i--)
      if(matrix[r][i] != 0 && visited[i] == 0)
        push(stack,i);
  }
  freeStack(stack);
}

//----------------------------------------------------------------------------
/*
2. Моделируем роботу поисковой системы.
Дан готовый простой граф с циклическими связями.
Нужно обойти этот граф двумя способами и
подсчитать количество ссылок на каждый из узлов графа (полустепень захода):
- обход графа рекурсивной функцией
(с подсчётом только смежных со стартовой вершин)
- обход графа по матрице смежности
(с подсчётом всех вершин графа)
В конце обхода вывести два получившихся списка всех узлов
в порядке уменьшения количества ссылок на них.

Результатом работы должен стать один файл с кодом на языке С,
содержащий функцию main и все необходимые функции.
*/

void countLinkRecurse(int st)
{
  assert(st < n);

  visited[st] = 1;
  int cnt = 0;
  for(int r = 0; r < n; r++)
  {
    cnt += matrix[r][st];
    if(matrix[st][r] == 1 && !visited[r])
      countLinkRecurse(r);
  }
  cout << "[" << st << "," << cnt << "] ";
}

void countLinkAdjacent(int st)
{
  assert(st < n);

  visited[st] = 1;

  for(int i = 0; i < n; i++)
  {
    if(matrix[st][i] == 1)
    {
      int cnt = 0;
      for(int r = 0; r < n; r++)
        cnt += matrix[r][i];
      cout << "[" << i << "," << cnt << "] ";
    }
  }
}

//----------------------------------------------------------------------------
void task_1(void)
{
  cout << "Task 1\n" << endl;

  cout << "Recursive traversal:" << endl;
  depthTraversRecurse(0);
  resetVisited();
  cout << endl;
  depthTraversRecurse(4);
  resetVisited();
  cout << endl;

  cout << "\nStack-based traversal:" << endl;
  depthTraversStack(0);
  resetVisited();
  cout << endl;
  depthTraversStack(4);
  resetVisited();
  cout << endl;
}
//----------------------------------------------------------------------------
void task_2(void)
{
  cout << "\nTask 2\n" << endl;

  cout << "Recursive counting links [node,count]:" << endl;
  countLinkRecurse(0);
  resetVisited();
  cout << endl;
  countLinkRecurse(4);
  resetVisited();
  cout << endl;

  cout << "\nLink count of adjacent nodes [node,count]:" << endl;
  countLinkAdjacent(0);
  cout << endl;
  countLinkAdjacent(4);
  cout << endl;
}
//----------------------------------------------------------------------------
int main() {
//----------------------------------------------------------------------------
  // Task 1
  //*
  task_1();
  //*/
//----------------------------------------------------------------------------
  // Task 2
  //*
  task_2();
  //*/
//----------------------------------------------------------------------------
	return 0;
}
//----------------------------------------------------------------------------
