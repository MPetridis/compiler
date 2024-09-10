typedef char ar[100];
class t {
private:
   float a,b; // double a,b;
   ar list;
public:
   float zz(int,ar);
};
int x = 5, i, k;
enum en { alpha = 1, beta, gamma };
int g[][2] = {{1000,3000},{1000,2000},{2000,1000}};
ar a;
class mystery_class : t {
   void try_it(int&);
};
void mystery_class::try_it(int& n) {
/*
** no comment
**/
   ar z;
   t x;
   if (n <= 0) x.a = 1.0;
   else {
      x.zz(n-1,z); // call zz of x
      x.b = -x.a*x.list[n--];
   }
}
void all(int i, int j) {
   cout << i << j;
}
int b = 1;
int main() {
int z,j;
ar y,w;
mystery_class mm;
y[z] = !x && !g[10][y[j]] || (z == k*3);
all(-y[w[i]],w[y[w[j]]]);
if (b && (x > a[i%k])) mm.try_it(k);
for (x=1;x<a[10,g[y[i]+x][k]];x++)
   cin >> y[x] >> x >> w[x];
x = !y[i];
switch (x) {
   case 0: return 0;
   case 1: break;
   default: return 1;
   }
}
