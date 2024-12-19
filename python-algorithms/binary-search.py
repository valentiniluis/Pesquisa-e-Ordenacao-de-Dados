import sys
from load import load_strings

names = load_strings(sys.argv[1])

def binarySearch(collection, item):
    start = 0
    end = len(collection) - 1

    while start <= end:

        midpoint = (start + end) // 2

        if collection[midpoint] == item:
            return midpoint
        elif collection[midpoint] > item:
            end = midpoint - 1
        else:
            start = midpoint + 1
    return None


namesToSearch = ['Alexis Ballard', 'Alejandra Beltran', 'Ricky Chang', 'Ophelia Gould', 'Blaine Rosario']


for name in namesToSearch:
    print(f'Index of \'{name}\': {binarySearch(names, name)}')
