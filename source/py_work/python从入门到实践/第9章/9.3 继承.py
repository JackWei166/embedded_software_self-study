
# 练习9-6：冰激凌小店 

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


class IceCreamStand(Restaurant):
	'''继承餐馆父类'''

	def __init__(self, restaurant_name, cuisine_typr):
		'''初始化属性'''
		super().__init__(restaurant_name, cuisine_typr)
		self.flavors = ['apple', 'milk', 'banana', ]

	def show_flavors(self):
		'''展示冰激凌口味'''
		print('Our icecream has these flavors: ')
		for flavor in self.flavors :
			print(flavor)

# icestand = IceCreamStand('ice', 'cold')

# icestand.show_flavors()





# 练习9-7：管理员 

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


class Admin(User):
	'''继承用户父类'''

	def __init__(self, first_name, last_name, location):
		'''初始化属性'''
		super().__init__(first_name, last_name, location)
		self.privileges = ['can add post', 'can delete post', 'can ban user', ]

	def show_privileges(self):
		'''展示管理员特权'''
		print('Admin has these privileges: ')
		for privilege in self.privileges :
			print(privilege)


# admin = Admin('zhang', 'san', 'beijing')

# admin.show_privileges()





# 练习9-8：权限 

class Privileges:
	'''模拟权限'''

	def __init__(self):
		'''初始化属性权限'''
		self.privileges = ['can add post', 'can delete post', 'can ban user', ]

	def show_privileges(self):
		print('Admin has these privileges: ')
		for privilege in self.privileges :
			print(privilege)


class Admin(User):
	'''继承用户父类'''

	def __init__(self, first_name, last_name, location):
		'''初始化属性'''
		super().__init__(first_name, last_name, location)
		self.privileges = Privileges()

# admin = Admin('zhang', 'san', 'beijing')

# admin.privileges.show_privileges()





# 练习9-9：电瓶升级
# 缩进有问题，觉得一时半会儿可能解决不了，以后再说。

class Car:
	def __init__(self, make, model, year):
 		self.make = make
 		self.model = model
 		self.year = year
 		self.odometer_reading = 0
 
	def get_descriptive_name(self):
 		long_name = f"{self.year} {self.make} {self.model}"
 		return long_name.title()
 
	def read_odometer(self):
 		print(f"This car has {self.odometer_reading} miles on it.")

	def update_odometer(self, mileage):
 		if mileage >= self.odometer_reading:
 			self.odometer_reading = mileage
 		else:
 			print("You can't roll back an odometer!")

	def increment_odometer(self, miles):
 		self.odometer_reading += miles


class Battery:
 	"""一次模拟电动汽车电瓶的简单尝试。"""

	def __init__(self, battery_size=75):
 		"""初始化电瓶的属性。"""
 		self.battery_size = battery_size

	def describe_battery(self):
 		"""打印一条描述电瓶容量的消息。"""
 		print(f"This car has a {self.battery_size}-kWh battery.")
 
 	def get_range(self):
 		"""打印一条消息，指出电瓶的续航里程。"""
 		if self.battery_size == 75:
 			range = 260
 		elif self.battery_size == 100:
 		 	range = 315
 		 	print(f"This car can go about {range} miles on a full charge.")


class ElectricCar(Car):
 	"""电动汽车的独特之处。"""
 	
 	def __init__(self, make, model, year):
	super().__init__(make, model, year)
	self.battery = Battery()
 

my_tesla = ElectricCar('tesla', 'model s', 2019)
print(my_tesla.get_descriptive_name())
my_tesla.battery.describe_battery()
















