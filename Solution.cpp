

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        
        int sum = l1->val + l2->val ;
        int carry = sum/10;
        ListNode* currentl1 = l1;
        ListNode* currentl2 = l2;
        ListNode* resultHead = new ListNode(sum%10);
        ListNode* previousResultNode = resultHead;
        currentl1 = currentl1->next;
        currentl2 = currentl2->next;
        
        while(currentl1 != NULL and currentl2 != NULL){
            sum = currentl1->val + currentl2->val + carry;
            carry = sum/10;
            ListNode* result = new ListNode(sum%10);
            previousResultNode->next = result;
            previousResultNode = result;
            
            currentl1 = currentl1->next;
            currentl2 = currentl2->next;
        }
        
        while(currentl1 != NULL){
            sum = currentl1->val + carry;
            carry = sum/10;
            
            ListNode* result = new ListNode(sum%10);
            previousResultNode->next = result;
            previousResultNode = result;
            
            currentl1 = currentl1->next;
        }
        
        while(currentl2 != NULL){
            sum = currentl2->val + carry;
            carry = sum/10;
            
            ListNode* result = new ListNode(sum%10);
            previousResultNode->next = result;
            previousResultNode = result;
            
            currentl2 = currentl2->next;
        }
        
        if(carry != 0){
            ListNode* result = new ListNode(carry);
            previousResultNode->next = result;
            previousResultNode = result;
        }
        
        return resultHead;
    }
};
