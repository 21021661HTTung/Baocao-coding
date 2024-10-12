#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Coverage {
    bool thuNhapAm_True = false, thuNhapAm_False = false;
    bool duoi5000000_True = false, duoi5000000_False = false;
    bool duoi10000000_True = false, duoi10000000_False = false;
    bool duoi20000000_True = false, duoi20000000_False = false;
};

void theoDoiDieuKien(long long thuNhap, Coverage &coverage) {
    coverage.thuNhapAm_True |= thuNhap < 0;
    coverage.thuNhapAm_False |= thuNhap >= 0;
    coverage.duoi5000000_True |= thuNhap < 5000000;
    coverage.duoi5000000_False |= thuNhap >= 5000000;
    coverage.duoi10000000_True |= thuNhap <= 10000000;
    coverage.duoi10000000_False |= thuNhap > 10000000;
    coverage.duoi20000000_True |= thuNhap < 20000000;
    coverage.duoi20000000_False |= thuNhap >= 20000000;
}

long long tinhThue(long long thuNhap, int &phanTramThue) {
    if (thuNhap < 0) return phanTramThue = -1, -1;
    if (thuNhap < 5000000) return phanTramThue = 0, 0;
    if (thuNhap <= 10000000) return phanTramThue = 10, thuNhap * 0.10;
    if (thuNhap < 20000000) return phanTramThue = 20, thuNhap * 0.20;
    return phanTramThue = 30, thuNhap * 0.30;
}

void kiemTraPhuCap2(const Coverage &coverage) {
    cout << "Kiểm tra phủ cấp 2:\n"
         << "Điều kiện thuNhap < 0: " << ((coverage.thuNhapAm_True && coverage.thuNhapAm_False) ? "Đã bao phủ" : "Chưa bao phủ") << endl
         << "Điều kiện thuNhap < 5000000: " << ((coverage.duoi5000000_True && coverage.duoi5000000_False) ? "Đã bao phủ" : "Chưa bao phủ") << endl
         << "Điều kiện thuNhap <= 10000000: " << ((coverage.duoi10000000_True && coverage.duoi10000000_False) ? "Đã bao phủ" : "Chưa bao phủ") << endl
         << "Điều kiện thuNhap < 20000000: " << ((coverage.duoi20000000_True && coverage.duoi20000000_False) ? "Đã bao phủ" : "Chưa bao phủ") << endl;
}

int main() {
    ifstream inFile("testcase.txt");
    if (!inFile) return cerr << "Không thể mở file testcases.txt\n", 1;

    vector<long long> testCases;
    long long thuNhap;
    while (inFile >> thuNhap) testCases.push_back(thuNhap);
    inFile.close();

    Coverage coverage;
    for (long long thuNhap : testCases) {
        int phanTramThue;
        long long thuePhaiNop = tinhThue(thuNhap, phanTramThue);
        theoDoiDieuKien(thuNhap, coverage);
        
        cout << "Thu nhập: " << thuNhap << " VND, ";
        if (thuNhap < 0) cout << "Kết quả: input không hợp lệ." << endl;
        else if (thuePhaiNop == 0) cout << "Kết quả: Miễn thuế." << endl;
        else cout << "Thuế phải nộp: " << thuePhaiNop << " VND, Phần trăm thuế: " << phanTramThue << "%" << endl;
    }

    kiemTraPhuCap2(coverage);
    return 0;
}
