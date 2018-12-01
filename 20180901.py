x = int(input())
price = input()
price = [int(y) for y in price.split(' ')]
new_price = [0 for i in range(x)]
new_price[0] = int((price[0] + price[1])/2)
for i in range(1, x-1):
    new_price[i] = int((price[i-1] + price[i] + price[i+1])/3)
new_price[x-1] = int((price[x-1] + price[x-2])/2)
for i in range(x-1):
    print(new_price[i], end=' ')
print(new_price[x-1])