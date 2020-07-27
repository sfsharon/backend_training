# Crack The Code ( [Book link](https://drive.google.com/file/d/1XOSOVAl5PsAGwrYoRzcP2EgajlHiiaaV/view?usp=sharing) )

# Chapter 3 - Stacks and Queues

## 3.4 (p. 58) In the classic problem of the Tower of Hanoi, you have 3 rods and N disks of different sizes, which can slide onto any tower. The puzzle starts with disks stored in ascending order of size from top to bottom (e.g., each disk sits on top of an even larger one).

* You have the following constraints :
  1. Only one disk can be moved at a time.
  2. A disk is slid off the top of one rod onto the next rod.
  3. A disk can only be placed on top of a larger disk.
     Write a program to move the disks from the first rod to the lat using stacks.

Sol. : Taking iterative solution from [Wikipedia link](https://en.wikipedia.org/wiki/Tower_of_Hanoi) :

* Iterative solution : 
  
  - For an even number of disks :
    - Make the legal move between pegs A and B (in either direction)
    - Make the legal move between pegs A and C (in either direction)
    - Make the legal move between pegs B and C (in either direction)
    - Repeat until complete.
  - For an odd number of disks :
    - Make the legal move between pegs A and |C (in either direction)
    - Make the legal move between pegs A and B (in either direction)
    - Make the legal move between pegs B and C (in either direction)
    - Repeat until complete.    
  - In each case, a total of 2<sup>n</sup>-1 moves are made.
  
  ## 3.5 (p.58) Implement a MyQueue class which implements a queue using two stacks.
  
  Sol. : 
  A queue is a FIFO - First In First Out machine. It's functions are enqueue() and dequeue().
  A stack is a LIFO - Last In First Out.  It's functins are push and pop.
  
  The idea is to push onto Stack A each item that is enqueued to the MyQueue object. Then, when a dequeue is called, all the content of Stack A is popped onto Stack B. Now we have the items in the correct order of insertion (LIFO) on Stack B. Stack B is popped, and the value returned to the caller of the dequeue(). If another dequeue() is called, Stack B is popped again and return value for the dequeue. However, if now an enqueue() arrives, to keep the correct order of items, all of Stack B elements are popped from Stack B to Stack A, and then the enqueue() value is pushed onto Stack A.
  
  Stack A can be called the enqueueStack, and Stack B can be called the dequeueStack.
  
  ```python
  class MyQueue() :
    __init__(self) :
        """
        Create two stacks 
        """
  ```