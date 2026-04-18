#include <bits/stdc++.h>

using namespace std;
map<string, int> years = {{"Ox",0}, {"Tiger", 1}, {"Rabbit",2},{"Dragon", 3}, {"Snake",4}, {"Horse",5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9}, {"Pig",10}, {"Rat", 11}};

int main(){ 
    int n;
    cin >> n;
    map<string, pair<int,string>> m = { {"Bessie",{0, "Ox"}}};
    for(int i =0;i<n;i++){
        string first, second, state,year;
        for(int j=0;j<8;j++){
            string str;
            cin >> str;
            if(j == 0){ 
                first = str;
            }
            if(j == 3){ 
                state = str;
            }
            if(j == 4){ 
                year = str;
            }
            if(j == 7){ 
                second = str;
            } 
        }
        if(state == "previous"){
            int y =years[year];
            int ny = years[m[second].second];
            int d;
            if(ny > y) d = ny - y;
            else d=12-(y-ny);
            m[first].first = m[second].first+d;
            m[first].second = year;
        }else{ 
            int y =years[year];
            int ny = years[m[second].second];
            int d;
            if(ny >= y) d = 12-(ny-y);
            else d=y-ny;
            m[first].first = m[second].first-d;
            m[first].second = year;
        }
    }
    cout << abs(m["Elsie"].first);


}
