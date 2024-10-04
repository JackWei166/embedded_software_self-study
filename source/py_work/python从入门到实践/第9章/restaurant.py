
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







