struct S0 { }; // POD
struct S1 { int i; }; // POD
struct S2 { int i; S2(int ii) : i(ii) { } }; // �⺻ �����ڰ� �����Ƿ� POD�� �ƴϴ�
struct S3 { int i; S3(int ii) : i(ii) { } S3() {} }; // POD
struct S4 { int i; S4(int ii) : i(ii) { } S4() = default; }; // POD
struct S5 { virtual void f(); }; // ���� �Լ��� �����Ƿ� POD�� �ƴϴ�

struct S6 : S1 { }; // POD
struct S7 : S0 { int b; } // POD
struct S8 : S1 { int b; } // ���� Ŭ������ ������ ����� �����Ƿ� POD�� �ƴϴ�.
struct S9 : S0, S1 { }; // POD
