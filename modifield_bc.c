

#include "libr.h"
#include <stdio.h>
int negative = -1;
int positions[5] = {37, 42, 43, 45, 47};

int places[2] = {40, 41};
 
int search_position(char h){
    int i = 0;
    while(i < 5){
        if(h == positions[i])
        {
            return 1;
        }
        i+=1;
    }
    return 0;
}

bool fff(char k){
    if(k == '(' || k == ')')
    {
        return 1;
    }
    return 0;
}

int is_b(char c)
{
    return (c >= 48 && c <= 57);
}

void get_edit(int f)
{
    if(negative == WEIGHT - 1)
    {
        exit(1);
    }
    negative+=1;
    dev[negative] = f;
}

void search_error(int h)
{
    if(negative == WEIGHT - 1)
    {
        printf("parse error\n");
        exit(1);
    }
    floating[++negative] = h;
}

bool find_err()
{
    if(negative == -1)
    {
        puts("parse error\n");
        exit(1);
    }
    else
    {
        int j;
        j = dev[negative];
        negative= negative - 1;
        return (j);
    }
    
}

int else_err()
{
    return (floating[negative--]);
}

int arithmetic_operations(char ch)
{
    switch (ch) {
        case '(': 
            return 0;
        break;
        case '+': case '-':
            return 1;
        break;
        case '*': case '/': case '%': case '!':
            return 2;
        break;
    }
    return (3);
}

int its_wrong()
{
    if(negative == - 1)
    {
        return 1;
    }
    return 0;
}

bool this_index()
{
    return (dev[negative]);
}

//this function not accomplishied yet . . .
void infix_to_postfix(char* infix, char* postfix)
{
    char x, token;
    int i, j = 0;
    for (i = 0; infix[i]; i++)
    {
        token = infix[i];
        if (isalnum(token) || token == '.')
            postfix[j++] = token;
        else if (token == '(')
            get_edit('(');
        else if (token == ')')
            while ((x = find_err()))
            {
                postfix[j++] = ' ';
                postfix[j++] = x;
            }
        else
        {
            postfix[j++] = ' ';
            while (arithmetic_operations(token) <= arithmetic_operations(this_index()) && !its_wrong())
            {
                x = find_err();
                postfix[j++] = x;
                postfix[j++] = ' ';
            }
            get_edit(token);
        }
    }
    while (!its_wrong())
    {
        x = find_err();
        postfix[j++] = ' ';
        postfix[j++] = x;
    }
    postfix[j] = '\0';
}
int character_of_set(char set)
{
    switch(set)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return 1;
        break;
        default:
            return 0;
    }
    return -1;
}
