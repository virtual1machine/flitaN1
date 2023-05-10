#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXBUFF 4096

bool CardinalityValidation(char *string, int *integer);
bool BinaryValidation(char *string, long long *integer);
long long BinToDec(long long BinaryDigit);
void ArrayPrint(long long array[], int cardinality);

int main(void)
{
//cardinality of an arrays
    int cardinality = 0;
    bool CorrectInput = true;
    do {
        printf("Cardinality of your array: \n");

        char buffer[MAXBUFF];
        fgets(buffer, MAXBUFF, stdin);

        CorrectInput = CardinalityValidation(buffer, &cardinality);
        if (!CorrectInput)
            printf("Must be positive integer!\n");
    } while (!CorrectInput);

//setting and filling array of binaries
    long long BinArray[cardinality];
    bool CorrectBinary = true;

    for (int j = 0; j < cardinality; j++) {
        do {
            printf("Element %i:", j+1);

            char BinBuffer[MAXBUFF];
            fgets(BinBuffer, MAXBUFF, stdin);

            CorrectBinary = BinaryValidation(BinBuffer, &(BinArray[j]));

            if (!CorrectBinary)
                printf("Must be binary digit!\n");
        } while (!CorrectBinary);
    }
//converting
    long long DecArray[cardinality];
    for (int i = 0; i < cardinality; i++)
    {
        DecArray[i] = BinToDec(BinArray[i]);
    }
    printf("Binary digits array:\n");
    ArrayPrint(BinArray, cardinality);
    printf("This array in decimal system:\n");
    ArrayPrint(DecArray, cardinality);
}

bool CardinalityValidation(char *string, int *integer)
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

    while (i < length && !isspace(string[i])) {
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

    *integer = (long) atoi(buff);
    if (*integer == 0)
        return false;

    return true;
}
bool BinaryValidation(char *string, long long *integer)
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

    while (i < length && !isspace(string[i])) {
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

    for (int k = 0; k < int_chars; k++) {
        if (buff[k] < '0' || buff[k] > '1')
            return false;
    }

    *integer = atoi(buff);

    return true;
}
long long BinToDec(long long BinaryDigit)
{
    int num = BinaryDigit;
    int DecimalDigit = 0;

    int base = 1;
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        DecimalDigit += last_digit * base;

        base = base * 2;
    }
    return DecimalDigit;
}
void ArrayPrint(long long array[], int cardinality)
{
    printf("{ ");
    for (int i = 0; i < cardinality; i++)
    {
        printf("%i ", array[i]);
    }
    printf("}\n");
}
