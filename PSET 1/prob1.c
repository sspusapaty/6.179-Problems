#include <stdio.h>
#include <math.h>

typedef struct complex_number {
    double i,j;
} Complex;

Complex Complex_init(double i, double j) {
    return (Complex){.i=i,.j=j};
}

Complex add_complex(Complex a, Complex b) {
    return (Complex){a.i + b.i, a.j + b.j};
}

Complex square_complex(Complex a){
    return (Complex){(a.i*a.i)-(a.j*a.j),2*a.j*a.i};
}

double magnitude_complex(Complex a){
    return (double)sqrt((a.i*a.i)+(a.j*a.j));
}

int fiveHundredValue(int n, int m, int a, int b){
    
    Complex c = (Complex){((double)a/(double)n)*3.5 - 2.5,(((double)b/(double)m) -.5) * 2};
    Complex sum = (Complex){0,0};
    for(int i =0; i<499; i++){
        //printf("%.10f", real_sum*real_sum + imag_sum*imag_sum);
        sum = add_complex(square_complex(sum),c);
        if(magnitude_complex(sum)>2){
            return 0;
        }
    }
    
    return 1;
}

void mandelbrot(int n, int m){
    for(int i = 1;i<=m;i++){
        printf("%s\n","");
        for(int j = 1;j<=n;j++){
            if(fiveHundredValue(n,m,j,i)==0){
                printf("%s"," ");
            }
            else{
                printf("%s","*");
            }
        }
    }
}

int main() {
    int n;
    scanf("%i", &n);
    int m;
    scanf("%i",&m);
    mandelbrot(n, m);
    return 0;
}
