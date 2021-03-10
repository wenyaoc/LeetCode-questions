class Solution {
public:
    long calculate(string s) {
        stack<int> stk;
        //int cur = 0;
        int n = s.length();
        long long res = 0, tmp = 0;
        int flag = 1;
        //+/-决定的是它后面的数字是否需要取反
        //也就是+/-号的时候计算这个符号前面的数字,看的是上一次的符号(记录在flag)
        for(int i=0; i<n; ++i) {
            if(s[i] >= '0' && s[i] <= '9') {
                //数字,归到目前的tmp里面
                tmp = tmp*10 + s[i] - '0';
            } else if (s[i] == '+') {
                res += flag * tmp;
                flag = 1;
                //重置tmp,记录下一个操作数
                tmp = 0;   
            } else if (s[i] == '-') {
                res += flag * tmp;
                flag = -1;
                tmp = 0;
            } else if (s[i] == '(') {
                stk.push(res);
                stk.push(flag);
                //类似于递归的过程,恢复到calculate一开始的变量状态
                res = 0;
                flag = 1;
                //tmp = 0; 这个其实不需要,因为合法的公式能够保证这个时候的tmp一定是0
            } else if (s[i] == ')') {
                //要先把剩下的括号内的内容算完
                res += flag * tmp;
                res *= stk.top(); //括号前的flag
                stk.pop();
                res += stk.top(); //括号前的res
                stk.pop();
                tmp = 0; //这里的tmp跟+/-后要重置tmp是一样的
            } //else的情况都是空格,可以不用处理
        }
        //因为最后一个肯定是数字,上面的for循环中对于数字只是把他们记录在了tmp里面,所以最后要把最后一个操作数算上
        return res + flag * tmp; 

        
        /*long Op;
        for (char c : s) {
            if (c == ' ') continue;
            if (c != ')') {
                if (c=='+'||c =='-'||c=='('|| stack.empty()) stack.push_back(long(c-'0'));
                else if (stack.back()!='+'-'0'&&stack.back()!='-'-'0'&& stack.back()!='('-'0') {
                    long pre = stack.back();
                    //cout << pre<<endl;
                    stack.pop_back();
                    stack.push_back(pre * 10 + (c - '0'));
                } else {
                    stack.push_back(long(c-'0'));
                }
            } else {
                long sum = 0;
                while (stack.back() != '('-'0') {
                    int currChar = stack.back();
                    stack.pop_back();
                    Op = stack.back();
                    if (Op == '-'-'0') {
                        sum = sum -currChar;
                        stack.pop_back();
                    } else {
                        sum += currChar;
                        if (Op == '+'-'0') stack.pop_back();
                    }
                }
                stack.pop_back();
                stack.push_back(sum);
            }
        }
        long ans = 0;
        while(!stack.empty()) {
            long currChar = stack.back();
            stack.pop_back();
            if (stack.empty()) {
                ans += currChar;
                break;
            }
            Op = stack.back();
            if (Op == '-'-'0') {
                ans = ans -currChar;
                stack.pop_back();
            } else {
                ans += currChar;
                stack.pop_back();
            }
        }
        return ans;*/
    }
};
