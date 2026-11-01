#include <algorithm>
#include <iostream>
#include <vector>

int linearSearch(const std::vector<int>& values, int key) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (values[i] == key) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int binarySearch(const std::vector<int>& values, int key) {
    int low = 0;
    int high = static_cast<int>(values.size()) - 1;

    while (low <= high) {
        const int middle = low + (high - low) / 2;
        if (values[middle] == key) {
            return middle;
        }
        if (values[middle] < key) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    return -1;
}

int main() {
    int count;
    std::cout << "Enter the number of students attended training: ";
    if (!(std::cin >> count) || count < 1 || count > 100) {
        std::cout << "Invalid number of students!\n";
        return 1;
    }

    std::vector<int> rollNumbers(count);
    std::cout << "Enter roll numbers:\n";
    for (int& rollNumber : rollNumbers) {
        std::cin >> rollNumber;
    }

    int choice;
    do {
        std::cout << "\n===== MENU =====\n"
                  << "1. Display Roll Numbers\n"
                  << "2. Linear Search\n"
                  << "3. Binary Search\n"
                  << "4. Exit\n"
                  << "Enter your choice: ";
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input!\n";
            return 1;
        }

        if (choice == 1) {
            for (int rollNumber : rollNumbers) {
                std::cout << rollNumber << ' ';
            }
            std::cout << '\n';
        } else if (choice == 2 || choice == 3) {
            int key;
            std::cout << "Enter roll number to search: ";
            std::cin >> key;

            std::vector<int> values = rollNumbers;
            if (choice == 3) {
                std::sort(values.begin(), values.end());
            }

            const int result = choice == 2
                ? linearSearch(values, key)
                : binarySearch(values, key);
            if (result >= 0) {
                std::cout << "Student with Roll Number " << key
                          << " attended the training program.\n";
            } else {
                std::cout << "Student with Roll Number " << key
                          << " did NOT attend the training program.\n";
            }
        } else if (choice == 4) {
            std::cout << "Exiting program...\n";
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
