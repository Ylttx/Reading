#ifndef PROBLEMS_H
#define PROBLEMS_H

// 面试题1: 赋值运算符函数
class CMyString {
public:
    CMyString(char *pData = 0);
    CMyString(const CMyString &str);
    ~CMyString(void);

    CMyString &operator=(const CMyString &str);

    const char *to_string(void) { return m_pData; }

private:
    char *m_pData;
};

// 面试题3: 数组中重复的数字
// 题目一：找出数组中重复的数字
bool duplicate(int numbers[], int length, int *duplication);

// 题目二：不修改数组找到重复的数字
int getDuplication(const int *numbers, int length);

#endif