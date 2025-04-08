/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    var ans =0;
    let i=0,j=height.length-1;
    while(i<j){
        let temp = Math.min(height[i],height[j])*(j-i);
        ans = Math.max(ans,temp);
        if(height[i]>height[j]){
            j--;
        }
        else{
            i++;
        }
    }
    return ans;

};