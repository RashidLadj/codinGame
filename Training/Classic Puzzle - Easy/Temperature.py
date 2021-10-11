n=int(input())
m=5526
for i in input().split():
 t=int(i)
 if abs(t)<abs(m)or(abs(t)==abs(m)and t>m):m=t
print(m if n!=0 else 0)