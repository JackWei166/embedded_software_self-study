
from user import User



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






























