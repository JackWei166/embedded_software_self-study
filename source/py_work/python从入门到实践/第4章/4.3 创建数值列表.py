#练习4-3：数到20
for num in range(1,21):
    print(num)

#练习4-4：一百万
#numlist=list(range(1,1000001))
#for num in numlist :
#   print(num)

#练习4-5：一百万求和
numlist=list(range(1,1000001))

min_in_list=min(numlist)
print(min_in_list)

max_in_list=max(numlist)
print(max_in_list)

sum_in_list=sum(numlist)
print(sum_in_list)

#练习4-6：奇数
numlist=list(range(1,21,2))
for num in numlist :
    print(num)

#练习4-7：3的倍数
numlist=list(range(3,31,3))
for num in numlist :
    print(num)

#练习4-8：立方 
squares=[]
for num in range(1,11) :
    squares.append(num**3)

for square in squares :
    print(square)


#练习4-9：立方解析
squares=[num**3 for num in range(1,11)]
print(squares)



