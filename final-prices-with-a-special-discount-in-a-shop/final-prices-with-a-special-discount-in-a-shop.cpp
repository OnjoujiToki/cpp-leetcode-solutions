class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        if (prices.size() == 1) return vector<int>{prices[0]};
        stack<int> s;       
        for (int i = 0; i < prices.size(); i++)  {
            int pos = 0;         
            while(!s.empty() && prices[i]<= prices[s.top()]) {
                prices[s.top()] -= prices[i];
                s.pop();
            }
            s.push(i);      
        }
        return prices;
    }
};