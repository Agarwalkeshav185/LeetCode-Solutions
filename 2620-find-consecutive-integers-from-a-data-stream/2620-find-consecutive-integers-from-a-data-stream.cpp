class DataStream {
public:
    int val, count;
    queue<int> q;
    int sameCount = 0;
    DataStream(int value, int k) {
        val = value;
        count = k;
    }
    
    bool consec(int num) {
        if(q.size() == count){
            if(q.front() == val) sameCount--;
            q.pop();
        }
        q.push(num);
        if(num == val) sameCount++;

        return q.size() == count && sameCount == count;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */