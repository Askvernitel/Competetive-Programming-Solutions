#include <bits/stdc++.h>

using namespace std;

int main(){
	int n = 8;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	string ans;
	for(int i =1;i<n-1;i++){
		if((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i]<a[i-1] && a[i] < a[i+1])){ 
			ans = "mixed";
			break;
		}else if(a[i] > a[i+1]){
			ans = "descending";
		}else{
			ans = "ascending";
		}
	}
	cout << ans;
}
