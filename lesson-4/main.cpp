#include <iostream>

using namespace std;

class AbstractEmployee{
    virtual void AskForPromotion()=0;
};

class Employee: AbstractEmployee{
private:
    string name;
    string surname;
    int age;
    double salary;
    int promoted = 0;
public:
    
    void AskForPromotion(){
        if ((age>=30) && (salary<3000)){
          cout<< "Promoted\n";
          promoted = 1;
        } 
        else cout<< "Promotion Declined\n";
    };
    
    Employee Promote(double addSalary){
        if (promoted = 1) return Employee(name, surname, age, salary+addSalary, 0);
    }
    
    void ShowInfo(){
        cout<<name<<' '<<surname<<' '<<age<<' '<<salary<<' '<<promoted<<'\n';
    }
    
    Employee(string name, string surname, int age, double salary, int promoted){
        this->name=name;
        this->surname=surname;
        this->age=age;
        this->salary=salary;
        this->promoted=promoted;
    };
    
};


int main() {
    Employee e1("Marcin", "Radom", 23, 4000, 0);
    e1.AskForPromotion();
    e1.ShowInfo();
    
    Employee e2("Igor", "Oleszek", 35, 2499.00, 0);
    e2.AskForPromotion();
    e2.ShowInfo();
    
    Employee e3 = e2.Promote(2000);
    e3.ShowInfo();
    
    return 0;
}
