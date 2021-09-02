// d_list.c - 2021年 九月 02日
// 实现双链表

#include <stdio.h>
#include <stdlib.h>
#include "d_list.h"

struct node {
	Item item;
	struct node *next;
	struct node *prev;
};

/**
 * 初始化链表
 */
void list_init(List *pl)
{
	*pl = NULL;
}

/**
 * 统计链表的节点数
 */
unsigned int list_count(List list)
{
	Node *pn = list;
	unsigned int count = 0;

	while (pn != NULL) {
		pn = pn->next;
		count++;
	}

	return count;
}

/**
 * 向链表末尾添加一个节点
 */
void list_append(List *pl, Item *pi)
{
	Node *pn_new = (Node *)malloc(sizeof(Node));

	if (pn_new == NULL) {
		puts("内存不足，无法添加节点！");
		return;
	}

	pn_new->item = *pi;
	pn_new->next = NULL;

	if (*pl == NULL) {
		pn_new->prev = NULL;
		*pl = pn_new;
	} else {
		Node *pn = *pl;
		while (pn->next != NULL)
			pn = pn->next;
		pn->next = pn_new;
		pn_new->prev = pn;
	}
	puts("添加节点成功！");
}

/**
 * 删除指定节点
 */
void list_delete(List *pl, Item *pi)
{
	// 删除头节点
	if ((*pl)->item == *pi) {
		if (list_count(*pl) == 1) {
			free(*pl);
			*pl = NULL;
		} else {
			List head = (*pl)->next;
			head->prev = NULL;
			free(*pl);
		}
	} else {
		Node *pn = *pl;
		while (pn->item != *pi)
			pn = pn->next;
		pn->prev->next = pn->next;
		pn->next->prev = pn->prev;
	}
	puts("删除节点成功！");
}

/**
 * 向链表的指定位置处插入节点
 */
void list_insert(List list, Item *pi, Item *pos)
{
	Node *pn = list;
	Node *pn_new = (Node *)malloc(sizeof(Node));

	pn_new->item = *pi;

	while ((list->item != *pos) && (pn->next->item != *pos))
		pn = pn->next;

	pn->next = pn_new;
	pn_new->prev = pn;
	pn_new->next = pn->next;
	pn->next->prev = pn_new;
}

/**
 * 清空链表
 */
void list_clean(List *pl)
{
	Node *pn = *pl;
	Node *pn_save;

	while (pn != NULL) {
		pn_save = pn->next;
		free(pn);
		pn = pn_save;
	}
	puts("清空链表成功！");
}