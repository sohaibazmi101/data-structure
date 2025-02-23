# **Two-Pointer Technique in C**

The Two-Pointer Technique is a powerful approach used in array and string problems to optimize solutions, typically by reducing time complexity from **O(N²) to O(N)**. It involves maintaining two *pointers* and moving them towards each other or in a specific direction based on conditions.

## **Finding a Pair with Given Sum (Sorted Array)**

This program finds two numbers in a **sorted array** that sum up to a given target using the **two-pointer** approach.

### **Algorithm:**

**Initialize two pointers:**

left at the start (0).
right at the end (n-1).
If arr[left] + arr[right] == target, print the pair.
If the sum is less than the target, move left forward (left++).
If the sum is greater, move right backward (right--).
Repeat until left < right.

### **Pseudo Code**

Procedure FIND_PAIR(arr, n, target):
    left ← 0 
    right ← n - 1

    While left < right:
        sum ← arr[left] + arr[right]  

        If sum = target:
            Print "Pair found: (", arr[left], ", ", arr[right], ")"
            Return

        Else If sum < target:
            left ← left + 1

        Else:
            right ← right - 1

    Print "No pair found"
End Procedure


## **Checking if a String is a Palindrome**

The **two-pointer** approach can also be used to check if a string is a palindrome.

### **Algorithm**

Place one pointer (left) at the start and the other (right) at the end.
Compare str[left] and str[right].
If they match, move both pointers (left++, right--).
If a mismatch is found, return false.
Repeat until left >= right.

### **Pseudo Code**

Procedure IS_PALINDROME(str):
    left ← 0 
    right ← length(str) - 1 

    While left < right:
        While NOT is_alphanumeric(str[left]) AND left < right:
            left ← left + 1

        While NOT is_alphanumeric(str[right]) AND left < right:
            right ← right - 1

        If to_lower(str[left]) ≠ to_lower(str[right]):
            Return FALSE

        left ← left + 1
        right ← right - 1

    Return TRUE
End Procedure
