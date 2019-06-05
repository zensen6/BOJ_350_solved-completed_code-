
MOD = 1000000000

arr = [0]*1000003
brr = [0]*1000003

n = int(input())

arr[1] = 1
arr[0] = 0
brr[1] = 1
brr[2] = -1     #F(i) - F(i-1) = F(i-2)
if n<0:
    
    for i in range(3,abs(n)+1):
        brr[i] = brr[i-2] - brr[i-1]
        if brr[i] <= -1*MOD:
            while brr[i] <=0:
                brr[i] += MOD
            brr[i] -= MOD

    print(-1)
    print(abs(brr[abs(n)]))


elif n==0:
    print(0)
    print(0)
else:
    for i in range(2,n+1):
        arr[i] = (arr[i-1] + arr[i-2])%MOD
    print(1)
    print(abs(arr[n]))



