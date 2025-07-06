//Từ dữ liệu đã tạo từ bài 1, xây dựng thêm hàm tìm kiếm trong danh sách liên kết đôi
//Yêu cầu người dùng nhập vào số nguyên dương bất kỳ
//kiểm tra xem số được nhập có trùng với dữ liệu phần tử nào trong danh sách liên kết không và in kết quả

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
        printf("Không đủ bộ nhớ\n");
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
// xây dưng thêm hàm tìm kiếm trong danh sách liên kết đôi
bool timKiem(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}
// giải phóng bộ nhớ của danh sách liên kết đôi
void freeNode(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}
// yêu cầu người dùng nhập vào số nguyên dương bất kỳ
// kiểm tra xem số được nhập có trùng với dữ liệu phần tử nào trong danh sách liên kết không và in kết quả
int main() {
    Node* head = taoRaDanhSach();

    int value;
    printf("Nhập vào một số nguyên dương: ");
    scanf("%d", &value);

    if (timKiem(head, value)) {
        printf("Số %d có trong danh sách liên kết.\n", value);
    } else {
        printf("Số %d không có trong danh sách liên kết.\n", value);
    }

    freeNode(head);

    return 0;
}
