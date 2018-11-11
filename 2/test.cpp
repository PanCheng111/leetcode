#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        int add = 0;
        while (l1 != NULL || l2 != NULL) {
            int tmp = add;
            if (l1) tmp += l1->val;
            if (l2) tmp += l2->val;
            if (tmp >= 10) { 
                tmp -= 10; 
                add = 1;
            }
            else add = 0;

            if (head == NULL) {
                head = new ListNode(tmp);
                tail = head;
            }
            else {
                tail->next = new ListNode(tmp);
                tail = tail->next;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (add == 1) {
            tail->next = new ListNode(add);
        }
        return head;
    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(8);
    //l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(0);
    //l2->next = new ListNode(6);
    //l2->next->next = new ListNode(4);
    
    Solution s;
    ListNode *ret = s.addTwoNumbers(l1, l2);
    while (ret != NULL) {
        printf("%d->", ret->val);
        ret = ret->next;
    }
    printf("\n");
    return 0;
}