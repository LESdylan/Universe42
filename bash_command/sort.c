#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 6

typedef struct Manage
{
    char *pseudo;
    int id;
} Manage;


static void ft_swap(Manage *ptr, Manage *ptr2)
{
    Manage temp;

    temp = *ptr;
    *ptr = *ptr2;
    *ptr2 = temp;
}
/**
 * Shuffles an array of `Manage` elements using the Fisher-Yates algorithm,
 * utilizing pointer arithmetic for element manipulation.
 * @param array A pointer to the array of `Manage` elements to be shuffled.
 * @param len The number of elements in the array to be shuffled.
 * @note This function performs an in-place shuffle, meaning the original
 * array is modified directly.
 */
static void shuffle(Manage *array, int len)
{
    Manage *end;
    Manage *ptr;
    Manage *swap_with;

    end = array + len;
    ptr = end - 1;
    while(ptr >= array + 1)
    {
        swap_with = array + rand() % (ptr - array + 1);
        ft_swap(ptr, swap_with);
        ptr--;
    }
}
/**
 * The purpose of this function is to create a new list of `Manage` elements
 * with distinct values, where each element is initialized with a pseudo (name) from 
 * the provided `names` array, and the list is shuffled using the `shuffle` function.
 * @param len The number of elements to be included in the new list.
 * @param names An array of string literals (char pointers) representing the pseudo (names)
 * to be assigned to the `Manage` elements.
 * @return A pointer to the newly created and shuffled list of `Manage` structures. 
 * If an error occurs (e.g., insufficient memory), it returns `NULL`.
 * @note The `len` must not be greater than the total number of available `names`.
 */
static Manage *create_distinct_random_list(int len, char **names)
{
    Manage *new_list;
    Manage *ptr;
    Manage *result;
    Manage *res_ptr;
    int i;

    if (len > RANGE)
        return (NULL);
    new_list = malloc(RANGE * sizeof(Manage)); 
    result = malloc(len * sizeof(Manage));
    if (!result || !new_list)
        return (NULL);
    ptr = new_list;
    i = -1;
    while (++i < RANGE)
    {
        (ptr + i)->pseudo = *(names + i);
        (ptr + i)->id = i;
    }
    shuffle(new_list, RANGE);
    ptr = new_list;
    res_ptr = result;
    i = -1;
    while (++i < len)
        *res_ptr++ = *ptr++;

    free(new_list);
    return (result);
}

/**
 * The purpose of this function is to cut in half the whole grou`already shuffled
 * It assigns the first  half of the list ot `group_a` and the second half to `group_b`
 * @param lst A pointer to the first element of the shuffled list to be split
 * @param len the maximum length of the group 
 * @param group_a the pointer to the first node of the group a
 * @param group_b The pointer to the first node of the group b
 * @return nothing, just update, the datas within the variables
 * @note The function assumes that `len` is an even number. If the number
 * of elements in the list is odd, the behavior will be undefined
 */
static void split_into_groups(Manage *lst, int len, Manage **group_a, Manage **group_b)
{
    Manage *ptr_a;
    Manage *ptr_b;
    int i;

    *group_a = malloc(len / 2 * sizeof(Manage));
    *group_b = malloc(len / 2 * sizeof(Manage));
    if (!*group_a || !*group_b)
        return;
    ptr_a = *group_a;
    ptr_b = *group_b;
    i = -1;
    while (++i < len)
    {
        if (i < len / 2)
            *ptr_a++ = *lst++;
        else
            *ptr_b++ = *lst++;
    }
}

int main(void)
{
    srand(time(NULL));

    // List of names (pseudos)
    char *names[] = {"dlesieur", "anvilla", "jpantoja", "marimuno", "rocgarci", "vjan-nie"};
    int len = 6;

    // Create a distinct random list of Manage structures
    Manage *random_list = create_distinct_random_list(len, names);
    if (!random_list)
    {
        printf("Error: Failed to create the random list.\n");
        return 1;
    }

    // Print the random list of names
    printf("Random distinct list: ");
    for (int i = 0; i < len; i++)
    {
        printf("%s ", random_list[i].pseudo);
    }
    printf("\n");

    // Create two groups: A and B
    Manage *group_a, *group_b;
    split_into_groups(random_list, len, &group_a, &group_b);

    // Print Group A
    printf("Group A: ");
    for (int i = 0; i < len / 2; i++)
    {
        printf("%s ", group_a[i].pseudo);
    }
    printf("\n");

    // Print Group B
    printf("Group B: ");
    for (int i = 0; i < len / 2; i++)
    {
        printf("%s ", group_b[i].pseudo);
    }
    printf("\n");

    // Free the allocated memory
    free(random_list);
    free(group_a);
    free(group_b);

    return 0;
}