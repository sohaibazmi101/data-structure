## **String Operations and Manipulation**

Strings are an important data structure used for text processing, pattern matching, and various applications in data structures and algorithms. Common string operations include:

## **1. String Reversal**

### **Algorithm**

Initialize two pointers, left = 0 and right = length - 1.

Swap characters at left and right.

Move left forward and right backward until they meet.

Return the reversed string.

### **Pseudo Code**

FUNCTION ReverseString(str)
    left ← 0
    right ← length(str) - 1

    WHILE left < right DO
        SWAP str[left] and str[right]
        left ← left + 1
        right ← right - 1
    END WHILE

    RETURN str
END FUNCTION


## **2. String Concatenation**

### **Algorithm**

Copy the first string into a new array.

Append characters from the second string.

Return the concatenated string.

### **Pseudo Code**

FUNCTION Concatenate(str1, str2)
    newStr ← str1

    FOR each character in str2 DO
        APPEND character to newStr
    END FOR

    RETURN newStr
END FUNCTION



## **3. String Length Calculation**

### **Algorithm**

Initialize count = 0.

Iterate through the string, increasing count for each character.

Return count.

### **Pseudo Code**

FUNCTION StringLength(str)

    count ← 0

    FOR each character in str DO

        count ← count + 1

    END FOR

    RETURN count
    
END FUNCTION



## **4. Substring Extraction**

### **Algorithm**

Define start and end indexes.

Extract characters between start and end.

Return the substring.

### **Pseudo Code**

FUNCTION Substring(str, start, end)
    newStr ← ""

    FOR i ← start TO end DO
        newStr ← newStr + str[i]
    END FOR

    RETURN newStr
END FUNCTION


**5. String Comparison**

### **Algorithm**

Compare each character of two strings.

If a mismatch is found, return false.

If all characters match, return true.

### **Pseudo Code**

FUNCTION CompareStrings(str1, str2)
    IF length(str1) ≠ length(str2) THEN
        RETURN false
    END IF

    FOR i ← 0 TO length(str1) - 1 DO
        IF str1[i] ≠ str2[i] THEN
            RETURN false
        END IF
    END FOR

    RETURN true
END FUNCTION


**6. Palindrome Checking**

### **Algorithm**

Compare characters from both ends.

If characters don’t match, return false.

If all characters match, return true.


### **Pseudo Code**

FUNCTION IsPalindrome(str)
    left ← 0
    right ← length(str) - 1

    WHILE left < right DO
        IF str[left] ≠ str[right] THEN
            RETURN false
        END IF
        left ← left + 1
        right ← right - 1
    END WHILE

    RETURN true
END FUNCTION


**7. String Searching (Brute Force & KMP Algorithm)**

### **Algorithm**

Check if the substring exists by comparing character-by-character.

Return the starting index if found, otherwise return -1

### **Pseudo Code**

FUNCTION BruteForceSearch(text, pattern)
    n ← length(text)
    m ← length(pattern)

    FOR i ← 0 TO n - m DO
        match ← true
        FOR j ← 0 TO m - 1 DO
            IF text[i + j] ≠ pattern[j] THEN
                match ← false
                BREAK
            END IF
        END FOR
        IF match THEN
            RETURN i
        END IF
    END FOR

    RETURN -1
END FUNCTION


**8. String Replacement**

### **Algorithm**

Find occurrences of a substring.

Replace the substring with a new string.

Return the modified string.

### **Pseudo code**

FUNCTION ReplaceSubstring(str, oldSub, newSub)
    index ← FindSubstring(str, oldSub)
    
    IF index ≠ -1 THEN
        Remove oldSub from str at index
        Insert newSub at index
    END IF
    
    RETURN str
END FUNCTION


**9. Anagram Checking**

### **Algorithm**

Sort both strings.

If they match, they are anagrams.

### **Pseudo code**

FUNCTION IsAnagram(str1, str2)
    IF length(str1) ≠ length(str2) THEN
        RETURN false
    END IF

    sorted1 ← SortString(str1)
    sorted2 ← SortString(str2)

    RETURN CompareStrings(sorted1, sorted2)
END FUNCTION



**10. Pattern Matching**

### **Algorithm**

Preprocess the pattern to create a Longest Prefix Suffix (LPS) array.

Use the LPS array to avoid unnecessary comparisons.

Return the index of the pattern if found.

### **Pseudo code**

FUNCTION KMP(text, pattern)
    Compute LPS array for pattern
    i ← 0, j ← 0

    WHILE i < length(text) DO
        IF text[i] = pattern[j] THEN
            i ← i + 1
            j ← j + 1
        END IF

        IF j = length(pattern) THEN
            RETURN i - j  // Pattern found
            j ← LPS[j - 1]
        ELSE IF i < length(text) AND text[i] ≠ pattern[j] THEN
            IF j ≠ 0 THEN
                j ← LPS[j - 1]
            ELSE
                i ← i + 1
            END IF
        END IF
    END WHILE

    RETURN -1
END FUNCTION
