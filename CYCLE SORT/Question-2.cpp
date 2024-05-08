# include<iostream>
# include<vector>
using namespace std;

int main(){

    vector<int> nums={1,2,2,4};
    int n=nums.size();
    vector<int> ans;
    int i=0;
    while(i<n){
        int correctidx=nums[i]-1;
        if(i==correctidx) i++;
        else if(i!= correctidx && nums[i]==nums[correctidx]){
            if(ans.empty()) ans.push_back(nums[i]);
            i++;
        }
        else swap(nums[i],nums[correctidx]);
    }
    
    for(int i=0;i<n;i++){
        if(nums[i]!=i+1) ans.push_back(i+1);
    }

    cout<<ans[0]<<" "<<ans[1];
    return 0;
}