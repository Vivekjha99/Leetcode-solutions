class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
map<pair<int, int>, vector<pair<pair<int, int>, int>>> vec;
// here i am just maintaining x and y and pushed distance from any other  x1 & y1 from x & y
for(int i=0;i<n ;i++){
	for(int j=i+1;j<n;j++){
		int dis = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
		vec[{points[i][0],points[i][1]}].
		push_back({{points[j][0],points[j][1]},dis});
		vec[{points[j][0], points[j][1]}].
		push_back({{points[i][0], points[i][1]}, dis});
	}
}

set<pair<int, int>> visi; // to mark visi and also store negative value 

priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
greater<pair<int,pair<int,int>>>>q; // to have minimum distance 

q.push({0,{points[0][0],points[0][1]}});

int sum=0;

// standard mst
while(!q.empty()){
	int w = q.top().first;
	int x = q.top().second.first;
	int y = q.top().second.second;

	q.pop();

	if(visi.count({x,y}))continue; 
	visi.insert({x, y});
	sum+=w;

	for(auto ele :vec[{x,y}]){
		int newx=ele.first.first;
		int newy=ele.first.second;
		int adw = ele.second;
		q.push({adw,{newx,newy}});
	}
}
return sum;
    }
};