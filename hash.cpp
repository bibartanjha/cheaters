#include "hash.h"

#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <sstream>

using namespace std;

//constructor for the hashtable.It sets all the ll's to NULL
hash::hash(){

  for(int i = 0; i < SIZE; i++){
      table[i] = NULL;
  }  
}

//return the size of the hashtable
int hash::getSize(){

   return SIZE;

}

//this is the hashing function
void hash::hashing(vector<string> x,int size,int index){

  //this part computs the key
  int sum = 0;
  int primeMulti = 11;
  int exponent = 1;
  for(int i = 0; i < x.size();i++){
     for(int j = 0; j < x[i].size();j++){
     sum += (exponent * x[i][j]);
     exponent = exponent * primeMulti;
   }        
 }
 
  sum =(sum%size+size)% size;
 
  //use the key as the index to the hashtable.insert a ll node
  //into that index and set the data equal to the file number
  linked_list *node = new linked_list; 
  node->next = NULL;
  node->data = index;
  if(table[sum] == NULL){
    table[sum] = node;
 }
  else{
    node->next = table[sum];
    table[sum] = node;
  
 }  

}

//this is the function that traverses thru the entire hashtables
//and then identifies the collisions for each combination of files
vector<string>hash:: traverse(vector<string>files,int size,int min){

   //create the 2-D array to store the collisions
   vector<string> answer;
   int *matchTable[files.size()];
   for(int i = 0; i < files.size();i++){
      
      matchTable[i] = new int[files.size()];
   }   

   for(int i = 0; i < files.size();i++){
     
      for(int j = 0; j < files.size();j++){

         matchTable[i][j] = 0;
   }
 }

   //traverse thru the entire hashtable
   //increment the appropriate spot in the 2-D array when a collision
   //is identified 
   linked_list *ptr;
   linked_list *p;
   for(int i = 0; i < size; i++){
      
      if(table[i] != NULL){
         ptr = table[i];
         p = ptr->next;
      
         while(p != NULL){

           matchTable[ptr->data][p->data]++;
           p = p->next;
         }
      }
 
  }

   //identify the number of collisions between the 2
   //files that are greater than the number passed in the command
   //prompt.Put the numbers into a vector
   vector<int>sortNum;
   for(int i = 0; i < files.size();i++){
      for(int j = 0; j < files.size();j++){

         if(matchTable[i][j] > min){
           sortNum.push_back(matchTable[i][j]);
      }
   }
}

   //sort the numbers in descending order
   sort(sortNum.begin(),sortNum.end());
   reverse(sortNum.begin(),sortNum.end());
   

   //go thru the 2-D array again and find the filenames that correspond
   //to the collision number and put them in a string vector that 
   //will be printed
   vector<int>::iterator find = sortNum.begin();
   while(find != sortNum.end()){

     for(int i = 0; i < files.size(); i++){

         for(int j = 0; j < files.size(); j++){

            if(matchTable[i][j] == *find){
            
              string num;
              stringstream ss;
              ss << matchTable[i][j];
              num = ss.str();

              string print = num  + ":" + files[i] + "," + files[j];
              answer.push_back(print);
          }
         
        }
     }
     find++;
  }
 return answer;
}