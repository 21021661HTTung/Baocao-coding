#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

// Hàm tính thuế dựa trên thu nhập
long long tinhThue(long long thuNhap, int &phanTramThue) {
    if (thuNhap < 0) return phanTramThue = -1, -1; // Kiểm tra thu nhập âm
    if (thuNhap < 5000000) return phanTramThue = 0, 0; // Miễn thuế
    if (thuNhap <= 10000000) return phanTramThue = 10, thuNhap * 0.10; // Thuế 10%
    if (thuNhap < 20000000) return phanTramThue = 20, thuNhap * 0.20; // Thuế 20%
    return phanTramThue = 30, thuNhap * 0.30; // Thuế 30%
}

// Hàm để kiểm tra độ phủ all-uses từ tệp đầu vào
bool kiemTraDoPhuAllUses(const vector<long long>& testCases) {
    // Sử dụng một tập hợp để lưu trữ các điều kiện đã kiểm tra
    set<int> conditionsChecked;

    for (long long thuNhap : testCases) {
        if (thuNhap < 0) {
            conditionsChecked.insert(1); // Kiểm tra thu nhập âm
        } else if (thuNhap < 5000000) {
            conditionsChecked.insert(2); // Kiểm tra miễn thuế
        } else if (thuNhap <= 10000000) {
            conditionsChecked.insert(3); // Kiểm tra thuế 10%
        } else if (thuNhap < 20000000) {
            conditionsChecked.insert(4); // Kiểm tra thuế 20%
        } else {
            conditionsChecked.insert(5); // Kiểm tra thuế 30%
        }
    }

    // Kiểm tra xem tất cả các điều kiện đã được kiểm tra
    return conditionsChecked.size() == 5;
}

int main() {
    ifstream inFile("testcasedatyeucau.txt"); // Mở tệp để đọc
    if (!inFile) return cerr << "Không thể mở tệp testcasedatyeucau.txt\n", 1; // Kiểm tra lỗi mở tệp

    vector<long long> testCases; // Vector để lưu trữ các trường hợp kiểm tra
    long long thuNhap;

    // Đọc từng thu nhập từ tệp
    while (inFile >> thuNhap) {
        testCases.push_back(thuNhap);
    }
    inFile.close(); // Đóng tệp sau khi đọc xong

    // Kiểm tra độ phủ all-uses
    if (kiemTraDoPhuAllUses(testCases)) {
        cout << "Đầu vào đạt yêu cầu độ phủ all-uses." << endl;
    } else {
        cout << "Đầu vào không đạt yêu cầu độ phủ all-uses." << endl;
    }

    // Kiểm tra và tính thuế cho từng trường hợp
    for (long long thuNhap : testCases) {
        int phanTramThue = -1; // Giá trị mặc định
        long long thuePhaiNop = tinhThue(thuNhap, phanTramThue);
        
        cout << "Thu nhập: " << thuNhap << " VND, ";
        if (phanTramThue == -1) {
            cout << "Kết quả: input không hợp lệ." << endl;
        } else if (thuePhaiNop == 0) {
            cout << "Kết quả: Miễn thuế." << endl;
        } else {
            cout << "Thuế phải nộp: " << thuePhaiNop << " VND, Phần trăm thuế: " << phanTramThue << "%" << endl;
        }
    }
    return 0;
}
