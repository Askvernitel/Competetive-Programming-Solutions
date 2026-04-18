#include <bits/stdc++.h>

using namespace std;


int main(){
	double a,b,c;
	double i,j,k;

	cin >> a >> b >> c;
	cin >> i >> j >> k;
	
	double u = a+b+c;
	double v = i+j+k;
	double ans1 = a;
	double ans2 = b;
	double ans3 = c;
	for(double x=0;x<=u;x+=0.0001){
		double z = x/v;
		double v1 = a-(z*i);
		double v2 = b-(z*j);
		double v3 = c-(z*k);
		if(v1 < 0 || v2 < 0 || v3 < 0) break;
		ans1 = v1;
		ans2 = v2;
		ans3 = v3;	
	}
	cout << setprecision(4) << fixed;
	cout << ans1 << " " << ans2 << " " << ans3 << '\n';
}
