#练习4-10：切片
numlist=list(range(1,21,2))
for num in numlist :
    print(num)

print('The first three items in the list are:')
for num in numlist[:3] :
    print(num)

print('Three items from the middle of the list are:')
for num in numlist[3:6] :
    print(num)

print('The last three items in the list are:')
for num in numlist[7:] :
    print(num)


#练习4-11：你的比萨，我的比萨
pizzas=['a pizza','b pizza','c pizza']

friend_pizzas=pizzas[:]

pizzas.append('d pizza')
friend_pizzas.append('e pizza')

print('My favorite pizzas are:')
for pizza in pizzas:
    print(pizza)

print("My friend's favorite pizzas are:")
for pizza in friend_pizzas:
    print(pizza)


#练习4-12：使用多个循环
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods[:]

print("My favorite foods are:")
for food in my_foods:
    print(food)

print("\nMy friend's favorite foods are:")
for food in friend_foods:
    print(food)

