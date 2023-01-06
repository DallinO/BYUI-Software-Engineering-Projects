# Tree
## Introduction

In this tutorial you will learn the how a ***tree*** differs from other common linear data structures. We will cover terminology associated with a tree, common tree operations, and how to implement a tree in python.

Note: this section requires one to have an understanding of class and basic object-orientated programming.

## Description

A ***tree*** is a popular non-linear data-structure. Unlike other data structures like an array, stack, queue, and linked list which are linear in nature, a tree represents a hierarchical structure. The ordering information of a tree is not important. A tree contains nodes and 2 pointers. These two pointers are the left child and the right child of the parent node.

## Terminology

`Root`: The root of a tree is the topmost node of the tree that has no parent node. There is only ***one*** root node in every tree. \
`Parent Node`: The predecessor of a node is called the parent node. \
`Child Node`: The immediate successor of a node is called the child node. \
`Sibling`: Children of the same parent node are called siblings. \
`Edge`: Edge acts as a link between the parent node and the child node. \
`Leaf`: A node that has no child is known as the leaf node. It is the last node of the tree. There can be ***multiple*** leaf nodes in a tree. \
`Subtree`: The subtree of a node is the tree considering that particular node as the root node. \
`Depth`: The depth of the node is the distance from the root node to that particular node. \
`Height`: The height of the node is the distance from that node to the deepest node of that subtree. \
`Height of tree`: The Height of the tree is the maximum height of any node. This is the same as the height of the root node. \
`Level`: A level is the number of parent nodes corresponding to a given node of the tree. \
`Degree of node`:  The degree of a node is the number of its children. \
`NULL`: The number of NULL nodes in a binary tree is (N+1), where N is the number of nodes in a binary tree.

![](https://imgs.search.brave.com/seE49yBfoSIWxFVOT4BukkqR69U73ebhpEpQtzut2eI/rs:fit:1200:892:1/g:ce/aHR0cHM6Ly9taXJv/Lm1lZGl1bS5jb20v/bWF4LzM1MTYvMSp0/VUJZQ0hpMzJaajBC/MlVDdzBxbWxBLnBu/Zw)

## Implimentation

Like a queue, a tree is not a specific built-in data type. Just as you can use different methods to create a queue, there are multple ways to create a tree. The most common way is through defining the tree through a class. We fill focus on this method.

Here is an example of a tree class:

        # Creating node class
        class Node:
            def __init__(self, data):
                self.data = data
                self.left = None
                self.right = None

To do basic operations on a tree such as inserting or removing items we have to build our own methods within the node class which we will cover next.

## Basic Example Problems

### Exercise #1

Lets practice implimenting the operations we previously learned in Python. The full class declartion is attached as `tree_class.py`. Please review the file ***before*** continueing so you understand how to reference the objects and methods correctly.

First lets create a new tree:

        tree = BST()

Now we can add some nodes to our tree:

        tree.insert(8)
        tree.insert(2)
        tree.insert(5)  
        tree.insert(9)
        tree.insert(16)
        tree.insert(11)
        tree.insert(6)

***Practice***: Which of these nodes are the parent and child nodes of eachother? Which node is the root? Which are the leaves?

### Exercise #2

As we expand our tree, we should add a method to print the contents of the tree:

        def PrintTree(self):
            if self.left:
                self.left.PrintTree()
            print( self.data),
            if self.right:
                self.right.PrintTree()

### Exercise #3

Another foundational method to include is one that checks to see if the a single node or the entire tree is empty:

We can check to see if the root or child nodes are empty:

        # Checking full binary tree
        def IsFullTree(root):

            # Tree empty case
            if root is None:
                return True

            # Checking whether child is present
            if root.left is None and root.right is None:
                return True

            if root.left is not None and root.
            right is not None:
                return (IsFullTree(root.left) and
                IsFullTree(root.right))

            return False

## Intermediate Example Problems

### Exercise #1

Trees can grow to be extremly large. Lets practice creating a mehtod that will return the `height` of the tree:

        def GetHeight(self, node):
    
            if node is None:
                # This will occur if the sub-tree is empty
                return 0
            else:
                # One plus the height of either the left or right
                # sub-tree (which ever one is bigger ... hence the use
                # of the max function)
                return 1 + max(self.GetHeight(node.left),
                self.GetHeight(node.right))


### Exercise #2

What if we wanted to `traverse` the contents of our tree. How would we do this? Since there are no built in methods for this, we need to create our own method:

        def TraverseForward(self, node):
        
            if node is not None:
                yield from self.TraverseForward(node.left)
                yield node.data
                yield from self.TraverseForward(node.right)

By defualt, traversing occurs from left to right, but we can add a backwards traverse method:

        def TraverseBackward(self, node):

            if node is not None:
                yield from self.TraverseBackward(node.right)
                yield node.data
                yield from self.TraverseBackward(node.left)

### Exercise #3

Adding values are an essential part of working with trees.Next lets create a method to insert values:

        def Insert(self, data):
            # if value is lesser than the value of the parent node
            if data < self.data:
                if self.left:
                    # if we still need to move towards the left subtree
                    self.left.insert(data)
                else:
                    self.left = Node(data)
                    return
            # if value is greater than the value of the parent node        
            else:
                if self.right:
                    # if we still need to move towards the right subtree
                    self.right.insert(data)
                else:
                    self.right = Node(data)
                    return

We also need a method to check to see if the tree contains a value:

        def Contains(self, data, node):
           
            if data == node.data:
                # We found it!
                return True
            elif data < node.data:
                # Check the left side
                if node.left is None:
                    # Nothing there ... doesn't exist
                    return False
                else:
                    # More data to check.  Call Contains
                    # recursively on the left sub-tree
                    return self.Contains(data, node.left)
            else:
                # Check the right side
                if node.right is None:
                    # Nothing there ... doesn't exist
                    return False
                else:
                    # More data to check.  Call Contains
                    # recursively on the right sub-tree
                    return self.Contains(data, node.right)

## Problems to solve

1) Create a tree.
2) Add nine items to the tree including one with the value of '6'.
3) Check the tree to see if '6' is already contained.
4) Create a method that gives the node with the smallest value.
5) Create a method that removes a leaf node.
6) Create a method that returns the closest node value from a given target value.
7) Create a method that transfers a nested list into a `BST` object. **Note: trees can also be built from nested lists or dictionaries. This is to practice converting data types.* 
8) Create a method that transfers a dictionary into a `BST` object.
9) Create a method that reads in values from a json file and creates a `BST` object from that data.




