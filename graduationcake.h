#ifndef graduationcake_h
#define graduationcake_h

class graduationCake: public Cake{
    int gradYear;
  public:
      graduationCake(string flavor, int weight, string month, int day, int year, int gradYear):
      Cake(flavor, weight, month, day, year){
        this->gradYear=gradYear;
      }
      graduationCake(){gradYear=0000;} //default values
      void cakeText(){
        cout<<"Congratulations Graduate Class of "<<gradYear<<endl;
        }
      int getGradYear();
      void setGradYear(int gradYear);

};

#endif
