#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){


//declaring constant variables
const int NUMSTUD=10;   //rows
const int SCORES=5;      //column


//declaring variables
int count=0;             //for counting
int i, sum, lookUp;              //counting and sums
float avgAll;          //all scores totaled and divided by NUMSTUD
char A, B, C, D, F;  //char for grades
string stId[NUMSTUD];    //student ID array
string firstName[NUMSTUD], lastName[NUMSTUD];   //parallel array for names
string gradeOne[NUMSTUD], gradeTwo[NUMSTUD], gradeThree[NUMSTUD], gradeFour[NUMSTUD], gradeFive[NUMSTUD];  //string to read in scores
int gradeArray[NUMSTUD][SCORES];   //array to hold int scores
int gradeTotal[NUMSTUD]; //array for score totals
char gradeLetter[NUMSTUD]; //array for letter grade


ifstream dataFile ("data121.txt");    //open file to read from


if (dataFile){                           //if file is open
    for (count=0; count<NUMSTUD; count++){    //this loop reads the file into chunks I can work with
      dataFile>>stId[count];
      dataFile>>firstName[count];
      dataFile>>lastName[count];
      dataFile>>gradeOne[count];
      dataFile>>gradeTwo[count];
      dataFile>>gradeThree[count];
      dataFile>>gradeFour[count];
      dataFile>>gradeFive[count];
      }
} else {
    cout<<"File error"<<endl;        //if there is a file read error
    }

dataFile.close();   //gotta close this file somewhere


for (count=0; count<NUMSTUD; count++){                  //this writes all the score strings into int
      gradeArray[count][0]=std::stoi(gradeOne[count]);       //it isn't pretty but it works!
      gradeArray[count][1]=std::stoi(gradeTwo[count]);
      gradeArray[count][2]=std::stoi(gradeThree[count]);
      gradeArray[count][3]=std::stoi(gradeFour[count]);
      gradeArray[count][4]=std::stoi(gradeFive[count]);
      }


for (count=0; count<NUMSTUD; count++){             //this loop adds up scores
    sum=0;                                             //saves them to gradeTotal array
      for (i=0; i<SCORES; i++){
        sum= sum + gradeArray[count][i];
        gradeTotal[count]= sum;
      }
  }

for (count=0; count<NUMSTUD; count++){             //compare and assign letter grades
    if ( gradeTotal[count] >= 90) {
      gradeLetter[count]='A';
    }
    else if (gradeTotal[count] >= 80){
      gradeLetter[count]='B';
    }
    else if (gradeTotal[count] >= 70){
      gradeLetter[count]='C';
    }
    else if (gradeTotal[count] >= 60){
      gradeLetter[count]='D';
    }
    else gradeLetter[count]='F';
    cout<<endl;
}


for (count=0; count<NUMSTUD; count++){      //outputs all info
    cout<<"Student ID: "<<stId[count]<<" Student Name: "<<firstName[count]<<" "<<lastName[count]<<endl;
    for (i=0; i<SCORES; i++){
        cout<<"Score: "<<gradeArray[count][i]<<endl;
        }
    cout<<"Total grade score: "<<gradeTotal[count]<<". "<<"Letter grade: "<<gradeLetter[count]<<endl;
}


int maxGrade = gradeTotal[0];                      //compares total grade for each student
for (count=0; count <NUMSTUD; count++){              //saves highest grade score to maxGrade
    if (gradeTotal[count]>maxGrade){
    maxGrade=gradeTotal[count];
    }
}

for (count=0; count<NUMSTUD; count++){        //uses highest grade saved in maxGrade
  if (gradeTotal[count]==maxGrade){           //to compare to find the row
  lookUp=count;                               //so it can output the matching name from that row
  }
}
cout <<"The highest score is "<<maxGrade<<" by "<<firstName[lookUp]<<" "<<lastName[lookUp]<<endl;         //output highest grade & name


sum=0;   //zero out sum to use it again
for (count=0; count<NUMSTUD; count++){             //this loop adds up totals and divides them for avg
    sum= sum + gradeTotal[count];
  }
avgAll= sum/NUMSTUD;
cout<< "Average of all scores is "<<avgAll<<endl;


ofstream dataOut("report121.txt");   //create new txt doc
for (count=0; count<NUMSTUD; count++){     //loop to write name and letter grade
    dataOut<<firstName[count]<<" "<<lastName[count]<<" "<<gradeLetter[count]<<endl;
}
dataOut.close();    //close the file I created


}
