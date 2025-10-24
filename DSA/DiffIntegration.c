#include <stdio.h>
#include <stdlib.h>

struct node {
    float coeff;   // Changed coeff to float to handle fractions
    int exp;
    struct node* link;
};

// Function to create a new node
struct node* createNode(struct node* poly, float coeff, int exp) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->coeff = coeff;
    p->exp = exp;
    p->link = NULL;
    return p;
}

// Function to insert a node at the end of the polynomial
struct node* insertNode(struct node* poly, float coeff, int exp) {
    struct node* newNode = createNode(poly, coeff, exp);
    if (poly == NULL) {
        return newNode;
    }

    struct node* temp = poly;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
    return poly;
}

// Function to differentiate the polynomial
struct node* differentiate(struct node* poly) {
    struct node* result = NULL;
    struct node* temp = poly;
    while (temp != NULL) {
        float newCoeff = temp->coeff * temp->exp;  // Differentiate coefficient
        int newExp = temp->exp - 1;               // Decrement exponent

        // Add term only if coefficient is non-zero and exponent is non-negative
        if (newCoeff != 0 && newExp >= 0) {
            result = insertNode(result, newCoeff, newExp);
        }
        temp = temp->link;
    }
    return result;
}

// Function to integrate the polynomial
struct node* integration(struct node* poly) {
    struct node* intRes = NULL;  // Resultant polynomial for integration
    struct node* temp = poly;

    while (temp != NULL) {
        float newCoeff = temp->coeff / (temp->exp + 1);  // Divide coefficient by (exp + 1)
        int newExp = temp->exp + 1;                      // Increment exponent

        intRes = insertNode(intRes, newCoeff, newExp);   // Insert new term into result
        temp = temp->link;
    }
    return intRes;
}

// Function to display the polynomial
void display(struct node* poly) {
    struct node* temp = poly;
    while (temp != NULL) {
        if (temp->link != NULL) {
            if (temp->exp != 0)
                printf("%.2fx^%d + ", temp->coeff, temp->exp);
            else
                printf("%.2f + ", temp->coeff);
        } else {
            if (temp->exp != 0)
                printf("%.2fx^%d", temp->coeff, temp->exp);
            else
                printf("%.2f", temp->coeff);
        }
        temp = temp->link;
    }
    printf("\n");
}

// Main function
int main() {
    struct node* exp = NULL;
    struct node* resDiff = NULL;
    struct node* resInt = NULL;

    // Create the polynomial
    exp = insertNode(exp, 3, 3);
    exp = insertNode(exp, 2, 2);
    exp = insertNode(exp, 1, 1);

    // Display the original polynomial
    printf("Original Polynomial: ");
    display(exp);

    // Perform differentiation
    resDiff = differentiate(exp);
    printf("Differentiated Polynomial: ");
    display(resDiff);

    // Perform integration
    resInt = integration(exp);
    printf("Integrated Polynomial: ");
    display(resInt);

    return 0;
}
