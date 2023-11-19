#include<stdio.h>
#include<math.h>
int main()//1000000007
{
    int n;
    scanf("%d",&n);
    int dp[10010][2];
    dp[1][0]=dp[1][1]/*=dp[2][0]=dp[2][1]*/=1;
    //dp[3][0]=dp[3][1]=1;
    //dp[4][0]=dp[4][1]=2;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=(dp[i-1][1]+dp[i-2][1])%1000000007;
        dp[i][1]=(dp[i-1][0]+dp[i-2][0])%1000000007;
    }
    int res=(dp[n][1]+dp[n][0])%1000000007;
    printf("%d",res);
    return 0;
}