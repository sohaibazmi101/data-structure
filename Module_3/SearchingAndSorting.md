
---

# **1. Searching Algorithms**  

## **1.1 Linear Search**  
🔹 **Definition:**  
Linear Search is a simple searching algorithm that checks each element in a list sequentially until the target element is found or the list ends.

🔹 **Algorithm:**  
1. Start from the first element and traverse the array.  
2. Compare each element with the target.  
3. If found, return the index.  
4. If the element is not found, return `-1`.  

🔹 **Pseudo Code:**
```
Algorithm LinearSearch(A, n, key)
1. for i = 0 to n-1 do
2.     if A[i] == key then
3.         return i   // Element found
4. return -1          // Element not found
```

---

## **1.2 Binary Search (Only for Sorted Arrays)**  
🔹 **Definition:**  
Binary Search is an efficient algorithm that works on sorted arrays by repeatedly dividing the search space into halves.

🔹 **Algorithm:**  
1. Find the middle element.  
2. If the middle element is the target, return the index.  
3. If the target is smaller, search the left half; otherwise, search the right half.  
4. Repeat until the search space is empty.  

🔹 **Pseudo Code:**
```
Algorithm BinarySearch(A, low, high, key)
1. while low ≤ high do
2.     mid = (low + high) / 2
3.     if A[mid] == key then
4.         return mid
5.     else if A[mid] > key then
6.         high = mid - 1
7.     else
8.         low = mid + 1
9. return -1   // Element not found
```

---

## **Variants of Binary Search**
### **1.3 Finding First Occurrence**
Modify Binary Search to return the first occurrence of the key:
```
Algorithm FirstOccurrence(A, low, high, key)
1. result = -1
2. while low ≤ high do
3.     mid = (low + high) / 2
4.     if A[mid] == key then
5.         result = mid  // Save result
6.         high = mid - 1  // Search left half
7.     else if A[mid] > key then
8.         high = mid - 1
9.     else
10.        low = mid + 1
11. return result
```

### **1.4 Finding Last Occurrence**
Similar to First Occurrence but searches in the right half:
```
Algorithm LastOccurrence(A, low, high, key)
1. result = -1
2. while low ≤ high do
3.     mid = (low + high) / 2
4.     if A[mid] == key then
5.         result = mid  // Save result
6.         low = mid + 1  // Search right half
7.     else if A[mid] > key then
8.         high = mid - 1
9.     else
10.        low = mid + 1
11. return result
```

### **1.5 Counting Occurrences**
Find occurrences using **(Last Index - First Index + 1)**.

---

# **2. Sorting Algorithms**  

## **2.1 Bubble Sort**  
🔹 **Definition:**  
Repeatedly swaps adjacent elements if they are in the wrong order.

🔹 **Algorithm:**  
1. Traverse the array multiple times.  
2. Swap adjacent elements if needed.  
3. Repeat until no swaps are needed.  

🔹 **Pseudo Code:**
```
Algorithm BubbleSort(A, n)
1. for i = 0 to n-1 do
2.     for j = 0 to n-i-1 do
3.         if A[j] > A[j+1] then
4.             swap(A[j], A[j+1])
```

---

## **2.2 Selection Sort**  
🔹 **Definition:**  
Finds the smallest element and places it in the correct position.

🔹 **Algorithm:**  
1. Find the minimum element in the array.  
2. Swap it with the first unsorted element.  
3. Repeat for all elements.  

🔹 **Pseudo Code:**
```
Algorithm SelectionSort(A, n)
1. for i = 0 to n-1 do
2.     minIndex = i
3.     for j = i+1 to n-1 do
4.         if A[j] < A[minIndex] then
5.             minIndex = j
6.     swap(A[i], A[minIndex])
```

---

## **2.3 Insertion Sort**  
🔹 **Definition:**  
Sorts the array one element at a time by placing each in its correct position.

🔹 **Algorithm:**  
1. Take an element and compare it with previous elements.  
2. Shift elements until it fits in the correct position.  
3. Repeat for all elements.  

🔹 **Pseudo Code:**
```
Algorithm InsertionSort(A, n)
1. for i = 1 to n-1 do
2.     key = A[i]
3.     j = i - 1
4.     while j >= 0 and A[j] > key do
5.         A[j+1] = A[j]
6.         j = j - 1
7.     A[j+1] = key
```

---

## **2.4 Merge Sort** (Divide & Conquer)  
🔹 **Algorithm:**  
1. Divide array into two halves.  
2. Recursively sort each half.  
3. Merge the sorted halves.  

🔹 **Pseudo Code:**
```
Algorithm MergeSort(A, left, right)
1. if left < right then
2.     mid = (left + right) / 2
3.     MergeSort(A, left, mid)
4.     MergeSort(A, mid+1, right)
5.     Merge(A, left, mid, right)
```

---

## **2.5 Quick Sort** (Divide & Conquer)  
🔹 **Algorithm:**  
1. Pick a pivot element.  
2. Partition array into smaller and larger elements.  
3. Recursively sort partitions.  

🔹 **Pseudo Code:**
```
Algorithm QuickSort(A, low, high)
1. if low < high then
2.     pivot = Partition(A, low, high)
3.     QuickSort(A, low, pivot-1)
4.     QuickSort(A, pivot+1, high)
```

---

## **2.6 Heap Sort** (Uses Heap Data Structure)  
🔹 **Algorithm:**  
1. Convert array into a **Max Heap**.  
2. Swap the root with the last element.  
3. Heapify the remaining elements.  

🔹 **Pseudo Code:**
```
Algorithm HeapSort(A, n)
1. Build Max Heap(A)
2. for i = n-1 to 1 do
3.     swap(A[0], A[i])
4.     Heapify(A, 0, i)
```

---

## **2.7 Counting Sort** (For small integers)  
🔹 **Algorithm:**  
1. Count occurrences of each number.  
2. Calculate cumulative frequency.  
3. Place elements in sorted order.  

🔹 **Pseudo Code:**
```
Algorithm CountingSort(A, n, k)
1. Create count array of size k+1
2. for each element in A, increment count array
3. Compute prefix sum of count array
4. Place elements in sorted order using count array
```

---
