# Queue
## Introduction

In this tutorial you will learn the how a queue differs to other data structures, common queue operations, and how to implement a queue in python. Example problem #2 and the problem to solve require an understanding of stack and list data structures.

## Description

Like stack, queue is a linear data structure that is open at both ends and stores items in First In First Out (FIFO) manner, making them ideal when order is a priority for storing data. This is the same process we are all familiar with when we order food, or wait in line to at a check-out lane. The queue is commonly used in the real world to process customer oders. Think of an Amazon fulfillment warehouse that has to process hundreds of order a day. These orders are stored in queues. With a queue the least recently added item is removed first. Queue operations have a time complexity of O(1). 


![](https://imgs.search.brave.com/GA8W1CmYy-k3Bo4QPP_kFmKial1xsQjNLOzigOMSoAQ/rs:fit:1104:709:1/g:ce/aHR0cHM6Ly9taXJv/Lm1lZGl1bS5jb20v/bWF4LzExMDQvMSot/STZubDhpUWpvQUhh/T1V2c2staWRnLnBu/Zw)

## Operations

Position of the entry in a queue ready to be served, that is, the first entry that will be removed from the queue, is called the front of the queue(sometimes, head of the queue), similarly, the position of the last entry in the queue, that is, the one most recently added, is called the rear (or the tail) of the queue. See the below figure. Operations associated with queue are: 
- `Enqueue`: Adds an item to the queue. If the queue is full, then it is said to be an Overflow condition
- `Dequeue`: Removes an item from the queue. The items are popped in the same order in which they are pushed.
- `Front`: Get the front item from queue.
- `Rear`: Get the last item from queue.


## Implementation

The most common way to impliment a queue in python is through importing the queue module. Queue is built-in module of Python which is used to implement a queue. `queue.Queue(`*maxsize*`)` initializes a variable to a maximum size of *maxsize*. A *maxsize* of zero 0 means a infinite queue.

    from queue import Queue

There are various functions available in this module:

- `maxsize`: Number of items allowed in the queue.

        # Create a queue of size 10
        my_queue = Queue(maxsize = 10)

        # Create a queue of infinite size
        my_queue = Queue(maxsize = 0)

- `empty()`: Return True if the queue is empty, False otherwise.
- `full()`: Return True if there are maxsize items in the queue. If the queue was initialized with 0 (the default), then `full()` never returns True.
- `put()`: Put item into the queue.
- `put_nowait()`: Equivalent to `put(item, block=False)`.
- `get()`: Remove and return an item from the queue. If queue is empty, wait until an item is available.
- `get_nowait()`: Return an item if one is immediately available.
- `put(item)`: Put an item into the queue. If the queue is full, wait until a free slot is available before adding the item.
- `put_nowait(item)`: Put an item into the queue without blocking.
- `qsize()`: Return the number of items in the queue.
- `task_done()`: Indicate that a formerly enqueued task is complete.
- `join()`: Blocks until all items in the queue have been gotten and processed.

## Basic Problem Example

Let’s say that we are building a program that tracks people who are in line to ride a rollercoaster. We could use a queue to keep track of the people who are in line.

### Exercise #1

Firstly, we need to define our queue class. We will assume the ride holds 24 people. We can do that using the following code:

    from queue import Queue
    waitlist = Queue(maxsize=24)    

Now we’re ready to create our queue. The `put()` function allows data to be put into the queue. In the below code, we are going to add five people to the waitlist who entered the line:

    waitlist.put('Jacob')
    waitlist.put('Slade')
    waitlist.put('Mathew')
    waitlist.put('Luke')
    waitlist.put('Issac')

Theme parks are big and lines can stretch hundred of people long. What is we wanted to see how many people are in line? We can use the `psize()` function:

    waitlist.psize()

Our output would be:

    5

### Exercise #2

Now we have added to the queue our five names. Jacob is first in our queue, then Slade, and so on until we reach Issac, who is last. We can demonstrate this by using the `for` loop, like so:

    for q_item in q.queue:
        print q_item

Our code returns the following:

    Jacob
    Slade
    Mathew
    Luke
    Issac

We can use the `full()` function to determine if the line has enough people to fill the ride:

    waitlist.full()

If we wanted to remove people as they enter the ride we would use the `get()` function:

    waitlist.get()

### Exercise #3

But what if someone decides the line is too long and decides to leave? We can remove a specific element from the queue with the `get()` as long as we know what the item is. For example, lets say Martin decided to cancel:

    waitlist.get('Luke')

Luckily in practically, we control when an item leaves the queue.

We can use the `empty()` function to determine if the line is empty:

    waitlist.empty()

## Advanced Problem Example

Reversing a Queue using stack:

For reversing a queue one approach could be to store the elements of the queue in a temporary data structure in a manner such that if we re-insert the elements in the queue they would get inserted in reverse order. So now our task is to choose such a data structure that can serve the purpose. According to the approach, the data structure should have the property of LIFO as the last element to be inserted in the data structure should actually be the first element of the reversed queue.

    from collections import deque
 
    # Function to reverse the queue
    def reversequeue(queue):
        Stack = []
    
        while (queue):
            Stack.append(queue[0])
            queue.popleft()
    
        while (len(Stack) != 0):
            queue.append(Stack[-1])
            Stack.pop()
 
    # Test function
    queue = deque([10, 20, 30, 40, 50, 60, 70, 80, 90, 100])
    reversequeue(queue)
    print(queue)

## Problems to Solve

Practice building and operating on a queue:
1) Create a queue that holds 16 integers.
2) Print the size and contents of the queue.
3) Remove the first item from queue.
4) Remove the ninth element from queue.
5) Check if the queue is full.
6) Add two more items to the queue.
7) Check is the queue is full again.
8) Try adding an additional item.
9) Create a function that performs a simple mathematicle operation on the queue value (such as adding 1) and then remove the item from queue.
10) Using recursion run each item in queue through the function
11) Create a function that adds a new item to queue when space is available.
12) Create a function that fills the queue only when the queue is empty