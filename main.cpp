#include <iostream>
#include <string>

void processEvenOdd(const int* arr, int size) {
    if (size <= 0 || arr == nullptr) {
        std::cout << "Масив порожній або некоректний.\n";
        return;
    }
    int sumEven = 0, countEven = 0;
    int sumOdd = 0, countOdd = 0;
    for (const int* ptr = arr; ptr < arr + size; ++ptr) {
        if (*ptr % 2 == 0) {
            sumEven += *ptr;
            countEven++;
        } else {
            sumOdd += *ptr;
            countOdd++;
        }
    }
    std::cout << "\n--- Результат (Парні/Непарні) ---\n";
    if (countEven > 0) {
        std::cout << "Середнє значення парних елементів: " << static_cast<double>(sumEven) / countEven << "\n";
    } else {
        std::cout << "Парних елементів немає.\n";
    }
    if (countOdd > 0) {
        std::cout << "Середнє значення непарних елементів: " << static_cast<double>(sumOdd) / countOdd << "\n";
    } else {
        std::cout << "Непарних елементів немає.\n";
    }
}

void findMinMaxStrings(const std::string* arr, int size) {
    if (size <= 0 || arr == nullptr) {
        std::cout << "Масив порожній або некоректний.\n";
        return;
    }
    const std::string* shortest = arr;
    const std::string* longest = arr;
    for (const std::string* ptr = arr + 1; ptr < arr + size; ++ptr) {
        if (ptr->length() < shortest->length()) {
            shortest = ptr;
        }
        if (ptr->length() > longest->length()) {
            longest = ptr;
        }
    }
    std::cout << "\n--- Результат (Рядки) ---\n";
    std::cout << "Найкоротший рядок: \"" << *shortest << "\" (Розмір: " << shortest->length() << ")\n";
    std::cout << "Найдовший рядок: \"" << *longest << "\" (Розмір: " << longest->length() << ")\n";
}

void calculateReverseSum(const double* arr, int size) {
    if (size <= 0 || arr == nullptr) {
        std::cout << "Масив порожній або некоректний.\n";
        return;
    }
    double sum = 0.0;
    std::cout << "\n--- Результат (Зворотна сума) ---\n";
    std::cout << "Елементи у зворотному порядку: ";
    for (const double* ptr = arr + size - 1; ptr >= arr; --ptr) {
        std::cout << *ptr << " ";
        sum += *ptr;
    }
    std::cout << "\nСума елементів: " << sum << "\n";
}

int main() {
    int choice;
    do {
        std::cout << "\n================ МЕНЮ ================\n";
        std::cout << "1. Обчислити середнє парних/непарних чисел\n";
        std::cout << "2. Знайти найкоротший/найдовший рядок\n";
        std::cout << "3. Обчислити суму чисел (реверсний вивід)\n";
        std::cout << "0. Вихід\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        if (choice == 1) {
            int size;
            std::cout << "Введіть розмір масиву цілих чисел: ";
            std::cin >> size;
            int* arr = new int[size];
            std::cout << "Введіть " << size << " цілих чисел:\n";
            for (int i = 0; i < size; ++i) {
                std::cin >> arr[i];
            }
            processEvenOdd(arr, size);
            delete[] arr;
        } 
        else if (choice == 2) {
            int size;
            std::cout << "Введіть розмір масиву рядків: ";
            std::cin >> size;
            std::cin.ignore();
            std::string* arr = new std::string[size];
            std::cout << "Введіть " << size << " рядків:\n";
            for (int i = 0; i < size; ++i) {
                std::getline(std::cin, arr[i]);
            }
            findMinMaxStrings(arr, size);
            delete[] arr;
        } 
        else if (choice == 3) {
            int size;
            std::cout << "Введіть розмір масиву чисел з плаваючою крапкою: ";
            std::cin >> size;
            double* arr = new double[size];
            std::cout << "Введіть " << size << " чисел:\n";
            for (int i = 0; i < size; ++i) {
                std::cin >> arr[i];
            }
            calculateReverseSum(arr, size);
            delete[] arr;
        } 
        else if (choice != 0) {
            std::cout << "Некоректний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    std::cout << "Програму завершено.\n";
    return 0;
}
