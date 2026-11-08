#include <iostream>
#include <windows.h>

int find_element(
    int arr[], int size,
    int key, int& comp
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

int binary_search(
    int arr[], int size,
    int key,   int& comp
) {
    int l,
        r;
    l = 0;
    r = size - 1;

    comp = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        comp++;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return -1;
}

void bubbleSort(
    int arr[],
    int size
) {
    for (
        int i = 0;
        i < size - 1;
        i++
        ) {
        for (
            int j = 0;
            j < size - i - 1;
            j++
            ) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void verification(
    int arr[],
    int size,
    int key
) {
    int comp,
        index = find_element(arr, size,
                             key, comp);
    comp = 0;

        std::cout << "Лінійний пошук числа " << key << ": ";

    if (index != -1) {
        std::cout << "знайдено на індексі " << index << "\n";
    } else {
        std::cout << "не знайдено\n";
    }

    std::cout << "Порівнянь проведено: " << comp << "\n";

    index = binary_search(arr, size,
                          key, comp);

    std::cout << "Бінарний пошук числа " << key << ": ";

    if (index != -1) {
        std::cout << "знайдено на індексі " << index << "\n";
    } else {
        std::cout << "не знайдено\n";
    }

    std::cout << "Порівнянь проведено: " << comp << "\n\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[] = {
        27, 40, 18,
        52, 23, 34,
        15
    };

    int size;
    size = sizeof(arr)
         / sizeof(arr[0]);

    bubbleSort(arr, size);

    verification(arr, size, 27);
    verification(arr, size, 52);
    verification(arr, size, 31);

    return 0;
}
