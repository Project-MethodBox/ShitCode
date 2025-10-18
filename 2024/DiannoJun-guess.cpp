#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

struct node{
	int v,c;
	int l,r;
	int s,k;
};

const int MXN=1e5+6;
const int INF=0x3f3f3f3f;
node tr[MXN];
int rot,cnt;

inline void snode(int u, int v, int c){
	tr[u].v = v;
	tr[u].c = c;
	tr[u].s = 0;
	tr[u].k = rand();
	tr[u].l = tr[u].r = -1;
}
inline void init(void){
	srand(time(NULL));
	snode(rot = 0, -INF, 1);
	cnt = 0;
}
inline int getsc(int u){
	if(!~u)	return 0;
	return tr[u].s + tr[u].c;
}
inline void upd(int u){
	tr[u].s = getsc(tr[u].l) + getsc(tr[u].r);
}
inline void rrot(int &u){
	static int t;
	t = tr[u].l;
	tr[u].l = tr[t].r;
	upd(tr[t].r = u);
	upd(u = t);
}
inline void lrot(int &u){
	static int t;
	t = tr[u].r;
	tr[u].r = tr[t].l;
	upd(tr[t].l = u);
	upd(u = t);
}
void push(int &u, int x, int c){
	if(!~u){
		snode(u = ++cnt, x, c);
		return ;
	}
	if(tr[u].v == x){
		tr[u].c += c;
		return ;
	}
	if(x < tr[u].v){
		push(tr[u].l, x, c);
		if(tr[u].k > tr[tr[u].l].k)	rrot(u);
	}else{
		push(tr[u].r, x, c);
		if(tr[u].k > tr[tr[u].r].k)	lrot(u);
	}
	upd(u);
}
int merge(int x, int y){
	int ret;
	if(!~tr[x].r){
		tr[x].r = y;
		if(tr[x].k > tr[y].k)	lrot(x);
		ret = x;
	}else if(!~tr[y].l){
		tr[y].l = x;
		if(tr[y].k > tr[x].k)	rrot(y);
		ret = y;
	}else if(tr[x].s <= tr[y].s){
		tr[y].l = merge(x, tr[y].l);
		if(tr[y].k > tr[tr[y].l].k)	rrot(y);
		ret = y;
	}else{
		tr[x].r = merge(tr[x].r, y);
		if(tr[x].k > tr[tr[x].r].k)	lrot(x);
		ret = x;
	}
	upd(ret);
	return ret;
}
bool pop(int &u, int x, int c){
	if(!~u)	return false;
	if(tr[u].v == x){
		if(tr[u].c > c){
			tr[u].c -= c;
			return false;
		}
		tr[u].c = 0;
		if(!(~tr[u].l && ~tr[u].r)){
			u = ~(~tr[u].r | ~tr[u].l);
			return true;
		}
		u = merge(tr[u].l, tr[u].r);
		return true;
	}
	bool ret;
	if(x < tr[u].v){
		ret = pop(tr[u].l, x, c);
		if(~tr[u].l && tr[u].k > tr[tr[u].l].k)	rrot(u);
	}else{
		ret = pop(tr[u].r, x, c);
		if(~tr[u].r && tr[u].k > tr[tr[u].r].k)	lrot(u);
	}
	upd(u);
	return ret;
}
void debug(int u){
	if(!~u)	return ;
	printf("#%d s(%d,%d) v(%d,%d) k(%d) S(%d)\n",
		u, tr[u].l, tr[u].r, tr[u].v, tr[u].c,
		tr[u].k, tr[u].s);
	debug(tr[u].l), debug(tr[u].r);
}
int getRnkByVal(int u, int x){
	if(!~u)	return 0;
	if(tr[u].v == x)	return getsc(tr[u].l);
	if(x < tr[u].v)
		return getRnkByVal(tr[u].l, x);
	return getRnkByVal(tr[u].r, x) + getsc(tr[u].l) + tr[u].c;
}
int getIdxByVal(int u, int x){
	if(!~u)	return -1;
	if(tr[u].v == x)	return u;
	if(x < tr[u].v)
		return getIdxByVal(tr[u].l, x);
	return getIdxByVal(tr[u].r, x);
}
int getIdxByRnk(int u, int k){
	if(!~u)	return -1;
	if(k < getsc(tr[u].l))
		return getIdxByRnk(tr[u].l, k);
	if(k < getsc(tr[u].l) + tr[u].c)
		return u;
	return getIdxByRnk(tr[u].r, k - (getsc(tr[u].l) + tr[u].c));
}
int main (void){
    int num=3, guess, real;
	init();
    real = (rand()%10+10)%10;
    push(rot, real, 2);
    for(num=*&num; !!num; num=(*((int*)((char*)((&num)+1)-4)))-1){
        scanf("%d", &guess);
        int k = getIdxByVal(rot, guess);
        if(~k){
            printf("Success!");
            return 0;
        }k=getRnkByVal(rot, guess);
        if(k>2){
            printf("Too big!\n");
        }else{
            printf("Too small!\n");
        }
    }
    printf("Lose!");
	return 0;
}