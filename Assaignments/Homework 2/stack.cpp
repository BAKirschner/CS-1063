/**
 * File: stack.cpp
 * Aurhor: Brennan Kirschner
 * Course: CMPS 1063 - Fall 2019
 * Date: Oct 8, 2019
 * Description:
 *    Class implementation file for our array based stack of ints
 */

#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints and sets our top
 */
Stack::Stack(){
  Size = 10;
  A = new int [Size];
  Top = -1;
  BigSize = 0;
}

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints to a specified size and sets our top
 * Params:
 *    int s : integer size
 */
Stack::Stack(int s){
  Size = s;
  A = new int [Size];
  Top = -1;
}

/**
 * Push
 * Description:
 *    Adds item to top of stack
 * Params:
 *    int val : integer size
 * Returns:
 *     bool : true = success
 */
bool Stack::Push(int val){
  if(!Full()){
    Top++;
    A[Top] = val;
    CheckResizeGrow();
    if (Top > BigSize)
    {
      BigSize = Top + 1;
    }
    return true;
  }else{
    return false;
  }
}

/**
 * Pop
 * Description:
 *    Removes top of stack and returns it
 * Params:
 *    void
 * Returns:
 *     int : item on stack
 */
int Stack::Pop(){
  if(!Empty()){
    int temp = 0;   
    temp = A[Top];
    Top--;
    CheckResizeShrink();
    return temp;
  }else{
    // should return a value that implies failuer, but good enough for now
    cout<<"Cannot remove item from empty stack"<<endl;
  }
  return 0;
}

/**
 * Print
 * Description:
 *    Prints stack for inspection
 * Params:
 *    void
 * Returns:
 *     void
 */
void Stack::Print(){
  cout << "Stack Size:" << Size << endl;
  cout << "Largest Stack:" << BigSize << endl;
  for(int i = Top;i>=0 ; i--){
    cout<<A[i]<< " ";
  } 

}

/**
 * Empty
 * Description:
 *    Is stack empty
 * Params:
 *    void
 * Returns:
 *    bool : true = empty
 */
bool Stack::Empty(){
  return Top < 0;
}

/**
 * Full
 * Description:
 *    Is stack full
 * Params:
 *    void
 * Returns:
 *    bool : true = full
 */
bool Stack::Full(){
  return (Top == Size - 1);
}

/**
 * CheckResizeGrow
 * Description:
 *    checks if the stack needs to be resized and calls enlarge
 * Params:
 *    void
 *Returns:
 *    void
 */
void Stack::CheckResizeGrow(){
  double percent = Top / (double)Size;

  if(percent >= 0.8)
  {Enlarge();}
}

/**
 * Enlarge
 * Description:
 *    doubles the size of the stack if called by CheckResizeGrow
 * Params:
 *    void
 *Returns:
 *    void
 */
void Stack::Enlarge(){
  int newsize = Size * 2;
  int* NewArr = new int[newsize];
  for(int i = 0;i<Size; i++)
  {
    NewArr[i] = A[i];
  }

  int *temp = A;
  A = NewArr;
  delete [] temp;
  Size = newsize;
}

/**
 * CheckResizeShrink
 * Description:
 *    checks if the stack needs to be resized and calls reduce
 * Params:
 *    void
 *Returns:
 *    void
 */
void Stack::CheckResizeShrink(){
  double percent = Top / (double)Size;
    
  if(percent == 0.2)
  {Reduce();}
}

/**
 * Reduce
 * Description:
 *    halves the size of the stack if called by CheckResizeShrink
 * Params:
 *    void
 *Returns:
 *    void
 */
void Stack::Reduce(){
  int newsize2 = Size * 0.5;
  int* NewArr2 = new int[newsize2];
  Size = newsize2;
  for(int i = 0;i<Size; i++)
  {
    NewArr2[i] = A[i];
  }

  int *temp2 = A;
  A = NewArr2;
  delete [] temp2;
  
}
