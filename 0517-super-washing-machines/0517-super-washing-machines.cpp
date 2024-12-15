class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size();
        vector<int>leftSum(n,0);
        vector<int>rightSum(n,0);
        leftSum[0]=machines[0];
        rightSum[n-1]=machines[n-1];
        for(int i=1;i<n;i++){
            leftSum[i]=leftSum[i-1]+machines[i];
        }
        for(int i=n-2;i>=0;i--){
            rightSum[i]=machines[i]+rightSum[i+1];
        }
        int res=0;
        if(leftSum[n-1]%n!=0)return -1;
        int eachMachine=leftSum[n-1]/n;
        for(int i=0;i<n;i++){
            int left=eachMachine*i;
            int right=eachMachine*(n-i-1);
            int leftFlow=0,rightFlow=0;
            //if more dresses are needed in the machines to the left of current machine then we will find the left req dresses.
            if(i>0 && left>leftSum[i-1])leftFlow=(left-leftSum[i-1]);
            //if more dresses are needed in the machines to the right of the current machine and these dresses are sent from left to right then we cal them.
            if(i<n-1 && right>rightSum[i+1])rightFlow=(right-rightSum[i+1]);
            // cout<<i<<" "<<leftFlow<<" "<<rightFlow<<endl;
            res=max(res,leftFlow+rightFlow);
        }
        return res;
    }
};