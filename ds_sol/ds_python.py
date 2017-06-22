# List
## Two Sum problem


def two_sum(arr, target):
    arr_set = {}

    for ix, num in enumerate(arr):
        if (target - num) in arr_set:
            return ix, arr_set[target - num]
        else:
            arr_set[target - num] = ix

    return -1, -1


## Merge Sorted Array
def merger_sorted_arrays(arr1, arr2):
    i1 = 0
    i2 = 0
    arr3 =[]

    while i1 < len(arr1) and i2 < len(arr2):
        a1 = arr1[i1]
        a2 = arr2[i2]

        if a1 <= a2:
            arr3.append(a1)
            i1 += 1
        else:
            arr3.append(a2)
            i2 += 1

    if i1 == len(arr1):
        arr3.extend(arr2[i2:])
    else:
        arr3.extend(arr1[i1:])
    return arr3


# String
## String to integer
def atoi(str):
    result = 0
    sign = 1
    processed_str= str

    first_char = str[0]
    if first_char == '-':
        sign = -1
        processed_str = str[1:]
    elif first_char == '+':
        processed_str = str[1:]

    for char in processed_str:
        if not ord('0') < ord(char) < ord('9'):
            return -1
        char_int = ord(char)
        result = 10 * result + char_int

    return result * sign


## Reverse a string
def reverse_a_string(str):
    ret_str = ""
    for char in str:
        ret_str = char + ret_str
    return ret_str

# Hash Map
## Longest substring without repeated characters
def longest_substring_wo_repeated_chars(str):
    # ans = max(longest such substring starting at pos j)
    ans = 0
    for j in range(len(str)):
        j_set = set()
        for i in range(j, 0, -1):
            if str[i] in j_set:
                ans = max(ans, j-i+1)
                break
            else:
                j_set.add(str[i])
    return ans


## Single Number
def single_number(arr):
    from collections import defaultdict
    freq = defaultdict()
    for num in arr:
        freq[num] += 1
    for num in arr:
        if freq[num] ==1:
            return num


# Set

# Subsets
# Given, a distinct set of integers return a list of all subsets possible

def subsets(sub_set, num):

    if not num:
        print sub_set
        return

    subsets(sub_set, num[1:])
    sub_set.add(num[0])
    subsets(sub_set, num[1:])

# Linked List

# Reverse a Linked List

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


def reverse_linked_list(ListNode l):
    pass
