while True: 
    operation_type = input("Enter one of the following types of operations: ** or 1:7\nTo end the program enter 'q' character\n")

    if operation_type == "q":
        print("See you later!\n")
        break

    if operation_type != "**" and operation_type != "1:7":
        print("Error! Incorrect type of operation\n")
        continue

    number = int(input("Enter an integer number to operate with: "))

    if operation_type == "**":
        exponent = int(input("Enter an integer number of exponent: "))
        print(number ** exponent)
    else:
        result = ""
        for i in str(number):
            if i == "1":
                result += "7"
            else:
                result += i
        print(result)

    print("Success!\n")
