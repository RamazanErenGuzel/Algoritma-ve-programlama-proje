#include <stdio.h>
#include <math.h>

#define PLANET_COUNT 8

/* Bilim insaný adý (global) */
char bilimInsani[50];

/* Gezegen isimleri */
const char *planetNames[PLANET_COUNT] = {
    "Merkur", "Venus", "Dunya", "Mars",
    "Jupiter", "Saturn", "Uranus", "Neptun"
};

/* Yerçekimi ivmeleri (m/s^2) */
double gravities[PLANET_COUNT] = {
    3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15
};

/* Mutlak deðer (ternary zorunluluðu) */
double absVal(double x) {
    return x < 0 ? -x : x;
}

/* 1. Serbest Düþme Deneyi */
void serbestDusme(double *g) {
    double t;
    printf("Sure (s): ");
    scanf("%lf", &t);
    t = absVal(t);

    for(int i = 0; i < PLANET_COUNT; i++) {
        double h = 0.5 * (*(g + i)) * t * t;
        printf("Bilim Insani %s | %s: h = %.2f m\n",
               bilimInsani, planetNames[i], h);
    }
}

/* 2. Yukari Atis Deneyi */
void yukariAtis(double *g) {
    double v0;
    printf("Ilk hiz (m/s): ");
    scanf("%lf", &v0);
    v0 = absVal(v0);

    for(int i = 0; i < PLANET_COUNT; i++) {
        double hmax = (v0 * v0) / (2 * (*(g + i)));
        printf("Bilim Insani %s | %s: h_max = %.2f m\n",
               bilimInsani, planetNames[i], hmax);
    }
}

/* 3. Agirlik Deneyi */
void agirlik(double *g) {
    double m;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    m = absVal(m);

    for(int i = 0; i < PLANET_COUNT; i++) {
        printf("Bilim Insani %s | %s: G = %.2f N\n",
               bilimInsani, planetNames[i], m * (*(g + i)));
    }
}

/* 4. Potansiyel Enerji Deneyi */
void potansiyelEnerji(double *g) {
    double m, h;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    printf("Yukseklik (m): ");
    scanf("%lf", &h);

    m = absVal(m);
    h = absVal(h);

    for(int i = 0; i < PLANET_COUNT; i++) {
        printf("Bilim Insani %s | %s: Ep = %.2f J\n",
               bilimInsani, planetNames[i],
               m * (*(g + i)) * h);
    }
}

/* 5. Hidrostatik Basinç Deneyi */
void hidrostatik(double *g) {
    double rho, h;
    printf("Sivi yogunlugu (kg/m^3): ");
    scanf("%lf", &rho);
    printf("Derinlik (m): ");
    scanf("%lf", &h);

    rho = absVal(rho);
    h = absVal(h);

    for(int i = 0; i < PLANET_COUNT; i++) {
        printf("Bilim Insani %s | %s: P = %.2f Pa\n",
               bilimInsani, planetNames[i],
               rho * (*(g + i)) * h);
    }
}

/* 6. Arsimet Kaldirma Kuvveti */
void arsimet(double *g) {
    double rho, V;
    printf("Sivi yogunlugu (kg/m^3): ");
    scanf("%lf", &rho);
    printf("Batan hacim (m^3): ");
    scanf("%lf", &V);

    rho = absVal(rho);
    V = absVal(V);

    for(int i = 0; i < PLANET_COUNT; i++) {
        printf("Bilim Insani %s | %s: Fk = %.2f N\n",
               bilimInsani, planetNames[i],
               rho * (*(g + i)) * V);
    }
}

/* 7. Basit Sarkac Deneyi */
void sarkac(double *g) {
    double L;
    printf("Ip uzunlugu (m): ");
    scanf("%lf", &L);
    L = absVal(L);

    for(int i = 0; i < PLANET_COUNT; i++) {
        double T = 2 * M_PI * sqrt(L / (*(g + i)));
        printf("Bilim Insani %s | %s: T = %.2f s\n",
               bilimInsani, planetNames[i], T);
    }
}

/* 8. Sabit Ip Gerilmesi */
void ipGerilme(double *g) {
    double m;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    m = absVal(m);

    for(int i = 0; i < PLANET_COUNT; i++) {
        printf("Bilim Insani %s | %s: T = %.2f N\n",
               bilimInsani, planetNames[i],
               m * (*(g + i)));
    }
}

/* 9. Asansor Deneyi (9 ve 9.1 birebir) */
void asansor(double *g) {
    double m, a;
    int yon;

    printf("Kutle (kg): ");
    scanf("%lf", &m);
    printf("Asansor ivmesi (m/s^2): ");
    scanf("%lf", &a);

    m = absVal(m);
    a = absVal(a);

    printf("Asansor yonu:\n");
    printf("1 - Yukari ivmelenme\n");
    printf("2 - Asagi ivmelenme\n");
    printf("Secim: ");
    scanf("%d", &yon);

    for(int i = 0; i < PLANET_COUNT; i++) {
        double N = (yon == 1)
            ? m * ((*(g + i)) + a)
            : m * ((*(g + i)) - a);

        printf("Bilim Insani %s | %s: N = %.2f N\n",
               bilimInsani, planetNames[i], N);
    }
}

int main() {
    int secim;

    printf("Bilim insaninin adi: ");
    scanf("%s", bilimInsani);

    do {
        printf("\n--- Deney Menusu ---\n");
        printf("1- Serbest Dusme\n");
        printf("2- Yukari Atis\n");
        printf("3- Agirlik\n");
        printf("4- Potansiyel Enerji\n");
        printf("5- Hidrostatik Basinç\n");
        printf("6- Arsimet\n");
        printf("7- Basit Sarkac\n");
        printf("8- Sabit Ip Gerilmesi\n");
        printf("9- Asansor\n");
        printf("-1- Cikis\n");
        printf("Secim: ");
        scanf("%d", &secim);

        switch(secim) {
            case 1: serbestDusme(gravities); break;
            case 2: yukariAtis(gravities); break;
            case 3: agirlik(gravities); break;
            case 4: potansiyelEnerji(gravities); break;
            case 5: hidrostatik(gravities); break;
            case 6: arsimet(gravities); break;
            case 7: sarkac(gravities); break;
            case 8: ipGerilme(gravities); break;
            case 9: asansor(gravities); break;
        }

    } while(secim != -1);

    printf("\nProgram sonlandi. Iyi calismalar %s!\n", bilimInsani);
    return 0;
}
