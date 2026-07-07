class Solution {
public:
    long long sumAndMultiply(int n) {
        string  s = to_string(n);
        long long  sum =0;
        string tmp = "";
        for( char str : s){
            sum +=str-'0';
            if(str !='0'){

                tmp+=str;
            }

        }
        long long num = tmp.empty() ? 0 : stoll(tmp); 
        return num * sum;
    }
};