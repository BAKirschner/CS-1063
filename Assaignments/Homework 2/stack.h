/**
 * File: stack.h
 * Aurhor: Brennan Kirschner
 * Course: CMPS 1063 - Fall 2019
 * Date: Oct 8, 2019
 * Description:
 *    Definition of our stack class.
 */

class Stack{
  private:
    int *A;         // container of items (could make it a list)
    int Top;        // keep track of top
    int Size;       // Arrays need a size
    int BigSize;    // Largest Stack
  public:
    
    Stack();        // Default constructor
    
    Stack(int);        // overloaded constructor
    bool Push(int);    // Push value onto stack
    int Pop();         // Remove item from top of stack
    void Print();      // Help inspect values
    bool Empty();      // Is stack empty
    bool Full();       // is stack full
    void CheckResizeGrow();//check if stack needs resize
    void CheckResizeShrink();
    void Enlarge();    //enlarge the stack
    void Reduce();     //reduce the stack
    
};
