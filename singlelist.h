#ifndef SINGLELIST_H
#define SINGLELIST_H
#include "listnode.h"

class SingleList
{
public:
    SingleList();

private:
    ListNode *head;

    void initList();
    void append(ListNode &l);//在链表尾插入元素
};

#endif // SINGLELIST_H
