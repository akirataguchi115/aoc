f = open("1.txt", "r")
lines = f.readlines()
f.close()

left = []
right = []
for line in lines:
  left.append(line.split()[0])
  right.append(line.split()[1])

sum = 0
index = 0
while index < len(left):
  sum += int(left[index]) * right.count(left[index])
  index += 1

print(sum)