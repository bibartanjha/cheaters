#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#ifndef _HASH_H
#define _HASH_H

using namespace std;

//This is the hash class I created
class hash{

private:
   
   //size of the hash table
   static const int SIZE = 1000001;

   //the linked list that will be the hash table
   struct linked_list{
       int data;
       linked_list* next; 
   };
   
   //the actual hash table that contains an array of ll pointers
   linked_list* table[SIZE];

public:

   //hash constructor
   hash();

   //hash function to compute the keys
   void hashing(vector<string> x,int size,int index);

   //return size of the hash table
   int getSize();

   //find all the collisions and put them into a vector
   vector<string> traverse(vector<string>files,int size,int min);
   
};

#endif