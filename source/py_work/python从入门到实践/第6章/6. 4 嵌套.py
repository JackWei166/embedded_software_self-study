#练习6-7：人们
Wman = {'first_name': 'Wei', 'last_name': 'Man', 'age': 32, 'city': 'Tian Jin', }
Zsan = {'first_name': 'Zhang', 'last_name': 'San', 'age': 33, 'city': 'Bei Jing', }
Lsi = {'first_name': 'Li', 'last_name': 'Si', 'age': 34, 'city': 'Bei Jing', }

people = [Wman, Zsan, Lsi, ]

for person in people :
	print(person['first_name'])
	print(person['last_name'])
	print(person['age'])
	print(person['city'])
	print('\n')

for person in people :
	for k, v in person.items() : 
		print(f'{k}: {v}')
	print('\n')


#练习6-8：宠物
dog = {'type': 'dog', 'the_name_of_its_owner': 'Tom', }
cat = {'type': 'cat', 'the_name_of_its_owner': 'John', }

pets = [dog, cat, ]

for pet in pets :
	for k, v in pet.items() :
		print(f'{k}: {v}')
	print('\n')


#练习6-9：喜欢的地方
favorite_places = {
	'Zhang San': ['Beijing', ], 
	'Li Si': ['Beijing', 'Shanghai', ], 
	'Wang Wu': ['Beijing', 'Shanghai', 'Guangzhou', ], 
	}

for k, v in favorite_places.items() :
	print(f"{k}'s favorite place(s) is(are):")
	for place in v :
		print(place)
	print('\n')


#练习6-10：喜欢的数2
favorite_nums = {
	'Zhang San': [1, 2, ], 
	'Li Si': [3, 4, ], 
	'Wang Wu': [5, 6, ], 
	'Zhao Liu': [7, 8, ], 
	'Qian Qi': [9, 10, ], 
	}

for name, nums in favorite_nums.items() :
	print(f"{name}'s favorite number(s) is(are):")
	for num in nums :
		print(num)
	print('\n')


#练习6-11：城市
# cities = {
# 	'Beijing': {'country': 'China', 'population': '21 million', 'fact': "Beijing is the world's most populous national capital city.", }, 
# 	'Shanghai': {'country': 'China', 'population': '25 million', 'fact': "The population of the city proper is the third most populous in the world."}, 
# 	'Guangzhou': {'country': 'China', 'population': '18 million', 'fact': "Guangzhou is a major centre of research and innovation in the Asia-Pacific.", }, 
# 	}

# for city, info in cities.items() :
# 	print(f'Some infomation of {city}:')
# 	for k, v in info.items() :
# 		print(f'{k}: {v}')
# 	print('\n')


#练习6-12：扩展
users = {
	'aeinstein': {
		'first': 'albert',
		'last': 'einstein',
		'location': 'princeton',
		}, 
	'mcurie': {
		'first': 'marie',
		'last': 'curie',
		'location': 'paris',
		}, 
	'zsan' : {
		'first' : 'zhang', 
		'last' : 'san', 
		'location' : 'beijing', 	 
		}, 
	}

for username, u  ser_info in  .items():
	print(f"\nUsername: {username}")
	full_name = f"{user_info['first']} {user_info['last']}"
	location = user_info['location']
	print(f"\tFull name: {full_name.title()}")
	print(f"\tLocation: {location.title()}")


#练习7：自练
name = input('Please enter you name:') print(f'Hello, {name}!\n')




