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
    
    ListNode *findMid(ListNode *head){
        
        if(head==NULL||head->next==NULL) 
            return head;
    
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(slow!=NULL&&fast->next!=NULL&&fast->next->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *node=slow->next;
        slow->next=NULL;
        
        return node;
        
    }
    
    ListNode* merge(ListNode* list1, ListNode* list2) {
        
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
    
    ListNode* MergeSort(ListNode *head){
        
        if(head==NULL||head->next==NULL){
            return head;
        }
        
        ListNode* mid=findMid(head);
        
        ListNode* left=MergeSort(head);
        ListNode* right=MergeSort(mid);
        
        return merge(left,right);
    }
    
          
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
            if(list1==NULL)
            return list2;
        
        if(list2==NULL)
            return list1;
        
        ListNode *curr=list1;
        
        while(curr->next!=NULL){
            
            curr=curr->next;
        }
        
        curr->next=list2;
        
       return MergeSort(list1);
        
        
       
    }
};