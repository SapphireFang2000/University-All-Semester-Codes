#include <stdio.h>

void removingCommentsWhiteSpace(char *input_file, char *output_file)
{
    FILE *inputFile, *outputFile;
    char ch;
    int slash = 0, multiLineComment = 0, singleLineComment = 0, newline = 0 , space = 0;

    inputFile = fopen(input_file, "r");
    outputFile = fopen(output_file, "w");

    if (inputFile == NULL) 
    {
        printf("Error opening input file\n");
    } 
    else 
    {
        while ((ch = fgetc(inputFile)) != EOF) 
        {
            if (ch == '\n') 
            {
                newline = 1;
            } 
            else 
            {
                newline = 0;
            }
            
            if (ch == '/') 
            {
                slash = 1;
            }

            if (ch == '/' && slash == 1) 
            {
                singleLineComment = 1;
            }

            if (ch == '\n' && singleLineComment == 1) 
            {
                singleLineComment = 0;
            }

            if (ch == '*' && slash == 1) 
            {
                multiLineComment = 1;
            }

            if (ch == '/' && multiLineComment == 1) 
            {
                multiLineComment = 0;
            }

            if(ch != ' ')
            {
                space =0 ;
            }

            if (multiLineComment == 0 && singleLineComment == 0 && newline == 0 && space==0) {
                fputc(ch, outputFile);
            }
            
            if(space == 0 && ch ==' ')
            {
                space= 1;
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    char *input_file = "Input1.c";
    char *output_file = "Output.txt";

    removingCommentsWhiteSpace(input_file, output_file);

    printf("Input File (%s):\n", input_file);
    printf("===================================\n");

    FILE *inputFile = fopen(input_file, "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
    }
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        putchar(ch);
    }
    fclose(inputFile);

    printf("\n\nOutput File:\n");
    printf("===================================\n");

    FILE *outputFile = fopen(output_file, "r");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
    }
    while ((ch = fgetc(outputFile)) != EOF) {
        putchar(ch);
    }
    fclose(outputFile);

    return 0;
}