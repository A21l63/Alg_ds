#include <iostream>
#include "stack_array.h"
#include "stack.h"

int CheckNullStack(stack_a* stack) {
    return stack == NULL;
}

stack_a* CreateStack(int size) {
    stack_a* stack = (stack_a*)malloc(sizeof(stack_a));
    if (CheckNullStack(stack)) {
        return NULL;
    }
    stack->data_size = size;
    stack->last = 0;
    stack->data = (curr_type*) malloc(sizeof(curr_type) * stack->data_size);
    if (stack->data == NULL) {
        free(stack);
        return NULL;
    }
    return stack;
}

curr_type Peek(stack_a* stack) {
    return *(stack->data + stack->last);
}

//Функция Push (добавление элемента)

int Push(stack_a* stack, curr_type value) {
    if (stack->last < stack->data_size)
        stack->data[stack->last++] = value;
    else
    {
        curr_type* tmp = NULL;
        tmp = (curr_type *)realloc(stack->data, (++stack->last) * sizeof(curr_type));
        if (tmp == NULL)
            return 0;
        stack->data = tmp;
        stack->data[stack->last++] = value;
        stack->data_size++;
    }
    return 1;
}

//Функция Pop (Удаление элемента с возвращением)

curr_type Pop(stack_a* stack) {
    if (!CheckNullStack(stack) && stack->last > 0) {
        stack->last--;
        return 1;
    }
    return 0;
}

//Функция RemoveStack (удаление стека)

void RemoveStack(stack_a* stack) {
    if (!CheckNullStack(stack)) {
        free(stack->data);
        free(stack);
    }
}