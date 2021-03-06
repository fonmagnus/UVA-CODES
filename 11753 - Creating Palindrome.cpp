/*
//Author : Rezwanul Islam Maruf
//AUST ,CSE
//25-th batch..
*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>
#include <sstream>

#define FOR(i,j,n) for(i=j;i<=n;i++)
#define REP(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define inf 9999999
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define LL long long
#define LLU unsigned long long
#define DB double
#define LD long double
#define eps 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define inpI ({int a; scanf(" %d", &a); a;})
#define inpD ({DB a; scanf(" %lf", &a); a;})
#define inpLL ({LL a; scanf(" %lld", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795
#define NP next_permutation
#define PP prev_permutation
#define mp make_pair
#define PII pair <int , int>


#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)



int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);


//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
//

using namespace std;
#define SZ 100005

int k;
//int dp[SZ][SZ];

int s[SZ];
/*
int solve(int i,int j)
{
    if(i>=j )return 0;

    int &ret=dp[i][j];
    if(ret>k)return inf;
    if(ret!=-1)return ret;
    ret=inf;
    if(s[i]==s[j]) ret=solve(i+1,j-1);

    else ret=min(solve(i,j-1),solve(i+1,j))+1;

    return ret;
}*/
int solve(int i,int j,int mv)
{
    if(mv>k)return inf;
    if(i>=j )return mv;

    if(s[i]==s[j]) return solve(i+1,j-1,mv);

    else {
                    return min(solve(i,j-1,mv+1), solve(i+1,j,mv+1));
         }

}
int main()
{
   // FRD;

    int i,t=inpI,cs=1,val;
    while(t--)
    {
        int n=inpI;
        k=inpI;
        //s="";
        for(i=0;i<n;i++)
        {
            cin>>val;
        /*    std::string sT;
            std::stringstream out;
            out << val;
            sT = out.str();
            //cout<<sT<<endl;
            s=s+sT;*/
            s[i]=val;
        }
       // msn(dp,-1);
       // cout<<s<<endl;
        //ans.clear();

       // int ans=solve(0,n-1);
       int ans=solve(0,n-1,0);
        CS;
        if(ans==0)printf("Too easy");
        else if(ans<=k) printf("%d",ans);
        else printf("Too difficult");


//        cout<<ans;
        cout<<endl;
    }
    return 0;
}
