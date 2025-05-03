class Solution {
    public String pushDominoes(String dominoes) {
        int n=dominoes.length();
        StringBuilder sb=new StringBuilder(dominoes);
        int right=-1;
        for(int i=0;i<n;i++){
            if(sb.charAt(i)=='L'){
                if(right==-1){
                    for(int j=i-1;j>=0 && sb.charAt(j)=='.';j--){
                        sb.setCharAt(j,'L');
                    }
                }
                else{
                    for(int j=right+1,k=i-1;j<k;j++,k--){
                        sb.setCharAt(j,'R');
                        sb.setCharAt(k,'L');
                    }
                    right=-1;
                }
            }
            else if(sb.charAt(i)=='R'){
                if(right!=-1){
                    for(int j=right+1;j<i;j++){
                        sb.setCharAt(j,'R');
                    }
                }
                right=i;
            }
        }
        if(right!=-1){
            for(int i=right+1;i<n;i++){
                sb.setCharAt(i,'R');
            }
        }
        return sb.toString();
    }
}