#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int parent[101];

int Find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = Find(parent[x]);
}

bool Same(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y){
        return true;
    }
    return false;
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    parent[y] = x;
}

double Distance(int x1, int y1, int x2, int y2){
    double xD = pow(x1 - x2, 2);
    double yD = pow(y1 - y2, 2);
    double dis = sqrt(xD+yD);

    return dis;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<double,double>> v;
    vector<pair<double, pair<int,int>>> cost;
    cout.precision(2);
    int n;
    double x1, y2, answer = 0.0;
    cin >> n;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    
    for(int i=0; i<n; i++){
        cin >> x1 >> y2;
        v.push_back(make_pair(x1,y2));
    }
    
    for(int i=0; i<v.size(); i++){
        double xF = v[i].first;
        double yF = v[i].second;

        for(int j= i+1; j<v.size(); j++){
            double xL = v[j].first;
            double yL = v[j].second;

            double distance = Distance(xF,yF,xL,yL);
            cost.push_back(make_pair(distance, make_pair(i,j)));
        }
    }
    sort(cost.begin(), cost.end());

    for(int i=0; i<cost.size(); i++){
        double edgeCost = cost[i].first;
        int star1 = cost[i].second.first;
        int star2 = cost[i].second.second;

        if(!Same(star1, star2)){
            Union(star1, star2);
            answer += edgeCost;
        }
    }
    cout << answer << "\n";
}