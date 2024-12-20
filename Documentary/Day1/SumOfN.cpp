#include<iostream>
using namespace std;

int fact(int i,int n){
    if(n==0) {
      
     return i; 
    }
     return fact(i+n,n-1);
     }
int main(){
    int n;
    cout<<"Enter the number:"<<endl;
    cin>>n;
    cout<<fact(0,n);
}
