# C++ 正则表达式（Regex）教程

## 1. 基本概念

C++ 的正则表达式支持在 `<regex>` 头文件中，主要包含以下类：
- `std::regex`：表示一个正则表达式
- `std::regex_match`：完全匹配
- `std::regex_search`：搜索匹配
- `std::regex_replace`：替换匹配内容

## 2. 基本使用

```cpp
#include <regex>

// 基本使用示例
regex pattern("表达式");
bool match = regex_match(string, pattern);
```

## 3. 正则表达式基本符号

### 基本符号：
- `^` : 字符串开始
- `$` : 字符串结束
- `.` : 任意单个字符
- `*` : 前面的表达式出现0次或多次
- `+` : 前面的表达式出现1次或多次
- `?` : 前面的表达式出现0次或1次
- `[]` : 字符集合
- `()` : 分组
- `|` : 或运算

### 特殊字符：
- `\d` : 数字 [0-9]
- `\D` : 非数字
- `\w` : 单词字符 [a-zA-Z0-9_]
- `\W` : 非单词字符
- `\s` : 空白字符
- `\S` : 非空白字符

### 数量限定：
- `{n}` : 恰好n次
- `{n,}` : 至少n次
- `{n,m}` : n到m次

## 4. 实际示例

```cpp
#include <iostream>
#include <regex>
using namespace std;

int main() {
    // 1. 简单匹配
    regex email_pattern("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");
    string email = "test@example.com";
    if (regex_match(email, email_pattern)) {
        cout << "有效的邮箱地址" << endl;
    }

    // 2. 搜索匹配
    string text = "My phone number is 123-456-7890";
    regex phone_pattern("\\d{3}-\\d{3}-\\d{4}");
    smatch matches;
    if (regex_search(text, matches, phone_pattern)) {
        cout << "找到电话号码: " << matches[0] << endl;
    }

    // 3. 替换
    string result = regex_replace(text, phone_pattern, "XXX-XXX-XXXX");
    cout << "替换后: " << result << endl;
}
```

## 5. 常见用例

```cpp
// 匹配整数
regex integer_pattern("^-?\\d+$");

// 匹配浮点数
regex float_pattern("^-?\\d*\\.?\\d+$");

// 匹配日期 (yyyy-mm-dd)
regex date_pattern("^\\d{4}-(?:0[1-9]|1[0-2])-(?:0[1-9]|[12]\\d|3[01])$");

// 匹配URL
regex url_pattern("https?://(?:www\\.)?[\\w-]+\\.\\w{2,}(?:/[\\w-]*)*/?");
```

## 6. 注意事项

### 1. 转义字符
在 C++ 字符串中，反斜杠需要双写，例如：
```cpp
// 匹配数字需要写成
regex pattern("\\d+");  // 而不是 "\d+"
```

### 2. 异常处理
```cpp
try {
    regex pattern(user_input);
} catch (const regex_error& e) {
    cout << "无效的正则表达式: " << e.what() << endl;
}
```

### 3. 性能考虑
- 正则表达式的编译是比较耗时的操作
- 对于需要重复使用的模式，应该将 regex 对象保存起来而不是重复创建
- 对于简单的字符串操作，使用传统的字符串函数可能更快

## 7. 实用示例：验证密码强度

```cpp
bool isStrongPassword(const string& password) {
    // 至少8位，包含大小写字母、数字和特殊字符
    regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    return regex_match(password, pattern);
}
```

## 学习建议

1. 从简单的模式开始，逐步增加复杂度
2. 使用在线正则表达式测试工具（如 regex101.com）进行练习
3. 多实践，多测试不同的用例
4. 注意性能影响，在简单场景可以考虑使用传统字符串操作