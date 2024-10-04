# 练习7-4：比萨配料
pizza_ingredient = ''

while pizza_ingredient != 'quit' :
	pizza_ingredient = input('Please enter some ingredients you want to add: ')
	if pizza_ingredient != 'quit' :
		print(f'We will add {pizza_ingredient} to your pizza.')


# 习7-5：电影票
age = ''

while age != 'quit' :
	age = input('Please enter your age: ')
	if age != 'quit' :
		age = int(age)
		if age < 0 :
			print('Error!')
		elif age < 3 :
			print('You are free to see a movie.')
		elif age <= 12 :
			print('You should pay 10 dollors to see a movie.')
		else :
			print('You should pay 15 dollors to see a movie.')

# 练习7-6：三种出路
active = True
while active :
	pizza_ingredient = input('Please enter some ingredients you want to add: ')
	if pizza_ingredient != 'quit' :
		print(f'We will add {pizza_ingredient} to your pizza.')
	else :
		active = False


while True :
	pizza_ingredient = input('Please enter some ingredients you want to add: ')
	if pizza_ingredient != 'quit' :
		print(f'We will add {pizza_ingredient} to your pizza.')
	else :
		break


active = True
while active :
	age = input('Please enter your age: ')
	if age != 'quit' :
		age = int(age)
		if age < 0 :
			print('Error!')
		elif age < 3 :
			print('You are free to see a movie.')
		elif age <= 12 :
			print('You should pay 10 dollors to see a movie.')
		else :
			print('You should pay 15 dollors to see a movie.')
	else :
		active = False


while True :
	age = input('Please enter your age: ')
	if age != 'quit' :
		age = int(age)
		if age < 0 :
			print('Error!')
		elif age < 3 :
			print('You are free to see a movie.')
		elif age <= 12 :
			print('You should pay 10 dollors to see a movie.')
		else :
			print('You should pay 15 dollors to see a movie.')
	else :
		break


# 练习7-7：无限循环
a = 1
while a >= 1 :
	print(a)













