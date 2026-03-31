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
Output:
```
Discount: 50%
```

```c
_printf("%d Soleil !", 123);
```
Output:
```
123 Soleil !
```
## Man page

To read the man page:
```bash
man ./man_3_printf
```

## Testing

Compile with a test file:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c main.c -o test
./test
```

Check for memory leaks with Valgrind:
```bash
valgrind --leak-check=full ./test
```

## Flowchart
```mermaid
---
config:
  theme: neutral
  layout: dagre
---
flowchart TB
    Start(["Start"]) --> CheckNull{"format est NULL ?"}
    CheckNull -- oui --> ReturnError["return (-1)"]
    ReturnError --> End1(["End"])
    CheckNull -- non --> Init["compteur = 0 et va_start"]
    Init --> ReadChar["Lire format[i]"]
    ReadChar --> IsNull@{ label: "format[i] == '\\0' ?" }
    IsNull -- oui --> Cleanup["va_end puis return compteur"]
    Cleanup --> End2(["End"])
    IsNull -- non --> IsPercent@{ label: "format[i] == '%' ?" }
    IsPercent -- non --> WriteChar["write le caractere et compteur++"]
    WriteChar --> Advance1["i++"]
    Advance1 --> ReadChar
    IsPercent -- oui --> LookNext["Regarder format[i+1]"]
    LookNext --> CheckSpec{"Quel specifier ?"}
    CheckSpec -- c --> HandlerC["Handler c"]
    CheckSpec -- s --> HandlerS["Handler s"]
    CheckSpec -- pourcent --> HandlerPct["Handler %"]
    CheckSpec -- d ou i --> CheckIntMin{"n == INT_MIN ?"}
    CheckSpec -- autre --> HandlerEdge["Cas limite"]
    CheckIntMin -- oui --> PrintIntMin["Affiche -2147483648<br>return 11"]
    CheckIntMin -- non --> CheckNeg{"n &lt; 0 ?"}
    CheckNeg -- oui --> HandleNeg@{ label: "Affiche '-'<br>n = -n" }
    CheckNeg -- non --> PrintInt["print_int(n)"]
    HandleNeg --> PrintInt
    PrintIntMin --> AddCount["compteur += retour du handler"]
    HandlerC --> AddCount
    HandlerS --> AddCount
    HandlerPct --> AddCount
    PrintInt --> AddCount
    HandlerEdge --> AddCount
    AddCount --> Advance2["i++"]
    Advance2 --> ReadChar

    IsNull@{ shape: diamond}
    IsPercent@{ shape: diamond}
    HandleNeg@{ shape: rect}
```

## Authors

* Adam - [GitHub](https://github.com/Adamzou-lab)
* Panaki - [GitHub](https://github.com/Panaki-GILLOT)