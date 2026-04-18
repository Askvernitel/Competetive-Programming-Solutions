#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int m = 0;
	if(n == 1){
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 2;i*i<=n;i++){
		if(!(n%i)){
			m = n/i;
			break;
		}
	}

		cout << n-m << '\n';

}
