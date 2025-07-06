// Khởi tạo cấu trúc cho một phần tử trong danh sách liên kết bao gồm dữ liệu là một số nguyên, con trỏ đến phần tử tiếp theo và con trỏ trỏ đến phần tử trước đó
// Xây dựng hàm tạo phần tử mới cho danh sách liên kết
// Tạo ra danh sách liên kết đôi với 5 phần tử bất kỳ
// xây dựng thêm hàm xoá phần tử đầu tiên trong danh sách liên kết đôi

#include <stdio.h>
#include <stdlib.h>
// Khởi tạo cấu trúc cho một phần tử trong danh sách liên kết
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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
// hàm xoá phần tử đầu tiên trong danh sách liên kết đôi
Node* xoaPhanTuDau(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}
// Hàm chính
int main() {
    Node* head = taoRaDanhSach();
    printf("Danh sách liên kết đôi ban đầu: ");
    duyetToanBoDanhSach(head);

    // Xoá phần tử đầu tiên
    head = xoaPhanTuDau(head);
    printf("Danh sách liên kết đôi sau khi xoá phần tử đầu tiên: ");
    duyetToanBoDanhSach(head);

    // Giải phóng bộ nhớ
    freeNode(head);

    return 0;
}
