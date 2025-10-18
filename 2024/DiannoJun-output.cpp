#include <cstdio>
#include <bitset>
#include <cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int MXN = 1e5 + 6;
const int SHB = sizeof(uint) * 8;
const int HNS = 520, SHL = SHB - 1;

class hn {
	private:
		inline uint strfill(char *, char, uint) const;
	public:
		uint v[HNS];
		inline hn();
		inline hn(ull);
		inline void operator=(const hn &);
		inline void operator=(ull);
		inline void operator>>=(uint);
		inline void operator<<=(uint);
		inline void operator+=(const hn &);
		inline void operator*=(uint);
		inline void operator/=(uint);
		inline uint operator%(uint) const ;
		inline void operator~() ;
		inline void operator-() ;
		inline bool operator!()const;
		inline const char *c_str(char *);
};

char s[MXN], nums[MXN];

int main (void) {
	ull i;
	hn e(0), c(1);
	scanf("%s", s), -c;
	for (i = 0; s[i]; ++i)
		e *= 10, e += s[i] - '0';
  e+=c;
	printf("%s ", e.c_str(s));
  e+=2;
	printf("%s", e.c_str(s));
	return 0;
}

inline hn::hn() {
	this->operator=(0);
}

inline void hn::operator=(const hn &x) {
	memcpy(v, x.v, sizeof(v));
}

inline void hn::operator=(ull x) {
	memset(v, 0, sizeof(v));
	v[0] = x;
	v[1] = x >> SHB;
}

inline void hn::operator>>=(uint x) {
	uint bx = x / SHB, lx = x % SHB, rx = SHB - lx;
	uint top = 0, tmp, mod = (2 << lx) - 1, i;
	for (i = HNS - 1; ~i; --i) {
		tmp = (v[i] & mod) << rx;
		v[i] = (v[i] >> lx) | top;
		top = tmp;
	}
	for (i = HNS - 1; ~i; --i) {
		if (i + bx < HNS)
			v[i] = v[i + bx];
		else
			v[i] = 0;
	}
}

inline void hn::operator<<=(uint x) {
	uint bx = x / SHB, lx = x % SHB, rx = SHB - lx;
	uint but = 0, tmp, mod = ((2 << lx) - 1) << rx, i;
	for (i = 0; i < HNS; ++i) {
		tmp = (v[i] & mod) >> rx;
		v[i] = (v[i] << lx) | but;
		but = tmp;
	}
	for (i = 0; i < HNS; ++i) {
		if (i >= bx)
			v[i] = v[i - bx];
		else
			v[i] = 0;
	}
}

inline void hn::operator/=(uint x) {
	ull top = 0, i;
	for (i = HNS - 1; ~i; --i) {
		v[i] = (top |= v[i]) / x;
		top = (top % x) << SHB;
	}
}

inline void hn::operator+=(const hn &x) {
	ull but = 0, i;
	for (i = 0; i < HNS; ++i) {
		but += v[i], but += x.v[i];
		v[i] = but, but >>= SHB;
	}
}

inline uint hn::operator% (uint x) const {
	ull top = 0, i;
	for (i = HNS - 1; ~i; --i) {
		top |= v[i];
		top = (top % x) << SHB;
	}
	return top >> SHB;
}

inline const char *hn::c_str(char *bc) {
	hn tmp(*this);
  bool neg=0;
	uint i, n = 0;
  if(v[HNS-1]&(1ull<<(sizeof(v[0])*8-1))){
    this->operator-();
    *(bc++)='-';
    neg=1;
  }
	if (!tmp) {
		bc[0] = '0';
		bc[1] = 0;
		return bc;
	}
	while (!!tmp) {
		bc[n++] = tmp % 10 + '0';
		tmp /= 10;
	}
	for (i = 0; i<n >> 1; ++i)
		swap(bc[i], bc[n - i - 1]);
	bc[n] = 0;
  if(neg){
    --bc;
    this->operator-();
  }
	return bc;
}

inline bool hn::operator!()const {
	uint i;
	for (i = 0; i < HNS; ++i)
		if (v[i])
			return false;
	return true;
}

inline hn::hn(ull x) {
	this->operator=(x);
}

inline void hn::operator*=(uint x) {
	hn tmp(*this);
	uint i;
	this->operator=(0);
	for (i = 0; i < SHB; ++i, x >>= 1, tmp <<= 1) {
		if (x & 1)
			this->operator+=(tmp);
	}
}
inline void hn::operator~(){
  uint i;
  for(i = 0; i < HNS; ++i){
    this->v[i]=~v[i];
  }
}
inline void hn::operator-(){
  this->operator~();
  this->operator+=(1);
}