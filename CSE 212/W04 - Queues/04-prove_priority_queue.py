"""
CSE212 
(c) BYU-Idaho
04-Prove - Problem 2 - Solution

It is a violation of BYU-Idaho Honor Code to post or share this code with others or 
to post it online.  

This solution should not be shared with students.
"""

class Priority_Queue:
    """
    This queue follows the same FIFO process except that higher priority
    nodes will be dequeued before lower priority nodes.  Nodes of the same
    priority will follow the same FIFO process.
    """

    class Node:
        """
        Each node is the queue will have both a value and a priority.
        """

        def __init__(self, value, priority):
            """
            Initialize a new node
            """
            self.value = value
            self.priority = priority

        def __str__(self):
            """
            Display a single node
            """
            return "{} (Pri:{})".format(self.value, self.priority)

    def __init__(self):
        """ 
        Initialize an empty priority queue
        """
        self.queue = []

    def enqueue(self, value, priority):
        """
        Add a new value to the queue with an associated priority.  The
        node is always added to the back of the queue irregardless of 
        the priority.
        """
        #new_node = Priority_Queue.Node(priority, value)  --- Defect #1
        new_node = Priority_Queue.Node(value, priority)
        self.queue.append(new_node)

    def dequeue(self):
        """
        Remove the next value from the queue based on the priority.  The 
        highest priority item will be removed.  In the case of multiple
        values with the same high priority, the one closest to the front
        (in traditional FIFO order) will be removed.
        """
        if len(self.queue) == 0:  # Verify the queue is not empty
            print("The queue is empty.")
            return None
        # Find the index of the item with the highest priority to remove
        high_pri_index = 0
        for index in range(1, len(self.queue)):
            #if self.queue[index].priority >= self.queue[high_pri_index].priority:    ---- Defect #2        
            if self.queue[index].priority > self.queue[high_pri_index].priority:
                high_pri_index = index
        # Remove and return the item with the highest priority
        value = self.queue[high_pri_index].value
        del self.queue[high_pri_index]            # ---- Defect #3 ... this line was missing
        return value
        
    def __len__(self):
        """
        Support the len() function
        """
        return len(self.queue)

    def __str__(self):
        """ 
        Suppport the str() function to provide a string representation of the
        priority queue.
        """
        result = "["
        for node in self.queue:
            result += str(node)  # This uses the __str__ from the Node class
            result += ", "
        result += "]"
        return result

# Test Cases

# Test 1
# Scenario: Can I enqueue a value and dequeue it?
# Exepcted Result: It should display 100
print("Test 1")
queue = Priority_Queue()
queue.enqueue(100, 5)
value = queue.dequeue()
print(value)
# Defect(s) Found: The function is switching the value and the priority

print("=================")

# Test 2
# Scenario: Can I enqueue multiple values with different priority and 
#           dequeue them in the proper priority order?
# Exepcted Result: It should display 300, 400, then 200
print("Test 2")
queue = Priority_Queue()
queue.enqueue(200, 2)
queue.enqueue(300, 6)
queue.enqueue(400, 4)
print(queue.dequeue())
print(queue.dequeue())
print(queue.dequeue())
# Defect(s) Found: Needed to remove item from queue

print("=================")

# Test 3
# Scenario: Can I enqueue multiple values with some value having the same
#           priority and dequeue them to ensure that items with the same
#           priority follow the FIFO order?
# Exepcted Result: It should display 1000, 600, 700, 900, 800, 500
print("Test 3")
queue = Priority_Queue()
queue.enqueue(500, 8)
queue.enqueue(600, 15)
queue.enqueue(700, 15)
queue.enqueue(800, 10)
queue.enqueue(900, 15)
queue.enqueue(1000, 30)
print(queue.dequeue())
print(queue.dequeue())
print(queue.dequeue())
print(queue.dequeue())
print(queue.dequeue())
print(queue.dequeue())
# Defect(s) Found: Switch >= to just >

print("=================")

# Test 4
# Scenario: Can I dequeue from an empty queue?
# Exepcted Result: It should display an error message.
print("Test 4")
queue = Priority_Queue()
queue.dequeue()
# Defect(s) Found: None