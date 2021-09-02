// d_list.c - 2021年 九月 02日
// 双链表ADT

typedef int Item;

typedef struct node Node;

typedef Node *List;

void list_init(List *pl);

unsigned int list_count(List list);

void list_append(List *pl, Item *pi);

void list_delete(List *pl, Item *pi);

void list_insert(List list, Item *pi, Item *pos);

void list_clean(List *pl);