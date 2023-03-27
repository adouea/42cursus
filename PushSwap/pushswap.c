/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:25:11 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/15 14:42:14 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

// Define stack data structure
typedef struct s_stack 
{
    int items[MAX_STACK_SIZE];
    int top;
} t_stack;

// Initialize stack
void init(t_stack *s) 
{
    s->top = -1;
}

// Check if stack is empty
int is_empty(t_stack *s) 
{
    return (s->top == -1);
}

// Check if stack is full
int is_full(t_stack *s) 
{
    return (s->top == MAX_STACK_SIZE - 1);
}

// Push element onto stack
void push(t_stack *s, int x) {
    if (is_full(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = x;
}

// Pop element from stack
int pop(t_stack *s) 
{
    if (is_empty(s)) 
	{
        printf("Stack underflow\n");
        exit(1);
    }
    return (s->items[(s->top)--]);
}

// Find smallest integer in stack
int find_smallest(t_stack *s) 
{
    int smallest;
	int x;

	smallest = pop(s);
    while (!is_empty(s)) 
	{
        x = pop(s);
        if (x < smallest) 
		{
            push(s, smallest);
            smallest = x;
        } 
		else 
            push(s, x);
    }
    return (smallest);
}

// Sort stack using Pushswap algorithm
void push_swap(t_stack *s) 
{
    t_stack b;
	int smallest;
	int x;
    init(&b);
    while (!is_empty(s)) 
	{
        smallest = find_smallest(s);
        push(&b, smallest);
    }
    while (!is_empty(&b)) 
	{
        x = pop(&b);
        push(s, x);
    }
}

// Test the Pushswap algorithm
int main() {
    t_stack s;
    init(&s);
    push(&s, 5);
    push(&s, 2);
    push(&s, 8);
    push(&s, 1);
    push(&s, 6);
    push_swap(&s);
    printf("Sorted stack: ");
    while (!is_empty(&s)) {
        printf("%d ", pop(&s));
    }
    printf("\n");
    return 0;
}

