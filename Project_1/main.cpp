#include <iostream>   //needed to use strings
#include <fstream>  //needed to use files
#include <string>    //I think this is needed for strings
using namespace std;

int main(){

//variables
ofstream outputFile;          //create file object to write to file
ifstream inputFile;          //object to read from file
const int SIZE=3;            //constant int for total students
string studName [SIZE];      //student names
int studId [SIZE];           // student ids
int count;                   // for loop counter



outputFile.open("students.txt");                      //open file students.txt

  for (count=0; count<SIZE; count++){                //loop to write to file
      cout<<"Enter students full name."<<endl;
      getline(cin,studName[count]);                   //for name with space
      outputFile<<studName[count]<<endl;               //writes student name to file

      cout<<"Enter student's ID number."<<endl;
      cin>>studId[count];                               //student id
      outputFile<<studId[count]<<endl;                  //student id to file

      cin.ignore(1024, '\n');                        //clears the extra stuff from using cin and getline together
  }

outputFile.close();                                  //close file after storing names


inputFile.open ("students.txt");                      //opens file from before

  if (inputFile.is_open() ){                          //tests for file being open
      for (count=0; count<SIZE; count++){             //loop to read file names
          cout<<studName[count]<<endl;
          cout<<studId[count]<<endl;
          }

  inputFile.close();                                  //close file
  }


  else {                                              //else file doesn't open
    cout<<"File could not be read"<<endl;             //error message
    exit(1);                                          //exit
  }

return 0;                                            //end program
}
