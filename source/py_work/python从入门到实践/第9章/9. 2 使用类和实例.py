
# 练习9-4：就餐人数

class Restaurant:
	'''尝试模拟一个餐馆'''

	def __init__(self, restaurant_name, cuisine_type):
		'''初始化属性restaurant_name和cuisine_typr'''
		self.restaurant_name = restaurant_name
		self.cuisine_type = cuisine_type
		self.number_served = 0

	def describe_restaurant(self):
		'''描述餐馆'''
		print(f"The restaurant's name is {self.restaurant_name}.")
		print(f'Its cuisine type is {self.cuisine_type}.')

	def open_restaurant(self):
		'''打开餐厅'''
		print('The restaurant is opening.')

	def set_number_served(self, number):
		'''设置就餐人数'''
		self.number_served = number

	def increment_number_served(self, number):
		'''设置递增人数'''
		self.number_served += number


# restaurant = Restaurant('happy', 'light')

# print(f'The restaurant has served {restaurant.number_served} persons. ')

# restaurant.number_served = 200

# print(f'The restaurant has served {restaurant.number_served} persons. ')

# restaurant.set_number_served(300)

# print(f'The restaurant has served {restaurant.number_served} persons. ')

# restaurant.increment_number_served(100)

# print(f'The restaurant has served {restaurant.number_served} persons. ')



# 练习9-5：尝试登录次数

class User:
	'''尝试模拟用户'''

	def __init__(self, first_name, last_name, location):
		'''初始化属性，名字，地址'''
		self.first_name = first_name
		self.last_name = last_name
		self.location = location
		self.login_attempts = 0

	def describe_user(self):
		'''描述用户'''
		print(f"The user's name is {self.first_name.title()} {self.last_name.title()}.")
		print(f'The user is in {self.location.title()}.')

	def greet_user(self):
		'''和用户打招呼'''
		print(f'Hello, {self.first_name.title()} {self.last_name.title()}!')

	def increment_login_attempts(self):
		'''登录次数递增'''
		self.login_attempts += 1

	def reset_login_attempts(self):
		'''重置登录次数'''
		self.login_attempts = 0

user = User('li', 'sa', 'beijing')

count = 0
while count < 3 :
	user.increment_login_attempts()
	print(user.login_attempts)
	count += 1

user.reset_login_attempts()
print(user.login_attempts)





