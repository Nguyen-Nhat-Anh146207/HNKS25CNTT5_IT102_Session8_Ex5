
#include <stdio.h>

struct Subscription {
    int sub_id;
    char plan_name[31];
    double monthly_fee;
    int user_limit;
};

int main() {
    struct Subscription subscriptions[100];
    int N;
    int i;
    double total_revenue = 0;

    printf("Nhap so luong goi dich vu: ");

    if (scanf("%d", &N) != 1 || N <= 0 || N > 100) {
        printf("So luong goi dich vu khong hop le!\n");
        return 0;
    }

    for (i = 0; i < N; i++) {
        printf("\nNhap thong tin goi dich vu thu %d:\n", i + 1);

        printf("Ma goi: ");
        scanf("%d", &subscriptions[i].sub_id);

        printf("Ten goi: ");
        scanf("%30s", subscriptions[i].plan_name);

        printf("Cuoc phi hang thang (USD): ");
        scanf("%lf", &subscriptions[i].monthly_fee);

        printf("Gioi han user: ");
        scanf("%d", &subscriptions[i].user_limit);

        total_revenue += subscriptions[i].monthly_fee;
    }

    printf("\n");
    printf("===============================================================\n");
    printf("                 DANH SACH GOI DICH VU SAAS\n");
    printf("===============================================================\n");
    printf("%-10s %-20s %-18s %-15s\n",
           "MA GOI", "TEN GOI", "CUOC PHI (USD)", "GIOI HAN USER");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < N; i++) {
        printf("%-10d %-20s %-18.2f %-15d\n",
               subscriptions[i].sub_id,
               subscriptions[i].plan_name,
               subscriptions[i].monthly_fee,
               subscriptions[i].user_limit);
    }
    printf("---------------------------------------------------------------\n");

    printf("TONG DOANH THU HANG THANG: %.2f USD\n", total_revenue);

    return 0;
}