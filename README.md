# Test GitHub Actions CI/CD

Dự án C đơn giản với pipeline CI/CD tự động.

## Cấu trúc thư mục

```
.github/
  workflows/
    ci.yml          # GitHub Actions CI pipeline
src/
  test.c           # C source file
.gitignore         # Git ignore file
README.md          # This file
```

## Pipeline CI/CD

### Tính năng

- **Tự động Compile**: Triggers trên mỗi push hoặc pull request
- **Chạy Chương Trình**: Kiểm tra chương trình compile thành công
- **Upload Artifacts**: Lưu trữ binary đã compile để download

### Branches Được Theo Dõi

- `main`
- `develop`

## Cách Sử Dụng

### Build Locally

```bash
gcc -o test src/test.c
./test
```

### Push lên GitHub

```bash
git add .
git commit -m "Initial commit"
git push origin main
```

Pipeline sẽ tự động chạy trên GitHub Actions.

## Yêu Cầu

- GCC compiler
- Git

## Xem Kết Quả

Vào tab **Actions** trên GitHub repository để xem chi tiết pipeline execution.
