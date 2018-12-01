#include <iostream>
#include <string>
using namespace std;

#include "date.h"
#include "date.cpp"
#include "cake.h"
#include "cake.cpp"
#include "graduationcake.h"
#include "graduationcake.cpp"

int main(){

//graduationCake orderOne;
string flavorInput, monthInput;
int weightInput, dayInput, yearInput, gradYearInput;


cout<<"Welcome to Jenny's Bakery"<<endl;
cout<<"What flavor cake would you like?"<<endl;
cin>>flavorInput;

cout<<"How many pounds of cake?"<<endl;
cin>>weightInput;

cout<<"What month, day and year would you like to order for?"<<endl;
cin>>monthInput;
cin>>dayInput;
cin>>yearInput;


cout<<"What is the graduation year?"<<endl;
cin>>gradYearInput;



graduationCake orderOne(flavorInput, weightInput, monthInput, dayInput, yearInput, gradYearInput);

cout<<"Your order is: "<<endl;
cout<<"A "<<orderOne.getFlavor()<<" cake that is "<<orderOne.getWeight()<<
" lbs and costs $"<<orderOne.getCost()<<endl;
cout<<"Your cake order date is "<<orderOne.getMonth()<<" "<<orderOne.getDay()<<", "<<
     orderOne.getYear()<<"."<<endl;
cout<<"On the cake will be "<<endl;
orderOne.cakeText();


return 0;
}
