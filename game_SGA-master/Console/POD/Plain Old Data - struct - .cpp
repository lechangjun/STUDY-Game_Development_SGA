struct S0 { }; // POD
struct S1 { int i; }; // POD
struct S2 { int i; S2(int ii) : i(ii) { } }; // 기본 생성자가 없으므로 POD가 아니다
struct S3 { int i; S3(int ii) : i(ii) { } S3() {} }; // POD
struct S4 { int i; S4(int ii) : i(ii) { } S4() = default; }; // POD
struct S5 { virtual void f(); }; // 가상 함수가 있으므로 POD가 아니다

struct S6 : S1 { }; // POD
struct S7 : S0 { int b; } // POD
struct S8 : S1 { int b; } // 기저 클래스에 비정적 멤버가 있으므로 POD가 아니다.
struct S9 : S0, S1 { }; // POD
