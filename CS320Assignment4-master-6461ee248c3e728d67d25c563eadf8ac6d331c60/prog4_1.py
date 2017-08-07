import sys
print("Assignment #4-1, Anas Khafagi, anas.khafagi@gmail.com")
fileName = sys.argv[1]
tokens = []
file = open(fileName, 'r')
for line in file:
    print(",".join(line.split()))