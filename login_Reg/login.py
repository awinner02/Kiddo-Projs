txtfile = open("user.csv")

user = []
password = []

for line in txtfile:
  l = txtfile.readline() # read into line
  mylist = l.split(',')  # split
  user.append(mylist[0].strip())
  password.append(mylist[1].strip())

txtfile.close()

# Saved Login
dict = {}
for i in range(len(user)):
  dict[user[i]] = password[i]

print(dict)

while(True):
  work = input("Want to login? ")
  if work == "n":
    break
  
  userI = input("Enter user: ")
  passI = input("Enter pass: ")
  login = False
  
  for i, j in dict.items():
    if i == userI and j == passI:
      login = True
      break
  
  if login:
    print("Successful")
  else:
    print("Username or password invalid")