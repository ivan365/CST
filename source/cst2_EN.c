#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char base[4];
    char num_str[64];
    long value;
    int base_num;
    unsigned long mask;
    int started;

    printf("=== Конвертер систем счисления ===\n");
    printf("b - binary\n");
    printf("d - decimal\n");
    printf("h - hexadecimal\n");

    printf("choose system (b, d, h): ");
    if (scanf("%3s", base) != 1) {
        printf("Error.\n");
        return 1;
    }

    /* Определяем основание системы */
    base_num = 0;
    if (base[0] == 'b' || base[0] == 'B')
        base_num = 2;
    else if (base[0] == 'd' || base[0] == 'D')
        base_num = 10;
    else if (base[0] == 'h' || base[0] == 'H')
        base_num = 16;
    else {
        printf("Error: it has to be b, d or h.\n");
        return 1;
    }
    while(1){
        printf("Enter number: ");
        if (scanf("%63s", num_str) != 1) {
            printf("Error of number.\n");
            continue;
        }
        if (strstr(num_str, "exit") != NULL){
            break;
        }
        /* Конвертация строки в число */
        value = strtol(num_str, NULL, base_num);
        if (value == 0 && num_str[0] != '0') {
            printf("Error: Bad number for this system.\n");
            continue;
        }

        printf("\nResault:\n");

        /* Вывод в двоичной системе */
        if (base_num != 2) {
            printf("binary:          ");
            mask = 1UL << (sizeof(long) * 8 - 1);
            started = 0;
            while (mask > 0) {
                if (value & mask) {
                    putchar('1');
                    started = 1;
                } else if (started) {
                    putchar('0');
                }
                mask >>= 1;
            }
            if (!started) putchar('0');
            putchar('\n');
        }

        /* Вывод в десятичной */
        if (base_num != 10)
            printf("Decimal:        %ld\n", value);

        /* Вывод в шестнадцатеричной */
        if (base_num != 16)
            printf("Hexadecimal: %lX\n", value);
        printf("===================================\n");
    }
    printf("============= Bye! =============");
    return 0;
}

