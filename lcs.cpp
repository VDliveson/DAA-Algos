#include <iostream>
using namespace std;

void get_LCS(string x, string y, int m, int n)
{
    int dp[m+1][n+1];
    for(int i = 0; i <=m; i++){
        for(int j = 0; j <=n;j++){
            if(i==0 || j==0){
                dp[i][j] =0;
            }
            else if(x[i] == y[j]){
                dp[i][j] =dp[i-1][j-1]+1;
            }else{
                dp[i][j] =max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int index=dp[m][n];
    char LCSstring[index+1];
    int i=m;
    int j=n;

    while(i>=0 && j>= 0){
        if(x[i-1]==y[j-1]){
            LCSstring[index-1]=x[i-1];
            index--;
            j--;
            i--;
        }else if(dp[i-1][j]>dp[i][j - 1]){
            i--;
        }else{
            j--;
        }
    }

    cout<<"X : "<<x<<" Y : "<<y<<" LCSstring : "<<LCSstring<<endl;


}

int main()
{
    string x = "AGGTAB";
    string y = "GXTXAYB";
    int m = x.length();
    int n = y.length();
    get_LCS(x, y, m, n);
}