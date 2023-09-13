class Solution {
private:
    void solve(string digits,string output,vector<string>& v,int index,string map[]){
        //base 
        if(index>=digits.size()){
            v.push_back(output);
            return;
        }

        int digit = digits[index]-'0';
        string value = map[digit];
        for(int i =0; i<value.size();i++){
            output.push_back(value[i]);
            solve(digits,output,v,index+1,map);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        string output;
        int index= 0;
        if(digits.size()==0){
            return v;
        }
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,v,index,map);
        return v;
    }
};