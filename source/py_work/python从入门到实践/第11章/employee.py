class Employee:
	def __init__(self, last_name, first_name, annual_salary):
		self.last_name = last_name
		self.first_name = first_name
		self.annual_salary = annual_salary

	def give_raise(self, increasement=5000):
		self.annual_salary += increasement


# a_employee = Employee('san', 'zhang', 80000)
# print(a_employee.annual_salary)
# a_employee.give_raise()
# print(a_employee.annual_salary)
# a_employee.give_raise(1000)
# print(a_employee.annual_salary)


















