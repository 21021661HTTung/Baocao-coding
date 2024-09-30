#include <iostream>

using namespace std;

long long tinhThue(long long thuNhap, int &phanTramThue) {
    if (thuNhap < 0) {
        phanTramThue = -1; // Trường hợp thu nhập âm không hợp lệ
        return -1; 
    }
    if (thuNhap < 5000000) {
        phanTramThue = 0; // Miễn thuế
        return 0; 
    } 
    else if (thuNhap <= 10000000) {
        phanTramThue = 10; // Thuế 10%
        return thuNhap * 0.10; 
    } 
    else if (thuNhap < 20000000) {
        phanTramThue = 20; // Thuế 20%
        return thuNhap * 0.20; 
    } 
    else {
        phanTramThue = 30; // Thuế 30%
        return thuNhap * 0.30; 
    }
}

int main() {
    // Test cases kiểm thử giá trị biên
    long long testCases[] = {0, -1000000, 1000000, 19000000, 10000000, 20000000, 21000000};
    
    //Testcases kiểm thử bảng quyết định.
    // chọn 1 số bất kỳ trong các khoảng test cases để thử 
    // long long testCases[] = {-200000, 4000000, 8000000, 17000000, 22000000};
    for (int i = 0; i < 7; i++) { // Lặp qua từng trường hợp thử nghiệm( lưu ý thay đổi số lượng testCases)
        long long thuNhap = testCases[i];
        int phanTramThue; // Biến để lưu phần trăm thuế
        long long thuePhaiNop = tinhThue(thuNhap, phanTramThue);
        
        cout << "Thu nhập: " << thuNhap << " VND, ";
        
        // Kiểm tra kết quả thực tế và in ra tương ứng
        if (thuNhap < 0) {
            cout << "Kết quả: input không hợp lệ." << endl; 
        } else if (thuePhaiNop == 0) {
            cout << "Kết quả: Miễn thuế." << endl;
        } else {
            cout << "Thuế phải nộp: " << thuePhaiNop << " VND, Phần trăm thuế: " << phanTramThue << "%" << endl;
        }
    }
    
    return 0;
}
