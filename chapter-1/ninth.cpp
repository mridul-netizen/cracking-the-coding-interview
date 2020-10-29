#include<bits/stdc++.h>
using namespace std;

bool isSubstring(string s1, string s2) {
    return s1.find(s2);
}
bool isRotation(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    if(len1 == len2 && len1 > 0) {
        string s3 = s1+s1;
        return isSubstring(s3, s2);
    }
    return false;
}
int main()
{
    string s1 = "mridul";
    string s2 = "ulmrid";
    bool ans = isRotation(s1, s2);
    cout<<ans;
    return 0;
}