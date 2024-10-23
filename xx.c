typedef struct {
  int x;
} A;

typedef struct {
  A a;
} B;

typedef struct {
  B b;
} C;

C cx;
extern C cx2;
static C cx3 = {{{1}}};

void test() {
  C c = cx2;
  C c2 = cx3;
  int m = c.b.a.x;
}