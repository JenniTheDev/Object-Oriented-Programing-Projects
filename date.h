#ifndef date_h
#define date_h

class Date{
    string month;
    int day;
    int year;
  public:
    Date(string month, int day, int year):
    month(month), day(day), year(year)  //member initilization
    { this->month=month;
      this->day=day;
      this->year=year;
    }
    Date(){month="none"; day=0; year=0;} //default values
    string getMonth();
    void setMonth(string month);
    int getDay();
    void setDay(int day);
    int getYear();
    void setYear(int year);
};
#endif
