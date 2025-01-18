#include <stdio.h>
#include <string.h>

// Hàm Counting Sort
void countingSort(int arr[], int n, int maxVal) {
    // Tạo mảng đếm (count) có kích thước maxVal + 1 và mảng kết quả (output) có kích thước n
    int count[maxVal + 1];
    int output[n];
    // Khởi tạo tất cả phần tử trong mảng count[] về 0
    memset(count, 0, sizeof(count));
    // Đếm số lần xuất hiện của từng phần tử trong mảng arr[]
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;  // Tăng giá trị count[arr[i]] lên 1
    }
    // Cộng dồn mảng count để xác định vị trí cuối cùng của mỗi giá trị trong mảng sắp xếp
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];  // count[i] chứa vị trí cuối cùng của phần tử i trong output[]
    }
    // Duyệt ngược mảng arr[] để đặt giá trị vào vị trí đúng trong output[], đảm bảo tính ổn định
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];  // Đặt phần tử vào vị trí đúng
        count[arr[i]]--;  // Giảm giá trị count[arr[i]] để xử lý phần tử trùng nhau
    }
    // Sao chép mảng output[] đã sắp xếp vào arr[] để trả kết quả về
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
// Hàm hiển thị mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    // Khởi tạo mảng đầu vào
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);  // Tính số lượng phần tử trong mảng
    int maxVal = 8; // Giá trị lớn nhất trong mảng (cần biết trước)
    printf("Mảng ban đầu:\n");
    printArray(arr, n);
    // Gọi hàm Counting Sort để sắp xếp mảng
    countingSort(arr, n, maxVal);
    printf("Mảng sau khi sắp xếp:\n");
    printArray(arr, n);
}
