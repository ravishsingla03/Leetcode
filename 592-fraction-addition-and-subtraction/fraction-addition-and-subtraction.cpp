using namespace std;
class Solution {
public:
    string fractionAddition(string exp) {
        int n = exp.size();
        int numer =0;
        int deno =1;

        int i=0;
        while(i<n){
            int sign =1;
            if(exp[i]=='-' || exp[i]=='+'){
                if(exp[i]=='-') sign =-1;
                i++;
            }

            int num = 0;
            while(i<n && isdigit(exp[i])){
                num = num*10 + (exp[i] - '0');
                i++;
            }

            i++;

            int den =0;
            while(i<n && isdigit(exp[i])){
                den = den*10 + (exp[i] - '0');
                i++;
            }
            
            num = num*sign;

            numer = numer* den + num * deno;
            deno = deno* den;
            int gcdval = gcd(abs(numer),deno);
            numer = numer/gcdval;
            deno = deno/gcdval;
        }
        
        return to_string(numer)+ "/" + to_string(deno);
    }
};