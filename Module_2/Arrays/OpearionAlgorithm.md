## Procedure INSERT(arr, n, pos, value):
    If pos < 0 OR pos > n:
        Print "Invalid position"
        Return
    End If
    
    For i = n down to pos+1:
        arr[i] = arr[i-1] 
    End For
    
    arr[pos] = value
    n = n + 1 
    Print "Element inserted successfully"
End Procedure


## Procedure DELETE(arr, n, pos):
    If pos < 0 OR pos >= n:
        Print "Invalid position"
        Return
    End If
    
    For i = pos to n-2:
        arr[i] = arr[i+1]  // Shift elements left
    End For
    
    n = n - 1  // Decrease array size
    
    Print "Element deleted successfully"
End Procedure


## Procedure LINEAR_SEARCH(arr, n, key):
    For i = 0 to n-1:
        If arr[i] == key:
            Print "Element found at index", i
            Return i
        End If
    End For
    Print "Element not found"
    Return -1
End Procedure
