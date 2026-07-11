#include <cctype>
#include <cstdio>
namespace io
{
    using namespace std;
#define fastcall __attribute__((optimize("-O3")))
#define IL __inline__ __attribute__((always_inline))
    struct istream
    {
#define M (1 << 25)
        int f;
        char buf[M], *ch = buf - 1;
        fastcall IL istream() { fread(buf, 1, M, stdin); }
        fastcall IL istream &operator>>(int &x)
        {
            f = 1;
            while (!isdigit(*++ch))
                if (*ch == '-')
                    f = -1;
            for (x = *ch & 15; isdigit(*++ch);)
                x = x * 10 + (*ch & 15);
            x *= f;
            return *this;
        }
        fastcall IL istream &operator>>(long long &x)
        {
            f = 1;
            while (!isdigit(*++ch))
                if (*ch == '-')
                    f = -1;
            for (x = *ch & 15; isdigit(*++ch);)
                x = x * 10 + (*ch & 15);
            x *= f;
            return *this;
        }
        fastcall IL istream &operator>>(char &c)
        {
            c = *++ch;
            return *this;
        }
#undef M
    } cin;
    struct ostream
    {
#define M (1 << 23)
        char buf[M], *ch = buf - 1;
#define endl (char)10
        fastcall IL ostream &operator<<(int x)
        {
            if (!x)
            {
                *++ch = '0';
                return *this;
            }
            if (x < 0)
            {
                x = -x;
                *++ch = '-';
            }
            static int S[10], *top;
            top = S;
            while (x)
            {
                *++top = x % 10 ^ 48;
                x /= 10;
            }
            for (; top != S; --top)
                *++ch = *top;
            return *this;
        }
        fastcall IL ostream &operator<<(long long x)
        {
            if (!x)
            {
                *++ch = '0';
                return *this;
            }
            if (x < 0)
            {
                x = -x;
                *++ch = '-';
            }
            static int S[10], *top;
            top = S;
            while (x)
            {
                *++top = x % 10 ^ 48;
                x /= 10;
            }
            for (; top != S; --top)
                *++ch = *top;
            return *this;
        }
        fastcall IL ostream &operator<<(const char &x)
        {
            *++ch = x;
            return *this;
        }
        fastcall IL ~ostream() { fwrite(buf, 1, ch - buf + 1, stdout); }
#undef M
    } cout;
}