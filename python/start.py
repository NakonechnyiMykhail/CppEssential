# #include <random>
# import random
# # random.randint(1, 100)
# import random as r
# # r.randint(1, 100)
from random import randint
# randint(1, 100)

# int number = 13;
number = 13
# std::string name = "sdsd";
name = "Mike" # 'Mike'

# printf("Hello, %s", name);
print("Hello,", name)
# std::string text = "Hello, " + name;
# printf("%s", text);
print("Hello, " + name)
# std::cout << "Enter your name: ";
# std::cin >> name;
#name = input("Enter your name: ") # -> str
#name = str(input("Enter your name: "))
#number0 = input("Enter your age: ")  # x str ! -> int
#number = int(input("Enter your age: ")) # x str ! -> int
#number2 = float(input("Enter your name: "))
#isReady = bool(input())
#print(number0 + str(5))

# True / False
# 'S'
# 13
# 13.2
# "SDS"
# [12, 23] # list
# {'sd1':23, 'sd2':22, 'sd3':55} # dict (c++: map)

# int array = {12, 11, 44, 22};
data = [12, 11, 53, 22]
# for (int i = 0; i < 'length'; ++i)
#{
#   std::cout << array[i] << std::endl;
#}
# for (const auto& el : data) # -> static array???
# {
#     std:: cout << el << std: : endl
# }
for i in data:
    print(i)
for number in [1, 2, 3, 4, 5, 6, 7]:
    print(number, end=',')
print()
for number in range(20):
    print(number, end=' ')
print()

for number in range(5, 20):
    print(number, end=' ')
print()
for number in range(0, 20, 2):
    print(number, end=' ')
print()

for number in range(5, 20):
    if number % 2 == 0:
        print('a', end='')
        print(number, end=' ')
    elif number % 2 != 0:
        print('b', end='')
        print(number, end=' ')
    else:
        print('c', end='')
        print(number, end=' ')
print()
n, m = 3, 3
while True:
    print(n, end=":")
    n += 2
    if n > 20:
        break
print()
while m < 20:
    print(m, end=":")
    m += 3

random_number = randint(1, 100)
print(random_number)
print(randint(1, 100))
print(randint(1, 100))
