# import unittest
# from employee import Employee

# class TestEmployee(unittest.TestCase):
# 	def test_give_default_raise(self):
# 		an_employee = Employee('san', 'zhang', 80000)
# 		an_employee.give_raise()
# 		self.assertEqual(an_employee.annual_salary, 85000)

# 	def test_give_custom_raise(self):
# 		an_employee = Employee('san', 'zhang', 80000)
# 		an_employee.give_raise(10000)
# 		self.assertEqual(an_employee.annual_salary, 90000)

# if __name__ == '__main__':
# 	unittest.main()




import unittest
from employee import Employee

class TestEmployee(unittest.TestCase):
	def setUp(self):
		self.an_employee = Employee('san', 'zhang', 80000)

	def test_give_default_raise(self):
		self.an_employee.give_raise()
		self.assertEqual(self.an_employee.annual_salary, 85000)

	def test_give_custom_raise(self):
		self.an_employee.give_raise(10000)
		self.assertEqual(self.an_employee.annual_salary, 90000)

if __name__ == '__main__':
	unittest.main()

































