"""
*Student name: Narkis kremizi
*Student ID: 205832447
*Course Exercise Group: 05
*Exercise name: ex1.py
"""
import math
print ("please enter a mission number:")
mission = int(input())
# Finish program for input = 0
while mission != 0:
    # Receiving a number and checking whether it is preliminary
    if mission == 1:
        print ("please enter the mission type:")
        efficiency = raw_input()
        # Check whether the input is preliminary by dividing the number in all the smaller numbers
        if efficiency == 'a':
            print ("please enter a number:")
            number = int(input())
            result = ''
            i = 2
            # Treatment in the case of 0,1 or 2 input and other numbers
            if (number == 0) or (number == 1):
                print("NO")
            elif number == 2:
                print("YES")
            else:
                # Dividing the number in all the smaller numbers, if remainder=0, the number is prime
                while i < number:
                    result = number % i
                    if result == 0:
                        print ("NO")
                        break
                    else:
                        i += 1
                if result != 0:
                    print ("YES")
        # Check whether the input is preliminary by dividing the number in numbers to its root
        elif efficiency == 'b':
            print ("please enter a number:")
            number = int(input())
            squareRoot = ''
            result = ''
            i = 2
            # Calculate the root of the number
            squareRoot = math.sqrt(number)
            # Treatment in the case of 0,1 or 2 input and other numbers
            if (number == 0) or (number == 1):
                print("NO")
            elif number == 2:
                print("YES")
            else:
                # Dividing the number in numbers to its root, if remainder=0, the number is prime
                while i < squareRoot:
                    result = number % i
                    if result == 0:
                        print ("NO")
                        break
                    else:
                        i += 1
                if result != 0:
                    print ("YES")
        # Check whether the input is preliminary by dividing the number in *odd* numbers to its root
        else:
            print ("please enter a number:")
            number = int(input())
            squareRoot = ''
            result = ''
            i = 3
            # Calculate the root of the number
            squareRoot = math.sqrt(number)
            # Treatment in the case of 0, 1 or even numbers input
            if (number == 0) or (number == 1) or (number % 2 == 0):
                print("NO")
            # Treatment in the case of 2 and 3 input
            elif (number == 2) or (number == 3):
                print("YES")
            # Treatment in the case of other numbers input
            else:
                # Dividing the number in odd numbers to its root, if remainder=0, the number is prime
                while i < squareRoot:
                    result = number % i
                    if result == 0:
                        print ("NO")
                        break
                    else:
                        i += 2
                if result != 0:
                    print ("YES")
    # Receiving two numbers and printing all numbers from 1-100 divided by them
    elif mission == 2:
        print ("please enter two numbers:")
        # Receiving two numbers with a space between them
        numbers = raw_input()
        # Split the numbers into single numbers
        newNumbers = numbers.split()
        number1 = int(newNumbers[0])
        number2 = int(newNumbers[1])
        i = 1
        result1 = ''
        result2 = ''
        results = []
        # Check which numbers from 1-100 are divided by the numbers we received
        while i <= 100:
            result1 = i % number1
            result2 = i % number2
            if result1 == 0 or result2 == 0:
                results.append(i)
            i += 1
        print results
    print ("please enter a mission number:")
    mission = int (input())
