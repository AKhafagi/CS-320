class StackMachine(object):
    def __init__(self):
        self.tokens = []

    def push(self, arg):
        if arg is None:
            return
        self.tokens.append(arg)

    def pop(self):
        if not self.tokens:
            return None
        return self.tokens.pop();

    def add(self):
        if len(self.tokens) < 2:
            return
        arg1 = int(self.tokens.pop())
        arg2 = int(self.tokens.pop())
        answer = (arg1 + arg2)
        self.push(answer)

    def sub(self):
        if len(self.tokens) < 2:
            return
        arg1 = int(self.tokens.pop())
        arg2 = int(self.tokens.pop())
        answer = arg1 - arg2
        self.push(answer)

    def mul(self):
        if len(self.tokens) < 2:
            return
        arg1 = int(self.tokens.pop())
        arg2 = int(self.tokens.pop())
        answer = arg1 * arg2
        self.push(answer)

    def div(self):
        if len(self.tokens) < 2:
            return
        arg1 = int(self.tokens.pop())
        arg2 = int(self.tokens.pop())
        answer = arg1 / arg2
        self.push(int(answer))

    def mod(self):
        if len(self.tokens) < 2:
            return
        arg1 = int(self.tokens.pop())
        arg2 = int(self.tokens.pop())
        answer = arg1 % arg2
        self.push(answer)
