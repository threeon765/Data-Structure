int main() {}

/*
# Offset Table
Length - �ڷ��� ũ��
Offset - �ڷ���� �ּ� ����
�� ó�� �ڷ��� Offset�� 0���� �Ͽ�, ���� �ڷ���� length�� �������� ���ϸ� �ȴ�
Padding
���� ��ǻ�ʹ� 4����Ʈ ���� ��Ģ�� ���� �ּҸ� �����Ѵ�
ex) 9����Ʈ -> 12����Ʈ ����
�迭 ���� Composite �ڷ���� ���� ����� ��� length�� ���� ����
4����Ʈ ���� ��Ģ�� �����ϵ��� �Ѵ�
ex) 7����Ʈ 10�� �迭 -> 80�� �ƴ� 72�� ���� ũ��

# Array Memory Calculate
Address of X[a] = BaseAddress + a * SizeOfItem
int X[a][b]; -> �� ��
row major -> �� ������ ����
-> X00 X10 X20 ~ Xa-10 | X01 X11 X21 ~ Xa-11 | X02 ~
Address of X[c][d] = BaseAddress + (a * d + c) * SizeOfItem

# ADT �԰� ����
���� ����ϰ� �ִ� ��� ����ó�� �ۼ��ϸ� ��
�� ���긶�� ���, ����(precondi.), ���(postcondi.)�� �ۼ�

# int strcmp(const char *s1, const char *s2);
���ڿ� �ΰ��� ��
s1 < s2 -> -1, s1 == s2 -> 0, s1 > s2 -> 1

# int strlen(char* str);
���ڿ� ���� ��ȯ (NULL ������)

# ���๮��
CRLF \r\n LF \n CR \r

# command-line argument
int main(int argc, char* argv[])
�ٷΰ��� ������ ��� �� ���ʿ� ����� �ϳ��� �Է�
argv�� ���α׷� �̸��� �Է��� ���ڿ����� ����, argc�� �� ������ �ǹ�

# Redefinition problem
#inndef ITEMTYPE_H (��ó����)
#define ITEMTYPE_H
~~~
#endif
or
#pragma once (�����Ϸ�)
*/