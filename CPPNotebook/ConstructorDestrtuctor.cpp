#include<string>
#include<iostream>

using namespace std;

class Patient {
     int   heartRate;
     double moneyOwed;
     string name; 
 
    int getHeartRate() {
        return heartRate;
    };

    void setHeartRate(int heartrate) {
        heartRate = heartrate;
    }
  
    double getMoneyOwed() {
        return moneyOwed;
    };

    void setMoneyOwed(double money) {
        moneyOwed = money;
    };
    
    string getName() {
        
    };
    
    Patient(string Name, int heart, double money) {
        name = Name;
        heartRate = heart;
        moneyOwed = money;

    }//parametrized Constructor

    ~Patient();

};

Patient::~Patient() {
    cout << "This is destructor";
} // This could be defined outside  the class definition instead