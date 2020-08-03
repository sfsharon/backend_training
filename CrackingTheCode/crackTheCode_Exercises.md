# Crack The Code ( [Book link](https://drive.google.com/file/d/1XOSOVAl5PsAGwrYoRzcP2EgajlHiiaaV/view?usp=sharing), [Doc link](https://github.com/sfsharon/backend_training/blob/master/CrackingTheCode/crackTheCode_Exercises.md) )

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
  A stack is a LIFO - Last In First Out.  It's functions are push and pop.
  
  The idea is to push onto Stack A each item that is enqueued to the MyQueue object. Then, when a dequeue is called, all the content of Stack A is popped onto Stack B. Now we have the items in the correct order of insertion (LIFO) on Stack B. Stack B is popped, and the value returned to the caller of the dequeue(). If another dequeue() is called, Stack B is popped again and return value for the dequeue. However, if now an enqueue() arrives, to keep the correct order of items, all of Stack B elements are popped from Stack B to Stack A, and then the enqueue() value is pushed onto Stack A.
  
  Stack A can be called the enqueueStack, and Stack B can be called the dequeueStack.
  
  ```python
  #!/usr/bin/env python
  
  """
  Implement MyQueue using a simple stack implementation
  """
  
  # --------------------------------------------
  # Auxiliary class
  # --------------------------------------------  
  class myStack() :
    """
    Implement simple stack classes, using lists and their append() and pop() 
    built in methods
    """
      def __init__(self) :
        self.stack = []
      def push(self, val) :
        self.stack.append(val)
      def pop(self) :
        return self.stack.pop()
      def isEmpty(self) :
        return (len(self.stack) == 0)
  
  # --------------------------------------------
  # Main class
  # --------------------------------------------          
  class MyQueue() :
    ENQUEUE_STATE = "ENQUEUE"
    DEQUEUE_STATE = "DEQUEUE"
  
    __init__(self) :
        """
        Create two stacks 
        """
        self.enqueueStack = myStack()
        self.dequeueStack = myStack()
        # The Queue is initialized empty, therefore the initial state can only be enqueue
        self.state = self.ENQUEUE_STATE
  
    def enqueue(self, val) :
        # Simple case - Queue is in Enqueue mode, so just push value onto the enqueueStack
        if self.state == self.ENQUEUE_STATE :
            continue # Do nothing to change the inner object state
        # Need to move all content from dequeueStack to the enqueueStack, and then push
        # to the enqueueStack
        elif self.state == self.DEQUEUE_STATE :
            self.state = self.ENQUEUE_STATE
            self.move_from_dequeue_to_enqueue() # Not implemented here
  
        # Enqueue value onto the enqueueStack
        self.enqueueStack.push(val)
  
    def dequeue(self) :
        # Simple case - Queue is in Dequeue mode
        if self.state == self.DEQUEUE_STATE :
            continue # Do nothing to change the inner object state
        # Need to move all content from enqueueStack to the dequeueStack
        elif self.state == self.ENQUEUE_STATE :
            self.state = self.DEQUEUE_STATE
            self.move_from_enqueue_to_dequeue() # Not implemented here
  
        # Dequeue value onto the dequeueStack, and return it to the user
        if (self.dequeueStack.isEmpty() == True) :
            raise ValueError("*** Error - Trying the dequeue an empty queue")
        else :
            return self.dequeueStack.pop()        
  ```

# Chapter 4 - Trees and Graphs

## 4.3 (p. 60) Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.

Sol. :
The question says "binary tree", and NOT "binary search tree", so the tree does not have to hold the search tree rule of left subtree smaller then root, and right tree larger. So why does it matter that the input array is ordered ? It doesn't make sense.
So the main issue here is to traverse the input array, no matter in what order the elements are.
It looks like a BFS implementation could be done here, using a queue. The first element in the array will be the root tree node.
Then the children elements will be inserted into the queue. 
Number of elements at each level should be 2<sup>level</sup>, unless it's the final level. This will ensure a minimal height tree.
Maybe a queue is not a good idea. If I keep two indices into the array. One (parentIdx) points to the current parent node that is being populated with children, and another (currChildIdx) to the next available node intended to be a child.
For example :

```
Ex. 1 : array [1,2,3] :
                1
              /   \
            2      3
           / \    /  \               
         Nil Nil Nil Nil

Ex. 2 : array [0,1,2,3,4,5,6]
                0
       /                \
      1                  2
     /   \            /     \              
    3       4         5      6            
  /  \     /  \     /   \   /  \
 Nil Nil  Nil Nil Nil  Nil Nil  Nil

Init 
root = new_node(array[0])
enqueue(Array[1])
currChildIdx : 1 
level = 1

Step 0
Loop : while queue is not empty                 # Queue has one node : array[0]
        root = dequeue()                        # root = array[0]
        childLeft  = array[currChildIdx]        # currChildIdx     -> 1
        childRight = array[currChildIdx + 1]    # currChildIdx + 1 -> 2
        root_connect(childLeft, childRight)     # build subtree
    
        enqueue (currChildIdx)                  # array[1]
        enqueue(currChildIdx + 1)               # array[2]
        currChildIdx = currChildIdx + 2         # Index points to the next nodes to be added to tree,
                                                # meaning array[3]

Step 1
Loop : while queue is not empty                 # Queue has two nodes : array[1], array[2]
        # First iteration, for node array[1]. Second will be for array[2]
        root = dequeue()                        # root = array[1]
        childLeft  = array[currChildIdx]        # currChildIdx     -> 3
        childRight = array[currChildIdx + 1]    # currChildIdx + 1 -> 4
        root_connect(childLeft, childRight)     # build subtree

        enqueue (currChildIdx)          # array[3]
        enqueue(currChildIdx + 1)       # array[4]
        currChildIdx = currChildIdx + 2 # Index points to the next nodes to be added to tree,
                                        # meaning array[3]
 
```
