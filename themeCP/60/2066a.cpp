#include <bits/stdc++.h>


using namespace std;
void solve(int p){
	int n;
	cin >> n;
	int a[n];
	int s[n+1];
	
	memset(s, 0, sizeof(s));
	for(int i = 0;i<n;i++){
		cin >> a[i];
		s[a[i]]=1;
	}
	int p1 = n, p2 = 1;
	bool t = 0;
	for(int i = 1;i<=n;i++){
		if(!s[i]){
			t=1;
			p1=i;
			break;
		}
	}
	for(int i = 1;i<=n;i++){
		if(s[i]){
			p2=i;
			break;
		}
	}
	
	int maxv = 0, idx1=0, idx2 =0;
	if(!t){ 
		for(int i =0;i<n;i++){
			if(maxv < a[i]){ 
				maxv = a[i];
				idx1 = i;
			}
		}
		int sec = 0;
		for(int i =0;i<n;i++){
			if(maxv-a[i]> sec){ 
				sec = maxv-a[i];
				idx2 = i;
			}
		}
		p1 = idx1+1;
		p2 = idx2+1;
	}

	
	cout << "? " << p1 << " " << p2 << endl;
	int num1;
	cin >> num1;

	cout << "? " << p2 << " " << p1 << endl;
	int num2;
	cin >> num2;
	
	if( num1 != 0 && num2 != 0 && num1 == num2 && abs(a[p1-1]-a[p2-1]) <= num1){ 
		cout << "! B" << endl;
	}else{
		cout << "! A" << endl;
	}
}
int main(){
	int tc;
	cin >> tc;
	int cnt = 0;
	while(tc--){
		cnt++;
		solve(cnt);
	}
}
