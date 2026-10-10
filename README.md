# progr_2


## Запуск

С помощью make:

```bash
make run
```

Или вручную:

```bash
# части 1 и 2
g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp src/DynamicArray.cpp -o main

# часть 3 
g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp -o main

./main        # на Windows: main.exe
```

Очистка: `make clean`.
