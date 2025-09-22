class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = "";

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int freq1 = it.first;
            char ch1 = it.second;

            //check if the charcter ch1 is already used two times or not
            if(result.size() >= 2 && result[result.size() - 1]== ch1 && result[result.size() - 2] == ch1)
            {
                //proceed to add next avilable character
                
                if(pq.empty())
                {
                    //if pq is empty then break from here and return result
                    break;
                }

                int freq2 = pq.top().first;
                char ch2 = pq.top().second;
                pq.pop();
                result += ch2;
                freq2 -= 1;
                if(freq2 > 0) pq.push({freq2, ch2});

                if(freq1 > 0) pq.push({freq1, ch1});
            }
            else
            {
                result += ch1;
                freq1 -= 1;
                if(freq1 > 0) pq.push({freq1, ch1});
            }
            
        }
        return result;
    }
};