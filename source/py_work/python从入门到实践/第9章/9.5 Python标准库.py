
# 练习9-13：骰子

from random import randint

class Die:

	def __init__(self):
		self.sides = 6

	def roll_die(self):
		random_number = randint(1, self.sides)
		print(random_number)


six_sides_die = Die()

count = 0
while count < 10 :
	six_sides_die.roll_die()
	count += 1
print('\n')


ten_sides_die = Die()
ten_sides_die.sides = 10

count = 0
while count < 10 :
	ten_sides_die.roll_die()
	count += 1
print('\n')


twenty_sides_die = Die()
twenty_sides_die.sides = 20

count = 0
while count < 10 :
	twenty_sides_die.roll_die()
	count += 1
print('\n')



# 练习9-14：彩票
from random import choice

info = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'a', 'b', 'c', 'd', 'e', ]

info_0 = choice(info)
info_1 = choice(info)
info_2 = choice(info)
info_3 = choice(info)

print(f'As long as "{info_0}"、 "{info_1}"、 "{info_2}"、 "{info_3}" are on the lottery, you will win the big prize.')



# 练习9-15：彩票分析
my_ticket = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'a', 'b', 'c', 'd', 'e', ]

win_flag = 0
count = 0

while win_flag == 0 :
	ticket_0 = choice(my_ticket)
	ticket_1 = choice(my_ticket)
	ticket_2 = choice(my_ticket)
	ticket_3 = choice(my_ticket)

	count += 1

	if ticket_0 == 'd' and ticket_1 == 1 and ticket_2 == 0 and ticket_3 == 2 :
		win_flag = 1
		print(f'{count} times to execute the loop before winning the prize.')


# 练习9-16：Python Module of the Week 
import time
print('The time is      :', time.ctime())
later = time.time() + 15
print('15 secs from now :', time.ctime(later))















