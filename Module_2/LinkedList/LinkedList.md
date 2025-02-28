# **LINKED LIST**

## **1. SINGLY LINKED LIST**

A **Singly Linked List** consists of nodes where each node contains:

--> Data

--> A pointer to the next node in the sequence.

### **Operations in SLL**

**1. INSERTION**
**2. DELETION**
**3. TRAVERSAL**

## **Algorithm (Pseudocode)**

### **Insertion at End:**
    Create a new node

    If head is NULL, set head = new node

    Else

    Traverse to the last node

    Set last node's next = new node


### **Deletion from Beginning:**

        If head is NULL, return

        Else

        temp = head

        head = head->next

        Free temp

### **Traversal:**

        Set temp = head

        While temp is not NULL

        Print temp->data

        Move temp to temp->next


## **2. Doubly Linked List (DLL)**

A **Doubly Linked List** contains nodes with:

Data

A pointer to the next node

A pointer to the previous node

### **Operations in DLL**

Insertion (beginning, end, or specific position)

Deletion (beginning, end, or specific position)

Traversal (both forward and backward)

## **Algorithm (Pseudocode)**

### **Insertion at End:**

        Create a new node

        If head is NULL, set head = new node

        Else

        Traverse to last node

        Set last node's next = new node
        
        Set new node's prev = last node

### **Deletion from Beginning:**

        If head is NULL, return
        Else
        temp = head
        head = head->next
        Set head->prev = NULL
        Free temp
### **Traversal (Forward and Backward):**

Forward: Start from head, move using next pointers

Backward: Start from last node, move using prev pointers
