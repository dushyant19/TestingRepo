#include<bits/stdc++.h>
using namespace std;

// #define int long long

void q2(){
    int n;
    cin>>n;
    int dp[n][3];
    int arr[n][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for(int i=1;i<n;i++){
        dp[i][0] = arr[i][0] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = arr[i][1] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = arr[i][2] + max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;
}

void q3(){
    int n,W;
    cin>>n>>W;
    int w[n];
    int v[n];
    for(int i=0;i<n;i++)
    cin>>w[i]>>v[i];
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=W;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            dp[i][j] = dp[i-1][j];
            if(j-w[i-1]>=0){
                // cout<<"for i="<<i<<" and j="<<j<<endl;
                // cout<<"dp[i-1][j] is "<<dp[i][j]<<endl;
                // cout<<"w[i-1] is "<<w[i-1]<<endl;
                // cout<<"v[i-1] is "<<v[i-1]<<endl;
                // cout<<"v[i-1]+d[i-1][j-w[i-1]] is "<<v[i-1]+dp[i-1][j-w[i-1]]<<endl;
                dp[i][j] = max(dp[i][j],v[i-1]+dp[i-1][j-w[i-1]]);
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[n][W]<<endl;
}

void q4(){
    int n,W;
    cin>>n>>W;
    int w[n];
    int v[n];
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    int dp[n+1][100001];
    // if n==0 ==> min weight = 0 i.e cant pick anything
    // if v==0 ==> min weight = 0 i.e dont pick anything
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=100000;j++){
        dp[0][j]=INT_MAX;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=100000;j++){
            dp[i][j] = dp[i-1][j];
            if(v[i-1]<=j){
                dp[i][j] = min({dp[i][j],w[i-1]+dp[i-1][j-v[i-1]]});
            }
        }
    }

    int ans = 0;
    for(int j=0;j<=100000;j++){
        if(dp[n][j]<=W){
            ans = j;
        }
    }
    cout<<ans<<endl;
}

void q5(){
    string s,t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    int length = dp[n][m];
    cout<<length<<endl;
    int i = n,j = m;
    vector<int> ans(length+1);
    ans[length] = '\0';
    while(i>0&&j>0){
        if(s[i-1]==t[j-1]){
            cout<<"pushing "<<s[i-1]<<" to end"<<endl;
            ans[length-1]=s[i-1];
            length--;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>=dp[i][j-1]){
                // Go up
                i--;
            }
            else
            {
                // Go lefft
                j--;
            }
        }
    }
    for(int i=0;i<length;i++){
        printf("%c",ans[i]);
    }
    cout<<endl;
}


int32_t main(){
    q5();
}