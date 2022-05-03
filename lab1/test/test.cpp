#include "gtest/gtest.h"
#include "stack_array.cpp"
#include "stack_list.cpp"

TEST(List, NullHead)
{
    node *head;
    EXPECT_EQ(1, CheckNullHead(head));
}
TEST(List, NotNullHead)
{
    node *head;
    PushList(&head, 12);
    EXPECT_EQ(0, CheckNullHead(head));
}

TEST(List, Init)
{
    node * head = Init();
    EXPECT_NE(nullptr, head);
    free(head);
}

TEST(List, testPeekOk) {
    node *stack = Init();
    node node1 = {1, stack};
    EXPECT_EQ(PeekList(&node1), 1);
    delete(stack);
}

TEST(List, testPeekNull) {
    node *stack = Init();
    EXPECT_EQ(PeekList(stack), 0);
    delete(stack);
}

TEST(List, testPush) {
    node *stack = Init();
    PushList(&stack, 2);
    EXPECT_EQ(stack->value, 2);
    delete(stack);
}

TEST(List, PopNull) {
    // initialize new stack with zero len
    node *stack = Init();
    EXPECT_EQ(PopList(&stack), 0);
    delete(stack);
}

TEST(List, PopOk) {
    node *stack = Init();
    PushList(&stack, 21);
    EXPECT_EQ(PopList(&stack), 1);
    delete(stack);
}

TEST(Array, checkNull){
    stack_a *arr = NULL;
    EXPECT_EQ(CheckNullStack(arr), 1);
}

TEST(Array, createStack) {
    stack_a *arr = CreateStack(120);
    EXPECT_EQ(CheckNullStack(arr), 0);
    EXPECT_EQ(arr->data_size, 120);
}

TEST(Array, push){
    stack_a *stack_arr = CreateStack(0);
    Push(stack_arr, 1);
    EXPECT_EQ(stack_arr->data[stack_arr->last - 1], 1);
    EXPECT_EQ(stack_arr->data_size, 1);
    Push(stack_arr, 2);
    EXPECT_EQ(stack_arr->data[stack_arr->last - 1], 2);
    EXPECT_EQ(stack_arr->data_size, 2);
}

TEST(Array, peek) {
    stack_a *stack_arr = CreateStack(1);
    *stack_arr->data = 12;
    EXPECT_EQ(Peek(stack_arr), 12);
}

TEST(Array, pop){
    stack_a *stack_arr = CreateStack(2);
    *stack_arr->data = 12;
    *(++stack_arr->data) = 122;
    Pop(stack_arr);
    EXPECT_EQ(stack_arr->data[stack_arr->last - 1], 12);
}