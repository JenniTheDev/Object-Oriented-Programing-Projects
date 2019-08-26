

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//function declarations
const int NUMSTUD=10;
const int SCORES=5;
void storeData (int ids[], string names[], int scrAry[][SCORES]); //puts data from file in array
void letterGrade (int scrAry[][SCORES], int gradeTotal[], char gradeLetter[]); //assigns letter grade
void outputInfo (int ids[], string names[], int scrAry[][SCORES], int gradeTotal[], char gradeLetter[]); //outputs info
void highScore (string names[], int gradeTotal[]); //finds highest score
int studentSearch (string names[]); //search for student name
void studentLookup (int ids[], string names[], int scrAry[][SCORES], int gradeTotal[], char gradeLetter[], int &val); //looks up info for searched student
void makeFile (string names[], char gradeLetter[]); //makes new file with info



int main(){

  int stId[NUMSTUD]; //student id array
  
  string stName[NUMSTUD]; //student name array
  
  int scoresArray[NUMSTUD][SCORES]; //score array
  
  storeData(stId, stName, scoresArray);  //function 1
  
  int grTotal[NUMSTUD];  //array to hold total score for each student
  
  char grLetter[NUMSTUD];  //gives letter to grade total
  
  letterGrade (scoresArray, grTotal, grLetter); //function 2
  
  outputInfo (stId, stName, scoresArray, grTotal, grLetter); //function 3
  
  highScore (stName, grTotal); //function 4
  
  int studFnd= studentSearch (stName); //function 5 &holds int for student searched to use to lookup
  
  studentLookup (stId, stName, scoresArray, grTotal, grLetter, studFnd); //function 6
  
  makeFile(stName, grLetter);   //function 7
  
}




//function for opening file and putting data in arrays
void storeData (int ids[], string names[], int scrAry[][SCORES] ){
  ifstream dataFile ("data121.txt");	//open file to read from
	if (dataFile){                       	//if file is open
    	for (int count=0; count<NUMSTUD; count++){	//this loop reads the file into chunks I can work with
      	dataFile>>ids[count];
      	dataFile.ignore(2);
      	getline(dataFile,names[count],',');
      	for (int i=0; i<SCORES; i++){
          	dataFile>>scrAry[count][i];
          	dataFile.ignore(2);
      	}
    	}
  	} else {
    	cout<<"File error"<<endl;    	//if there is an error
    	}
  dataFile.close();   //gotta close this file somewhere
}


 //determine letter grade function
