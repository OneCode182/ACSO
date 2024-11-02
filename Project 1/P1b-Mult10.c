#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 500
#define RESULT_MAX_DIGITS 1000

void eliminar_zeros(char *str)
{
    while (*str == '0' && *(str + 1) != '\0')
    {
        str++;
    }
    printf("%s\n", str);
}

void multiplicar_numeros(const char *num1, const char *num2, char *resultado)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int i, j, k;
    int temp_result[RESULT_MAX_DIGITS] = {0};

    for (i = len1 - 1; i >= 0; i--)
    {
        for (j = len2 - 1; j >= 0; j--)
        {
            int idx_resultado = (len1 - 1 - i) + (len2 - 1 - j);
            int producto = (num1[i] - '0') * (num2[j] - '0');
            temp_result[idx_resultado] += producto;

            temp_result[idx_resultado + 1] += temp_result[idx_resultado] / 10;
            temp_result[idx_resultado] %= 10;
        }
    }

    k = 0;
    for (i = RESULT_MAX_DIGITS - 1; i >= 0; i--)
    {
        if (temp_result[i] != 0 || k > 0)
        {
            resultado[k++] = temp_result[i] + '0';
        }
    }
    resultado[k] = '\0';

    if (k == 0)
    {
        strcpy(resultado, "0");
    }
}

int main()
{
    int n, i;
    char num1[MAX_DIGITS + 1], num2[MAX_DIGITS + 1], resultado[RESULT_MAX_DIGITS + 1];

    if (scanf("%d", &n) != 1) return 1;

    for (i = 0; i < n; i++)
    {
        if (scanf("%s %s", num1, num2) != 2) return 1;

        multiplicar_numeros(num1, num2, resultado);

        eliminar_zeros(resultado);
    }

    return 0;
}
