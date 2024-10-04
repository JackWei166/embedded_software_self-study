
# 练习10-11：喜欢的数
import json

# number = input('Please enter your favorite number: ')
# number = 1

# with open('favorite_number.txt', 'w') as file:
# 	json.dump(number, file)

# with open('favorite_number.txt') as file:
# 	num = json.load(file)
# 	print(f'I know your favorite number! It is {num}.')


# 练习10-12：记住喜欢的数 
# try:
# 	with open('favorite_number.txt') as file:
# 		num = json.load(file)
# 		print(f'I know your favorite number! It is {num}.')
# except FileNotFoundError:
# 	# number = input('Please enter your favorite number: ')
# 	number = 1
# 	with open('favorite_number.txt', 'w') as file:
# 		json.dump(number, file)


# 练习10-13：验证用户

import json

def get_stored_username():
 """如果存储了用户名，就获取它。"""
	filename = 'username.json'
 	try:
 		with open(filename) as f:
 		username = json.load(f)
 	except FileNotFoundError:
 		return None
 	else:
 		return username

def get_new_username():
 """提示用户输入用户名。"""
 	username = input("What is your name? ")
 	filename = 'username.json'
 	with open(filename, 'w') as f:
 		json.dump(username, f)
 		return username

def greet_user():
 """问候用户，并指出其名字。"""
 	username = get_stored_username()
 	if username:
 		user = input(f'Is the name "{username} true?(y or n)"')
 		if user == 'y'
 			print(f"Welcome back, {username}!")
 		else:
 			username = get_new_username()
 			print(f"We'll remember you when you come back, {username}!")
 	else:
 		username = get_new_username()
 		print(f"We'll remember you when you come back, {username}!")

greet_user()

























