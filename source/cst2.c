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

    printf("=== \033[1mКонвертер систем счисления \033[0m===\n");
    printf("\033[31m" "b - двоичная (binary)\n");
    printf("\033[33m" "d - десятичная (decimal)\n");
    printf("\033[32m" "h - шестнадцатеричная (hexadecimal)\n" "\033[0m\n");

    printf("Из какой системы (b, d, h): ");
    if (scanf("%3s", base) != 1) {
        printf("Ошибка ввода.\n");
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
        printf("Ошибка: нужно ввести b, d или h.\n");
        return 1;
    }
    while(1){
        printf("Введи число: ");
        if (scanf("%63s", num_str) != 1) {
            printf("Ошибка ввода числа.\n");
            continue;
        }
        if (strstr(num_str, "exit") != NULL){
            break;
        }
        /* Конвертация строки в число */
        value = strtol(num_str, NULL, base_num);
        if (value == 0 && num_str[0] != '0') {
            printf("Ошибка: неверное число для этой системы.\n");
            continue;
        }

        printf("\nРезультат:\n");

        /* Вывод в двоичной системе */
        if (base_num != 2) {
            printf("2️⃣  Двоичная:          ");
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
            printf("🔟 Десятичная:        %ld\n", value);

        /* Вывод в шестнадцатеричной */
        if (base_num != 16)
            printf("#️⃣  Шестнадцатеричная: %lX\n", value);
        printf("===================================\n");
    }
    printf("============= Пока👋! =============");
    return 0;
}