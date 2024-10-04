def city_function(city, country, population=''):
	if population:
		info = f'{city.title()}, {country.title()} - population {population}'
	else:
		info = f'{city.title()} {country.title()}'
	return info

# city = city_function('beijing', 'china')
# print(city)
































