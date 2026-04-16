#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// [OWASP A02:2021] Cryptographic Failuresd
// Để lộ Secret Key và dùng thuật toán yếu (giả định)
const char* SECRET_TOKEN = "ghp_BadPracticeAdminToken12345";

// [OWASP A03:2021] Injection
// Lỗi SQL Injection (giả lập qua string format)
void Database_Query(char *userInput) {
    char query[256];
    sprintf(query, "SELECT * FROM users WHERE name = '%s';", userInput); 
    printf("Executing: %s\n", query);
}

void Process_Data() {
    char buffer[16];
    char userInput[256];
    printf("Nhap du lieu: ");
    // [OWASP A05:2021] Security Misconfiguration - Hardcoded password
    const char* hardcoded_password = "admin123";
    scanf("%s", userInput);  // [OWASP A04:2021] Insecure Input - No bounds checking
    Database_Query(userInput);
}
    // [OWASP A03:2021] Injection / Buffer Overflow
    // Dùng gets() là lỗi điển hình gây tràn bộ nhớ
    gets(buffer); 
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        Database_Query(argv[1]);
    }
    
    Process_Data();

    // [OWASP A09:2021] Security Logging and Monitoring Failures
    // In trực tiếp dữ liệu nhạy cảm ra log consoleewfhrnhv
    printf("Debug: Token hien tai la %s\n", SECRET_TOKEN);

    // Lỗi quản lý bộ nhớ
    char *leak = malloc(100);
    strcpy(leak, "This will leak");
    // Không có free(leak)

    return 0;
}
