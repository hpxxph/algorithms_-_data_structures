#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <fstream> 
#include <iomanip> 

template <typename T>
void fill_vector(std::vector<T>& vector, int size);
 
template <typename T>
void _qsort (std::vector<T>& vector, int first, int last);

template <typename T>
void _printVector(std::vector<T>& vector, int size);

int main () 
{
    srand(time(NULL));

    const int SIZE = 10;
    std::vector<int> vector(SIZE); 
    
    fill_vector(vector, SIZE);

    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    _qsort(vector, 0, SIZE - 1);
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    _printVector(vector, SIZE);
    
    std::ofstream time_file("execution_time.txt");
    time_file << duration.count();
    time_file.close();

    return 0; 
}

template <typename T>
void fill_vector(std::vector<T>& vector, int size) {
    for (int i = 0; i < size; ++i) {
        vector[i] = rand() % 15; 
    }
}

template <typename T>
void _qsort(std::vector<T>& vector, int first, int last) {
    T middle = vector[(first + last) / 2];

    int i = first;
    int j = last;

    do {
        while (vector[i] < middle)
            i += 1;
        while (vector[j] > middle)
            j -= 1;

        if (i <= j) {
            int swap = vector[i];
            vector[i] = vector[j];
            vector[j] = swap;

            i += 1;
            j -= 1;
        }

    } while (i <= j);

    if (first < j) {
        _qsort(vector, first, j);
    }
    if (i < last) {
        _qsort(vector, i, last);
    }
}

template <typename T>
void _printVector(std::vector<T>& vector, int size) {
    for (int i = 0; i < size; i += 1) {
        std::cout << "| "<< vector[i] << " |"; 
    }
}