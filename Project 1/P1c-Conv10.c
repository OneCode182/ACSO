#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIGITS 1000

int valor_caracter(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (isalpha(c)) {
        return toupper(c) - 'A' + 10;
    }
    return -1;
}

void convertir_a_base10(const char *numero, int base, char *resultado) {
    int len = strlen(numero);
    int i, j;
    int res_len = 0;
    int temp[MAX_DIGITS] = {0}; /* Para almacenar el resultado en dígitos */

    for (i = 0; i < len; i++) {
        int valor = valor_caracter(numero[i]);
        if (valor < 0 || valor >= base) {
            printf("Error: Caracter no válido para la base %d\n", base);
            strcpy(resultado, "0");
            return;
        }
        
        /* Multiplicar el resultado actual por la base y sumar el valor del dígito actual */
        for (j = 0; j < res_len; j++) {
            temp[j] *= base;
        }
        temp[0] += valor;
        
        /* Manejo de acarreo */
        for (j = 0; j < res_len || temp[j] != 0; j++) {
            if (j == res_len) res_len++;
            temp[j + 1] += temp[j] / 10;
            temp[j] %= 10;
        }
    }

    /* Ignorar ceros a la izquierda al construir la cadena de salida */
    i = res_len - 1;
    while (i >= 0 && temp[i] == 0) {
        i--;
    }

    /* Si i < 0, el número es 0 */
    if (i < 0) {
        strcpy(resultado, "0");
    } else {
        int k = 0;
        for (; i >= 0; i--) {
            resultado[k++] = temp[i] + '0';
        }
        resultado[k] = '\0';
    }
}

int main() {
    int n, base, i;
    char numero[MAX_DIGITS + 1];
    char resultado[MAX_DIGITS * 2]; /* Doble tamaño para almacenar números grandes */

    if (scanf("%d", &n) != 1) return 1;

    for (i = 0; i < n; i++) {
        if (scanf("%d %s", &base, numero) != 2) return 1;
        
        if (base < 2 || base > 36) {
            printf("Error: Base fuera del rango permitido (2-36)\n");
            continue;
        }

        convertir_a_base10(numero, base, resultado);
        printf("%s\n", resultado);
    }

    return 0;
}
