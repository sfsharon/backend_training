#!/usr/bin/env python
"""
Solution to question 5.3, page 64 of 'Cracking the Coding Interview' book
"""

def find_neighbor_num (val) :
    """
    Find the next smallest and largest neighbor for a positive integer input value.
    A neighbor is a number with the same number of '1's as the input val number
    """

    valNumOnes = count_ones(val)

    # Corner cases : 1. If val is zero, there are no neighbors.
    #                2. Do not support negative numbers (need to implement twos complement)
    if val <= 0 :
        print ("find_neighbor_num :  error in value " + str(val)) 
        return ("null", "null")

    nextLargest  = val + 1
    nextSmallest = val -1

    # Find next largest neighbor
    while count_ones(nextLargest) != valNumOnes :
        nextLargest += 1

    # Find next smallest neighbor
    while count_ones(nextSmallest) != valNumOnes :
        if nextSmallest == 0 :
            print ("find_neighbor_num :  Could not find next smallest neighbor for value " + str(val)) 
            nextSmallest = "null"
            break

        nextSmallest -= 1



    return (nextLargest, nextSmallest)

def count_ones  (val) :
    """
    Calculate the number of '1's in an integer positive value
    """

    numOfOnes = 0

    while val != 0 :
        #print(val)
        numOfOnes += val & 0x1
        val = val >> 1

    return numOfOnes
    
    
if __name__ == "__main__" :
    val = 6
    print ("For value " + str(val) + " neighbors : ")
    print(find_neighbor_num(val))
    
    val = 7
    print ("For value " + str(val) + " neighbors : ")
    print(find_neighbor_num(val))
    
    val = 1
    print ("For value " + str(val) + " neighbors : ")
    print(find_neighbor_num(val))
    
    val = 0
    print ("For value " + str(val) + " neighbors : ")
    print(find_neighbor_num(val))
    
    
    # val = 6
    # print ("For value " + str(val) + " neighbors : " + str(count_ones(val)))
    
    # val = 7
    # print ("For value " + str(val) + " neighbors : " + str(count_ones(val)))
    
    # val = 1
    # print ("For value " + str(val) + " neighbors : " + str(count_ones(val)))
    
    # val = 0
    # print ("For value " + str(val) + " neighbors : " + str(count_ones(val)))    
    