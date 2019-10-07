/**
 * File: main.cpp
 * Aurhor: Brennan Kirschner
 * Course: CMPS 1063 - Fall 2019
 * Date: Oct 8, 2019
 * Description:
 *    Main driver of an Array based implementation of a stack.
 */

#include <iostream>
#include <fstream>
#include "stack.h"
#include "stdlib.h"

using namespace std;

/**
 * Main Program
 * 
 */
int main() {
  ofstream outfile;
  outfile.open("stack_out.txt");

  outfile << "Brennan Kirschner\n";
  outfile << "Homework 2\n";
  outfile << "Due Oct 8, 2019\n";


  srand(34234); // seed random number gen

  Stack S1; // Instance of our stack default constructor

  // Load the stack with random nums
  for (int i = 0; i < 10; i++) {
    S1.Push(rand() % 100);
  }

  // make sure it looks correct
  S1.Print();

  // Pop some items off the top  
  S1.Pop();
  S1.Pop();
  S1.Pop();
  S1.Pop();
  S1.Pop();
  S1.Pop();
  S1.Pop();

  cout << endl;

  // Check for correct behavior again.
  S1.Print();

  outfile.close();
  return 0;
}
