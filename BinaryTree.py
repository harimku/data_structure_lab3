from array import *
import numpy as np


# tree node definition
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    def get(self):
        return self.data
    def getLeft(self):
        return self.left
    def getRight(self):
        return self.right
    def setLeft(self, left):
        self.left = left
    def setRight(self, new_right):
        self.right = new_right
    def set(self,data):
        self.data = data
    node = property(get,set)
    left = property(getLeft,setLeft)
    right = property(getRight, setRight)


# Binary Tree 
class BinaryTree:
    def __init__(self):
        self.root = None

    def getRoot(self):
        return self.root

    def insert(self, data):
        pdata = TreeNode(data)
        if self.root is None:
            self.root = pdata
            return None

        runner = self.root
        while (runner):
            if (runner.node < data):
                if runner.right is None:
                    runner.right = pdata
                    return None
                else:
                    runner = runner.right
            elif (runner.node > data):
                if runner.left is None:
                    runner.left = pdata
                    return None
                else:
                    runner = runner.left
            else: # duplicate values -- how to handle?
                runner = pdata
                return None

    def search(self, data):
        runner = self.root
        while (runner):
            if (runner.node > data):
                if runner.left is None:
                    return None
                else:
                    runner = runner.left
            elif (runner.node < data):
                if runner.right is None:
                    return None
                else:
                    runner = runner.right
            else:
                return data

'''
    def PrintTree(self, root):
        arr = []
        runner = self.root
        done = false

        while (not done):
            if runner.node is not None:

'''


def main():       
    # Automated Test
    arr = [42, 68, 35, 1, 70, 25, 79, 59, 63, 65]

    bt = BinaryTree()
    for i in arr:
        bt.insert(i)

    x = bt.search(42)
    print(x)
    #bt.PrintTree()
    

    

if __name__ == '__main__':
    main()