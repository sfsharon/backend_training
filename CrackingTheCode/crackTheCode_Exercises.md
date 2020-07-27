# Crack The Code ( [link](https://drive.google.com/file/d/1XOSOVAl5PsAGwrYoRzcP2EgajlHiiaaV/view?usp=sharing) )

# Chapter 3 - Stacks and Queues

## 3.4 In the classic problem of the Tower of Hanoi, you have 3 rods and N disks of different sizes, which can slide onto any tower. The puzzle starts with disks stored in ascending order of size from top to bottom (e.g., each disk sits on top of an even larger one). You have the following constraints :
A. Only one disk can be moved at a time.
B. A disk is slid off the top of one rod onto the next rod.
C. A disk can only be placed on top of a larger disk.
Write a program to move the disks from the first rod to the lat using stacks.

Sol. : Taking [Wikipedia link](https://en.wikipedia.org/wiki/Tower_of_Hanoi) :

Iterative solution : 
For an even number of disks :
    * Make the legal move between pegs A and B (in either direction)
    * Make the legal move between pegs A and C (in either direction)
    * Make the legal move between pegs B and C (in either direction)
    * Repeat until complete.
For an odd number of disks :
    * Make the legal move between pegs A and |C (in either direction)
    * Make the legal move between pegs A and B (in either direction)
    * Make the legal move between pegs B and C (in either direction)
    * Repeat until complete.    
 In each case, a total of 2<sup>n</sup>-1 moves are made.