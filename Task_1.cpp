#include <iostream>
#include <windows.h>

int find_element(
    int arr[], int size,
    int key,   int& comp
) {
    for (
        int i = 0;
        i < size;
        i++
        ) {
        comp++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void verification(
                 int arr[],
                 int size,
                 int key
                 ) {
    int comp = 0,
        index = find_element(arr, size,
                             key, comp);

    std::cout << "Пошук числа " << key << ": ";
    if (index != -1) {
        std::cout << "знайдено на індексі " << index << "\n";
    } else {
        std::cout << "не знайдено" << "\n";
    }
    std::cout << "Порівнянь проведено: " << comp << "\n";

}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[] = {
                  27, 40, 18,
                  52, 23, 34,
                  15
                },
        size = sizeof(arr)
             / sizeof(arr[0]);

    verification(arr, size, 27);
    verification(arr, size, 52);
    verification(arr, size, 31);

    return 0;
}
