/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    typedef pair<int, ListNode*> pr ;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* h = new ListNode();
        ListNode* temp = h;
        priority_queue<pr, vector<pr>, greater<pr>> pq;

        int n = lists.size();

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();

            temp->next = new ListNode(t.first);

            temp=temp->next;

            if(t.second->next != NULL)
            {
                pq.push({t.second->next->val, t.second->next});
            }
        }

        return h->next;
    }
};