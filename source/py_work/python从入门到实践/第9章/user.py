

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



