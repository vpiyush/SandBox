myDict = {"Name":"Naveena", "Age":23, "Gender":"F"}

#print keys
print(myDict.keys())
#print values
print(myDict.values())

#clear disctionary
myDict.clear()
print(myDict)

myDict = {"Name":"Naveena", "Age":23, "Gender":"F"}
#delete a single key
del myDict['Age']
print(myDict)

#length of dict
print(len(myDict))

#total items in terms of tuple pair
print(myDict.items())

#to check if a key is present in a dictionary
print("Name" in myDict)


for temp in myDict:
    #keys
    print(temp)
    #values
    print(myDict[temp])
