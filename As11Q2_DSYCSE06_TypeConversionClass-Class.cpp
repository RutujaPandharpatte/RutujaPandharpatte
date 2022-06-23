#include<iostream>
#include<math.h>
#define pi 3.141592654
using namespace std;
class Rectangle
{
    private:
    double x,y;
    public:
    Rectangle()
    {
        x=y=0;
    }
    Rectangle(double x,double y)
    {
        this->x=x;
        this->y=y;
    }
    void getdata()
    {
        cout<<"\nEnter X and Y Co-ordinates\n";
        cout<<"x : ";
        cin>>x;
        cout<<"y : ";
        cin>>y;   
    }
    double getx()
    {
        return x;
    }
    double gety()
    {
        return y;
    }
    void show()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};
class Polar
{
    private:
    double r,theta;
    public:
    Polar()
    {
        r=theta=0;
    }
    void gets()
    {
        cout<<"\nEnter R and Theta\n";
        cout<<"r : ";
        cin>>r;
        cout<<"theta : ";
        cin>>theta;   
    }
    void operator=(Rectangle r1)
    {
        r=sqrt(pow(r1.getx(),2)+pow(r1.gety(),2));
        theta=atan(r1.gety()/r1.getx());
        theta=(theta*180)/pi; 
    }
    operator Rectangle()
    {
        double x,y;
        x=r*cos(theta);
        y=r*sin(theta);
        return Rectangle(x,y);
    }
    void show()
    {
        cout<<"("<<r<<","<<theta<<")"<<endl;
    }
};
int main()
{
    cout<<"\n********************** Rectangular to Polar Conversion **********************\n";
    Rectangle r1;
    r1.getdata();
    cout<<"\nRectangular Co-ordinates : ";
    r1.show();
    Polar p1;
    p1=r1;
    cout<<"\nPolar Co-ordinates : ";
    p1.show();
    cout<<"\n********************** Polar to Rectangular Conversion **********************\n";
    Polar p2;
    p2.gets();
    cout<<"\nPolar Co-ordinates : ";
    p2.show();
    Rectangle r2;
    r2=p2;
    cout<<"\nRectangular Co-ordinates : ";
    r2.show();
    cout<<endl;
    return 0;
}