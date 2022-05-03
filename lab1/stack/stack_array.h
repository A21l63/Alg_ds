#ifndef ALG_DS1_STACK_ARRAY_H
#define ALG_DS1_STACK_ARRAY_H
typedef int curr_type;

//Структура стека на массиве

typedef struct {
    curr_type* data;                 //Указатель на хранимые данные
    int last;                        //Номер текущего последнего (верхнего) элемента
    int data_size;                   //Размер data
} stack_a;

stack_a* CreateStack(int size);

curr_type Peek(stack_a* stack);

int Push(stack_a* stack, curr_type a);

curr_type Pop(stack_a* stack);

void RemoveStack(stack_a* stack);

#endif //ALG_DS1_STACK_ARRAY_H
