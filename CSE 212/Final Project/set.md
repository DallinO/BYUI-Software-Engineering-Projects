# Set
## Introduction

In this tutorial you will learn the how a ***Set*** differs to Lists, Tuple and Dictionaries. We will cover common set operations, and how to implement a set in python.

## Description

Sets are used to store multiple items in a single variable As mentioned before, a Set is one of the four built-in data types in Python used to store collections of data: List, Tuple, Dictionary, and Sets.

A set is a collection which is ***unordered***, ***unchangeable***, ***unindexed*** and do ***not*** allow duplicates

***Unordered*** means that the items in a set do not have a defined order. et items can appear in a different order every time you use them, and cannot be referred to by index or key.

Set items are ***unchangeable***, meaning that we cannot change the items after the set has been created. Once a set is created, you cannot change its items, but you can remove items and add new items.

## Operations

### *Access Set Items*

Since sets are not indexed, the only way to access an item is to loop through the contents using a `for` loop:

        my_set = {"red", "green", "blue"}

        for x in my_set:
            print(x)

Or by asking is a specific value is in the set by using the `in` keyword:

        print("green" in my_set)

### *Add Set Items*

To add an item to a set, use the `add()` method:

        my_set.add("yellow")

We can also add items from one set to another by using the `update()` method:

        set_1 = {"red", "green", "blue"}
        set_2 = {"yellow", "orange", "purple"}

        set_1.update(set_2)

You can use the `update()` method on any iterable object like lists and tuples:

        my_set = {"red", "green", "blue"}
        my_list = ["yellow", "orange", "purple"]

        my_set.update(my_list)

### *Remove Set Item*

While you can not change a set item, you can remove an item. We do this by using the `remove()` or the `discard()` method:

        my_set.remove("red")

Or
        
        my_set.discard("red")

The difference between `remove()` and `discard()` is that `remove()` will raise an error if the item does not exist, where as `discard()` will not.

You can use the `pop()` method to remove an item, however since sets are unordered it will always remove the ***last*** item.

        my_set.pop()

The `clear()` method will empty the entire set leaving it empty:

        my_set.clear()

The `del` keyword will delete the set completely:

        del my_set

### *Joining Sets*

There are several ways to join two or more sets in Python. As we mentioned before, you can use the `update()` method that inserts the items from the referenced set (or other iterable data structure) into the target set.

Another way is to use the `union()` method. This will return a ***new*** set with all the items:

        set_1 = {"red", "green", "blue"}
        set_2 = {"yellow", "orange", "purple"}

        set_3 = set_1.union(set_2)

It is important to note that `update()` and `union()` will ***exclude*** duplicates. In contrast to this, the `intersection_update()` method will keep ***only** duplicates:

    
        set_1.intersection_update(set_2)

Or you can use the `intersection()` method that will return a ***new*** set:

        set_3 = set_1.intersection(set_2)

If you want to keep all the items but ***exclude*** the duplicates you can use the `symmetric_difference_update()` method:

        set_1.symmetric_difference_update(set_2)

Or you can use the `symmetric_difference()` to create a ***new*** set with all the item excluding duplicates:

        set_3 = set_1.symmetric_difference(set_2)

### *Other Methods*

`copy()` - Returns a copy of the set. \
`difference()` - Returns a set containing the difference between two or more sets. \
`difference_update()` - Removes the items in this set that are also included in another, specified set. \
`isdisjoint()` - Returns whether two sets have a intersection or not. \
`issubset()` - Returns whether another set contains this set or not. 
`issuperset()` - Returns whether this set contains another set or not.

![](https://cdn-images-1.medium.com/max/1600/0*a02OPI3-TnbKXyub.png)

## Basic Example Problems
### Exercise #1

Check to see if "blue" is in the set.

        colors = {"red", "green", "blue"}

Solution:

        if "blue" in colors:
            print("Item found!")

Check to see if 47 is in the set.

        integers = {21, 64, 83, 47, 52, 95}

Solution:

        if 47 in colors:
            print("Item found!")

### Exercise #2

Use the `update()` method to add multiple items from *more_colors* to *colors*.

        colors = {"red", "green", "blue"}
        more_colors = {"yellow", "orange", "purple"}

Solution:

        colors.update(more_colors)

### Exercise #3

Use the `remove()` method to remove "yellow" from the *more_colors* set.

        more_colors = {"yellow", "orange", "purple"}

Solution:

        more_colors.remove("yellow")

Or

        more_colors.discard("yellow")

## Intermediate Example Problems
### Exercise #1

Determine wich sets are subsets of *alpha*. Remember that sets are ***unordered***.

        # Primary set:
        alpha = {3, 5, "yellow", 8, "red", "green", 8, "Blue", 9}
        # Possible subsets:
        beta = {5, "green", 0}
        gamma = {8, "yellow", 9, 8}
        delta = {2, "red"}

Solution:

        is_subset = beta.issubset(alpha)
        is_subset = gamma.issubset(alpha)
        is_subset = delta.issubset(alpha)

### Exercise #2

Determin if *alpha* and *beta* have an intersection.

        alpha = {4, 6, 2, 8, 0}
        beta = {1, 5, 7, 3, 9}

Solution:

        has_intersection = alpha.isdisjoint(beta)

### Exercise #3

Create a ***new*** list that stores all item ***except*** duplicate values in *alpha* and *beta*.

        alpha = {3, "green", 7, 4, "red", "blue", 9, 6, "orange"}
        beta = {8, 3, "blue", 9, 2, 5, "yellow", "pink", 7}

Solution:

        gamma = alpha.symmetric_difference(beta)

## Problems to solve

Practice building and operating on a set:
1) Create a set.
2) Add ten items to the set including one duplicate.
3) Remove the duplicate item.
4) Readd one instance of the item removed (the set should now only have nine items).
5) Display the contents of the set.
6) Add two more items to the queue.
7) Create a second set with the same number of items with several of the same elements, but ensure there are several differences.
8) Create a new set that holds the duplicates items from each set.
9) Update the newly made set to hold the non-duplicated items from the first two sets.
10) Empty then delete the set.
11) Create a function that pops an item from each set and compares them to see if they are the same.






