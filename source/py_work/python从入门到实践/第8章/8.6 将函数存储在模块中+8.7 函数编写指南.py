# 练习8-15：打印模型
import printing_functions

unprinted_designs = ['dog', 'cat', 'car', ]
completed_models = []

printing_functions.print_models(unprinted_designs, completed_models)

printing_functions.show_completed_models(completed_models)


# 练习8-16：导入
# import user
# user_info = user.build_profile('li','si', location='shanghai', hobby='reading')
# print(user_info)

# from user import build_profile
# user_info = build_profile('li','si', location='shanghai', hobby='reading')
# print(user_info)

# from user import build_profile as bp
# user_info = bp('li','si', location='shanghai', hobby='reading')
# print(user_info)

# import user as u
# user_info = u.build_profile('li','si', location='shanghai', hobby='reading')
# print(user_info)

from user import *
user_info = build_profile('li','si', location='shanghai', hobby='reading')
print(user_info)


# 练习8-17：函数编写指南

# def print_models(unprinted_designs, completed_models):
# 	"""
# 	模拟打印每个设计，直到没有未打印的设计为止。
# 	打印每个设计后，都将其移到列表completed_models中。
# 	"""
# 	while unprinted_designs:
# 		current_design = unprinted_designs.pop()
# 		print(f"Printing model: {current_design}")
# 		completed_models.append(current_design)

# def show_completed_models(completed_models):
# 	"""显示打印好的所有模型。"""
# 	print("\nThe following models have been printed:")
# 	for completed_model in completed_models:
# 		print(completed_model)


# def function_name(
# 		parameter_0, parameter_1, parameter_2,
# 		parameter_3, parameter_4, parameter_5):
# 	function body...





