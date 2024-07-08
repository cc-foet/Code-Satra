## Stacks & Queues

To check if the given string is a palindrome usign stack and queue, we first push every letter of the string in the stack and enqueue every letter into a queue simulataneously.

Then we check if the stack and the queue are the same by repeatedly poping and dequeueing and comparing them.

If at any point 2 letter are different we return false, else we return true.