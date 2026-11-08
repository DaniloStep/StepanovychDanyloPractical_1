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
    int key, int& comp
) {
    int l = 0,
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
        }
        else {
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

void test_search(
    int arr[], int size,
    int key, int expected_index
) {
    int comp = 0;

    int actual_linear_idx = find_element(arr, size, 
                                         key, comp);
    std::cout << "Лінійний пошук числа " << key << ": ";
    if (actual_linear_idx != -1) {
        std::cout << "знайдено на індексі " << actual_linear_idx << "\n";
    } else {
        std::cout << "не знайдено\n";
    }
    std::cout << "Порівнянь проведено: " << comp << "\n";

    if (actual_linear_idx == expected_index) {
        std::cout << "Статус лінійного пошуку: [УСПІШНО]\n";
    } else {
        std::cout << "Статус лінійного пошуку: [ПОМИЛКА] (Очікувався: " << expected_index << ", Фактичний: " << actual_linear_idx << ")\n";
    }

    std::cout << "\n";

    int actual_binary_idx = binary_search(arr, size, key, comp);
    std::cout << "Бінарний пошук числа " << key << ": ";
    if (actual_binary_idx != -1) {
        std::cout << "знайдено на індексі " << actual_binary_idx << "\n";
    } else {
        std::cout << "не знайдено\n";
    }
    std::cout << "Порівнянь проведено: " << comp << "\n";

    if (actual_binary_idx == expected_index) {
        std::cout << "Статус бінарного пошуку: [УСПІШНО]\n";
    }
    else {
        std::cout << "Статус бінарного пошуку: [ПОМИЛКА] (Очікувався: " << expected_index << ", Фактичний: " << actual_binary_idx << ")\n";
    }

    std::cout << "----------------------------------------------\n";
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

    bubbleSort(arr, size);

    test_search(arr, size, 27, 3);   
    test_search(arr, size, 52, 6);   
    test_search(arr, size, 31, -1);

    return 0;
}
