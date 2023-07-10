

#include "libr.h"

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

int search_index(char k){
    if(k == '(' || k == ')'){
        return 1;
    }
    return 0;
}

int is_b(char foot)
{
    return (foot >= 48 && foot <= 57);
}

void get_edit(int f)
{
    if(negative == WEIGHT - 1)
    {
        exit(1);
    }
    negative++;
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

int find_err()
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
    // switch (ch) {
    //     case '(': 
    //         return 0;
    //     break;
    //     case '+': case '-':
    //         return 1;
    //     break;
    //     case '*': case '/': case '%': case '!':
    //         return 2;
    //     break;
    // }
    // return (3);

    if(ch == '(')
    {
        return 0;
    }
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    if(ch == '*' || ch == '/' || ch == '%' || ch == '!')
    {
        return 2;
    }
    return 3;
}

int its_wrong()
{
    if(negative == - 1)
    {
        return 1;
    }
    return 0;
}

int this_index()
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
            while ((x = find_err()) != '(')
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
int character_of_set(char flag)
{
   if (flag == '+' || flag == '-' || flag == '*' || flag == '/' || flag == '%')
        return 1;
    if (flag == '0' || flag == '1' || flag == '2' || flag == '3' ||
        flag == '4' || flag == '5' || flag == '6' || flag == '7' ||
        flag == '8' || flag == '9' || flag == ' ' || flag == '.')
        return 0;
    else
        return -1;
}

// // // // // // // / / //////


#include "libr.h" 

int this_operator_return(char* txt)
{
    int j = 0;
    while(txt[j] != '\0')
    {
        if(txt[j] == '%' || txt[j] == '*' || 
          txt[j] == '+' || txt[j] == '-' || 
          txt[j] == '/')
          {
              return 1;
          }
          j+=1;
    }
    return 0;
}

////////////////////////////////////////////////////////
  
int my_atoi(char* str)
{
    int res = 0;
        for (int i = 0; str[i] != '\0'; ++i)
        {
            if (str[i] > '9' || str[i] <'0')
                return -10; 
        res = res * 10 + str[i] - '0';
        }
    return res;
}

char* my_strcpy(char* param_1, char* param_2){
    for(int i = 0; param_2[i] != '\0'; i++){
        param_1[i] = param_2[i];
    }
    return param_1;
}

void sort_of_input_things(char* dec)
{
    if(!this_operator_return(dec))
    {
        printf(" %d \n", my_atoi(dec));
    }

    char approve[512];
    int k = 0;
    int length, value, number1, number2, ret, call = 0, F;
    int pointer = 0;
    int pointer_of_value;
    my_strcpy(approve, dec);
    length = strlen(approve);
    int places[6];
    while(k < length)
    {
        switch(character_of_set(approve[k]))
        {
            case 0: 
                if(approve[k] == ' ' && call != 0)
                {
                    search_error(value);
                    call = 0;
                    break;
                }
                if(approve[k] == ' ' && call == 0) break;
                call+=1;
                if(approve[k] == '.')
                {
                    pointer = 1;
                    pointer_of_value = value;
                    call = 0;
                    break;
                }
                value = approve[k] - '0';
                places[5] = places[4];
                places[4] = places[3];
                places[3] = places[2];
                places[2] = places[1];
                places[1] = places[0];
                places[0] = value;
                if(call == 1)
                {
                    value = places[0];
                    F = 10;
                }
                if(call == 2)
                {
                    value = (places[1] * 10) + places[0];
                    F = 100;
                }
                if(call == 3)
                {
                    value = (places[2] * 100) + (places[1] *10) + places[0];
                    F = 1000;
                }
                if(call == 4)
                {
                value = (places[3] * 1000) + (places[2] * 100) + (places[1] * 10) + places[0];
                    F = 10000;
                }
                if(call == 5)
                {
                    value = (places[3] * 10000) + (places[2] * 1000) + (places[1] * 100) + (places[1] * 10) + places[0];
                    F = 100000;
                }
                if(pointer == 1  &&  approve[k + 1] == ' ')
                {
                    value = pointer_of_value + (value / F);
                    pointer = 0;
                    break;
                }
                break;
            case -1:
                perror("parse error");
                break;
            case 1:
                number1 = else_err();
                number2 = else_err();
                switch (approve[k])
                {
                    case '+':
                        ret = number2 + number1;
                        break;
                    case '-':
                        ret = number2 - number1;
                        break;
                    case '*':
                        ret = number2 * number1;
                        break;
                    case '/':
                        ret = number2 / number1;
                        break;
                    case '%':
                        ret = (int)number2 % (int)number1;
                        break;
                }
               search_error(ret);
        }
    }
    printf("%d\n", ret);
}

#include "libr.h"

bool is_divide_zero(char* str)
{
    for (int i = 0; str[i + 1] != '\0'; i++)
    {
        if (str[i] == '/' && str[i + 1] == '0') return true;
    }
    return false;
}

bool is_parse_error(const char* str)
{
    for (int t = 0; str[t + 1] != '\0'; t++)
    {
        if (str[t] == '/' || str[t] == '*')
        {
            if (str[t + 1] == '+' || str[t + 1] == '-') return true;
        }
        else if (str[t] == '+' || str[t] == '-')
        {
            if (str[t + 1] == '*' || str[t + 1] == '/') return true;
        }
        else if (str[t] == '(' && str[t + 1] == ')')
        {
            return true;
        }
        else if (str[t] == ')' && str[t + 1] == '(')
        {
            return true;
        }
    }
    return false;
}


bool is_error_string(char* str)
{
    for (int i = 0; str[i + 1] != '\0'; i++)
    {
        if (!character_of_set(str[i]) && !search_index(str[i]) && !is_b(str[i]))
        {
            return true;
        }
    }
    return false;
}

void strip(char* str)
{
    for (int i=0; str[i]!='\0'; i++)
    {
        if(str[i] == ' ')
            memmove(&str[i], &str[i + 1], strlen(str) - i);
    }
}

int main(int ac, char** av)
{
    if (ac == 2)
    {
        char* infix = strdup(av[1]);
        char postfix[strlen(infix)];
        strip(infix);
        // printf("%s\n", infix);
        if (is_divide_zero(infix))
        {
            fprintf(stderr, "divide by zero\n");
            exit(1);
        }
        else if (is_parse_error(infix))
        {
            fprintf(stderr, "parse error\n");
            exit(EXIT_FAILURE);
        }
        else if (is_error_string(infix))
        {
            fprintf(stderr, "parse error\n");
            exit(1);
        }
        infix_to_postfix(infix, postfix);
        sort_of_input_things(postfix);
    }
    return 0;
}