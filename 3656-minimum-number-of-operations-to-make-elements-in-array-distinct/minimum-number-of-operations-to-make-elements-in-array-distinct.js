/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function(nums) {
    var mp =[];
    for(let i = nums.length-1;i>=0;i--){
        if(mp[nums[i]]){
            var temp = i/3;
            return parseInt(temp) + 1;
        }
        mp[nums[i]]=1;
    }
    return 0;
};