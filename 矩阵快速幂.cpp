#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int N = 1005;
const int MOD = 1e9+7;
struct matrix{
	int m[N][N];
};
//重载*为矩阵乘法
matrix operator * (const matrix&a,const matrix&b)
{
	matrix c;
	memset(c.m,0,sizeof(c.m));
	for (int i = 0 ; i < N ; i++ ) {
		for (int j = 0 ; j < N ; j++ ) {
			for (int k = 0 ; k < N ; k++ ) {
				c.m[i][j] = (c.m[i][j] + a.m[i][j] * b.m[i][j]) % MOD;
			}
		}
	}
	return c;
}
//矩阵快速幂。代码几乎和普通快速幂一模一样
matrix pow_matrix(matrix a,int n)
{
	matrix ans;
	memset(ans.m,0,sizeof(ans.m));
	for (int i = 0 ; i < N ; i++ ) { //初始化为单位矩阵，类似于普通快速幂的ans=1;
		ans.m[i][i] = 1;
	}
	while(n) {	//不能简写为ans*=a;因为只重载了*运算符
		if (n&1) {
			ans = ans * a;
		}
		a = a * a;
		n >>= 1;
	}
	return ans;
}
signed main ()
{
	return 0;
}
