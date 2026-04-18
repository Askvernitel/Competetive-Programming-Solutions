#include <bits/stdc++.h>
#define int long long
using namespace std;
int c[20];
signed main(){

	string str;
	int k;
	cin >> str >> k;
	for(int i =0;i<str.size();i++){
		c[i]=str[i]-48;
	}

	int n = str.size();
	if(k > n){ 
		cout << (int)pow(10,k)  << '\n';
		return 0;
	}
	int p = n-1;
	int t = k;
	int u = 0;
	int cof = 1;
	while(t > 0){
		u+=(c[p])*cof;
		c[p]=0;
		cof*=10;
		t--;
		p--;
	}
	int x = (u+cof/2)/cof;
	c[p] +=x;
	int carry=0;
	for(int i = p;i>=0;i--){
		c[i]+=carry;
		if(i == 0 && c[i] == 10) break;
		int v = c[i]/10;
		c[i]%=10;
		carry = v;
	}
for(int i =0;i<n;i++){
		cout << c[i];
	}
			
}
