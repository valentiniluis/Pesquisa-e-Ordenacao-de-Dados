import sys
from load import load_numbers

numbers = load_numbers(sys.argv[1])

def merge_sort(numbers):
    if len(numbers) <= 1:
        return numbers
    middle_index = len(numbers) // 2
    left_values = merge_sort(numbers[:middle_index])
    right_values = merge_sort(numbers[middle_index:])
    sorted_values = []
    left_index = 0
    right_index = 0
    while left_index < len(left_values) and right_index < len(right_values):
        if left_values[left_index] < right_values[right_index]:
            sorted_values.append(left_values[left_index])
            left_index += 1
        else:
            sorted_values.append(right_values[right_index])
            right_index += 1
    sorted_values += left_values[left_index:]
    sorted_values += right_values[right_index:]
    return sorted_values

sorted_list = merge_sort(numbers)
print(sorted_list)
