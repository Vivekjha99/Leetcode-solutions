class Solution {
public:
    int perform(int x,int y,int op){
        if(op=='+')return x+y;
        if(op=='-')return x-y;
        if(op=='*')return x*y;
        return 0;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int>res;
        bool isNo=1;//we are checking this because to check that the expression ends in a result
        for(int i=0;i<expression.size();i++){
            if(!isdigit(expression[i])){
                //now we are at some operator
                isNo=0;
                vector<int>leftExp=diffWaysToCompute(expression.substr(0,i));
                vector<int>rightExp=diffWaysToCompute(expression.substr(i+1));
                for(int x:leftExp){
                    for(int y:rightExp){
                        int val=perform(x,y,expression[i]);
                        res.push_back(val);
                    }
                }
            }
        }
        if(isNo==1)res.push_back(stoi(expression));
        return res;
    }
};