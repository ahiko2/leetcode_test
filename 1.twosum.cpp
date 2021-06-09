vector<int> twoSum(vector<int>& nums, int target) {
        int sum{0};
        vector<int> ChosenNum;
        
        for(int i = 0;i < nums.size();i++){
            
            for(int j = i + 1;j < nums.size();j++){
                sum = nums[i] + nums[j];
                
                if(sum == target){
                    ChosenNum.push_back(i);
                    ChosenNum.push_back(j);
                    break;
                }
            }
        }
      return ChosenNum;
        
    }
