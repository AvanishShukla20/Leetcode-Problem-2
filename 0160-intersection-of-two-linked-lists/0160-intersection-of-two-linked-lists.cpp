/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(ListNode* h)
    {
        int cnt =0;
        while(h != NULL)
        {
            cnt++;
            h=h->next;
        }

        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = countNodes(headA);
        int n2 = countNodes(headB);
        ListNode* gr = NULL;
        ListNode* sm = NULL;

        if(n2 > n1)
        {
            gr = headB;
            sm = headA;
        }
        else
        {
            gr = headA;
            sm = headB;
        }

        int d = abs(n2 - n1);

        while(d--)
        {
            gr = gr->next;
        }

        while(sm != NULL && sm != gr)
        {
            sm = sm->next;
            gr = gr->next;
        }

        return sm;
    }
};