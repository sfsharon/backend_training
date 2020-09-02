# IBM online test

Taken from: [IBM - HackerRank](https://www.hackerrank.com/)

## 12. Minimum Sum

Given an array of integers, perform some number *k* operations. Each operation consists of removing an element from the array, dividing it by 2 and inserting the ceiling of that result back into the array. Minimize the sum of the elementsin the final array.

**Example:**
*nums = [10,20,7]*
*k = 4*

Pick    Pick/2      Ceiling     Result
Initial array                   [10,20,7]
7       3.5         4           [10,20,4]
10      5           5           [5,20,4]
20      10          10          [5,10,4]
10      5           5           [5,5,4]

The sum of the final array is 5 + 5 + 4 = 14, and that sum is minimal.

```c
/*
 * Complete the 'minSum' function below.
 * The function accepts following parameters :
 * 1. INTEGER_ARRAY number
 * 2. INTEGER k
 */ 

int minSum(int num_count, int* num, int k) {

}

int main()
{
 // ...
}
```

## 13. Custom-Sorted Array

In an array, elemets at any two indices can be scapped in a single operationcalled a *move*. For example, if the array is *arr = [17,4,8]*, swap *arr[0]=17* and *arr[2]=8* to get *arr`=[8,4,17]* in a single move. Determine the minimum number of moves required to sort an array such that all of the *even* elements are at the beginning of the array, and all of the *odd* elements are at the end of the array.

**Example:**

*arr = [6,3,4,5]*

The following four arrays are valid custom-sorted arrays :

* *a = [6,4,3,5]*
* *a = [4,6,3,5]*
* *a = [6,4,5,3]*
* *a = [4,6,5,3]*

The most efficient sorting requires 1 move: swap the 4 and the 3.

**Function Description**
COmplete the function *moves* in the editor below.

moves has the following parameter(s): *int arr[n]:* an array of positive integers

**Returns**
    *int:* the minimum number of moves it takes to sort an array of integers with all even elements at earlier indices than any odd element.

**Note:** The order of the elements within even or odd does not matter.

** Sample Input 

STDIN       Function

-----       --------

4       -> arr[] size n = 4
13      -> arr = [13, 10, 21, 20]
10
21
20

**Sample Output
1

**Explanation
Swap *arr[0]* and *arr[3]* to get the custom-sorted array *arr`=[20, 10, 21, 13]* in 1 move.
