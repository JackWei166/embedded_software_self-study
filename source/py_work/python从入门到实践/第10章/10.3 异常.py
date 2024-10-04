
# 练习10-6：加法运算
# num_1 = input('Please enter a number: ')
# try:
# 	num_1 = int(num_1)
# except ValueError:
# 	print('It is not a number. Please enter a number.')


# num_2 = input('Please enter another number: ')
# try:
# 	num_2 = int(num_2)
# except ValueError:
# 	print('It is not a number. Please enter a number.')

# num_sum = num_1 + num_2

# print(f'The sum of the two numbers is {num_sum}.')



# # 练习10-7：加法计算器 

# while True:
# 	num_1 = input('Please enter a number: ')
# 	if num_1 == 'q':
# 		break
# 	try:
# 		num_1 = int(num_1)
# 	except ValueError:
# 		print('It is not a number. Please enter a number.')
# 	else:
# 		num_1 = input('Please enter a number again: ')
	
	
# 	num_2 = input('Please enter another number: ')
# 	if num_1 == 'q':
# 		break
# 	try:
# 		num_2 = int(num_2)
# 	except ValueError:
# 		print('It is not a number. Please enter a number.')
# 	else:
# 		num_1 = input('Please enter a number again: ')

# 	num_sum = num_1 + num_2
	
# 	print(f'The sum of the two numbers is {num_sum}.')


# 练习10-8：猫和狗

# pets = ['cats.txt', 'dogs.txt', ]

# for pet in pets:
# 	try:
# 		with open(pet) as file:
# 			contents = file.read()
# 			print(contents)
# 			print('\n')
# 	except FileNotFoundError:
# 		print(f'The file "{pet}" is not found!')



# 练习10-9：静默的猫和狗 

# pets = ['cats.txt', 'dogs.txt', ]

# for pet in pets:
# 	try:
# 		with open(pet) as file:
# 			contents = file.read()
# 			print(contents)
# 			print('\n')
# 	except FileNotFoundError:
# 		pass


# 练习10-10：常见单词
with open('cats.txt') as file:
	contents = file.read()
	num = contents.lower().count('the')
	print(num)











