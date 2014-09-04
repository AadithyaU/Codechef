#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <climits>
#include <queue>
#include <fstream>
#include <iomanip>   
#include <stack>
#include <cassert>
using namespace std;

//Useful input scanners
#define sd(x) 						scanf("%d",&x)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())



void reverse(char *str,int length) 
{
 	int i = 0;
 	int j = length - 1;
 	char temp;
   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
   str[length] = '\0';
   cout<<"reverse string is "<<str<<endl;
}

int lps(char *source) {
	   int n = strlen(source);
    int LP[n][n];
    int ind[n];
    int a = 0;
    //All sub strings with single character will be a plindrome of size 1
    for(int i=0; i < n; i++){
        LP[i][i] = 1;
    }
    //Here gap represents gap between i and j.
    for(int gap=1;gap<n;gap++){
        for(int i=0;i<n-gap;i++ ){
                    int j=i+gap;
                    if(source[i]==source[j] && gap==1)
                        LP[i][j]=2;
                    else if(source[i]==source[j])
                        LP[i][j]=LP[i+1][j-1]+2;
                    else
                        LP[i][j]= maX(LP[i][j-1], LP[i+1][j]);              
         }      
    }   

    char str1[n];
    for(int q = 0; q < n; q++) str1[q] = source[q];
    reverse(str1,n);
    //Rebuilding string from LP matrix
    int finlen = LP[0][n-1];
    char strBuff[finlen + 1];
    strBuff[finlen] = '\0';
    int x = n;
    int index = finlen;
    int y = n;

    cout<<source<<" "<<str1<<endl;
   while (x > 0 && y > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
   	cout<<" now values of x and y are "<<x-1<<" "<<y-1<<endl;
      if (source[x-1] == str1[y-1])
      {
      	cout<<"Are they really equal "<<x-1<<" "<<y-1<<" "<<source[x-1]<<" "<<str1[y-1]<<endl;
          strBuff[index-1] = source[x-1]; // Put current character in result
          x--; y--; index--;  
          cout<<" char was "<<strBuff[index]<<" at x and y as "<<x<<" "<<y<<" "<<source[x]<<" "<<source[y]<<endl;
         // ind[a++] = x;
            // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (LP[x-1][y] > LP[x][y-1])
         x--;
      else
         y--;
   }
   cout<<strBuff<<endl;



/*


    while(x < y){
        if(source[x] == source[y]){
            strBuff[p++] = source[x];
            ind[a++] = x;
            ind[a++] = y;
            x++;
            y--;
            cout<<"the value at "<<p-1 <<" is  "<<strBuff[p-1]<<" with x and y as "<<x-1<< " "<<y+1<<endl;
        } else if(LP[x][y-1] > LP[x+1][y]){
           / y--;
        } else {
            x++;
        }
    }
    cout<<"the value of p is "<<p<<endl;
    cout<<"the reverse string is "<<rev<<endl;
    int tlen = p;
    //cout<<strBuff<<"\n";
  /*  if(x == y){          
        strBuff[p++] = source[x];//.append(str);
    }
  */ // ind[a++] = x; 
   /* sort(ind,ind+a);
    cout<<"the index array is "<<endl;
    for(int w = 0;w < a;w++) cout<<ind[w]<<" ";
   	cout<<endl;

    for(int g = 0; g < tlen; g++) 
    	strBuff[p++] = rev[g];
    strBuff[p] = '\0';
    	printf("%s\n",strBuff);
    	int k = 0;
    	int l = 0;
    	a = 0;
    	for(int g = 0; g < n; g++) {
    		if(g != ind[a]) {
    			source[l++] = source[g];
    		}
    		else a++;
    	}
    	source[l] = '\0';
    	//cout<<"the source is "<<source<<endl;
*/    	return finlen;
}


int main() {
	int t;
	sd(t);
	while(t--) {
		char str[100001];
		scanf("%s",str);
		int count = 0;
		int flen = strlen(str);
		
		cout<<lps(str)<<endl;
//		cout<<str<<endl;
//		cout<<lps(str)<<endl;
//		cout<<str<<endl;
		
		//cout<<count<<"\n";
	}
	return 0;
}