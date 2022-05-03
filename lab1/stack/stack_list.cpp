#include "stack_list.h"
#include <cstdlib>
#include <cstdio>
#include "iostream"
/*
Работа со стеком на списке
*/

//Сначала создаем node* ... = NULL

//Функция CheckNullHead (проверка верхнего элемента на NULL)

node* Init(void){
    node * head = nullptr;
    head = (node*) malloc(sizeof(node));
    if (head != nullptr)
        head->next = nullptr;
    else
        return nullptr;
    return head;
}

int CheckNullHead(node* head)
{
    if (head == nullptr || head->next == nullptr)
        return 1;
    else
        return 0;
}

//Функция Push (добавление элемента)

int PushList(node **head, curr_type value) {
    node* elem;
    elem = (node *) malloc(sizeof(node));
    if (elem == NULL)
        return 0;
    elem->value = value;
    elem->next = *head;
    (*head) = elem;
    return 1;
}

//Функция Pop (Удаление элемента с возвращением)

int PopList(node **head) {
    if (CheckNullHead(*head) == 0)
    {
        node* q = *head;
        *head = q->next;
        free(q);
        return 1;
    }
    else
        return 0;
}

//Функция Peek (Возвращение элемента без удаления)

curr_type PeekList(node *head) {
    return CheckNullHead(head) ? 0 : head->value;
}
