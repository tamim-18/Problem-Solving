#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,q;
	cin>>n>>q;
	multiset<long long>s;  //here we use it as we have to remove elements from it;
	long long i;
	for ( i = 0; i < n; ++i)
	{
		/* code */
		long long x;
		cin>>x;
		s.insert(x);
	}
	while(q--)
	{
		long long t;
		cin>>t;
		auto it=s.upper_bound(t); // this is returning the ierator of first largest element of t
		if(it==s.begin())  // checking if no element is greater than t
			cout<<-1<<endl; // if so then yes
	  else 
	  {
	  	cout<<*(--it)<<endl; // otherwise we're sure that we can buy ticket with the price less than or euqal t
	  	s.erase(it);  //removing the iterator
	  }
	}

}