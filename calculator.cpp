#include<iostream>
using namespace std;
int main(){
    double n1,n2;
    char op;
    cout<<"Enter the value of n1:";
    cin>>n1;
    cout<<"Enter the value of n2:";
    cin>>n2;
    cout<<"Enter the operator(+,-,/,*):";
    cin>>op;
    if(op=='+')
    cout<<n1+n2;
    else if(op=='-')
    cout<<n1-n2;
    else if(op=='*')
    cout<<n1*n2;
    else{
        if(n2!=0)
        cout<<n1/n2;
    }
}