void letterGrade (int scrAry[][SCORES], int gradeTotal[], char gradeLetter[]){
  for (int count=0; count<NUMSTUD; count++){         	//this loop adds up scores
  	int sum=0;                                         	//saves them to gradeTotal array
    	for (int i=0; i<SCORES; i++){
      	sum= sum + scrAry[count][i];
      	gradeTotal[count]= sum;
    	}
	}
  for (int count=0; count<NUMSTUD; count++){         	//compare and assign letter grades
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
}


//this is for outputting the data altogether
void outputInfo (int ids[], string names[], int scrAry[][SCORES], int gradeTotal[], char gradeLetter[]){
  for (int count=0; count<NUMSTUD; count++){  	//outputs all info
  	cout<<"Student ID: "<<ids[count]<<" Student Name: "<<names[count]<<endl;
  	for (int i=0; i<SCORES; i++){
      	cout<<"Score: "<<scrAry[count][i]<<endl;
      	}
  	cout<<"Total grade score: "<<gradeTotal[count]<<". "<<"Letter grade: "<<gradeLetter[count]<<endl;
  	}
}


//finds highest score and student it belongs to
void highScore (string names[], int gradeTotal[]){
  int maxGrade = gradeTotal[0];                  	//compares total grade for each student
  for (int count=0; count <NUMSTUD; count++){          	//saves highest grade score to maxGrade
  	if (gradeTotal[count]>maxGrade)
  	maxGrade=gradeTotal[count];
  	}
  	cout<<"The highest score is "<<maxGrade<<endl;     	//output highest grade & name
}


//search for name
int studentSearch (string names[]){
  string nameSearch;
  cout<<"Enter a student name to search: "<<endl;
	getline(cin, nameSearch);
	cout<<"You are searching for "<<nameSearch<<endl;

	int lookUp=0;
	for (int i=0; i<NUMSTUD; i++){
  	if (names[i]==nameSearch){ 	//loop to compare names
      	cout<<"Name Found: "<<names[i]<<endl;
      	lookUp=i; }
}
return lookUp;
}

//This function outputs the searched for student's info
void studentLookup (int ids[], string names[], int scrAry[][SCORES], int gradeTotal[], char gradeLetter[],int &val){
  	cout<<"Here is the info you requested: "<<endl;
  	cout<<ids[val]<<" "<<names[val]<<endl;
  	for (int i=0; i<SCORES; i++){  //loop for scores
    	cout<<scrAry[val][i]<<" ";
  	}
  	cout<<"Total: "<<gradeTotal[val]<<" Grade Letter: "<<gradeLetter[val]<<endl;
}

//this function creates a file
void makeFile (string names[], char gradeLetter[]){
  ofstream dataOut("report121.txt");   //create new txt doc
  for (int count=0; count<NUMSTUD; count++){ 	//loop to write name and letter grade
  	dataOut<<names[count]<<" "<<gradeLetter[count]<<endl;
  	}
  dataOut.close();	//close the file I created
}nclude <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NUMSTUD=10;
const int SCORES=5;
void storeData (int ids[], string names[], int scrAry[][SCORES]); //puts data from file in array
void letterGrade (int scrAry[][SCORES], int gradeTotal[], char gradeLetter[]); //assigns letter grade
void outputInfo (int ids[], string names[], int scrAry[][SCORES], int gradeTotal[], char gradeLetter[]); //outputs info
void highScore (string names[], int gradeTotal[]); //finds highest score
int studentSearch (string names[]); //search for student name
void studentLookup (int ids[], string names[], int scrAry[][SCORES], int gradeTotal[], char gradeLetter[], int &val); //looks up info for searched student
void makeFile (string names[], char gradeLetter[]); //makes new file with info

int main(){
int stId[NUMSTUD]; //student id array
string stName[NUMSTUD]; //student name array
int scoresArray[NUMSTUD][SCORES]; //score array
storeData(stId, stName, scoresArray);  //function 1
int grTotal[NUMSTUD];  //array to hold total score for each student
char grLetter[NUMSTUD];  //gives letter to grade total
letterGrade (scoresArray, grTotal, grLetter); //function 2
outputInfo (stId, stName, scoresArray, grTotal, grLetter); //function 3
highScore (stName, grTotal); //function 4
int studFnd= studentSearch (stName); //function 5 &holds int for student searched to use to lookup
studentLookup (stId, stName, scoresArray, grTotal, grLetter, studFnd); //function 6
makeFile(stName, grLetter);   //function 7
}




//function for opening file and putting data in arrays
void storeData (int ids[], string names[], int scrAry[][SCORES] ){
  ifstream dataFile ("data121.txt");	//open file to read from
	if (dataFile){                       	//if file is open
    	for (int count=0; count<NUMSTUD; count++){	//this loop reads the file into chunks I can work with
      	dataFile>>ids[count];
      	dataFile.ignore(2);
      	getline(dataFile,names[count],',');
      	for (int i=0; i<SCORES; i++){
          	dataFile>>scrAry[count][i];
          	dataFile.ignore(2);
      	}
    	}
  	} else {
    	cout<<"File error"<<endl;    	//if there is an error
    	}
  dataFile.close();   //gotta close this file somewhere
}


 //determine letter grade function
void letterGrade (int scrAry[][SCORES], int gradeTotal[], char gradeLetter[]){
  for (int count=0; count<NUMSTUD; count++){         	//this loop adds up scores
  	int sum=0;                                         	//saves them to gradeTotal array
    	for (int i=0; i<SCORES; i++){
      	sum= sum + scrAry[count][i];
      	gradeTotal[count]= sum;
    	}
	}
  for (int count=0; count<NUMSTUD; count++){         	//compare and assign letter grades
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
}


//this is for outputting the data altogether
void outputInfo (int ids[], string names[], int scrAry[][SCORES], int gradeTotal[], char gradeLetter[]){
  for (int count=0; count<NUMSTUD; count++){  	//outputs all info
  	cout<<"Student ID: "<<ids[count]<<" Student Name: "<<names[count]<<endl;
  	for (int i=0; i<SCORES; i++){
      	cout<<"Score: "<<scrAry[count][i]<<endl;
      	}
  	cout<<"Total grade score: "<<gradeTotal[count]<<". "<<"Letter grade: "<<gradeLetter[count]<<endl;
  	}
}


//finds highest score and student it belongs to
void highScore (string names[], int gradeTotal[]){
  int maxGrade = gradeTotal[0];                  	//compares total grade for each student
  for (int count=0; count <NUMSTUD; count++){          	//saves highest grade score to maxGrade
  	if (gradeTotal[count]>maxGrade)
  	maxGrade=gradeTotal[count];
  	}
  	cout<<"The highest score is "<<maxGrade<<endl;     	//output highest grade & name
}


//search for name
int studentSearch (string names[]){
  string nameSearch;
  cout<<"Enter a student name to search: "<<endl;
	getline(cin, nameSearch);
	cout<<"You are searching for "<<nameSearch<<endl;

	int lookUp=0;
	for (int i=0; i<NUMSTUD; i++){
  	if (names[i]==nameSearch){ 	//loop to compare names
      	cout<<"Name Found: "<<names[i]<<endl;
      	lookUp=i; }
}
return lookUp;
}

//This function outputs the searched for student's info
void studentLookup (int ids[], string names[], int scrAry[][SCORES], int gradeTotal[], char gradeLetter[],int &val){
  	cout<<"Here is the info you requested: "<<endl;
  	cout<<ids[val]<<" "<<names[val]<<endl;
  	for (int i=0; i<SCORES; i++){  //loop for scores
    	cout<<scrAry[val][i]<<" ";
  	}
  	cout<<"Total: "<<gradeTotal[val]<<" Grade Letter: "<<gradeLetter[val]<<endl;
}

//this function creates a file
void makeFile (string names[], char gradeLetter[]){
  ofstream dataOut("report121.txt");   //create new txt doc
  for (int count=0; count<NUMSTUD; count++){ 	//loop to write name and letter grade
  	dataOut<<names[count]<<" "<<gradeLetter[count]<<endl;
  	}
  dataOut.close();	//close the file I created
}
