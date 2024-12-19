import sys
from load import load_strings
import random

names = load_strings(sys.argv[1])

def quicksort_strings(names):
    if len(names) <= 1:
        return names
    pivot_index = random.choice(range(len(names)))
    pivot = names[pivot_index]
    less_than_pivot = []
    greater_than_pivot = []

    for index, value in enumerate(names):
        if index == pivot_index:
            continue
        if value <= pivot:
            less_than_pivot.append(value)
        else:
            greater_than_pivot.append(value)

    return quicksort_strings(less_than_pivot) + [pivot] + quicksort_strings(greater_than_pivot)

def writeNamesToFile(names):
    with open('sorted-names.txt', 'w') as file:
        for name in names:
            file.write(name + '\n')

sorted_names = quicksort_strings(names)
writeNamesToFile(sorted_names)