/****************************************
 *
 * Auther : Galal Amr Ewida .
 * Bank A simple project to apply some concepts of object-oriented programming.
 * Version 1.
 * cpp Project.
 * A second-year student at the Department of Electronic Engineering in Menouf
****************************************/

#include <bits/stdc++.h>
using namespace std;
class employee
{
protected:

    string name;
    int emp_id;
    float salary;
public:
    employee():name("galal"),emp_id(0),salary(0) ///overloading
    {
    }
    employee(string n,int id,float s)
    {
        name=n;
        emp_id=id;
        salary =s;
    }
    /// pure function (interface)
    virtual float get_tsalary()=0;
    virtual void print()
    {
        cout<<"name ="<<name<<" id = "<<emp_id<<" salary ="<<salary<<endl;
    }
};

class sales:public employee
{
private :
    float gross_sales;
    float commission_rate;
public:
    sales(string n,int id,float s,float gs,float cr):employee(n,id,s)///Reuse concept
    {
        gross_sales=gs;
        commission_rate=cr;
    }
    float get_tsalary()///Overriding
    {
        return salary+(gross_sales*commission_rate);
    }
    void print()
    {
        employee::print();///Reuse concept
        cout<<"gross sales ="<<gross_sales<<" commission rate "<<commission_rate<<" salary ="<<salary<<endl;

    }
};




class engineer :public employee
{
private:
    string speciality;
    int experience;
    int ovartime_hours;
    float overtime_rate;
public:
    engineer ( string n,int id,float s,string sp,int e,int oh,float o) :employee(n,id,s)
    {

        speciality=sp;
        experience=e;
        ovartime_hours=oh;
        overtime_rate=o;


    }
    float get_tsalary()///override
    {
        return salary+(ovartime_hours*overtime_rate);
    }
    void print()
    {
        employee::print();///Reuse concept
        cout<<" speciality ="<<speciality<<" experience "<<experience <<" ovartime_hours ="<<ovartime_hours <<endl;

    }
};
int main()
{
    employee *emp_ptr;
    sales s1("galal",1234,8000,500000,0.10);
    engineer e1("ahmed",150,15000,"soft engineer",2,10,50);
    emp_ptr=&s1;
    emp_ptr->get_tsalary();
    emp_ptr->print();
    emp_ptr=&e1;
    emp_ptr->get_tsalary();
    emp_ptr->print();





    return 0;
}
