


// day   - 0,   1,   2,   3,   4 ,  5,  6
// price - 100, 80,  60,  70,  60,  75, 85
// span  - 1,   1,   1,    2,  1,   4,   6



// s.push(0);
// for (int  i = 1; i < n; i++)
// {
//     while(!s.empty() && price[s.top])
//         s.top();
//     if(s.empty())
//         span[i] = i+1;
//     else 
//         span[i] = i-s.top();
//     s.push(i);
// }


#include <bits/stdc++.h> 
using namespace std; 

void calculateSpan(int price[], int n, int S[]) 
{ 
	S[0] = 1; 

	for (int i = 1; i < n; i++) 
	{ 
		S[i] = 1; 

		for (int j = i - 1; (j >= 0) && (price[i] >= price[j]); j--) 
			S[i]++; 
	} 
} 

void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 
 
int main() 
{ 
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int price[n];
        for(int i = 0;i<n;i++) {
            cin>>price[i];
        }
        int S[n]; 
        calculateSpan(price, n, S); 
        printArray(S, n); 
        cout<<endl;
    }
	return 0; 
} 

