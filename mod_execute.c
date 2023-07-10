#include "lib.h" 

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
                places[5] = places[5-1];
                places[5-1] = places[5-2];
                places[5-2] = places[5-3];
                places[5-3] = places[5-4];
                places[5-4] = places[0];
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