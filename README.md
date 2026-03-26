# _printf

_printf is a recreated version of the real C function printf. We developed
it as a project for Holberton School. It prints output according to a format
string and handles conversion specifiers like %c, %s and %%.

## Compilation

To compile the project, use the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```

## Requirements

* Ubuntu 20.04 LTS
* GCC compiler
* C standard: gnu89

## Examples
```c
_printf("Hello, %s!\n", "World");
```
Output:
```
Hello, World!
```
```c
_printf("The letter is: %c\n", 'A');
```
Output:
```
The letter is: A
```
```c
_printf("Discount: 50%%\n");
```
Output;
```
Discount: 50%
```

## Man page

To read the man page:
```bash
man ./man_3_printf
```

## Testing

Compile with a test file:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format -I. *.c tests/main.c -o tests/test
```

Check for memory leaks with Valgrind:
```bash
valgrind --leak-check=full ./tests/test
```

## Flowchart
```mermaid
---
config:
  theme: neutral
---
flowchart TB
    Start(["Start"]) --> CheckNull{"format est NULL ?"}
    CheckNull -- oui --> ReturnError["return -1"]
    ReturnError --> End1(["End"])
    CheckNull -- non --> Init["compteur = 0 et va_start"]
    Init --> ReadChar["Lire format[i]"]
    ReadChar --> IsNull{"format[i] est le caractere \0 ?"}
    IsNull -- oui --> Cleanup["va_end puis return compteur"]
    Cleanup --> End2(["End"])
    IsNull -- non --> IsPercent{"format[i] est un % ?"}
    IsPercent -- non --> WriteChar["write le caractere et compteur++"]
    WriteChar --> Advance1["i plus 1"]
    Advance1 --> ReadChar
    IsPercent -- oui --> LookNext["Regarder format[i] + 1"]
    LookNext --> CheckSpec{"Quel specifier ?"}
    CheckSpec -- c --> HandlerC["Handler c"]
    CheckSpec -- s --> HandlerS["Handler s"]
    CheckSpec -- pourcent --> HandlerPct["Handler %"]
    CheckSpec -- d ou i --> HandlerD["Handler d et i"]
    CheckSpec -- autre --> HandlerEdge["Cas limite"]
    HandlerC --> AddCount["compteur++ retour du handler"]
    HandlerS --> AddCount
    HandlerPct --> AddCount
    HandlerD --> AddCount
    HandlerEdge --> AddCount
    AddCount --> Advance2["avancer apres le specifier"]
    Advance2 --> ReadChar

    style Start fill:#eee
    style CheckNull fill:#eee
    style ReturnError fill:#eee
```

## Authors

* Adam - [GitHub](https://github.com/Adamzou-lab)
* Panaki - [GitHub](https://github.com/Panaki-GILLOT)