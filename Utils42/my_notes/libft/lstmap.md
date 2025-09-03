The function `ft_lstmap` is part of the `libft` (a custom C library) and operates on linked lists. It is used to create a new linked list by applying a function (`f`) to the content of each element in the original list (`lst`). If an error occurs during the mapping process, it will clean up the memory allocated so far and return `NULL`.

### Function Signature:

```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

```

### Parameters:

- **`lst`**: The original linked list to be mapped (applied with the function `f`).
- **`f`**: A function that takes a `void *` (pointer to the content of a list node) and returns a new `void *`. This function is applied to the content of each element in the original list to transform it.
- **`del`**: A function used to delete a node's content if memory allocation fails during the transformation process (cleanup function). This is important to avoid memory leaks in case of errors.

### Return:

- The function returns a new linked list, which is the result of applying the function `f` to each element in the original list (`lst`). If there is an error (e.g., memory allocation failure), it returns `NULL`.

### Step-by-Step Breakdown:

1. **Initial Setup**:
    
    - The function initializes `new_list` to `NULL` because this is where the new list will be constructed.
    - It then starts iterating over the original list (`lst`), which holds the elements that need to be transformed.
    
    ```c
    new_list = NULL;
    while (lst) {
    
    ```
    
2. **Creating a New Node**:
    
    - For each element in the original list (`lst`), a new node (`new_node`) is created by applying the function `f` to the content of the current node (`lst->content`). This means `f(lst->content)` will transform the content of the current node.
    - `ft_lstnew(f(lst->content))` creates the new node with the transformed content.
    
    ```c
    new_node = ft_lstnew(f(lst->content));
    ```
    
3. **Checking for Memory Allocation Failure**:
    
    - If `ft_lstnew` returns `NULL` (which indicates that memory allocation for the new node failed), the function frees all previously allocated memory (nodes) using the `ft_lstclear` function and returns `NULL` to signal an error.
    
    ```c
    if (!new_node) {
        ft_lstclear(&new_list, del);
        return (NULL);
    }
    ```
    
4. **Adding the New Node to the New List**:
    
    - If the new node was created successfully, it is added to the end of the new list (`new_list`) using `ft_lstadd_back`. This function ensures the new node is appended to the last node in the new list.
    
    ```c
    ft_lstadd_back(&new_list, new_node);
    ```
    
5. **Moving to the Next Node**:
    
    - The function moves to the next node in the original list (`lst = lst->next;`) to process the next element.
    
    ```c
    lst = lst->next;
    ```
    
6. **Returning the New List**:
    
    - After processing all elements in the original list, the function returns the new list (`new_list`), which now contains the transformed nodes.
    
    ```c
    return (new_list);
    ```
    

### Example Usage:

Let's illustrate this with a simple example.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content) {
    t_list *new = malloc(sizeof(t_list));
    if (!new) return NULL;
    new->content = content;
    new->next = NULL;
    return new;
}

void ft_lstadd_back(t_list **lst, t_list *new) {
    t_list *temp = *lst;
    if (*lst == NULL) {
        *lst = new;
        return;
    }
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

void ft_lstclear(t_list **lst, void (*del)(void *)) {
    t_list *tmp;
    while (*lst) {
        tmp = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = tmp;
    }
}

void *increment(void *n) {
    int *new_n = malloc(sizeof(int));
    if (!new_n) return NULL;
    *new_n = *(int *)n + 1;
    return new_n;
}

void delete(void *content) {
    free(content);
}

int main() {
    t_list *lst = ft_lstnew(malloc(sizeof(int)));
    *(int *)(lst->content) = 1;

    t_list *new_lst = ft_lstmap(lst, increment, delete);

    // Printing new list's content
    while (new_lst) {
        printf("%d\\n", *(int *)(new_lst->content));
        new_lst = new_lst->next;
    }

    return 0;
}

```

### Example Explanation:

1. **`lst` Initialization**:
    - A list (`lst`) is created with a single node that holds the value `1`.
2. **`ft_lstmap` Transformation**:
    - The `ft_lstmap` function is called with the `increment` function (which increases the value by 1) and the `delete` function (to free memory).
3. **Result**:
    - The result is a new list where the content of the first node is `2` (i.e., `1 + 1`).

### Memory Management:

- **`ft_lstnew`** allocates memory for each new node.
- **`ft_lstadd_back`** appends the new node to the end of the new list.
- **`ft_lstclear`** ensures that if memory allocation fails, all previously allocated memory is freed.
- The function uses `delete` to free any allocated memory for each node's content in case of failure.

### Conclusion:

- `ft_lstmap` is a powerful function for transforming linked list data in `libft`.
- It applies a function to each element's content and builds a new list with the transformed content.
- If memory allocation fails, it handles the error by freeing the previously allocated memory and returning `NULL`.