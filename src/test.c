#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * AI CI/CD TEST FILE - INTENTIONALLY VULNERABLE
 * WARNING:
 * This file is intentionally insecure and is only for testing
 * security scanning / code review / CI analysis tools.
 */

/* Hardcoded secrets */
const char *API_KEY = "sk_test_SUPER_SECRET_ABCXYZ_123456";
const char *JWT_SECRET = "my_ultra_weak_jwt_secret";
const char *DB_USER = "admin";
const char *DB_PASS = "root_password_123";

/* Weak randomness */
int GenerateOTP() {
    srand(time(NULL));
    return rand() % 1000000;
}

/* SQL Injection simulation */
void LoginUser(char *username, char *password) {
    char query[512];
    sprintf(
        query,
        "SELECT * FROM users WHERE username='%s' AND password='%s';",
        username,
        password
    );
    printf("[DB] Executing query: %s\n", query);
}

/* Command Injection */
void RunBackup(char *target) {
    char cmd[256];
    sprintf(cmd, "tar -czf backup.tar.gz %s", target);
    system(cmd);
}

/* Path Traversal */
void ReadUserFile(char *filename) {
    char path[256];
    sprintf(path, "./data/%s", filename);

    FILE *f = fopen(path, "r");
    if (f == NULL) {
        printf("Cannot open file: %s\n", path);
        return;
    }

    char line[128];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
}

/* Format String vulnerability */
void PrintUserMessage(char *msg) {
    printf(msg);
    printf("\n");
}

/* Buffer Overflow */
void CopyNickname(char *input) {
    char nickname[16];
    strcpy(nickname, input);
    printf("Nickname: %s\n", nickname);
}

/* Dangerous input handling */
void CollectProfile() {
    char name[32];
    char bio[64];
    char note[16];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your bio: ");
    scanf("%s", bio);

    printf("Enter short note: ");
    gets(note);

    printf("Name: %s\n", name);
    printf("Bio: %s\n", bio);
    printf("Note: %s\n", note);
}

/* Use-after-free + double free */
void MemoryAbuse() {
    char *data = (char *)malloc(32);
    if (data == NULL) {
        return;
    }

    strcpy(data, "temporary sensitive data");
    printf("Allocated data: %s\n", data);

    free(data);

    /* Use-after-free */
    printf("After free: %s\n", data);

    /* Double free */
    free(data);
}

/* Memory leak */
void LeakMemory() {
    char *buf = (char *)malloc(2048);
    if (buf != NULL) {
        strcpy(buf, "This heap allocation is never released.");
        printf("Leaked buffer at %p\n", (void *)buf);
    }
}

/* Insecure temp file usage */
void CreateTempFile() {
    char filename[L_tmpnam];
    tmpnam(filename);

    FILE *f = fopen(filename, "w");
    if (f != NULL) {
        fprintf(f, "temporary token = %s\n", API_KEY);
        fclose(f);
        printf("Temp file created: %s\n", filename);
    }
}

/* Information disclosure */
void DebugDump() {
    printf("[DEBUG] API_KEY    = %s\n", API_KEY);
    printf("[DEBUG] JWT_SECRET = %s\n", JWT_SECRET);
    printf("[DEBUG] DB_USER    = %s\n", DB_USER);
    printf("[DEBUG] DB_PASS    = %s\n", DB_PASS);
}

/* Integer issue simulation */
void AllocateFromUserSize(int size) {
    char *buf = (char *)malloc(size);
    if (buf == NULL) {
        printf("Allocation failed\n");
        return;
    }

    memset(buf, 'A', size);
    printf("Allocated %d bytes\n", size);

    free(buf);
}

int main(int argc, char *argv[]) {
    printf("=== AI CI/CD SECURITY TEST PROGRAM ===\n");

    char username[64];
    char password[64];
    char message[128];
    char fileInput[128];
    char nicknameInput[128];

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    LoginUser(username, password);

    if (argc > 1) {
        RunBackup(argv[1]);
    }

    printf("Enter file to read: ");
    scanf("%s", fileInput);
    ReadUserFile(fileInput);

    printf("Enter message: ");
    scanf("%s", message);
    PrintUserMessage(message);

    printf("Enter nickname: ");
    scanf("%s", nicknameInput);
    CopyNickname(nicknameInput);

    CollectProfile();

    DebugDump();

    printf("Generated OTP: %d\n", GenerateOTP());

    MemoryAbuse();
    LeakMemory();
    CreateTempFile();

    if (argc > 2) {
        int size = atoi(argv[2]);
        AllocateFromUserSize(size);
    }

    return 0;
}