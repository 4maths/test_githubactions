{
  "tool": "security-scan",
  "decision": "BLOCK",
  "summary": "C\u00f3 nhi\u1ec1u v\u1ea5n \u0111\u1ec1 b\u1ea3o m\u1eadt nghi\u00eam tr\u1ecdng trong code, bao g\u1ed3m l\u1ed9 secret key, l\u1ed7i SQL Injection, tr\u00e0n b\u1ed9 nh\u1edb, qu\u1ea3n l\u00fd b\u1ed9 nh\u1edb kh\u00f4ng \u0111\u00fang v\u00e0 ghi log kh\u00f4ng an to\u00e0n.",
  "findings": [
    {
      "type": "SECURITY",
      "severity": "HIGH",
      "title": "L\u1ed9 Secret Key",
      "description": "Secret key \u0111\u01b0\u1ee3c hardcode trong code v\u00e0 c\u00f3 th\u1ec3 b\u1ecb l\u1ed9.",
      "file": "src/test.c",
      "line": null,
      "suggestion": "N\u00ean s\u1eed d\u1ee5ng bi\u1ebfn m\u00f4i tr\u01b0\u1eddng ho\u1eb7c file c\u1ea5u h\u00ecnh \u0111\u1ec3 l\u01b0u tr\u1eef secret key.",
      "metadata": {
        "owasp_category": "A02:2021 - Cryptographic Failures",
        "why_it_matters": "L\u1ed9 secret key c\u00f3 th\u1ec3 d\u1eabn \u0111\u1ebfn m\u1ea5t quy\u1ec1n ki\u1ec3m so\u00e1t h\u1ec7 th\u1ed1ng.",
        "snippet": "const char* SECRET_TOKEN = \"ghp_BadPracticeAdminToken12345\";"
      }
    },
    {
      "type": "SECURITY",
      "severity": "HIGH",
      "title": "L\u1ed7i SQL Injection",
      "description": "Code s\u1eed d\u1ee5ng sprintf \u0111\u1ec3 t\u1ea1o c\u00e2u l\u1ec7nh SQL, d\u1ec5 b\u1ecb t\u1ea5n c\u00f4ng b\u1eb1ng SQL Injection.",
      "file": "src/test.c",
      "line": null,
      "suggestion": "N\u00ean s\u1eed d\u1ee5ng prepared statement ho\u1eb7c parameterized query \u0111\u1ec3 ng\u0103n ch\u1eb7n SQL Injection.",
      "metadata": {
        "owasp_category": "A03:2021 - Injection",
        "why_it_matters": "L\u1ed7i SQL Injection c\u00f3 th\u1ec3 d\u1eabn \u0111\u1ebfn m\u1ea5t d\u1eef li\u1ec7u ho\u1eb7c chi\u1ebfm quy\u1ec1n ki\u1ec3m so\u00e1t h\u1ec7 th\u1ed1ng.",
        "snippet": "sprintf(query, \"SELECT * FROM users WHERE name = '%s';\", userInput);"
      }
    },
    {
      "type": "SECURITY",
      "severity": "HIGH",
      "title": "Tr\u00e0n b\u1ed9 nh\u1edb",
      "description": "Code s\u1eed d\u1ee5ng gets() \u0111\u1ec3 \u0111\u1ecdc d\u1eef li\u1ec7u t\u1eeb ng\u01b0\u1eddi d\u00f9ng, d\u1ec5 b\u1ecb tr\u00e0n b\u1ed9 nh\u1edb.",
      "file": "src/test.c",
      "line": null,
      "suggestion": "N\u00ean s\u1eed d\u1ee5ng fgets() ho\u1eb7c readline() \u0111\u1ec3 \u0111\u1ecdc d\u1eef li\u1ec7u t\u1eeb ng\u01b0\u1eddi d\u00f9ng.",
      "metadata": {
        "owasp_category": "A03:2021 - Injection",
        "why_it_matters": "Tr\u00e0n b\u1ed9 nh\u1edb c\u00f3 th\u1ec3 d\u1eabn \u0111\u1ebfn m\u1ea5t quy\u1ec1n ki\u1ec3m so\u00e1t h\u1ec7 th\u1ed1ng.",
        "snippet": "gets(buffer);"
      }
    },
    {
      "type": "SECURITY",
      "severity": "MEDIUM",
      "title": "Ghi log kh\u00f4ng an to\u00e0n",
      "description": "Code ghi log tr\u1ef1c ti\u1ebfp d\u1eef li\u1ec7u nh\u1ea1y c\u1ea3m ra console.",
      "file": "src/test.c",
      "line": null,
      "suggestion": "N\u00ean s\u1eed d\u1ee5ng logging framework \u0111\u1ec3 ghi log v\u00e0 \u1ea9n d\u1eef li\u1ec7u nh\u1ea1y c\u1ea3m.",
      "metadata": {
        "owasp_category": "A09:2021 - Security Logging and Monitoring Failures",
        "why_it_matters": "Ghi log kh\u00f4ng an to\u00e0n c\u00f3 th\u1ec3 d\u1eabn \u0111\u1ebfn l\u1ed9 d\u1eef li\u1ec7u nh\u1ea1y c\u1ea3m.",
        "snippet": "printf(\"Debug: Token hien tai la %s\\n\", SECRET_TOKEN);"
      }
    },
    {
      "type": "SECURITY",
      "severity": "LOW",
      "title": "Qu\u1ea3n l\u00fd b\u1ed9 nh\u1edb kh\u00f4ng \u0111\u00fang",
      "description": "Code kh\u00f4ng gi\u1ea3i ph\u00f3ng b\u1ed9 nh\u1edb \u0111\u00e3 c\u1ea5p ph\u00e1t.",
      "file": "src/test.c",
      "line": null,
      "suggestion": "N\u00ean s\u1eed d\u1ee5ng free() \u0111\u1ec3 gi\u1ea3i ph\u00f3ng b\u1ed9 nh\u1edb \u0111\u00e3 c\u1ea5p ph\u00e1t.",
      "metadata": {
        "owasp_category": "A06:2021 - Vulnerable and Outdated Components",
        "why_it_matters": "Qu\u1ea3n l\u00fd b\u1ed9 nh\u1edb kh\u00f4ng \u0111\u00fang c\u00f3 th\u1ec3 d\u1eabn \u0111\u1ebfn m\u1ea5t hi\u1ec7u su\u1ea5t h\u1ec7 th\u1ed1ng.",
        "snippet": "char *leak = malloc(100);"
      }
    }
  ],
  "metadata": {},
  "errors": [],
  "high_count": 3,
  "medium_count": 1,
  "low_count": 1,
  "has_blocking_issues": true,
  "is_bypassed": false,
  "bypass_label": null
}