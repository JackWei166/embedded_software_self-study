# 练习7-8：熟食店 
sandwich_orders = ['aaa sandwich', 'bbb sandwich', 'ccc sandwich', ]
finished_sandwiches = []

while sandwich_orders :
	sandwich = sandwich_orders.pop()
	print(f'I made your {sandwich}.')
	finished_sandwiches.append(sandwich)

print('\nWe have made all sandwich orders: ')
for sandwich in finished_sandwiches :
	print(sandwich)


# 练习7-9：五香烟熏牛肉卖完了 
sandwich_orders = ['aaa sandwich', 'pastrami sandwich', 'bbb sandwich', 'ccc sandwich', 'pastrami sandwich', 'tuna sandwich', 'pastrami sandwich', ]

print('\nPastrami sandwich has been sold out.')

while 'pastrami sandwich' in sandwich_orders :
	sandwich_orders.remove('pastrami sandwich')

for sandwich in sandwich_orders :
	print(sandwich)


# 练习7-10：梦想的度假胜地
responses = {}

polling_active = True

while polling_active :
	name = input("What's your name?")
	place = input('If you could visit one place in the world, where would you go?')
	responses[name] = place
	repeat = input('Would you like to let another person respond? (yes/ no) ')
	if repeat == 'no' :
		polling_active = False

print('---Poll Results---')
for name, response in responses.items() :
	print(f'{name.title()} would like to visit {response.title()}. ')

















