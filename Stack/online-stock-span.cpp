class StockSpanner {
   public:
        stack<pair<int, int>> st;
        int time=0;
       
        StockSpanner() {
        }
       
        int next(int price) {
           int span;
           time++;
           while(!st.empty() && st.top().first <= price){
               st.pop();
           }
           if(st.empty()){
               span = time;
           }else{
               span = time - st.top().second;
           }
           st.push({price, time});
           return span;
       }
};
