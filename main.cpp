#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "hash.h"

using namespace std;



/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main(int argc,char*argv[])
{
    string dir =argv[1];
    vector<string> files = vector<string>();

    //get the file names into a vector
    getdir(dir,files);          
    
    //get rid of "." and ".."
    vector<string>::iterator remove;
    for(remove = files.begin();remove != files.end();remove++){

       if((*remove).substr(0,1) == "."){

         files.erase(remove);
         remove--;
   }
 }


    //create hash object
    hash *h = new hash();
    
    //get the size of the hashtable into a variable
    int table_size = h->getSize();    

    ifstream myFile;
    for(int i = 0; i < files.size(); i++){
      string name = argv[1] + files[i];  //CHANGE TO ARGV[1] at the end

      //open the .txt file
      myFile.open(name.c_str());

      string newstring;
      
      //get the n value into a variable
      int n = atoi(argv[2]); //CHANGE TO ATOI(ARGV[2]) at the end

      vector<string>result;

       //get the first n word sequence into a vector
       for(int j = 0; j < n; j++){
         myFile >> newstring;
         result.push_back(newstring);
     }
         //while file is not done,keep putting words into a vector
         while(myFile >> newstring){
          
          //call the hash function
          h->hashing(result,table_size,i);         
 

          //compute the next n word sequence
	  result.erase(result.begin());
          result.push_back(newstring);
     }
     
      //once file is done,close the file and open next file	 
      myFile.close(); 
   }
   
   //get the result to be printed out into a vector
   vector<string> finalResult = h->traverse(files,table_size,atoi(argv[3]));

   vector<string>::iterator finalIter;
   for(finalIter = finalResult.begin();finalIter!=finalResult.end();finalIter++){
      //print out the final answer  
      cout << (*finalIter) << endl;

    }
}