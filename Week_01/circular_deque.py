class MyCircularDeque(object):

    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        :type k: int
        """
        self.size = k
        self.elements = []
        self.rear = -1

    def insertFront(self, value):
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.rear < self.size - 1:
            self.elements.insert(0,value)
            self.rear += 1
            return True
        else:
            return False
            

    def insertLast(self, value):
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.rear < self.size - 1:
            self.elements.append(value)
            self.rear += 1
            return True
        else:
            return False
        

    def deleteFront(self):
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        if self.rear != -1:
            self.elements.pop(0)
            self.rear -= 1
            return True
        else:
            return False

        
    def deleteLast(self):
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        if self.rear != -1:
            self.elements.pop()
            self.rear -= 1
            return True
        else:
            return False
        

    def getFront(self):
        """
        Get the front item from the deque.
        :rtype: int
        """
        if self.rear > -1:
            return self.elements[0]
        else:
            return -1
        

    def getRear(self):
        """
        Get the last item from the deque.
        :rtype: int
        """
        if self.rear > -1:
            return self.elements[self.rear]
        else:
            return -1
        

    def isEmpty(self):
        """
        Checks whether the circular deque is empty or not.
        :rtype: bool
        """
        if self.rear > -1:
            return False
        else:
            return True
        

    def isFull(self):
        """
        Checks whether the circular deque is full or not.
        :rtype: bool
        """
        if self.rear < self.size - 1:
            return False
        else:
            return True


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
