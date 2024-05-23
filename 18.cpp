#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include <algorithm> 
#define pi 3.14
using namespace std;


class circ
{
    public:
    double r;
 public:
 circ(int rad)
 {
    r = rad;
 }
 double S()
 {
    double s = pi * r * r;
    return s;
 }
 double C()
 {
    double c = 2 * pi * r;
    return c;
 }
double get_r()
 {
    return r;
 }
 void set_r(double r1)
 {
    r = r1;
 }
 void get_inf()
 {
    cout<<"Радиус = "<<r<<endl;
    cout<<"Площадь = "<<S()<<endl;
    cout<<"Длинна = "<<C()<<endl;
 }
}; 
class cylinder: public circ
{
    private: 
    double h;

public:
cylinder(double rad, double hi):circ(r)
{
    r = rad;
    h = hi;
}
 double get_h()
 {
    return h;
 }
 void set_h(double hi)
 {
    h = hi;
 } 
 double V()
 {
    double v =  S() * h;
    return v; 
 }
  void get_inf()
 {
    cout<<"Радиус = "<<r<<endl;
    cout<<"Площадь = "<<S()<<endl;
    cout<<"Длинна = "<<C()<<endl;
    cout<<"Высота = "<<h<<endl;
    cout<<"Объём = "<<V()<<endl;
 }


};
 bool compare(const cylinder& p1, const cylinder& p2) 
{ 
    return p1.r < p2.r; 
} 
int main()
{
    int p;
    cout<<"Количество элементов: ";
    cin>>p;
    std::vector<cylinder>cyli ;
    int rr, hh;
    for(int i = 0; i < p; i++)
    {
        cout<<"Радиус: ";
        cin>>rr;
        cout<<"Высота: ";
        cin>>hh;
        cyli.push_back(cylinder(rr,hh));
    }
    for(int i = 0; i < (int)cyli.size(); i++)
    {
        std::cout<<i+1<<endl;
        cyli[i].get_inf();
        cout<<endl;
    }
    
    std::vector<cylinder>cylin;
    
    for(int i = 0; i < (int)cyli.size(); i++)
    {
        if(std::fmod(cyli[i].get_r(), 2)) cylin.push_back(cyli[i]);
    }
    int flag = 0;
    if(cylin.empty())
    {
        cout<<"Пусто";
        flag = 1;
    }
    
    if(flag == 0)
    {
        sort(cylin.begin(), cylin.end(), compare);
        for(int i = 0; i < (int)cylin.size(); i++)
            {
                cout<<i+1<<endl;
                cylin[i].get_inf();
                cout<<endl;
            }
        
    }
    
    
    

    return 0;
}