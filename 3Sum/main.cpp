/*By Cebastian Santiago
* Leetcode 15
*/
#include<iostream>
#include<vector>
#include<algorithm>




std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    //variables
    std::vector<std::vector<int>> temp;
    std::vector<int> one;
   
    //sort the vector
    std::sort(nums.begin(), nums.end());
    

    //if vector less then two elements return or vector empty
    if (nums.empty() || nums.size()-1 < 2){
        return temp;
    }


    //loop through the vector 
    for (size_t i = 0; i < nums.size(); i++) {
        //check for duplicates
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }


        //if in here were good did not encouter duplicates
        int lft = i + 1;
        int rght = nums.size() - 1;
        
        //while lft < rght
        while (lft < rght) {
            int three = nums[i] + nums[lft] + nums[rght];
             if (three > 0) {
                rght-=1;
             }

            else if (three < 0){
                lft+=1;
            }

            else {
                 one.push_back(nums[i]);
                 one.push_back(nums[lft]);
                 one.push_back(nums[rght]);
                 temp.push_back(one);
                 one.clear();

                lft+=1;
                while (nums[lft] == nums[lft-1] && lft < rght) {
                    lft+=1;
                }

            }

        }

    }


    return temp;
}



int main() {
    std::vector<int> num = { 0,0,0,0 };

    std::vector<std::vector<int>> an = threeSum(num);

    //display 
    for (size_t i = 0; i < an.size(); i++) {
        for (size_t j = 0; j < an[i].size(); j++) {
            std::cout << an[i][j] << std::endl;
        }
    }


	return 0;
}