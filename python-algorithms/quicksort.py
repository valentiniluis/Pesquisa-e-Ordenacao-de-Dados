import sys
from load import load_numbers
import random

numbers = load_numbers(sys.argv[1])

def quicksort(numbers):
    if len(numbers) <= 1:
        return numbers
    pivot_index = random.choice(range(len(numbers)))
    pivot = numbers[pivot_index]
    less_than_pivot = []
    greater_than_pivot = []

    for index, value in enumerate(numbers):
        if index == pivot_index:
            continue
        if value <= pivot:
            less_than_pivot.append(value)
        else:
            greater_than_pivot.append(value)

    return quicksort(less_than_pivot) + [pivot] + quicksort(greater_than_pivot)

print(quicksort(numbers))