#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1000

void eliminar_zeros(char *str)
{
    while (*str == '0' && *(str + 1) != '\0')
    {
        str++;
    }
    printf("%s\n", str);
}

void sumar_numeros(const char *num1, const char *num2, char *resultado)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0, i = 0;
    int index1 = len1 - 1;
    int index2 = len2 - 1;
    int j;

    while (index1 >= 0 || index2 >= 0 || carry)
    {
        int digito1 = (index1 >= 0) ? num1[index1--] - '0' : 0;
        int digito2 = (index2 >= 0) ? num2[index2--] - '0' : 0;

        int suma = digito1 + digito2 + carry;
        resultado[i++] = (suma % 10) + '0';
        carry = suma / 10;
    }

    resultado[i] = '\0';

    for (j = 0; j < i / 2; j++)
    {
        char temp = resultado[j];
        resultado[j] = resultado[i - j - 1];
        resultado[i - j - 1] = temp;
    }
}

int main()
{
    int n, i;
    char num1[MAX_DIGITS + 1], num2[MAX_DIGITS + 1], resultado[MAX_DIGITS + 2];

    if (scanf("%d", &n) != 1) return 1;

    for (i = 0; i < n; i++)
    {
        if (scanf("%s %s", num1, num2) != 2) return 1;

        sumar_numeros(num1, num2, resultado);

        eliminar_zeros(resultado);
    }

    return 0;
}
