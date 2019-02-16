#include <iostream>
#include <cstdlib>

using namespace std;

typedef int valueType;

struct ListNode
{
    valueType val;
    ListNode* next;

    ListNode(valueType val, ListNode* next=0)
        : val(val), next(next) {}
};

void insert_front(ListNode* header, valueType x)
{
    ListNode* p = new ListNode(x);
    if (header->next != 0){
        p->next = header->next;
    }
    header->next = p;
}

void append(ListNode* header, valueType x)
{
    ListNode* p = new ListNode(x);
    ListNode* tmp = header;
    while (tmp->next != 0){
      tmp = tmp->next;
    }
    tmp->next = p;
}

void rollleft(ListNode*& header) {
    ListNode* tmp = header;
    ListNode* real_header = header->next->next;
    while (tmp->next != 0){
      tmp = tmp->next;
    }
    tmp->next = header->next;
    header->next->next = 0;
    header->next = real_header;
}

void rollright(ListNode*& header) {
    ListNode* tmp = header;
    int cnt;
    while (tmp->next != 0){
      tmp = tmp->next;
      cnt++;
    }
    tmp->next = header->next;
    header->next = tmp;
    tmp = header;
    for (int i=0; i<cnt; i++) {
        tmp = tmp->next;
    }
    tmp->next = 0;
}

void print_list(ListNode* node)
{
    while(node != 0) {
        cout << node->val << endl;
        node = node->next;
  }
}

main()
{
    int M;
    cin >> M;
    string order;
    int num, cnt = 0;
    ListNode* header = new ListNode(0);
    for (int i=0; i<M; i++) {
        cin >> order;
        if(order == "li") {
            cin >> num;
            insert_front(header, num);
            cnt++;
        }
        else if(order == "ri") {
            cin >> num;
            append(header, num);
            cnt++;
        }
        else if(order == "rr") {
            if (cnt > 1) rollright(header);
        }
        else if(order == "lr") {
            if (cnt > 1) rollleft(header);
        }
    }
    print_list(header->next);
}