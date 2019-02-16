#include <iostream>

using namespace std;

typedef int valueType;

struct ListNode
{
    valueType val;
    ListNode* next;

    ListNode(valueType val, ListNode* next=0)
        : val(val), next(next) {}
};

class LinkedList
{
public:
    ListNode* header;
    ListNode* tail;

    LinkedList();
    void print_list();
    void insert_front(valueType x);
    void append(valueType x);
};

LinkedList::LinkedList()
{
    header = new ListNode(0);
    tail = header;
}

void LinkedList::print_list()
{
      ListNode* node = header->next;
      while(node != 0) {
        cout << node->val << endl;
        node = node->next;
    }
}

void LinkedList::append(valueType x)
{
    ListNode* p = new ListNode(x);
    ListNode* tmp = header;
    while (tmp->next != 0){
      tmp = tmp->next;
    }
    tmp->next = p;
    tail = p;
}

void move(LinkedList arr[], valueType a, valueType b)
{
    arr[b].tail->next = arr[a].header->next;
    arr[b].tail = arr[a].tail;
    arr[a].header->next = 0;
    arr[a].tail = arr[a].header;
}


main()
{
    LinkedList platform[100001];
    int M;
    cin >> M;
    char order;
    int a, b;
    for (int i=0; i<M; i++) {
        cin >> order >> a >> b;
        if (order == 'N') {
            platform[b].append(a);
        }
        else if (order == 'M') {
            if (platform[a].header == platform[a].tail) {
                continue;
            }
            move(platform, a, b);
        }
    }
    for (int i=0; i<100001; i++){
        platform[i].print_list();
    }
 }


