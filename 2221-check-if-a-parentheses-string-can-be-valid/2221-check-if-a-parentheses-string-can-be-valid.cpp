class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if((n&1) || (locked[0]=='1' && s[0]==')') || (locked[n-1]=='1' && s[n-1]=='(')) return false;

        stack<int> lock;
        stack<int> unlock;

        for(int i=0;i<n; i++){
            if(locked[i]=='1'){
                if(s[i]=='('){
                    lock.push(i);
                }
                else{
                    if(!lock.empty())
                        lock.pop();
                    else if(!unlock.empty())
                        unlock.pop();
                    else 
                        return false;
                }
            }
            else
                unlock.push(i);
        }
        while(!lock.empty() && !unlock.empty()){
            if(lock.top() < unlock.top()){
                lock.pop();
                unlock.pop();
            }
            else return false;
        }
        return lock.empty();
    }
};