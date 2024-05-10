#include<stdio.h>

int sep(char lexeme)
{
    if(lexeme == '\'' || lexeme == ',' || lexeme == ';' || lexeme == '\"')
    {
        return 1;
    }

    return 0;
}

int par(char lexeme)
{
    if(lexeme == '(' || lexeme == ')')
    {
        return 1;
    }

    return 0;
}

int keyword(char lexeme[])
{
    FILE *kw;
    kw = fopen("Keyword.txt","r");
    char c,kwstr[100];
    int i=0,result=0;
    while((c = getc(kw))!=EOF)
    {
        if(!isspace(c))
        {
            kwstr[i] = c;
            i++;
        }
        else
        {
            for(int j=0; j<strlen(kwstr); j++)
            {
                if(kwstr[j]!=lexeme[j])
                {
                    result = 0;
                    break;
                }
                result = 1;
            }
            i = 0;
            if(result==1)
            {
                return result;
            }
            memset(kwstr,0,strlen(kwstr));
        }
    }
    fclose(kw);
    return result;
}

int op(char lexeme[])
{
    FILE *op;
    op = fopen("Operator.txt","r");
    char c,opstr[100];
    int i=0,result=0;
    while((c = getc(op))!=EOF)
    {
        if(!isspace(c))
        {
            opstr[i] = c;
            i++;
        }
        else
        {
            for(int j=0; j<strlen(opstr); j++)
            {
                if(opstr[j]!=lexeme[j])
                {
                    result = 0;
                    break;
                }
                result = 1;
            }
            i = 0;
            if(result==1)
            {
                return result;
            }
            memset(opstr,0,strlen(opstr));
        }
    }
    fclose(op);
    return result;
}

int identifier(char lexeme[])
{
    int i = 0;
    int l=0;
    int s=0;
    if(isalpha(lexeme[i]) || (lexeme[i]=='_'))
    {
        s=1;
        i++;
    }
    else
        s=0;
    l=strlen(lexeme);
    if(s)
    {
        for(; i<l; i++)
        {
            if(isalpha(lexeme[i]) || (lexeme[i]=='_') || isdigit(lexeme[i]))
            {
                s=1;
            }
            else
            {
                s=0;
                break;
            }
        }
    }
    return s;
}

int num(char lexeme[])
{
    int i = 0;
    int l=0;
    int s=0;
    if(isdigit(lexeme[i]))
    {
        s=1;
        i++;
    }
    else if(lexeme[i]=='.')
    {
        s=2;
        i++;
    }
    else s=0;
    l=strlen(lexeme);
    if(s==1)
        for( ; i<l; i++)
        {
            if(isdigit(lexeme[i]))
                s=1;
            else if(lexeme[i]=='.')
            {
                s=2;
                i++;
                break;
            }
            else
            {
                s=0;
                break;
            }
        }
    if(s==2)
        if(isdigit(lexeme[i]))
        {
            s=3;
            i++;
        }
        else
            s=0;
    if(s==3)
        for(; i<l; i++)
        {
            if(isdigit(lexeme[i]))
                s=3;
            else
            {
                s=0;
                break;
            }
        }
    if(s==3) s=1;
    return s;
}

int main()
{
    FILE *ptr1,*ptr2;
    ptr1 = fopen("Input.txt","r");
    ptr2= fopen("Output.txt","w");
    int i=1;
    char c,temp;
    printf("Input:\n");
    while((c=getc(ptr1))!=EOF)  //<
    {
        printf("%c",c);
        if(c == '<' || c == '>' || c == '!' || c == '=')
        {
            temp = c;
            c=getc(ptr1);
            printf("%c",c);
            if(c == '=')
            {
                fprintf(ptr2," %c%c ",temp,c); // <=
            }
            else if( c == '\'')
            {
                fprintf(ptr2," %c %c ",temp,c);
            }
            else
            {
                fprintf(ptr2," %c %c",temp,c);
            }
        }
        else if(c == ',' || c == ';' || c == '+' || c == '-' || c == '/' || c == '*' || c == '(' || c == '"' || c == ')' || c == '\'')
        {
            fprintf(ptr2," %c ",c);
        }
        else
            fputc(c,ptr2);
    }
    fclose(ptr1);
    fclose(ptr2);
    ptr2= fopen("Output.txt","r");
    printf("\nOutput Step 1:\n");
    while((c=getc(ptr2))!=EOF)
    {
        printf("%c",c);
    }
    fclose(ptr2);

    ptr2= fopen("Output.txt","r");
    ptr1 = fopen("Output2.txt","w");

    char lex[100];
    char unknown[100];
    int ln;
    i=0;
    int sp = 0,ucheck = 0;
    while((c=fgetc(ptr2))!=EOF)
    {
        if(!isspace(c))
        {
            lex[i]=c;
            i++;
            sp=0;
        }
        else if(sp != 1)
        {
            sp = 1;
            fputc('[',ptr1);
            if(keyword(lex) == 1)
            {
                fprintf(ptr1,"kw %s",lex);
            }
            else if(sep(lex[0]) == 1)
            {
                fprintf(ptr1,"sep %s",lex);
            }
            else if(identifier(lex) == 1)
            {
                fprintf(ptr1,"id %s",lex);
            }
            else if(num(lex) == 1)
            {
                fprintf(ptr1,"num %s",lex);
            }
            else if(op(lex) == 1)
            {
                fprintf(ptr1,"op %s",lex);
            }
            else if(par(lex[0]) == 1)
            {
                fprintf(ptr1,"par %s",lex);
            }
            else
            {
                fprintf(ptr1,"unkn %s",lex);
                ucheck = 1;
                ln=strlen(lex);
                for(int i=0; i<ln; i++)
                {
                    unknown[i]=lex[i];
                }
            }
            fprintf(ptr1,"] ");
            i = 0;
            memset(lex,0,strlen(lex));
        }
    }
    fclose(ptr2);
    fclose(ptr1);

    ptr2= fopen("Output2.txt","r");
    printf("\nOutput 2:\n");
    while((c=getc(ptr2))!=EOF)
    {
        printf("%c",c);
    }
    fclose(ptr2);

    if(ucheck)
        printf("\n\n Unknown lexeme found and the lexeme is ");
    for(int i=0; i<ln; i++)
    {
        printf("%c",unknown[i]);
    }

    printf("\n");
    return 0;
}
