#include <bits/stdc++.h>

using namespace std;

#define int long long

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local_Debug
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
// g++ file_name.cpp -DLocal_Debug

#define pie 3.141592653589793238462643383279
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pb push_back
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rsort(x) sort(x,greater<int> ())
#define endl "\n"
#define gcd __gcd
#define lcm(a,b) (a*b)/gcd(a,b)
#define deci(n) fixed << setprecision(n)
#define test() int test_case;cin >> test_case;while (test_case--)
#define sp " "
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define max5(a,b,c,d,e) max(max4(a,b,c,d),e)
#define min5(a,b,c,d,e) min(min4(a,b,c,d),e)


typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int,int> mi;

/*Power function starts*/
int Power(int a,int n,int mod){
    int res=1;
    while(n){
        if(n%2!=0){
            res=((res%mod)*(a%mod))%mod;
            n--;
        }
        else
        {
            a=((a%mod)*(a%mod))%mod;
            n/=2;
        }
    }
    return res;
}

/*Power function ends*/


/* Prime Checker starts */
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
/* Prime Checker ends */

/* Sum of Digits starts */
int getSum(int n) 
{  
   int sum = 0; 
   while (n != 0) 
   { 
       sum = sum + n % 10; 
       n = n/10; 
   } 
   return sum; 
} 
/* Sum of digits ends */

/* Ceiling function starts */
int myceil(int n,int x)
{
    int y;
    if(n%x==0)
    {
        y=n/x;
        return y;
    }
    else
    {
        y=n/x+1;
        return y;
    }
    
}
/* ceiling function ends */


int md=M1;
vi fact, inv;
 
void inverse(ll n)
{if(n>=inv.size()){ll size=inv.size();size=size==0? 1:size;
inv.resize(n + 1);inv[0] = 1;
for (ll i = size; i <= n; i++)inv[i] = Power(fact[i], md-2, md);}}
 
void factorial(ll n)
{if(n>=fact.size()){ll size=fact.size();size=size==0? 1:size;
fact.resize(n + 1);fact[0] = 1;for (ll i = size; i <= n; i++)
fact[i] = (fact[i - 1] * i) % md;
}}
 
ll ncr(ll n, ll r) { return (((fact[n] * inv[r]) % md) * inv[n - r]) % md; }

#define MAX_SIZE 1300000
int primes[MAX_SIZE];
// Function to generate N prime numbers using  
// Sieve of Eratosthenes 
void Sieve()  
{  
    bool IsPrime[MAX_SIZE];  
    memset(IsPrime, true, sizeof(IsPrime));  
    
    for (int p = 2; p * p < MAX_SIZE; p++)  
    {  
        if (IsPrime[p] == true)  
        {
            for (int i = p * p; i <  MAX_SIZE; i += p)  
                IsPrime[i] = false;  
        }  
    }  
    int index = 0;
    for (int p = 2; p < MAX_SIZE; p++)  
       if (IsPrime[p])   // Store all prime numbers  
            {
                primes[index] = p;
                index++;
            }
             
}  
//********************THE END OF TEMPLATES*******************//

void Recursive();void q2();void q3();void q4();void q5();
void q6();void q7();void q8();void q9();void q10();

int32_t main()
{
    test(){
        Recursive();
    }
    return 0;
}

int knapsack(int weights[],int values[],int n,int W,int** dp){
    if(n==0||W==0){
        return 0;
    }
    if(dp[n][W]>-1){
        return dp[n][W];
    }
    if(weights[n-1]>W){
        return dp[n][W] = knapsack(weights,values,n-1,W,dp);
    }
    int ans1 = values[n-1] + knapsack(weights,values,n-1,W-weights[n-1],dp);
    int ans2 = knapsack(weights,values,n-1,W,dp);
    return dp[n][W] = max(ans1,ans2);
}

void Recursive(){
    int n,W;
    cin>>n>>W;
    int weights[n],values[n];
    for(int i=0;i<n;i++)
    cin>>weights[i];
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[W+1];
        for(int j=0;j<=W;j++){
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(weights,values,n,W,dp)<<endl;
}

void q2(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    int cnt = 0;
    int sum = 0;
    int min = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            sum = sum + abs(arr[i][j]);
            if(arr[i][j]<0)
            cnt++;
            if(min>abs(arr[i][j])){
                min = abs(arr[i][j]);
            }
        }
    }
    int ans = 0;
    if(cnt%2==0){
        ans = sum;
    }
    else
    {
        ans = sum - 2*min;
    }
    cout<<ans<<endl; 
}

void q3()
{
    int n,w;
    cin>>n>>w;
    int weights[n];
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    int sum=0;
    vector<int> answers;
    bool set = false;
    int ans=0;
    for(int i=0;i<n;i++){
        if(sum>=myceil(w,2)){
            break;
        }
        if(sum+weights[i]>=w){
            if(weights[i]>w){
                continue;
            }
            else
            {
                set = true;
                ans = i+1;
                break;
            }
        }
        else
        {
            sum=sum+weights[i];
            answers.push_back(i+1);
        }
    }

    if(set){
        cout<<1<<endl;
        cout<<ans;
    }
    else if(sum<myceil(w,2)){
        cout<<-1;
    }
    else
    {
        {
            cout<<answers.size()<<endl;
            for(int i=0;i<answers.size();i++){
                cout<<answers[i]<<" ";
            }
        }
    }
    cout<<endl;
}

void q4(){
    int n;
    cin>>n;
    int a[n],b[n];
    int max = 0;
    int curr = 0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        curr=curr + b[i]-a[i];
        if(curr>max){
            max=curr;
        }
    }
    cout<<max<<endl;
}

vector<int> Digits(int n){
    int m=n;
    vector<int> ans;
    while(m){
        ans.push_back(m%10);
        m=m/10;
    }
    return ans;
}

bool DistinctDigits(vector<int> a){
    // for(int i=0;i<a.size();i++)
    // {
    //     cout<<a[i];
    // }
    bool set = true;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size()-1;i++){
        if(a[i]==a[i+1]){
            set=false;
            break;
        }
    }
    return set;
}

void q5(){
    string s;
    cin>>s;
    vector<char> ans;
    for(int i=0;i<s.length();i++){
        if(s[i]!='+'){
            ans.push_back(s[i]);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<"+";
    }
    cout<<ans[ans.size()-1]<<endl;
}

