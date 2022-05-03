#ifndef ALG_DS1_STACK_LIST_H
#define ALG_DS1_STACK_LIST_H
#pragma once

#include "stack.h"

//Структура узла

typedef struct node {
    curr_type value;                 //Хранимое значение
    struct node *next;               //Указатель на предыдущий элемент стека
} node;

node* Init(void);

int CheckNullHead(node* head);

int PushList(node **head, curr_type value);

curr_type PopList(node **head);

curr_type PeekList(node *head);

#endif //ALG_DS1_STACK_LIST_H
