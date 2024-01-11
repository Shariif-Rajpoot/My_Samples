#include<iostream>
#include<cmath>
using namespace std;
class simpleCal
{
    protected:
    float x,y;
    char opt;
    public:
    float sum(float,float);
    float sub(float,float);
    float multiplay(float,float);
    float divide(float,float);
    int modulas(int,int);
};
class scientificCal
{
    protected:
    float num;
    public:
    float power(float,float);
    int factorial(int);
    float underRoot(float);
    int power_of_two(int);
};
class calculation : public simpleCal , public  scientificCal
{
    private:
    void question();
    public:
    void getMeIn(); 
};
/*
    OBJECTS
*/
float simpleCal :: sum(float x, float y)
{
    return x+y;
}
float simpleCal :: sub(float x, float y)
{
    return x-y;
}
float simpleCal :: multiplay(float x, float y)
{
    return x*y;
}
float simpleCal :: divide(float x, float y)
{
    return x/y;
}
int simpleCal :: modulas(int x, int y)
{
    return x%y;
}
float scientificCal :: power(float p,float n)
{
    float pow = 1;
    for(int i = 1;i<=p;i++)
    {
        pow *= n;
    }
    return pow;
}

int scientificCal :: factorial(int n)
{
    float fact = 1;
    for(int i = n;i>0;i--)
    {
        fact *= i;
    }
    return fact;
}
float scientificCal::underRoot(float n)
{
    return sqrt(n);
}
int scientificCal :: power_of_two(int n)
{
    return pow(2,n);
}
void calculation :: getMeIn()
{
    cout<<"\t\t\t\t(*******Select from the options that are given below*******) \n";
    cout<<"\t\tEnter operator + for addition "<<endl;
    cout<<"Enter operator - for subtraction "<<endl;
    cout<<"\t\tEnter operator * for multiplication "<<endl;
    cout<<"Enter operator / for division "<<endl;
    cout<<"\t\tEnter ! for factorial "<<endl;
    cout<<"Enter ^ for raising to raising the number to the power of 2 "<<endl;   
    cout<<"\t\tEnter operator % to find reminder "<<endl;
    cout<<"Enter (p || P) for power root "<<endl;
    cout<<"\t\tEnter (s || S) for under root "<<endl;
    cout<<"\t\t\t\t(Kindly Enter your choice ===> "; 
    cin>>opt;
    question();
}
void calculation :: question()
{   
    switch(opt)
    {
        case '+':
        {
            cout<<"Enter two numbers ";
            cin>>x>>y;
            cout<<"The sum of "<<x<< " and "<<y<<" is "<<sum(x,y)<<endl;
        }
        break;
        
        case '-':
        {
            cout<<"Enter two numbers ";
            cin>>x>>y;
            cout<<"The subtraction of "<<x<< " and "<<y<<" is "<<sub(x,y)<<endl;
        }
        break;

        case '*':
        {
            cout<<"Enter two numbers ";
            cin>>x>>y;
            cout<<"The multiplication of "<<x<< " and "<<y<<" is "<<multiplay(x,y)<<endl;
        }
        break;

        case '/':
        {
            cout<<"Enter two numbers ";
            cin>>x>>y;
            cout<<"The division of "<<x<< " and "<<y<<" is "<<divide(x,y)<<endl;
        }
        break;

        case '%':
        {
            cout<<"Enter two numbers ";
            cin>>x>>y;
            cout<<"The reminder of "<<x<< " and "<<y<<" is "<<modulas(x,y)<<endl;
        }
        break;

        case '!':
        {
            cout<<"Enter number to find its factorial ";
            cin>>num;
            cout<<"The factorial of the "<<num<<" is "<<factorial(num)<<endl;    
        }
        break; 
        
        case '^':
        {
            cout<<"Enter number to raise the power of 2=====> 2^";
            cin>>num;
            cout<<"The answer after the raising "<<num<<" to the power of "<<"2 is 2^"<<num<<" : "<<power_of_two(num)<<endl;    
        }
        break; 
        
        case 'P':
        case 'p':
        {
            cout<<"Enter two valuse ";
            cin>>x>>y;
            cout<<"The answer of "<<x<< " raise to the power "<<y<<" is "<<power(x,y)<<endl;
        }
        break;
        
        case 'S':
        case 's':
        {
            cout<<"Enter number to find its under root ";
            cin>>x;
            cout<<"The under root of the "<<x<<" is "<<underRoot(x)<<endl;
        }
        break;


        default:
        {
            cout<<"Please select from the options that are listed by developer \n";
            getMeIn();
        }   
    }
    char choice;
    cout<<"Do you want to continue press (C || c) for more operation and any other to exit ====> ";
    cin>>choice;
    if(choice == 'C' || choice == 'c')
    getMeIn();
}
int main()
{
    calculation c1;
    c1.getMeIn();
    return 0;
}