
# 练习10-3：访客
# guest_name = input('Please enter your name: ')

# guest_name = 'zhang san'
# with open('guest.txt', 'w') as file:
# 	file.write(guest_name)



# 练习10-4：访客名单
name = ''

while name != 'quit':
	# name = input('Please enter your name: ')
	# name = 'zhang san'
	print(f'Hello, {name.title()}!')
	with open('guest_book.txt', 'a') as file:
		file.write(f'{name}\n')

# 练习10-5：调查 
reason = ''

while reason != 'quit':
	reason = input('Why do you like programing?')
	with open('reasons.txt', 'a') as file:
		file.write(f'{reason}\n')































