#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct Product {
    char name[50];
    int code;
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    Product p;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product code: ");
    scanf("%d", &p.code);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    products[num_products++] = p;
    printf("Product added successfully!\n");
}

void display_products() {
    printf("Products in inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. Name: %s | Code: %d | Quantity: %d | Price: %.2f\n", i+1, products[i].name, products[i].code, products[i].quantity, products[i].price);
    }
}

void update_quantity() {
    int code, quantity;
    printf("Enter product code: ");
    scanf("%d", &code);
    printf("Enter new quantity: ");
    scanf("%d", &quantity);
    for (int i = 0; i < num_products; i++) {
        if (products[i].code == code) {
            products[i].quantity = quantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void generate_report() {
    float total_sales = 0;
    printf("Sales report:\n");
    for (int i = 0; i < num_products; i++) {
        float sales = (products[i].quantity * products[i].price);
        total_sales += sales;
        printf("%d. Name: %s | Code: %d | Quantity: %d | Price: %.2f | Sales: %.2f\n", i+1, products[i].name, products[i].code, products[i].quantity, products[i].price, sales);
    }
    printf("Total sales: %.2f\n", total_sales);
}

int main() {
    int choice;
    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Update product quantity\n");
        printf("4. Generate sales report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                update_quantity();
                break;
            case 4:
                generate_report();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
