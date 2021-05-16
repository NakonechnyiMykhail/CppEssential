
class Calculator:
    number1 = 0
    number2 = 0

    def __init__(self):
        self.number1 = float(input("Enter a first number: "))
        self.number2 = float(input("Enter a second number: "))

    def add(self):
        return self.number1 + self.number2

# calc = Calculator()
# print(calc.add())