def is_palindrome_string(input_string):
    stack = []
    for i in input_string:
        stack.append(i)
    reverse_string = ""
    while len(stack) != 0:
        reverse_string += stack.pop()
    if input_string == reverse_string:
        return True
    else:
        return False

input_string = 'CodeSatra'
print(is_palindrome_string(input_string))
