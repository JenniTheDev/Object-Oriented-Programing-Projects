#include "cake.h"


//getters and setters for Cake class
string Cake::getFlavor(){return pflavor;}
void Cake::setFlavor(string f){pflavor=f;}
int Cake::getCost(){return pcost;}
void Cake::setCost(int c){pcost=c;}
int Cake::getWeight(){return pweight;}
void Cake::setWeight(int w){pweight=w;}
int Cake::getPriceLb(){return ppriceLb;}


string Cake::getMonth(){return dateOrdered.getMonth();}
int Cake::getDay(){return dateOrdered.getDay();}
int Cake::getYear(){return dateOrdered.getYear();}
