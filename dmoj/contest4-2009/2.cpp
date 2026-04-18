#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	int k = 2;
	for(int i =0;i<n;i++){
		k*=2;
		k-=1;
	}
	cout << k*k;
}
