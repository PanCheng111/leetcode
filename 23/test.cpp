#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        int totNum = 0;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while (true) {
            bool flag = false;
            int min = 2147483647, idx = -1;
            for (int i = 0; i < len; i++)
                if (lists[i] != NULL && lists[i]->val < min) {
                    min = lists[i]->val;
                    idx = i;
                    flag = true;
                }
            if (!flag) break;
            //printf("pick list[%d]\n", idx);
            if (head == NULL) {
                head = new ListNode(lists[idx]->val);
                tail = head;
                lists[idx] = lists[idx]->next;
            }
            else {
                tail->next = new ListNode(lists[idx]->val);
                tail = tail->next;
                lists[idx] = lists[idx]->next;
            }
        }
        return head;
    }
};

int main() {
    Solution s;
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(4);
    ListNode *c = new ListNode(5);
    a->next = b;
    b->next = c;

    ListNode *d = new ListNode(1);
    ListNode *e = new ListNode(3);
    ListNode *f = new ListNode(4);
    d->next = e;
    e->next = f;

    ListNode *g = new ListNode(2);
    ListNode *h = new ListNode(6);
    g->next = h;

    vector<ListNode *> list;
    list.push_back(a);
    list.push_back(d);
    list.push_back(g);

    ListNode *ret = s.mergeKLists(list);
    while (ret != NULL) { printf("%d, ", ret->val); ret = ret->next; }
    printf("\n");
    return 0;
}
