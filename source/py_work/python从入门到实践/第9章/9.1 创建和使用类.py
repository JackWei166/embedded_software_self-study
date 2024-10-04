
# 练习9-1：餐馆
class Restaurant:
	'''尝试模拟一个餐馆'''

	def __init__(self, restaurant_name, cuisine_type):
		'''初始化属性restaurant_name和cuisine_typr'''
		self.restaurant_name = restaurant_name
		self.cuisine_type = cuisine_type

	def describe_restaurant(self):
		'''描述餐馆'''
		print(f"The restaurant's name is {self.restaurant_name}.")
		print(f'Its cuisine type is {self.cuisine_type}.')

	def open_restaurant(self):
		'''打开餐厅'''
		print('The restaurant is opening.')

# my_restaurant = Restaurant('happy', 'light')

# print(my_restaurant.restaurant_name)
# print(my_restaurant.cuisine_type)
# my_restaurant.describe_restaurant()
# my_restaurant.open_restaurant()


# 练习9-2：三家餐馆
# my_restaurant = Restaurant('happy', 'light')
# your_restaurant = Restaurant('sad', 'oily')
# his_restaurant = Restaurant('pleasant', 'sweet')

# my_restaurant.describe_restaurant()
# your_restaurant.describe_restaurant()
# his_restaurant.describe_restaurant()



# 练习9-3：用户
class User:
	'''尝试模拟用户'''

	def __init__(self, first_name, last_name, location):
		'''初始化属性，名字，地址'''
		self.first_name = first_name
		self.last_name = last_name
		self.location = location

	def describe_user(self):
		'''描述用户'''
		print(f"The user's name is {self.first_name.title()} {self.last_name.title()}.")
		print(f'The user is in {self.location.title()}.')

	def greet_user(self):
		'''和用户打招呼'''
		print(f'Hello, {self.first_name.title()} {self.last_name.title()}!')


user_zs = User('zhang', 'san', 'beijing')
user_ls = User('li', 'si', 'shanghai')
user_ww = User('wang', 'wu', 'guangzhou')

user_zs.describe_user()
user_zs.greet_user()
user_ls.describe_user()
user_ls.greet_user()
user_ww.describe_user()
user_ww.greet_user()






