#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "practice.h"
#include <string>
#include <cstring>
using namespace std;
namespace sdds {
    employee::employee() { 
        cout << "default constructor " << endl;                                  //default constructor
         name = nullptr;
        emp_no = -1;
        salary = -1;
    }

    employee::employee(const char* myname  , int num ,int salary ) { 
        cout << "2nd constructor" << endl;                                       //arguments constructor
        if (myname != nullptr && myname[0] != '\0') {
            this->name = new char[strlen(myname) + 1];
            strcpy(this->name, myname);
            emp_no = num;
            this->salary = salary;
        }
        else {
            *this = employee();
        }
        
    }

    employee::employee(const employee& a) {
        cout << "copy constructor" << endl;
        emp_no = a.emp_no;
        salary = a.salary;
        if (a.name != nullptr ) {
            name = new char[strlen(a.name) + 1];
            strcpy(name, a.name);
        }
        else {
            name = nullptr;
        }

    }

    employee& employee::operator=(const employee& e) {
        cout << "operator = execute" << endl;
        if (this != &e) {
            emp_no = e.emp_no;
            salary = e.salary;
            if (e.name != nullptr) {
                name = new char[strlen(e.name) + 1];
                strcpy(name, e.name);
            }
            else {
                cout << "hello" << endl;
                name = nullptr;
            }
        }
        return *this;
    }

    void employee::display(ostream& os) {
        os << "employee name  :: " << name<<endl;
        os << "employee num :: " << emp_no <<endl;
        os << "employee salary :: " << salary << endl;
    }

    void employee::modifyname(char* modifyname) {
        if (name != nullptr && name[0] != '\0') {
            if (name) {
                delete[] name;
                name = nullptr;
            }

            name = new char[strlen(modifyname) + 1];
            strcpy(name, modifyname);
        }
        else {
            name = nullptr;
        }

    }
    
     employee::operator bool()const {
         return (emp_no != 0);
    }

    employee& employee::operator+=(int sal) {
        this->salary += sal;
        return *this;
    }

    int employee::returnsal() {
        return salary;
    }

    bool operator==( employee& e1, employee& e2) {
        return (e1.returnsal() == e2.returnsal());
    }

    employee& employee::operator++() {
        ++salary;
        return *this;

    }

    employee& employee::operator++(int) {
        employee e = *this;
        ++(*this);
        return e;
    }

    int employee::operator+( const employee right) {
        return (this->salary + right.salary);
    }
    void employee::readdata(istream& is) {
        char tmp_name[40];
        cout << "name  :: ";
        is >> tmp_name;
        is.ignore();
        name = new char[strlen(tmp_name) + 1];
        strcpy(name, tmp_name); 
        cout << "employee number :: ";
        is >> emp_no;
        cout << "enter the salary : ";
        is >> salary;

    }

    istream& operator>>(istream& is, employee& e) {
        e.readdata(is);
        return is;
    }

    ostream& operator<<(ostream& os, employee& e) {
        e.display(os);
        return os;
    }

   

    employee::~employee() {
        cout << name <<" is dying " << endl;
        delete[] name;
        name = nullptr;
    }
}