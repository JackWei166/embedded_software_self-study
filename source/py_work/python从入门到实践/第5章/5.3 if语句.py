#练习5-3：外星人颜色
alien_color='green'

if alien_color=='green':
    print('You got 5 points.\n')

alien_color='red'

if alien_color=='green':
    print('You got 5 points.\n')


#练习5-4：外星人颜色2
alien_color = 'green'

if alien_color == 'green' :
    print('You got 5 points.\n')
else :
    print('You got 10 points.\n')

alien_color = 'red'

if alien_color == 'green' :
    print('You got 5 points.\n')
else :
    print('You got 10 points.\n')


#练习5-5：外星人颜色3
alien_color = 'green'

if alien_color == 'green' :
    print('You got 5 points.\n')
elif alien_color == 'yellow' :
    print('You got 10 points.\n')
else :
    print('You got 15 points.\n')

alien_color = 'yellow'

if alien_color == 'green' :
    print('You got 5 points.\n')
elif alien_color == 'yellow' :
    print('You got 10 points.\n')
else :
    print('You got 15 points.\n')

alien_color = 'yellow'

if alien_color == 'green' :
    print('You got 5 points.\n')
elif alien_color == 'yellow' :
    print('You got 10 points.\n')
else :
    print('You got 15 points.\n')


#练习5-6：人生的不同阶段
age = 26

if age < 2 :
    print('He is a baby.\n')
elif age < 4 :
    print('He is a toddler.\n')
elif age < 13 :
    print('He is a child.\n')
elif age < 20 :
    print('He is an adolescent.\n')
elif age < 65 :
    print('He is an adult.\n')
else :
    print('He is the aged.\n')


#练习5-7：喜欢的水果
fruits = ['banana', 'apple', 'pear', 'orange', 'strawberry']
favorite_fruits = ['banana', 'apple', 'pear']

if fruits[0] in favorite_fruits :
    print(f'You really like {fruits[0]}!\n') 
if fruits[1] in favorite_fruits :
    print(f'You really like {fruits[1]}!\n')
if fruits[2] in favorite_fruits :
    print(f'You really like {fruits[2]}!\n')
if fruits[3] in favorite_fruits :
    print(f'You really like {fruits[3]}!\n')
if fruits[4] in favorite_fruits :
    print(f'You really like {fruits[4]}!\n')

for fruit in fruits :
    if fruit in favorite_fruits :
        print(f'You really like {fruit}!\n') 




