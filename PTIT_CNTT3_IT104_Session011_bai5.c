//Từ dữ liệu đã tạo từ bài 1, xây dựng thêm hàm thêm mới phần tử vào đầu danh sách liên kết đôi
//Yêu cầu người dùng nhập vào số nguyên dương bất kỳ
//Thêm phần tử có dữ liệu là số đã nhập vào đầu danh sách liên kết

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
// Hàm thêm phần tử mới vào đầu danh sách liên kết đôi
Node* themVaoDau(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// hàm chính
int main() {
    Node* head = taoRaDanhSach();
    printf("Danh sach lien ket ban dau: ");
    duyetToanBoDanhSach(head);

    int data;
    printf("Nhap so nguyen duong can them vao dau danh sach: ");
    scanf("%d", &data);

    head = themVaoDau(head, data);
    printf("Danh sach lien ket sau khi them: ");
    duyetToanBoDanhSach(head);

    freeNode(head);
    return 0;
}


