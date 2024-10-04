
#练习3-4：嘉宾名单
namelist=["Zhang San","Li Si","Wang Wu"]
message=f"{namelist[0]}, would you like to eat wanfan with me?"
print(message)
message=f"{namelist[1]}, would you like to eat wanfan with me?"
print(message)
message=f"{namelist[2]}, would you like to eat wanfan with me?"
print(message)



#练习3-5：修改嘉宾名单
message=f"{namelist[0]} will not come."
print(message)

namelist[0]="Zhao Liu"

message=f"{namelist[0]}, would you like to eat wanfan with me?"
print(message)
message=f"{namelist[1]}, would you like to eat wanfan with me?"
print(message)
message=f"{namelist[2]}, would you like to eat wanfan with me?"
print(message)



#练习3-6：添加嘉宾
message="I found a bigger table."
print(message)

namelist.insert(0,'Zhang San')

namelist.insert(0,'Li Er')

namelist.append('Wei Yi')

message=f"{namelist[0]}, would you like to eat wanfan with me?"
print(message)
message=f"{namelist[1]}, would you like to eat wanfan with me?"
print(message)
message=f"{namelist[2]}, would you like to eat wanfan with me?"
print(message)
message=f"{namelist[3]}, would you like to eat wanfan with me?"
print(message)
message=f"{namelist[4]}, would you like to eat wanfan with me?"
print(message)
message=f"{namelist[5]}, would you like to eat wanfan with me?"
print(message)



#练习3-7：缩减名单
message="Now I can only visit two persons to eat wanfan with me."
print(message)

print(namelist)

popped_name=namelist.pop()
message=f"Very sorry, {popped_name}, you can not come my home to eat wanfan beacause……"
print(message)
popped_name=namelist.pop(0)
message=f"Very sorry, {popped_name}, you can not come my home to eat wanfan beacause……"
print(message)
popped_name=namelist.pop(0)
message=f"Very sorry, {popped_name}, you can not come my home to eat wanfan beacause……"
print(message)
popped_name=namelist.pop(0)
message=f"Very sorry, {popped_name}, you can not come my home to eat wanfan beacause……"
print(message)

message=f"{namelist[0]}, you can come my home to eat wanfan."
print(message)
message=f"{namelist[1]}, you can come my home to eat wanfan."
print(message)

del namelist[0]
del namelist[0]
print(namelist)



