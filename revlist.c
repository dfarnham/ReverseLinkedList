#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;


Node *
reverse(Node *input) {
    // if the given input is null, or a single node just return the input
    // as it's already in a configuration representing a reversed list
    if (!input || !input->next) return input;

    // pointer "head" represents the current head of the input
    // pointer "nhead" represents the "new head" of the reversed list being created
    // assign head and nhead to the first 2 Nodes of the input list respectively
    //
    // +-------+   +-------+ 
    // | head  |   |       |
    // |       |-> | nhead |->??
    // | input |   |       |
    // +-------+   +-------+
    Node *head = input;
    Node *nhead = head->next;

    // the existing head will become the tail of the reversed list
    // so create that structure now
    head->next = (Node *)NULL;

    // head has now been reversed, i.e. its "next" points to null
    //
    // Current state;
    //    null<-head , nhead->??
    //        +-------+   +-------+ 
    //        |       |   |       |
    // null <-| head  |   | nhead |->??
    //        |       |   |       |
    //        +-------+   +-------+
    //
    // traverse the list reversing "nhead" next pointers until the
    // current tail is found, which is when nhead->next points to null
    // we need another pointer to shadow nhead while connections are re-assigned
    while (nhead->next) {
        Node *shadow = nhead; // save the position of "nhead"
        nhead = nhead->next;  // move the "nhead" pointer forward
        shadow->next = head;  // re-assign the shadow next pointer
        head = shadow;        // move "head" forward
    }

    // this is the known exit state from above
    //
    // Known state;
    //   ...<-head , nhead->null  
    //        +-------+     +-------+   +-------+ 
    //        |       |     |       |   |       |
    //  null<-|       |<-...| head  |   | nhead |->null
    //        |       |     |       |   |       |
    //        +-------+     +-------+   +-------+
    //
    // all that's left is to assign nhead->next to head and return the new head
    nhead->next = head;
    return nhead;
}

// 
// Nothing interesting beyond this point, just driver code
// -------------------------------------------------------
//
Node *
make_node(int val) {
    Node *node = (Node *)calloc(1, sizeof(Node));

    if (!node) {
        fprintf(stderr, "calloc() failure\n");
        exit(1);
    }
    node->val = val;
    node->next = (Node *)NULL;

    return node;
}


Node *
build_list(int testno) {
    if (testno <= 0) return (Node *)NULL;

    Node *head = make_node(1);
    Node *ptr = head;

    for (int i = 1; i < testno; i++) {
        ptr->next = make_node(i + 1);
        ptr = ptr->next;
    }

    return head;
}


void
free_list(Node *head) {
    if (!head) return;

    Node *ptr = head;
    do {
        head = ptr->next;
        free(ptr);
        ptr = head;
    } while (ptr);
}


void
print_list(Node *head) {
    for (Node *ptr = head; ptr; ptr = ptr->next) {
        printf("%d -> ", ptr->val);
    }
    printf("null\n");
}


int
main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage %s n\n", argv[0]);
        exit(1);
    }

    Node *lst = build_list(atoi(argv[1]));

    printf("original:\n");
    print_list(lst);

    printf("-----------\n");

    printf("reversed:\n");
    lst = reverse(lst);
    print_list(lst);

    free_list(lst);
}
