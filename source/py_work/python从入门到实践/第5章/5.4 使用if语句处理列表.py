#练习5-8：以特殊方式跟管理员打招呼
users = ['admin', 'Tom', 'Jack', 'Jerry', 'Mary']

for user in users :
	if user == 'admin' :
		print('Hello admin, would you like to see a status report?\n')
	if user != 'admin' :
		print(f'Hello {user}, thank you for logging in again.\n')


#练习5-9：处理没有用户的情形
users = []

if users :
	for user in users :
		if user == 'admin' :
			print('Hello admin, would you like to see a status report?\n')
		if user != 'admin' :
			print(f'Hello {user}, thank you for logging in again.\n')
else :
	print('We need to find some users!\n')


users = []

if users == 0 :
	for user in users :
		if user == 'admin' :
			print('Hello admin, would you like to see a status report?\n')
		if user != 'admin' :
			print(f'Hello {user}, thank you for logging in again.\n')
elif users != 0 :
	print('We need to find some users!\n')


users = ['admin', 'Tom', 'Jack', 'Jerry', 'Mary']

if users != 0 :
	for user in users :
		if user == 'admin' :
			print('Hello admin, would you like to see a status report?\n')
		if user != 'admin' :
			print(f'Hello {user}, thank you for logging in again.\n')
elif users == 0 :
	print('We need to find some users!\n')


users = []

if users :
	for user in users :
		if user == 'admin' :
			print('Hello admin, would you like to see a status report?\n')
		if user != 'admin' :
			print(f'Hello {user}, thank you for logging in again.\n')
elif users != 0 :
	print('We need to find some users!\n')


#练习5-10：检查用户名
current_users = ['admin', 'Tom', 'Jack', 'Jerry', 'Mary']
lit_current_users = [user.lower() for user in current_users]

new_users = ['ADMIN', 'Tom', 'Zhang San', 'Li Si', 'Wang Wu']

for user in new_users :
	if user.lower() in lit_current_users :
		print(f'The name "{user}" has been used. Please enter other name.\n')
	else :
		print(f'The name "{user}" has not been used.\n')

#练习5-11：序数
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9,]

for num in nums :
	if num == 1 :
		print(f'{num}st')
	elif num == 2 :
		print(f'{num}nd')
	elif num == 3 :
		print(f'{num}rd')
	else :
		print(f'{num}th')

















