# 练习8-6：城市名 
def city_country(city, country):
	city = f'{city.title()}, {country.title()}'
	return city

city = city_country('beijing', 'china')
print(city)

city = city_country('shanghai', 'china')
print(city)

city = city_country('new york', 'america')
print(city)


# 练习8-7：专辑 
def make_album(name, singer, ):
	album = {'name': name, 'singer': singer, }
	return album

album = make_album('aaa', 'john')
print(album)

album = make_album('bbb', 'zhang san')
print(album)

album = make_album('ccc', 'li si')
print(album)


def make_album(name, singer, num = None):
	album = {'name': name, 'singer': singer, }

	if num :
		album['num'] = num
	
	return album

album = make_album('aaa', 'john')
print(album)

album = make_album('bbb', 'zhang san', 10)
print(album)

album = make_album('ccc', 'li si',12)
print(album)


# 练习8-8：用户的专辑
def make_album(name, singer, num = None):
	album = {'name': name, 'singer': singer, }

	if num :
		album['num'] = num
	
	return album

while True :
	print("Please enter the name and the singer's name of album. ")
	print("Enter 'q' to quit.")

	name = input('The name: ')
	if name == 'q':
		break
	singer_name = input("The singer's name: ")
	if singer_name == 'q':
		break

	album = make_album(name, singer_name)

	print(album)
	print('\n')




