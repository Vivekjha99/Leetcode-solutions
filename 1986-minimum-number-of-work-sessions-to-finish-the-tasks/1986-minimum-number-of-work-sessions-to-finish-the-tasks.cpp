class Solution {
public:
    void solve(int idx,vector<int>&sess,int &ans,vector<int>&tasks,int time){
        if(idx>=tasks.size()){
            ans=min(ans,(int)sess.size());
            return ;
        }
        //if current ans is greater than ans not checking again
        if(sess.size()>ans)return;
        //first checking with existing grps
        for(int i=0;i<sess.size();i++){
            if(tasks[idx]+sess[i]<=time){
                sess[i]+=tasks[idx];
                solve(idx+1,sess,ans,tasks,time);
                sess[i]-=tasks[idx];
            }
        }
        //now adding the new session
        sess.push_back(tasks[idx]);
        solve(idx+1,sess,ans,tasks,time);
        sess.pop_back();
    }
    int minSessions(vector<int>& tasks, int time) {
        int ans=INT_MAX;
        vector<int>sess;
        solve(0,sess,ans,tasks,time);
        return ans;
    }
};