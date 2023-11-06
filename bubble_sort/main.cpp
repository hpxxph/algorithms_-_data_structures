#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

template <typename T>
void _fillvector(std::vector<T>& vector, int size);

template <typename T>
void _bsort(std::vector<T>& vector, int size);

template <typename T>
void outputVector(std::vector<T>& vector, int size);

int main () {
    const int SIZE = 10;
    std::vector<int> vector(SIZE);

    _fillvector(vector, SIZE);

    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    _bsort(vector, SIZE);
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    outputVector(vector, SIZE);

    std::ofstream time_file("bubble_time.txt");
    time_file << duration.count();
    time_file.close();

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
    for (int i = 0; i < size - 1 ; ++i) {
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
void outputVector(std::vector<T> &vector, int size) {
    for (int i = 0; i < size; i += 1) {
        std::cout << "| " << vector[i] << " |";
    }
}