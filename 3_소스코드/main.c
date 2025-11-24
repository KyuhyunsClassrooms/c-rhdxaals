#include <stdio.h>
#include <string.h>

#define MAX 100

// 상품 구조체
struct Product {
    char name[50];
    int price;
    int stock;
};

struct Product p[MAX];
int count = 0;

// 함수 선언
void addProduct();
void printProducts();
void searchProduct();
void calcTotal();

int main() {
    int menu;

    while (1) {  // 반복 시작
        
        // 메뉴 출력
        printf("\n===== 메뉴 =====\n");
        printf("1. 상품 등록\n");
        printf("2. 상품 목록 출력\n");
        printf("3. 상품 검색\n");
        printf("4. 총 재고 금액 계산\n");
        printf("0. 종료\n");
        printf("메뉴 번호 입력: ");

        if (scanf("%d", &menu) != 1) {    // 숫자 아닌 입력 방지
            printf("숫자만 입력하세요!\n");
            while (getchar() != '\n');   // 버퍼 비우기
            continue;
        }
        while (getchar() != '\n');       // 입력 후 버퍼 비우기

        // 메뉴 처리
        if (menu == 1) {
            addProduct();
        }
        else if (menu == 2) {
            printProducts();
        }
        else if (menu == 3) {
            searchProduct();
        }
        else if (menu == 4) {
            calcTotal();
        }
        else if (menu == 0) {
            printf("프로그램 종료\n");
            break;
        }
        else {
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}


// =======================
// 1. 상품 등록
// =======================
void addProduct() {
    if (count >= MAX) {
        printf("더 이상 등록할 수 없습니다.\n");
        return;
    }

    printf("\n[상품 등록]\n");

    printf("상품명: ");
    scanf("%s", p[count].name);

    printf("가격: ");
    scanf("%d", &p[count].price);

    printf("재고 수량: ");
    scanf("%d", &p[count].stock);

    count++;
    printf("상품 등록 완료!\n");
}


// =======================
// 2. 상품 목록 출력
// =======================
void printProducts() {
    printf("\n[상품 목록]\n");

    if (count == 0) {
        printf("등록된 상품이 없습니다.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d) 이름: %s | 가격: %d원 | 재고: %d개\n",
               i + 1, p[i].name, p[i].price, p[i].stock);
    }
}


// =======================
// 3. 상품 검색
// =======================
void searchProduct() {
    char target[50];
    int found = 0;

    printf("\n[상품 검색]\n");
    printf("검색할 상품명 입력: ");
    scanf("%s", target);

    for (int i = 0; i < count; i++) {
        if (strcmp(p[i].name, target) == 0) {
            printf("상품 발견!\n");
            printf("이름: %s | 가격: %d | 재고: %d\n",
                   p[i].name, p[i].price, p[i].stock);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("해당 상품이 없습니다.\n");
}


// =======================
// 4. 총 재고 금액 계산
// =======================
void calcTotal() {
    long long total = 0;

    printf("\n[총 재고 금액 계산]\n");

    for (int i = 0; i < count; i++) {
        total += (long long)p[i].price * p[i].stock;
    }

    printf("전체 재고 금액: %lld원\n", total);
}
