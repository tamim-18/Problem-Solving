#include <bits/stdc++.h>
using namespace std;
#define mod 1000000000000000000
#define MOD         1000000007
#define ll long long
#define ull unsigned ll
#define mp      make_pair
#define pb      push_back
#define forn(i,n)   for(ll i=0;i<n;i++)
#define for1(i,n)   for(ll i=1;i<=n;i++)
#define forn1(i,n)  for(int i=1;i<n;i++)
#define rep(i,x,n)  for(ll i=x;i<=n;i++)
#define repr(i,x,j) for(ll i=x;i>=j;i--)
#define vi vector<ll>
#define mii map<ll,ll>
#define umii unordered_map<ll,ll>
#define vii vector<pair<ll,ll>>
#define vvi vector<vector<int>>
#define pii pair<ll,ll>
#define F first
#define S second
#define fill(a,x) memset(a,x,sizeof a);
#define all(x) x.begin(),x.end()
#define test ll t;cin>>t;while(t--)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.rbegin(),v.rend())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define mxvi(v) max_element(v.begin(),v.end())-v.begin()
#define mnvi(v) min_element(v.begin(),v.end())-v.begin()
#define countv(v,a) count(v.begin(),v.end(),a)
#define case cout<<"Case #"<<++i<<": "
#define R return 0
const int mara = 1e5+7;
vi a(mara),prime(mara),v(mara),luck;
vi ar[mara];
int vis[mara];
ll aa[mara],bb[mara],cc[mara],dd[mara];
map<ll,bool>flag;
bool is_prime(ll n)
{
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		  return false;
		
	}
	return true;
}
double distance(ll x1,ll y1,ll x2,ll y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool cmp(pair<ll,ll> &a,pair<ll,ll> &b)
{
	return (a.S<b.S);
}


void solution()
{
	
	vii v;
	ll n;
	cin>>n;
	ll a,b;
	forn(i,n)
	{
		cin>>a>>b;
		v.pb({a,b});
	}
	// for(auto u:v) cout<<u.F<<" "<<u.S<<endl;
	// cout<<endl;
	sort(all(v),cmp);
	// for(auto u:v) cout<<u.F<<" "<<u.S<<endl;
	cout<<endl;
	ll last=-1;
	ll cnt=0;
	forn(i,n)
	{
		if(v[i].F>=last)
		{
			cnt++;
			last=v[i].S;
		}
	}
	cout<<cnt<<endl;
	
	
} 
 
int main()
{
 
   //test
   {
       solution();
   }
   R;
}
 
//Take Cp is FUN not competetive
//Always stick to CP
//1st think small then big