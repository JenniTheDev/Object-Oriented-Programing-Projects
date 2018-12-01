#ifndef cake_h
#define cake_h

class Cake {	//private must use functions to refer to
  	string pflavor;
  	int pcost;
  	int pweight;
  	int ppriceLb=10;
    Date dateOrdered;
	public:
  	Cake(string flavor, int weight, string month, int day, int year):
    dateOrdered(month,day,year){    //member initilization list
      this->pflavor=flavor;
    	this->pweight=weight;
    	this->pcost=weight*ppriceLb;
    }
    Cake(){pflavor="vanilla"; pcost=0; pweight=0;}//default values?
  	~Cake(){cout<<"Thanks for shopping!"<<endl;} //cake deconstructor
  	string getFlavor();
  	void setFlavor(string f);
  	int getCost();
  	void setCost(int c);
  	int getWeight();
  	void setWeight(int w);
  	int getPriceLb();
    string getMonth();
    int getDay();
    int getYear();

};
#endif
