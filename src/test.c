#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * AI CI/CD TEST FILE - VULNERABLE CODE SAMPLE
 * This file contains intentional security flaws for testing purposes.
 */

// [OWASP A02:2021] Cryptographic Failures
// Phát hiện qua Regex: Hardcoded Secret/Token
const char* SECRET_TOKEN = "ghp_CriticalAdminAccessKey_9999999999";
const char* DB_PASSWORD = "super_secret_password_123";

// [OWASP A03:2021] Injection
// Lỗi SQL Injection giả lập qua string concatenation
void Database_Query(char *userInput) {
    char query[512];
    // Rất nguy hiểm: Nối chuỗi trực tiếp vào câu lệnh SQL
    sprintf(query, "SELECT * FROM users WHERE name = '%s' AND role = 'admin';", userInput); 
    printf("[DB LOG] Executing: %s\n", query);
}

// [OWASP A03:2021] Command Injection
void Execute_System_Command(char *cmd) {
    char full_cmd[128];
    // Cho phép thực thi lệnh hệ thống từ input người dùng
    sprintf(full_cmd, "ls -la %s", cmd);
    system(full_cmd); 
}

void Process_User_Data() {
    char buffer[16];
    char userInput[256];
    
    printf("Nhap ten nguoi dung: ");
    // [OWASP A04:2021] Insecure Input - Không kiểm tra độ dài (Buffer Overflow)
    scanf("%s", userInput); 
    
    Database_Query(userInput);

    printf("Nhap thong tin phu: ");
    // [OWASP A03:2021] Buffer Overflow
    // gets() là hàm cực kỳ nguy hiểm, luôn gây tràn bộ nhớ
    gets(buffer); 
    
    printf("Du lieu da nhan: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    printf("--- HE THONG KIEM THU BAO MAT AI CI/CD ---\n");

    if (argc > 1) {
        // Test Command Injection qua đối số dòng lệnh
        Execute_System_Command(argv[1]);
    }
    
    Process_User_Data();

 
    printf("[DEBUG] Current Session Token: %s\n", SECRET_TOKEN);
    printf("[DEBUG] Admin Password: %s\n", DB_PASSWORD);

    // [Memory Management] Lỗi rò rỉ bộ nhớ (Memory Leak)
    char *leak = (char *)malloc(1024);
    if (leak != NULL) {
        strcpy(leak, "This data is never freed, causing a memory leak.");
        printf("Memory allocated at: %p\n", (void*)leak);
    }
    // Quên free(leak)

    return 0;
}
