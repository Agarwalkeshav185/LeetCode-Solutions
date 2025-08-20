class RLEIterator {
public:
    vector<int> encoded;
    int curind = 0;
    RLEIterator(vector<int>& encoding) {
        encoded = encoding;
    }
    int next(int n) {
        if(curind >= encoded.size()) return -1;
        while(curind<encoded.size() && n!=0){
            if(encoded[curind] == n){
                int ans = encoded[curind+1];
                curind +=2;
                return ans;
            }
            else if(encoded[curind] < n ) {
                n -= encoded[curind];
                curind+=2;
            }
            else {
                encoded[curind] -= n;
                return encoded[curind+1];
            }
        } 
        return -1;  
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */