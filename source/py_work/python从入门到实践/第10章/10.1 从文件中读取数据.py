
# 练习10-1：Python学习笔记 

# with open('learning_python.txt') as file:
# 	contents = file.read()
# 	print(contents.rstrip())


# with open('learning_python.txt') as file:
# 	for line in file:
# 		print(line)


# with open('learning_python.txt') as file:
# 	lines = file.readlines()

# for line in lines:
# 	print(line.rstrip())


# 练习10-2：C语言学习笔记 
with open('learning_python.txt') as file:
	for line in file:
		line = line.replace('python', 'C')
		print(line)



















