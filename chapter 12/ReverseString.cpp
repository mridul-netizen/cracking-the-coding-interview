#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void reverse(char* str)
{
    char* end = str;
    char temp;
    if(str) {
        while(*end)//find end of string
        {
            ++end;
        }
        --end;//set one character back since last character is null
    }

    //swap characters from starting of string with the end of string until the pointers meet
    while(str<end)
    {
        temp = *str;
        *str++ = end;
        *end-- = *tmp;
    }

}
int main()
{
    char* str  = "geeksforgeeks";
    reverse(str);
}