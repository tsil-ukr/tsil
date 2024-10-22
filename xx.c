typedef struct {
  int x;
} A;

typedef struct {
  A a;
} B;

typedef struct {
  B b;
} C;

void test() {
  C c;
  int m = c.b.a.x;
}