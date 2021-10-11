#define SMALLEST(x,y)((x)==0?(x):(y))

int main(){
    int n,min=5526; scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        int t; scanf("%d", &t);
        if (abs(min) > abs(t) || (abs(min) == abs(t) && t > min))
            min = t;
    }
    printf("%d",SMALLEST(n,min));
}