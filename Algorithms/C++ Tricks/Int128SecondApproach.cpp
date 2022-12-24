__int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
 
void print(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
    //printf("\n");
}
std::ostream& operator<<(std::ostream& os, __int128 x)
{
    if(x<0) return os << "-" << -x;
    if(x<10) return  os << (char)(x+'0');
    return os << x/10 << (char)(x%10+'0');
}
