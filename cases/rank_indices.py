def get_sorted_indices(numbers):
    return sorted(range(len(numbers)), key=lambda i: numbers[i])

# Example usage:
input_str = """51 1 94 61 46 45 54 52 42 73 36 5 97 63 25 8 82 14 65 56 96 19 21 90 23 76 59 75 79 67 3 78 83 20 24 6 74 37 35 88 70 71 40 48 33 38 58 49 86 13 80 44 53 84 72 28 60 93 15 7 85 11 31 17 91 12 62 81 64 41 77 4 98 99 18 50 27 92 0 34 89 32 95 69 39 2 10 43 22 29 66 30 16 55 26 87 57 9 68 47"""

# Convert the input string to a list of integers
numbers = list(map(int, input_str.split()))

# Get sorted indices
sorted_indices = get_sorted_indices(numbers)

# Print them space-separated
print(" ".join(map(str, sorted_indices)))
