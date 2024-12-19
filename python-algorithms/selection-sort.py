import sys
from load import load_numbers

numbers = load_numbers(sys.argv[1])

def selectionSort(numbers):
    sorted = []
    for i in range(len(numbers)):
        min_index = 0
        for j in range(len(numbers)):
            if numbers[j] < numbers[min_index]:
                min_index = j
        sorted.append(numbers.pop(min_index))
    return sorted

print(selectionSort(numbers))