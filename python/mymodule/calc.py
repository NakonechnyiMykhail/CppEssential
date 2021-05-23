
class Calculator:
    number1 = 0
    number2 = 0

    def __init__(self):
        self.number1 = float(input("Enter a first number: "))
        self.number2 = float(input("Enter a second number: "))

    def add(self):
        return self.number1 + self.number2

    def minus(self):
        return self.number1 - self.number2

    def mult(self):
        return self.number1 * self.number2

    def deriv(self):
        return self.number1 / self.number2

    def deriv2(self):
        return self.number1 // self.number2

    def mod(self):
        return self.number1 % self.number2

    def get_number1(self):
        # TODO
        pass

    def get_number2(self):
        return self.number2

    def set_number1(self):
        self.number1 = float(input(""))

    def set_number2(self):
        # TODO
        pass
# calc = Calculator()
# print(calc.add())
