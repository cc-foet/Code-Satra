class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()

    def is_empty(self):
        return len(self.items) == 0


class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)

    def is_empty(self):
        return len(self.items) == 0


def is_palindrome(string):
    stack = Stack()
    queue = Queue()

    for char in string:
        stack.push(char)
        queue.enqueue(char)

    while not stack.is_empty() and not queue.is_empty():
        if stack.pop() != queue.dequeue():
            return False

    return True


string = "CodeSatra"
print(is_palindrome(string))