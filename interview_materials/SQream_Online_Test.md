# SQream online test

(Ofer from ofers@sqreamtech.com)

* [SQream - Question bank](http://www.questions-bank.com)

## The purpose of this exercise is to compress an array of Integers.

### Assumptions :

1. The array has 1 million elements.
2. The data in the array is normally distributed, and the values are between 1 and 100
3. The compression algorithm should be based on removing leading zeros in the binary representation of each value.
4. The compression algorithm should be multithreaded.

### Test Calculation:

Given an input of an array containing 1 miliion elements, compress the array using a multithreaded algorithm and store it in memory.

```cpp
#include <iostream>
#include "student.h"

void compress(int arr[], int size){

}
```

### My Solution

It works. However, the compressed integer index is wrong. Instead of being consecutive, it is a multiplication of 4. 

```cpp
#include <iostream>
#include <stdexcept>
#include <thread>
//#include "student.h"

#define MIN_VALUE (0)
#define MAX_VALUE (100)

int compress_four_to_one(int v1,
                         int v2,
                         int v3,
                         int v4);

void thread_function(int arr[], int start_idx, int end_idx);

void compress(int arr[], int size) {
    /* Each element is an int, i.e. a 32 bit value.
      Each element has the value of 100 at most, which needs
      needs 7 bits at most. The decimal value 100 is 0b1100100
      For first iteration, a single thread will compress 4 elements
      into one integer.
    */

    //// Assume array length is divisible by four.
    //int actual_size = (size / 4);

    std::thread t1(&thread_function, arr, 0, (size/4));
    std::thread t2(&thread_function, arr, (size / 4), (size / 2));
    std::thread t3(&thread_function, arr, (size / 2), ((3*size) / 4));
    std::thread t4(&thread_function, arr, ((3 * size) / 4), size);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "main compress ended " << std::endl;

}

int compress_four_to_one(int v1,
                         int v2,
                         int v3,
                         int v4)
{
    /*
    Function assumes integer is 32 bit long (as the test shoed type(int) = 4)
    After validating input parameters range, copy the first parameter to the first byte,
    the second parameter to the second byte, and so on.
    */
    if ((v1 < MIN_VALUE) || (v1 > MAX_VALUE) ||
        (v2 < MIN_VALUE) || (v2 > MAX_VALUE) ||
        (v3 < MIN_VALUE) || (v3 > MAX_VALUE) ||
        (v4 < MIN_VALUE) || (v4 > MAX_VALUE))
    {
        std::cout << "Invalid arguments : " << v1 <<
                                               " " <<
                                               v2 <<
                                               " " <<
                                               v3 <<
                                               " " <<
                                               v4 <<
                                               std::endl;


        throw std::invalid_argument("Invalid argument.");
    }

    // No need to move v1, because it already aligned in the first byte place
    int v2_moved = v2 << 8;
    int v3_moved = v3 << 16;
    int v4_moved = v4 << 24;
    return (v1 + v2_moved + v3_moved + v4_moved);
}

void thread_function(int arr[], int start_idx, int end_idx)
{
    // Assume range divisible by 4
    int actual_size = (end_idx - start_idx) / 4;
    std::cout << "Thread calc from " << start_idx << " to " << (start_idx + actual_size) << std::endl;
    std::cout << "end_idx" << end_idx;
    for (int i = 0; i < actual_size; i++)
    {
        // Get current index to compress into four elements
        int curr_i = start_idx + (i * 4);
        arr[start_idx + i] = compress_four_to_one(arr[curr_i],
                                                  arr[curr_i + 1],
                                                  arr[curr_i + 2],
                                                  arr[curr_i + 3]);
    }
}

int main()
{
    int myArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    compress(myArray, 20);
    std::cout << myArray[3];
    return 0;
}
```