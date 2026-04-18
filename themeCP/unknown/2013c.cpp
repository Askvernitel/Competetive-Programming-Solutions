#include <bits/stdc++.h>

using namespace std;
int ask(string cur, int num, int front){ 
	string str = to_string(num);
	if(front){
		cur+=str;
	}else{
		cur=str+cur;
	}
	cout << "? " << cur  << endl;
	int ans;
	cin >> ans;
	return ans;
}

void solve(){
	int n;
	cin >> n;
	int c = 0;
	string s="";
	int t = 0;
	int p = 0;
	while(c < n){
		c++;
		int fi=1,se=0;
		int front = 1;
		if(!p){ 
		int cor = ask(s,fi,front);
		if(cor){
			s+=to_string(fi);
			continue;
		}
		cor = ask(s,se,front);
		if(cor){ 
			s+=to_string(se);
			continue;
		}
		}
		p=1;
		front =!front;
		int cor = ask(s,fi,front);
		if(cor){ 
			s=to_string(fi)+s;
			continue;
		}
		s=to_string(se)+s;
	//	cor = ask(s,se,front);
	//	if(cor){ 
	//		continue;
	//	}
	}
	cout <<"! "<< s << endl;

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
	
}
