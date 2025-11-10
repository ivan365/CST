#!/usr/bin/env python3

def main():
    print("=== Конвертер систем счисления ===")
    print("b - двоичная (binary)")
    print("d - десятичная (decimal)")
    print("h - шестнадцатеричная (hexadecimal)")

    base = input("Из какой системы (b, d, h): ").strip().lower()
    bases = {"b": 2, "d": 10, "h": 16}

    if base not in bases:
        print("Ошибка: нужно ввести b, d или h.")
        return

    num_str = input("Введи число: ").strip()

    try:
        value = int(num_str, bases[base])
    except ValueError:
        print("Ошибка: неверное число для этой системы.")
        return

    print("\nРезультат:")
    if base != "b":
        print(f"Двоичная:         {bin(value)[2:]}")
    if base != "d":
        print(f"Десятичная:       {value}")
    if base != "h":
        print(f"Шестнадцатеричная: {hex(value)[2:].upper()}")

if __name__ == "__main__":
    main()