// Khởi tạo cấu trúc cho một phần tử trong danh sách liên kết bao gồm dữ liệu là một số nguyên, con trỏ đến phần tử tiếp theo và con trỏ trỏ đến phần tử trước đó
// Xây dựng hàm tạo phần tử mới cho danh sách liên kết
// Tạo ra danh sách liên kết đôi với 5 phần tử bất kỳ
// xây dựng  hàm xoá 1 phần tử ở vị trí bất kỳ
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
// Hàm xoá phần tử ở vị trí bất kỳ
Node* xoaPhanTu(Node* head, int position) {
    if (head == NULL || position < 0) {
        return head;
    }

    Node* current = head;
    int index = 0;

    // Duyệt đến phần tử ở vị trí cần xoá
    while (current != NULL && index < position) {
        current = current->next;
        index++;
    }

    // Nếu không tìm thấy phần tử ở vị trí đó
    if (current == NULL) {
        return head;
    }

    // Cập nhật con trỏ prev và next của các phần tử lân cận
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    return head;
}
// Hàm chính
int main() {
    Node* head = taoRaDanhSach();
    printf("Danh sách liên kết đôi ban đầu: ");
    duyetToanBoDanhSach(head);

    int position;
    printf("Nhập vị trí của phần tử cần xoá (bắt đầu từ 0): ");
    scanf("%d", &position);

    head = xoaPhanTu(head, position);
    printf("Danh sách liên kết đôi sau khi xoá phần tử ở vị trí %d: ", position);
    duyetToanBoDanhSach(head);

    freeNode(head);
    return 0;
}
