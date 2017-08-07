import sys
from StackMachine import StackMachine
stack = StackMachine()
print("Assignment #4-2, Anas Khafagi, anas.khafagi@gmail.com")
fileName = sys.argv[1]
tokens = []
file = open(fileName, 'r')
for line in file:
    tokens = line.split();
    if len(tokens) == 2:
        if tokens[0] == "push" and tokens[1].isnumeric():
            stack.push(tokens[1])
    elif len(tokens) == 1:
        if tokens[0] == "pop":
            print(stack.pop())
        elif tokens[0] == "add":
            stack.add()
        elif tokens[0] == "sub":
            stack.sub()
        elif tokens[0] == "mul":
            stack.mul()
        elif tokens[0] == "div":
            stack.div()
        elif tokens[0] == "mod":
            stack.mod()
        else:
            continue
