class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        vector<int> indegree(numCourses,0);
        for(int i=0;i<n; i++){
            indegree[prerequisites[i][0]]++;
        }
        for(int i=0;i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> cnt;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(cnt.size() == numCourses) return true;
        return false;

    }
};