#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
void _fillvector(std::vector<T>& vector, int size);

template <typename T>
void _bsort(std::vector<T>& vector, int size);

template <typename T>
void _bsearch(std::vector<T>& vector, int size, int value);

template <typename T>
void outputVector(std::vector<T>& vector, int size);

int main () {
    const int SIZE = 10; 
    std::vector<int> vector(SIZE); 
    
    _fillvector(vector, SIZE);
    _bsort(vector, SIZE);

    std::cout << "Enter your value: "; 
    int value; 
    std::cin >> value; 

    _bsearch(vector, SIZE, value); 
    std::cout << std::endl; 
    outputVector(vector, SIZE);

    return 0; 
}

template <typename T>
void _fillvector(std::vector<T>& vector, int size) {
    bool alreadyThere;

    for (int i = 0; i < size; ++i) {
        int randomElements; 

        do 
        {
            alreadyThere = 0; 
            randomElements = rand() % 20; 

            for (int j = 0; j < i; ++j) {
                if (vector[j] == randomElements) {
                    alreadyThere = 1; 
                }
            }

        } while (alreadyThere);

        vector[i] = randomElements; 
    } 
}

template <typename T>
void _bsort(std::vector<T>& vector, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp; 
            }
        }
    }
}

template <typename T>
void _bsearch(std::vector<T>& vector, int size, int value) {
    int low = 0;  
    int high = size - 1; 

    while (low <= high) 
    {
        int mid = (low + high) / 2; 

        if (value == vector[mid]) { 
            std::cout << "Value: " << value << " index: " << mid << std::endl; 
            break;
        } else if (value > vector[mid]) { 
            low = mid + 1; 
        } else { 
            high = mid - 1; 
        }
    }  
}

template <typename T>
void outputVector(std::vector<T>& vector, int size) {
    for (int i = 0; i < size; i += 1) {
        std::cout << "| " << vector[i] << " |";
    }
}