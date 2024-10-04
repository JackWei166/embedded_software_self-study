# 练习8-12：三明治
def make_sandwich(*ingredients):
	print('We will add these ingredients to sandwich: ')
	for ingredient in ingredients :
		print(ingredient)
	print('\n')

make_sandwich('egg', 'apple', 'bacon') 
make_sandwich('egg', 'pear', 'bacon')
make_sandwich('egg', 'lettuce', 'bacon')


# 练习8-13：用户简介
def build_profile(first, last, **user_info):
	user_info['first_name'] = first
	user_info['last_name'] = last
	return user_info

user_profile = build_profile('zhang', 'san', location='beijing', field='vehicle', hobby='reading')

print(user_profile)


# 练习8-14：汽车
def make_car(manu, model, **car_info):
	car_info['manufacturer'] = manu
	car_info['model'] = model
	return car_info

car_profile = make_car('changcheng', 'haval', color='white', tow_package='Ture')

print(car_profile)



















