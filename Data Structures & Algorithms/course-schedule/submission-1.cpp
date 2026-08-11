class Solution {
public:
    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for(auto &p : prerequisites)
        {
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Courses with no prerequisites
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        int completed = 0;

        // Topological sort
        while(!q.empty())
        {
            int course = q.front();
            q.pop();

            completed++;

            for(int next : adj[course])
            {
                indegree[next]--;

                if(indegree[next] == 0)
                    q.push(next);
            }
        }

        return completed == numCourses;
    }
};