class BST:

    class Node:


        def __init__(self, data):
       
            self.data = data
            self.left = None
            self.right = None

    def __init__(self):

        self.root = None

    def insert(self, data):

        if self.root is None:
            self.root = BST.Node(data)
        else:
            self._insert(data, self.root)  # Start at the root


    def _insert(self, data, node):

        if data < node.data:
            # The data belongs on the left side.
            if node.left is None:
                # We found an empty spot
                node.left = BST.Node(data)
            else:
                # Need to keep looking.  Call _insert
                # recursively on the left sub-tree.
                self._insert(data, node.left)
        elif data > node.data:
            # The data belongs on the right side.
            if node.right is None:
                # We found an empty spot
                node.right = BST.Node(data)
            else:
                # Need to keep looking.  Call _insert
                # recursively on the right sub-tree.
                self._insert(data, node.right)

    def __contains__(self, data):

        return self._contains(data, self.root)  # Start at the root


    def _contains(self, data, node):

        if data == node.data:
            # We found it!
            return True
        elif data < node.data:
            # Check the left side
            if node.left is None:
                # Nothing there ... doesn't exist
                return False
            else:
                # More data to check.  Call _contains
                # recursively on the left sub-tree
                return self._contains(data, node.left)
        else:
            # Check the right side
            if node.right is None:
                # Nothing there ... doesn't exist
                return False
            else:
                # More data to check.  Call _contains
                # recursively on the right sub-tree
                return self._contains(data, node.right)

            
    def __iter__(self):

        yield from self._traverse_forward(self.root)  # Start at the root
        
    def _traverse_forward(self, node):

        if node is not None:
            yield from self._traverse_forward(node.left)
            yield node.data
            yield from self._traverse_forward(node.right)
        
    def __reversed__(self):
      
        yield from self._traverse_backward(self.root)  # Start at the root


    def _traverse_backward(self, node):

        if node is not None:
            yield from self._traverse_backward(node.right)
            yield node.data
            yield from self._traverse_backward(node.left)

    def get_height(self):
   
        if self.root is None:
            return 0
        else:
            return self._get_height(self.root)  # Start at the root


    def _get_height(self, node):

        if node is None:
            # This will occur if the sub-tree is empty
            return 0
        else:
            # One plus the height of either the left or right
            # sub-tree (which ever one is bigger ... hence the use
            # of the max function)
            return 1 + max(self._get_height(node.left), self._get_height(node.right))


def create_bst_from_sorted_list(sorted_list):

    bst = BST()  # Create an empty BST to start with 
    _insert_middle(sorted_list, 0, len(sorted_list)-1, bst)
    return bst


def _insert_middle(sorted_list, first, last, bst):
    
    if first > last:
        # No more values to insert 
        return

    # Determine the middle relative to 'first' and 'last'
    middle = (last - first) // 2 + first

    # Insert the value into the BST
    bst.insert(sorted_list[middle])

    # Find the middle number in the first half of the list to add 
    _insert_middle(sorted_list, first, middle-1, bst)
    # Find the middle number in the second half of the list to add
    _insert_middle(sorted_list, middle+1, last, bst)
