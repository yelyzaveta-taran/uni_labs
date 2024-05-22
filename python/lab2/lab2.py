while True: 
    operation_type = input("Enter one of the following types of operations: ** or 1:7\nTo end the program enter 'e' character\n")
    if operation_type == "e":
        break
    number = int(input("Enter a number to operate with: "))
    if operation_type == "**":
        exponent = int(input("Enter a number of exponent: "))
        print(pow(number, exponent))
    elif operation_type == "1:7":
        result = ""
        for i in str(number):
            if i == "1":
                result += "7"
            else:
                result += i
        print(result)
    else:
        print("Incorrect type of operation")
