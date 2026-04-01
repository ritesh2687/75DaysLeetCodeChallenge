class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []

        for token in tokens:
            if token in "+-*/":
                b = stack.pop()
                a = stack.pop()

                if token == "+":
                    stack.append(a + b)
                elif token == "-":
                    stack.append(a - b)
                elif token == "*":
                    stack.append(a * b)
                else:
                    # safer integer division (truncate toward zero)
                    res = abs(a) // abs(b)
                    if (a < 0) ^ (b < 0):  # XOR for sign
                        res = -res
                    stack.append(res)
            else:
                stack.append(int(token))

        return stack[-1]    