import random

unique_numbers = random.sample(range(1, 2147483647), 214748364)
print(' '.join(map(str, unique_numbers)))