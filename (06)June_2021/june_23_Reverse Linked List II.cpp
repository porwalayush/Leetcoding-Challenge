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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *pre=NULL,*cur=head;
        while(left>1)
        {
            pre=cur;
            cur=cur->next;
            left--;
            right--;
        }
        ListNode *con=pre,*tail=cur;
        pre=cur;
        cur=cur->next;
        while(right>1)
        {
            ListNode* third=cur->next;
            cur->next=pre;
            pre=cur;
            cur=third;
            right--;
        }
        if(con!=NULL)
        {
            con->next=pre;
        }
        else
            head=pre;
        tail->next=cur;
        return head;
        
    }
};