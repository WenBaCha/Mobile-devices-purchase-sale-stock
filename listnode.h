#ifndef LISTNODE_H
#define LISTNODE_H
#include <QString>
#include "itemwidget.h"
class ListNode
{
public:
    ListNode();
private:
    ItemWidget item;
    ListNode * next;
};

#endif // LISTNODE_H
