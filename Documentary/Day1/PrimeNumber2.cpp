#include<iostream>
using namespace std;

int main()
{
  int n,i;
  cout<<"Enter Number :";
  cin>>n;
  int count=0;
  if(n<=1)
  {
    cout<<"Not Prime"<<endl;
  }
  if(n>1)
  {
    for(i=2;i<n;i++)
    {
      if(n%i==0)
      {
        count+=1;
      }
    }
    if(count>=2)
    {
      cout<<"not prime"<<endl;
      }
    else
    {
      cout<<"prime"<<endl;
    }
  }
}