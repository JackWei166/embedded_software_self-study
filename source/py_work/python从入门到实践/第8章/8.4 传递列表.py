# 练习8-9：消息 
def show_messages(messages):
	for message in messages :
		print(message)

messages = ['zhang san', 'li si', 'wang wu', ]
show_messages(messages)


# 练习8-10：发送消息
# def sent_messages(messages, sent_messages):
# 	while messages:
# 		message = messages.pop()
# 		print(message)
# 		sent_messages.append(message)


# messages = ['zhang san', 'li si', 'wang wu', ]
# st_messages = []

# sent_messages(messages, st_messages)

# print(messages)
# print(st_messages)



# 练习8-11：消息归档

def sent_messages(messages, sent_messages):
	while messages:
		message = messages.pop()
		print(message)
		sent_messages.append(message)


messages = ['zhang san', 'li si', 'wang wu', ]
st_messages = []

sent_messages(messages[:], st_messages)

print(messages)
print(st_messages)








