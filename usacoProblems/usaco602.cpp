#include <bits/stdc++.h>

using namespace std;

int n;
pair<int,int> a[50004];
set<pair<int,int>> choices;
vector<pair<int,int>> cur_choice;
set<pair<int,int>> chosen;
int area = INT_MAX;

bool is_in(pair<int,int> coord, vector<pair<int,int>>& cur_choice){
    for(pair<int,int> choice:cur_choice){ 
        if(coord == choice){
            return true;
        }
    }
    return false;
}
void calc_area(vector<pair<int,int>>& cur_choice){ 
    int min_x=INT_MAX, max_x=INT_MIN, min_y=INT_MAX, max_y=INT_MIN;
    for(int i =0;i<n;i++){
        if(!is_in(a[i], cur_choice)){
            min_x = min(a[i].first, min_x);
            max_x = max(a[i].first, max_x);
            min_y = min(a[i].second, min_y);
            max_y = max(a[i].second, max_y);
        }
    }
    area = min(area, (max_x-min_x)*(max_y- min_y));
}


void rec(){ 
    if(cur_choice.size() == 3){
        calc_area(cur_choice);
        return;
    }
    for(pair<int,int> choice:choices){ 
        if(chosen.find(choice) != chosen.end()) continue;
        chosen.insert(choice);
        cur_choice.push_back(choice);
        rec();
        chosen.erase(choice);
        cur_choice.pop_back();
    }
}
int main(){
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a+n);
    for(int i =0;i<3;i++){
        choices.insert(a[i]);
    }
    for(int i =n-1;i>=n-3;i--){
        choices.insert(a[i]);
    }

    sort(a, a+n, [&](pair<int,int> a, pair<int,int> b){
        if(a.second > b.second){
            return true;
        }
        if(a.second == b.second){
            return a.first >= b.first;
        }
        return false;
    });

    for(int i =0;i<3;i++){
        choices.insert(a[i]);
    }
    for(int i =n-1;i>=n-3;i--){
        choices.insert(a[i]);
    }



    rec();
    cout <<area; 
}
