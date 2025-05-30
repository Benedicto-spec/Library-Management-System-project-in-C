#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[50];
    int isIssued; // 0 = available, 1 = issued
} Book;

Book books[MAX_BOOKS];
int bookCount = 0;

// Pre-load 50 sample books
void initializeSampleBooks() {
    Book samples[] = {
        {1, "To Kill a Mockingbird\n", "Harper Lee\n", 0},
        {2, "1984\n", "George Orwell\n", 0},
        {3, "Pride and Prejudice\n", "Jane Austen\n", 0},
        {4, "The Great Gatsby\n", "F. Scott Fitzgerald\n", 0},
        {5, "Moby-Dick\n", "Herman Melville\n", 0},
        {6, "War and Peace\n", "Leo Tolstoy\n", 0},
        {7, "The Catcher in the Rye\n", "J.D. Salinger\n", 0},
        {8, "The Hobbit\n", "J.R.R. Tolkien\n", 0},
        {9, "Brave New World\n", "Aldous Huxley\n", 0},
        {10, "Crime and Punishment\n", "Fyodor Dostoevsky\n", 0},
        {11, "The Odyssey\n", "Homer\n", 0},
        {12, "The Brothers Karamazov\n", "Fyodor Dostoevsky\n", 0},
        {13, "Jane Eyre\n", "Charlotte Brontë\n", 0},
        {14, "Wuthering Heights\n", "Emily Brontë\n", 0},
        {15, "The Lord of the Rings\n", "J.R.R. Tolkien\n", 0},
        {16, "Animal Farm\n", "George Orwell\n", 0},
        {17, "Great Expectations\n", "Charles Dickens\n", 0},
        {18, "Lolita\n", "Vladimir Nabokov\n", 0},
        {19, "Ulysses\n", "James Joyce\n", 0},
        {20, "The Divine Comedy\n", "Dante Alighieri\n", 0},
        {21, "Harry Potter and the Sorcerer’s Stone\n", "J.K. Rowling\n", 0},
        {22, "The Alchemist\n", "Paulo Coelho\n", 0},
    };
    int n = sizeof(samples) / sizeof(samples[0]);
    for (int i = 0; i < n && bookCount < MAX_BOOKS; i++) {
        books[bookCount++] = samples[i];
    }
}
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library full!\n");
        return;
    }
    printf("Enter book ID: ");
    if (scanf("%d", &books[bookCount].id) != 1) {
        printf("Invalid input. Please enter a number for the book ID.\n");
        // Optionally, clear the input buffer:
        while (getchar() != '\n');
        return; // Don't proceed with adding the book
    }
    printf("Enter book title: ");
    getchar(); // clear newline
    fgets(books[bookCount].title, 100, stdin);
    books[bookCount].title[strcspn(books[bookCount].title, "\n")] = '\0';
    printf("Enter author name: ");
    fgets(books[bookCount].author, 50, stdin);
    books[bookCount].author[strcspn(books[bookCount].author, "\n")] = '\0';
    books[bookCount].isIssued = 0;
    bookCount++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    printf("=== Book List ===\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d | Title: %s | Author: %s | Status: %s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].isIssued ? "Issued" : "Available");
    }
}

void searchBook() {
    char search[100];
    printf("Enter book title to search: ");
    getchar(); // Clear newline from buffer
    fgets(search, 100, stdin);

    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, search)) {
            printf("Found: ID %d | Title: %sAuthor: %s\n",
                   books[i].id,
                   books[i].title,
                   books[i].author);
        }
    }
}

void deleteBook() {
    int id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("Book deleted.\n");
            return;
        }
    }

    printf("Book not found.\n");
}

void issueBook() {
    int id;
    printf("Enter book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (books[i].isIssued) {
                printf("Book already issued.\n");
            } else {
                books[i].isIssued = 1;
                printf("Book issued successfully.\n");
            }
            return;
        }
    }  

    

    printf("Book not found.\n");
}
void returnBook() {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (!books[i].isIssued) {
                printf("Book was not issued.\n");
            } else {
                books[i].isIssued = 0;
                printf("Book returned.\n");
            }
            return;
        }
    }

    printf("Book not found.\n");
}

int main() {
    initializeSampleBooks();  // Pre-load sample books
    int choice;

    while (1) {
        printf("\n=== Library Management System ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Issue Book\n");
        printf("6. Return Book\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number from 1 to 7.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue; // Go back to the menu
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: issueBook(); break;
            case 6: returnBook(); break;
            case 7: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
