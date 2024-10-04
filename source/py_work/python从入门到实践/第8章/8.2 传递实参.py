# 练习8-3：T恤 
def make_shirt(size, wording):
	print(f'The size of the shirt is {size} and the wording is "{wording}". ')

make_shirt(29, 'UP')

make_shirt(wording = 'UP', size = 29)


# 练习8-4：大号T恤 
def make_shirt(size, wording = 'I love Python'):
	print(f'The size of the shirt is {size} and the wording is "{wording}". ')

make_shirt('large size')

make_shirt('medium size')

make_shirt('large size', 'UP')


# 练习8-5：城市 
def describe_city(city, nation = 'China'):
	print(f'{city.title()} is in {nation.title()}. ')

describe_city('beijing')

describe_city('shanghai')

describe_city('new york', 'america')















