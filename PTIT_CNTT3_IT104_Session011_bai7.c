// Khởi tạo cấu trúc cho một phần tử trong danh sách liên kết bao gồm dữ liệu là một số nguyên, con trỏ đến phần tử tiếp theo và con trỏ trỏ đến phần tử trước đó
// Xây dựng hàm tạo phần tử mới cho danh sách liên kết
// Tạo ra danh sách liên kết đôi với 5 phần tử bất kỳ
// xây dựng thêm hàm thêm mới phần tử vào vị trí bất kỳ
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Khởi tạo cấu trúc cho một phần tử trong danh sách liên kết
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Xây dựng hàm tạo phần tử mới cho danh sách liên kết
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("ko đủ bộ nhớ\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// Tạo ra danh sách liên kết đôi với 5 phần tử bất kỳ
Node* taoRaDanhSach() {
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* fourth = createNode(4);
    Node* fifth = createNode(5);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    return head;
}
// Hàm duyệt toàn bộ danh sách liên kết đôi và in dữ liệu của từng phần tử
void duyetToanBoDanhSach(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
// Hàm giải phóng bộ nhớ của danh sách liên kết đôi
void freeNode(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}
// hàm thêm phần tử mới vào vị trí bất kỳ danh sách liên kết đôi
Node* themVaoViTri(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Vị trí không hợp lệ\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    return head;
}
// Hàm chính
int main() {
    Node* head = taoRaDanhSach();
    printf("Danh sách liên kết đôi ban đầu: ");
    duyetToanBoDanhSach(head);

    int data, position;
    printf("Nhập dữ liệu phần tử mới: ");
    scanf("%d", &data);
    printf("Nhập vị trí chèn phần tử mới (bắt đầu từ 0): ");
    scanf("%d", &position);

    head = themVaoViTri(head, data, position);
    printf("Danh sách liên kết đôi sau khi thêm phần tử: ");
    duyetToanBoDanhSach(head);

    // Giải phóng bộ nhớ
    freeNode(head);

    return 0;
}
