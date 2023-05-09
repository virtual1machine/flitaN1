#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXBUFF 500

int GetInteger(void);
bool InputValidation(char *string, int *integer);
int convert(int binary);

int main(void)
{
//taking size of an array
    int cardinality = 0;
    bool CorrectInput = true;

    do
    {
        printf("Cardinality of your array: \n");

        char buffer[MAXBUFF];

        fgets(buffer, MAXBUFF, stdin);
        CorrectInput = InputValidation(buffer, &cardinality);

        if (!CorrectInput)
            printf("Must be positive integer!\n");
    } while (!CorrectInput);

    printf("%i\n", cardinality);
}

int GetInteger(void)
{
}

bool InputValidation(char *string, int *integer)
{
    int i = 0;

    while (isspace(string[i]))
        i++;

    int length = strlen(string);

    if (length == i)
        return false;

    char buff[MAXBUFF];
    int int_chars = 0;

    if ((string[i] == '-') || (!isdigit(string[i])) || string[i] == 0)
        return false;

    while (i < length && !isspace(string[i]))
    {
        if (!isdigit(string[i]))
            return false;

        buff[int_chars] = string[i];

        int_chars++;
        i++;
    }
    buff[int_chars] = '\0';

    while (isspace(string[i]))
        i++;
    if (string[i] != '\0')
        return false;

    *integer = atoi(buff);

    if (*integer == 0)
        return false;

    return true;
}
