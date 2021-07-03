
def onlyOccurrence(arr):
    map = {}
    for num in arr:
        if num in map:
            map[num] = 2
        else:
            map[num] = 1
    for elem in map:
        if map[elem] == 1:
            print(elem)

def duplicateOccurrence(arr):
    map = {}
    for num in arr:
        if num in map:
            map[num] = 2
        else:
            map[num] = 1
    for elem in map:
        if map[elem] > 1:
            print(elem)

onlyOccurrence([1, 1, 2, 3, 4, 4])
duplicateOccurrence([1, 1, 2, 3, 4, 4])