class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>taskq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>serverq;
        for(int i=0;i<servers.size();i++)serverq.push({servers[i],i});
        vector<int>ans;
        int time=0;
        for(int t=0;t<tasks.size();t++){
            time=max(time,t);
            if(serverq.empty() && taskq.top().first>time)time=taskq.top().first;
            while(taskq.size()>0 && taskq.top().first<=time){
                serverq.push({servers[taskq.top().second],taskq.top().second});
                taskq.pop();
            }
            int currServer=serverq.top().first;
            int currIdx=serverq.top().second;
            serverq.pop();
            int finishTime=time+tasks[t];
            taskq.push({finishTime,currIdx});
            ans.push_back(currIdx);
        }
        return  ans;
    }
};