//Từ dữ liệu đã tạo từ bài 1, xây dựng thêm hàm lấy ra độ dài trong danh sách liên kết đôi
//Thực hiện gọi hàm lấy ra độ dài danh sách liên kết đôi và in ra mnaf hình
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
//hàm giải phóng bộ nhớ của danh sách liên kết đôi
void giaiPhongBoNho(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}
// Hàm tính độ dài của danh sách liên kết đôi
int doDaiDanhSach(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->n
        ext;
    }
    return length;
}
// Hàm chính
int main() {
    Node* head = taoRaDanhSach();
    int length = doDaiDanhSach(head);
    printf("Danh sách liên kết có %d phần tử\n", length);

    // Giải phóng bộ nhớ
    giaiPhongBoNho(head);

    return 0;
}


