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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* dummyList=new ListNode();
        dummyList->next=head;
        ListNode* pTemp;
        pTemp=dummyList;
        int size=0,i=0;
        while(temp)
        {
            size++;
            temp=temp->next;
        }
        
        cout<<"Size of List :"<<size<<" ";
        while(head)
        {
            if(n==size-i)
            {
                pTemp->next=head->next;
            }
            else{
                pTemp=head;
            }
            head=head->next;
            i++;
        }

        return dummyList->next;
    }
};