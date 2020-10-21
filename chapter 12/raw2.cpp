#include<iostream>
using namespace std;


int main(){

   int *p = new int;
   int *q = new int;

   cout<< &q<<endl;
   cout<< &p<<endl;

   p = NULL;
   cout<<p<<endl;
   q = p;

   cout<< *q<<endl;
   cout<< *p<<endl;

    return 0;
}