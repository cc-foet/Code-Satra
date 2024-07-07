# this code take the list of customers bills and 
# return True if possible to provide change,  else return False


def lemonadeChange(bills):
    """
    Determine if you can provide the correct change to every customer in the queue.
    
    Parameters:
    bills (List[int]): List of integers representing the bills that customers pay with.
    
    Returns:
    bool: True if you can provide the correct change to every customer, False otherwise.
    """
    five_dollar_count = 0  # Counter for the number of $5 bills
    ten_dollar_count = 0   # Counter for the number of $10 bills

    # Iterate through each bill in the list
    for bill in bills:
        if bill == 5:
            # If the customer pays with a $5 bill, increment the $5 bill counter
            five_dollar_count += 1
        elif bill == 10:
            # If the customer pays with a $10 bill, check for a $5 bill for change
            if five_dollar_count == 0:
                return False  # Cannot provide change
            five_dollar_count -= 1  # Provide one $5 bill as change
            ten_dollar_count += 1   # Increment the $10 bill counter
        elif bill == 20:
            # If the customer pays with a $20 bill, try to provide change
            if ten_dollar_count > 0 and five_dollar_count > 0:
                # Prefer to give one $10 bill and one $5 bill as change
                ten_dollar_count -= 1
                five_dollar_count -= 1
            elif five_dollar_count >= 3:
                # Otherwise, give three $5 bills as change
                five_dollar_count -= 3
            else:
                return False  # Cannot provide change

    return True  # Successfully provided change to all customers

# Example usage:
bills = [5, 5, 5, 10, 20, 10, 10]
print(lemonadeChange(bills))  # Output: False

# Code by- Vikas Saroj
