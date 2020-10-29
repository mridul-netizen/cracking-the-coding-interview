#include<bits/stdc++.h>
using namespace std;

# define d 256 //no. of characters in the input string
// pat -> pattern
// txt -> text
// q  -> prime number

void search(char pat[], char txt[], int q) {
    int M = strlen(pat);//16 extra 1 for null character
    int N = strlen(txt);//6
    int i, j;
    int p = 0;//hash value for pattern
    int t = 0;//hash value for text
    int h = 1;

    //the value of h would be "pow(d,M-1)%q"
    for ( i = 0; i < M-1; i++)
    {
        h = (h*d) % q; 
    }
    //calculate the hash value of pattern and first
    //window of text
    for ( i = 0; i <= M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * p + txt[i]) % q;
    }
    //slide the pattern over text one by one
    for ( i = 0; i <= N-M; i++)
    {
        // Check the hash values of current window of text 
        // and pattern. If the hash values match then only 
        // check for characters on by one
        if(p == t) {
            //check for characters one by one
            for ( i = 0; i < M; i++)
            {
                if(txt[i+j] != pat[j])
                    break;
            }
            //if p == t and pat[0...M-1] = txt[i,i+1,....i+M-1]
            if(j == M)
                cout<<"Pattern found at index"<<i<<endl;
        }

        //Calculate hash value for next window of text:Remove
        //leading digit,add trailing digit
        if(i < N-M) {
            t = (d*(t-txt[i]*h) + txt[i+M]) % q;
            cout<<t<<endl;
            //we might get negative value of t, converting it to positive
            if(t < 0)
            t = (t+q);
        }
    }
    cout<<t;
}
int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "geeks";

    int q = 101;//some prime number

    search(pat, txt, q);

    return 0;
}