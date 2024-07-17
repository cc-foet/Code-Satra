## Greedy Algorithm

To start we first need to sort our array. We can use any algorithm for this purpose.

Next we us 2 counters, one for \$5 bills and one for \$10 bills.

Now we iterate over every element of the array. If its 5 then we increment the \$5 counter, if its 10 then we increment the \$10 counter and decrement the \$5 counter and if it's 20 then we check if we have a \$10 bill. If we have one, we decrement both \$10 and \$5 counters. If not we decrement \$5 by 3.

If at any time we don't have enough bills for the change we return False. Else we return True.