#include <cstdio>
using namespace std;
typedef long long ll;

// 这是一份使用一个非常奇怪的变种线段树（可能空间会更优一些吧？）
// （下文称为ST3）解决一道树状数组题的代码（不太喜欢写注释，凑合看罢）

struct node {
	ll v, sum, tad;
    // 分别存当前值、区间总值、懒标记
	int ls, rs, ft;
    // 左儿子、右儿子、父亲的编号
	int l, r, m;
    // 区间左、右极限与中间点编号
};
inline ll max(ll, ll);  // 求最大值
inline ll min(ll, ll);  // 求最小值
inline ll qread(void);  // 快读
inline void qread(ll &);// 快读
inline void qwrite(ll); // 快写
const int MXN = 5e5 + 10;

node t[MXN];
int ncnt, a[MXN];

void build(int x, int l, int r) {
    // 构造ST3
	t[x].l = l, t[x].r = r, t[x].m = (l + r) >> 1;
	t[x].rs = t[x].ls = -1, t[x].sum = t[x].v = a[t[x].m];
	if (l <= t[x].m - 1) {
		build(t[x].ls = ncnt++, l, t[x].m - 1);
		t[t[x].ls].ft = x;
		t[x].sum += t[t[x].ls].sum;
	}
	if (r >= t[x].m + 1) {
		build(t[x].rs = ncnt++, t[x].m + 1, r);
		t[t[x].rs].ft = x;
		t[x].sum += t[t[x].rs].sum;
	}
}

inline void pullup(int u) {
    // 更新上传
	while (1) {
		t[u].sum = t[u].v;
		if (~t[u].rs)
			t[u].sum += t[t[u].rs].sum;
		if (~t[u].ls)
			t[u].sum += t[t[u].ls].sum;
		if (!u)
			break;
		u = t[u].ft;
	}
}

void add_one(int u, int m, ll x) {
    // 单点修改（当前点编号， 修改点编号，增量）
	if (t[u].m == m) {
		t[u].v += x;
		pullup(u);
	} else {
		if (t[u].m > m)
			add_one(t[u].ls, m, x);
		if (t[u].m < m)
			add_one(t[u].rs, m, x);
	}
}

ll get_zone(int u, int lm, int rm) {
    // 区间查询（当前点编号， 区间左，区间右）
	ll res = 0;
	if (t[u].l == lm && t[u].r == rm)
		return t[u].sum;
	if (lm <= t[u].m && rm >= t[u].m)
		res += t[u].v;
	if (lm <= t[u].m - 1)
		res += get_zone(t[u].ls, lm, min(t[u].m - 1, rm));
	if (rm >= t[u].m + 1)
		res += get_zone(t[u].rs, max(t[u].m + 1, lm), rm);
	return res;
}

int main (void) {
	int n, m, o, x, y;
	n = qread(), m = qread();
    // 读入两个数，表示数组大小和操作数量
	for (x = 1; x <= n; ++x)
		a[x] = qread();
        // 读入每个位置的初始值
	build(ncnt++, 1, n);
    // 构建ST3
	while (m--) {
		o = qread(), x = qread(), y = qread();
        // 读操作o=1：给x位置加上y
        //   操作o=0：求[x,y]的和
		if (o & 1)
			add_one(0, x, y);
		else
			qwrite(get_zone(0, min(x, y), max(x, y))), putchar(10);
	}
    // 复杂度O(n*log2(m))
	return 0;
}

inline ll max(ll x, ll y) {
	return x > y ? x : y;
}

inline ll min(ll x, ll y) {
	return x > y ? y : x;
}

inline void qread(ll &bl) {
	static char bc, sn;
	sn = bl = 0;
	while ((bc = getchar())) {
		if (bc == '-')
			sn ^= 1;
		else if (bc >= '0' && bc <= '9')
			break;
	}
	while (bc >= '0' && bc <= '9') {
		bl = (bl << 3) + (bl << 1) + (bc - '0');
		bc = getchar();
	}
	bl = sn ? -bl : bl;
}

inline ll qread(void) {
	static ll bl;
	qread(bl);
	return bl;
}

inline void qwrite(ll x) {
	static char bufs[32];
	static int i;
	if (x == 0ll) {
		putchar('0');
		return;
	}
	if (x < 0)
		putchar('-'), x = -x;
	i = 0;
	while (x) {
		bufs[i++] = '0' + (x % 10);
		x /= 10;
	}
	for (--i; ~i; --i)
		putchar(bufs[i]);
}
