#include<stdio.h>
#include<stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* insertNode(struct Node* poly, int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (poly == NULL) {
        return newNode;
    }

    struct Node* temp = poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return poly;
}

struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    struct Node* temp2 = poly2;

    while (temp1 != NULL) {
        temp2 = poly2;
        while (temp2 != NULL) {
            int coeffProduct = temp1->coeff * temp2->coeff;
            int expSum = temp1->exp + temp2->exp;

            result = insertNode(result, coeffProduct, expSum);

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    struct Node *current = result;
    while (current != NULL && current->next != NULL) {
        struct Node *nextNode = current->next;

        if (current->exp == nextNode->exp) {
            current->coeff += nextNode->coeff;
            current->next = nextNode->next;
            free(nextNode);
        } else {
            current = current->next;
        }
    }

    return result;
}

void display(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void main() {
    struct Node* poly1 = NULL, *poly2 = NULL, *result = NULL;

    // Hardcoded input for polynomial 1: 3x^3 + 2x^2 + 1
    //poly1 = insertNode(poly1, 3, 3);
    poly1 = insertNode(poly1, 2, 2);
    poly1 = insertNode(poly1, 1, 0);

    // Hardcoded input for polynomial 2: 4x^2 + 3x + 5
    //poly2 = insertNode(poly2, 4, 2);
    poly2 = insertNode(poly2, 3, 1);
    poly2 = insertNode(poly2, 5, 0);

    printf("First Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    result = multiplyPolynomials(poly1, poly2);
    printf("Result: ");
    display(result);
}
