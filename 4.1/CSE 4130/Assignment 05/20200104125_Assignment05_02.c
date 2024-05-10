#include <stdio.h>
#include <stdlib.h>

void Exp();
void Term();
void Factor();
void match(char symbol);

void error()
{
    printf("Invalid expression\n");
    exit(1);
}

void Exp()
{
    Term();
    char op = getchar();
    if (op == '+' || op == '-')
    {
        Term();
    }
    else
    {
        ungetc(op, stdin);
    }
}

void Term()
{
    Factor();
    char op = getchar();
    if (op == '*' || op == '/')
    {
        Factor();
    }
    else
    {
        ungetc(op, stdin);
    }
}

void Factor()
{
    char symbol = getchar();
    if (symbol == '(')
    {
        Exp();
        match(')');
    }
    else if (symbol == 'a' || symbol == 'b' || symbol == 'c' || symbol == 'd' || symbol == 'e')
    {

    }
    else if (symbol >= '0' && symbol <= '9')
    {

    }
    else
    {
        error();
    }
}

void match(char symbol)
{
    char input;
    scanf(" %c", &input);
    if (input != symbol)
    {
        error();
    }
}

int main()
{
    Exp();

    if (getchar() != '\n')
    {
        error();
    }

    printf("Valid expression\n");

    return 0;
}
