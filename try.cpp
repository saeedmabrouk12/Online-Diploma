#include <iostream>
#include<bits/stdc++.h>
//#include <limits>
//typedef std::numeric_limits< double > dbl;
//اصحي للكلام
using namespace std;
//#ifndef ONLINE_JUDGE
//freopen(fi, "r", stdin);
//freopen(fo, "w", stdout);
//#else
// online submission
//#endif
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lp1(i, n)		for(int i=1;i<(int)(n);++i)
typedef long long ll;
//cout.precision(dbl::max_digits10);
int arry[4][2]= {  {-1,0},{1,0},
                    {0,-1},{0,1} };
void func(vector<vector<pair<char,int>>>&vec , int ,int);
int main(){
    int n ;
    cin >>n;
    cout<<n;
    return 0;
} 

