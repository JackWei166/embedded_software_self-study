import unittest
from city_functions import city_function

class CITIESTestCase(unittest.TestCase):
	def test_city_function_1(self):
		info = city_function('beijing', 'china')
		self.assertEqual(info, 'Beijing China')

	def test_city_function_2(self):
			info = city_function('beijing', 'china', 21000000)
			self.assertEqual(info, 'Beijing, China - population 21000000')


if __name__ == '__main__':
	unittest.main()
































