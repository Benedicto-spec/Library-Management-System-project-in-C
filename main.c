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
