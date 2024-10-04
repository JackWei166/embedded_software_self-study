#练习6-4：词汇表2
python_terms = {
	'title()': 'It returns a string where the first character in every word is upper case.', 
	'strip()': 'It removes spaces at the beginning and at the end of the string.', 
	'append()': 'It adds an item to the end of the list.', 
	'pop()': 'It removes the item at the given index from the list and returns the removed item.', 
	'sort()': 'It sorts the items of a list in ascending or descending order.', 
	'reverse()': 'It reverses the elements of the list.', 
	'range()': 'It returns a sequence of numbers between the give range.', 
	'tuple': 'It is a list whose elements cannot be modified.', 
	'get()': 'It returns the value for the specified key if the key is in the dictionary.', 
	'items()': "It returns a view object that displays a list of dictionary's (key, value) tuple pairs.", 
	}

for term, meaning in python_terms.items() :
	print(f"{term}: {meaning}\n" )


#练习6-5：河流
rivers = {
	'the Changjiang River': 'China', 
	'the Huanghe River': 'China', 
	'the Nile': 'Egypt', 
	}

for river, nation in rivers.items() :
	print(f'{river.title()} runs through {nation}.\n')

for river in rivers.keys() :
	print(river.title())
print('\n')

for nation in set(rivers.values()) :
	print(nation)
print('\n')


#练习6-6：调查
favorite_languages = {
	'jen': 'python',
	'sarah': 'c',
	'edward': 'ruby',
	'phil': 'python',
	}

namelist = ['jen', 'zhang san', 'li si']

for name in namelist :
	if name in favorite_languages.keys() :
		print(f'{name.title()}, thank you for taking the poll!\n')
	else :
		print(f'{name.title()}, could you take a poll?\n')


















