# **Sliding Window Technique**

The **Sliding Window technique** is an optimized approach to solve problems related to **subarrays, substrings, and sequences** efficiently. It reduces nested loops **(O(N²)) to O(N)** complexity in many cases.

## **Algorithm**

**1. Initialize Variables**
maxSum = 0 → Stores the maximum sum found.
windowSum = 0 → Tracks the sum of the current sliding window.
**2. Compute the sum of the first K elements** (Initial Window).
**3. Slide the window**
Move the window one step forward by:
Subtracting the element that is leaving the window (arr[i-K]).
Adding the new element entering the window (arr[i]).
Update maxSum if windowSum is larger.
**4. Return** maxSum after checking all subarrays.

## **Pseudo Code**

FUNCTION maxSumSlidingWindow(arr, n, k)
    maxSum ← 0
    windowSum ← 0

    FOR i ← 0 TO k - 1 DO
        windowSum ← windowSum + arr[i]
    END FOR
    maxSum ← windowSum

    FOR i ← k TO n - 1 DO
        windowSum ← windowSum + arr[i] - arr[i - k]
        IF windowSum > maxSum THEN
            maxSum ← windowSum
        END IF
    END FOR

    RETURN maxSum
END FUNCTION
