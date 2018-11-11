#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class LRUCache {
private:
    struct Node {
        int key, value;
        Node *next, *prev;
        Node(int _key, int _value) : key(_key), value(_value) {
            next = prev = NULL;
        }
    };

    int size, used;
    map<int, Node *> dict;
    Node *head;
    Node *tail;

    void moveToLRU(Node *entry) {
        if (entry == head) return;
        if (tail == entry) tail = entry->prev;
        if (tail == NULL) tail = entry;
        tail->next = NULL;
        if (entry->prev != NULL) entry->prev->next = entry->next;
        if (entry->next != NULL) entry->next->prev = entry->prev;
        entry->next = head;
        if (head) head->prev = entry;
        head = entry;
    }

public:
    LRUCache(int capacity) {
        size = capacity;
        head = NULL;
        tail = NULL;
        used = 0;
    }
    
    int get(int key) {
        if (dict.find(key) == dict.end()) return -1;
        Node *entry = dict[key];
        moveToLRU(entry);
        return entry->value;
    }
    
    void put(int key, int value) {
        if (dict.find(key) == dict.end()) {
            Node *entry = new Node(key, value);
            dict.insert(make_pair(key, entry));
            if (head == NULL) {
                head = entry;
                tail = entry;
            }
            else {
                entry->next = head;
                head->prev = entry;
                head = entry;
            }
            used ++;
            if (used > size) {
                used --;
                Node *tmp = tail->prev;
                dict.erase(tail->key);
                delete tail;
                if (tmp != NULL) {
                    tmp->next = NULL;
                    tail = tmp;
                }
                else {
                    tail = NULL;
                    head = NULL;
                }
            }
        }
        else {
            Node *entry = dict[key];
            entry->value = value;
            moveToLRU(entry);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
    LRUCache cache(2);// = new LRUCache( 2 /* capacity */ );

    cache.put(1, 1);
    cache.put(2, 2);
    printf("%d\n", cache.get(1));       // returns 1
    cache.put(3, 3);    // evicts key 2
    printf("%d\n", cache.get(2));       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    printf("%d\n", cache.get(1));       // returns -1 (not found)
    printf("%d\n", cache.get(3));       // returns 3
    printf("%d\n", cache.get(4));       // returns 4
    printf("\n");
    //["LRUCache","put","put","get","get","put","get","get","get"]
    //[[2],[2,1],[3,2],[3],[2],[4,3],[2],[3],[4]]
    LRUCache l(2);
    l.put(2, 1);
    l.put(3, 2);
    printf("%d\n", l.get(3));
    printf("%d\n", l.get(2));
    l.put(4, 3);
    printf("%d\n", l.get(2));
    printf("%d\n", l.get(3));
    printf("%d\n", l.get(4));

    return 0;
}