import sys
from load import load_strings

names = load_strings(sys.argv[1])

def linear_search(collection, target):
    for index, value in enumerate(collection):
        if value == target:
            return index
    return None

namesToSearch = ['Alexis Ballard', 'Alejandra Beltran', 'Ricky Chang', 'Ophelia Gould', 'Blaine Rosario']

for n in namesToSearch:
    print(f'Index of {n}: {linear_search(names, n)}')