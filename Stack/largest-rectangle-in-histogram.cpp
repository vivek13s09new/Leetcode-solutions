class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> s;
        int n=heights.size();
        vector<int> RSE(n, 0); // next smaller element index on the right
        vector<int> LSE(n, 0); // next smaller element index on the left
        s.push(0);
        LSE[0] =-1;
        for (int i = 1 ; i < n ; i++){
            while(!s.empty() && heights[i] <= heights[s.top()])
                s.pop();
            if(s.empty())
                LSE[i] = -1;
            else
                LSE[i] = s.top();
            s.push(i);
        }
        while(s.empty() == false)
            s.pop();
        
        s.push(n-1);
        RSE[n-1] = n;
        for(int i = n-2; i >=0; i--){
            while(!s.empty() && heights[i] <= heights[s.top()])
                s.pop();
            if(s.empty())
                RSE[i] = n;
           else
               RSE[i] = s.top();
        s.push(i);
        }
         
        while(s.empty() == false)
            s.pop();
        
        int maxarea = 0;
        for(int i = 0; i <n ; i++){
            int width = RSE[i] - LSE[i] - 1;
            int area = heights[i] * width;
            if(area > maxarea){
              maxarea =  area;  
            }
        }
        return maxarea;
    }
};
