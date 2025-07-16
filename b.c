#include <stdio.h>

struct student {
    int roll;
    float marks;
};

int main() {
    struct student s1 = {101, 89.5};
    struct student *ptr;

    ptr = &s1;  // pointer stores address of s1

    // Accessing members using structure pointer
    printf("Roll: %d\n", ptr->roll);
    printf("Marks: %.2f\n", ptr->marks);

    return 0;
}