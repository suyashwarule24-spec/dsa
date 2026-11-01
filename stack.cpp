// Extracted from Assignment_No_6_Vedant_Wagh.pdf
#include <stdio.h>
 #include <ctype.h>

 #define MAX 100

 char stack[MAX];
 int top = -1;

 void push(char ch)
 {
     stack[++top] = ch;
 }

 char pop()
 {
     return stack[top--];
 }

 int precedence(char ch)
 {
     if (ch == '^')
         return 3;
     else if (ch == '*' || ch == '/')
         return 2;
     else if (ch == '+' || ch == '-')
         return 1;
     else
         return 0;
 }

 void infixToPostfix(char infix[], char postfix[])
 {
     int i, j = 0;
     char ch;

     top = -1;

     for (i = 0; infix[i] != '\0'; i++)
     {
         ch = infix[i];

         if (isalnum(ch))
         {
             postfix[j++] = ch;
         }

         else if (ch == '(')
         {
             push(ch);
         }

         else if (ch == ')')
         {
             while (stack[top] != '(')
             {
                 postfix[j++] = pop();
             }

             pop();
         }

         else
         {
             while (top != -1 &&
                    stack[top] != '(' &&

                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[])
{
    int value[MAX];
    int vtop = -1;

    int i, a, b;
    char ch;
    int values[26] = {0};

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isalpha(postfix[i]))
        {
            ch = postfix[i];

            if (values[ch - 'a'] == 0)
            {
                printf("Enter value of %c: ", ch);
                scanf("%d", &values[ch - 'a']);
            }
        }
    }

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if (isalpha(ch))
        {
            value[++vtop] = values[ch - 'a'];
        }
        else
        {
            b = value[vtop--];
            a = value[vtop--];

            switch (ch)
            {
                case '+':
                    value[++vtop] = a + b;
                    break;

                case '-':
                    value[++vtop] = a - b;
                    break;

                case '*':
                    value[++vtop] = a * b;
                    break;

                case '/':
                    value[++vtop] = a / b;
                    break;

                case '^':
                    value[++vtop] = 1;
                    break;
            }
        }
    }

    return value[vtop];
}

 int main()
 {
     char infix[MAX];
     char postfix[MAX];
     int result;

     printf("Enter infix expression: ");
     scanf("%s", infix);

     infixToPostfix(infix, postfix);

     printf("\nPostfix expression: %s", postfix);

     result = evaluatePostfix(postfix);

     printf("\nResult = %d\n", result);

     return 0;
 }
