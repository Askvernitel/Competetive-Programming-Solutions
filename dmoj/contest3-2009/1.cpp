#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int main(){
	string a,b;
	cin >> a >> b;
	
	int n =2;
	string mx = b;
	for(int i =n;i>=0;i--){
		if(a[i] > b[i]){ 
			mx =a;
			break;
		}else if(b[i] > a[i]){	
			mx = b;
			break;
		}
	}
	reverse(mx.begin(), mx.end());
	cout << mx;
}
