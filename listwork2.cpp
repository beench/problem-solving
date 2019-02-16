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

void free_list(ListNode*& header, int k)
{
    ListNode* p = header;
    for (int i=0; i<k-1; i++){
        p = p->next;
    }
    ListNode* nxt = p->next;
    p->next = nxt->next;
    nxt->next = 0;
    free(nxt);
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
    char order;
    int num, cnt = 0;
    ListNode* header = new ListNode(0);
    for (int i=0; i<M; i++) {
        cin >> order >> num;
        if(order == 'I') {
            insert_front(header, num);
            cnt++;
        }
        else if(order == 'D') {
            if (num <= cnt){
                free_list(header, num);
                cnt--;
            }
        }
        else if(order == 'A') {
            append(header, num);
            cnt++;
        }
    }
    print_list(header->next);
}