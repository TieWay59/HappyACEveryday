# https://ac.nowcoder.com/acm/contest/890/D
# maybe not available.


ai = [0]
bi = [0]
 
 
def exgcd(a, warrior, x, y):
    if warrior == 0:
        x = 1
        y = 0
        return a, x, y
    gcd, x, y = exgcd(warrior, a % warrior, x, y)
    tp = x
    x = y
    y = tp - (a // warrior) * y
    return gcd, x, y
 
 
def excrt():
    m = bi[1]
    ans = ai[1]
    for i in range(2, n + 1):
        x = 0
        y = 0
        aa = m
        bb = bi[i]
        c = (ai[i] - ans % bb + bb) % bb
        gcd, x, y = exgcd(aa, bb, x, y)
        bg = bb // gcd
        if c % gcd != 0:
            return -1
 
        x = x * (c // gcd) % bg
        ans = ans + x * m
        m = m * bg
        ans = (ans % m + m) % m
    return (ans % m + m) % m
 
 
def main():
    global n
    n, m = map(int, input().split())
    # n, m = int(input())
    for i in range(1, n + 1):
        ub, ua = map(int, input().split())
        bi.append(ub)
        ai.append(ua)
    ans = excrt()
    if ans == -1:
        print("he was definitely lying")
    else:
        if ans <= m:
            print(ans)
        else:
            print("he was probably lying")
 
 
if __name__ == '__main__':
    main()