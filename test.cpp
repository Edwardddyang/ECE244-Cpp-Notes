#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
       int left = 0;
       int total = 0;
       int right = 0;


       for(int i = 0; i < height.size(); i++){
            if(i == 0 && height[i] == 0){
                while(height[i] == 0)
                    i++;
                right = i;
            }
             
            if(i == right){
                while(height[right] <= height[i] && right < height.size()){
                    right++;
                }
                if(right == height.size()){
                    for(int j = i + 1; j < height.size(); j++){
                      right = max(height[j], height[j - 1]); 
                    }
                }
            }
            if(min(height[right], height[left]) - height[i] > 0)
                total += min(height[right], height[left]) - height[i];
            if(height[left] <= height[i])
                left = i;
       }
        return total;  
    }



int main(){

  vector<int> numbers = {0,1,0,2,1,0,1,3,2,1,2,1};  
  cout << trap(numbers); 
}