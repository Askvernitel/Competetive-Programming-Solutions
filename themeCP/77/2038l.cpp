#include <bits/stdc++.h>


using namespace std;

int main(){
	int n;
	cin >> n;
	int t = n;
	int k = n;
	int ans =0;
	int p = n/3;
	
	ans += n;
	int c = (n)/2;
	
	t -= c;

	ans += t/3;
	if(t%3){
		ans++;
	}

	cout << ans << '\n';

}
