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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1==NULL)
            return list2;
        
        if(list2==NULL)
            return list1;
        
        ListNode *dummy=new ListNode(-1);
        ListNode *tail=dummy;
        
        ListNode *curr1=list1;
        ListNode *curr2=list2;
        
        
        while(curr1!=NULL&&curr2!=NULL){
            
            if(curr1->val<curr2->val){
                tail->next=curr1;
                ListNode *next=curr1->next;
                curr1->next=NULL;
                curr1=next;
              
            }
            else {
                 tail->next=curr2;
                ListNode *next=curr2->next;
                curr2->next=NULL;
                curr2=next;
            }
            
            tail=tail->next;
            
        }
        
        if(curr1!=NULL){
            tail->next=curr1;
        }
        
        
        if(curr2!=NULL){
            tail->next=curr2;
        }
        
        return dummy->next;
    }
};