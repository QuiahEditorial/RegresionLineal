// Por Roberto A. Zavala

// Libro : https://www.amazon.com.mx/dp/B074TTGLL2
// 🙏🏼    : DNv7acPAeVBhTXbKv26itJecPG1SPy2o4F

// De acuerdo con regresión lineal
// m = \frac{sum_{i=1}^{n} Y_i x_i - n \bar{x}\bar{Y}}{sum_{i=1}^{n} x_i - n x_i ^2}

const int n = 10;                       // Se toman los últimos 10 valores para realizar regresión
const int N = n+1;

float Y[N];                             // vecto re n+1 entradas
float Sx, SY, Sx2, SYx, xm, Ym;         // variables necesarias
float m, b;                             // regresores

void setup()
{
Serial.begin(9600);
Serial.println("Regresión Lineal");
Sx = ( n * ( n + 1 ) ) / 2;             // La sumatoria por inducción
xm = Sx / n;
}

void loop()
{
medir();
pendiente();
interseccion();
Serial.write(10);
delay(1000);
}

void medir()
{
for ( int i=1; i<=n-1; i++ ) { Y[i] = Y[i+1]; }
Y[n] = analogRead(0); // Serial.println(Y[n]);
for ( int i=1; i<=n; i++ ) { Serial.print(Y[i]); Serial.print("\t"); }
}

void pendiente()
{
SY = 0;
Ym = 0;
SYx= 0;
m  = 0;
for ( int i=1; i<=10; i++ ) { SY = SY + Y[i]; Ym = Ym + Y[i]; SYx = SYx + Y[i] * i;}
Ym = SY/n;
m = SYx - (n * xm * Ym);
m = m / ( Sx - pow(xm,2) );
// Serial.print(Ym); Serial.print("\t"); 
// Serial.print(SY); Serial.print("\t");
Serial.print(m); Serial.print("\t");
}

void interseccion()
{
b = Ym - m * xm;
Serial.print(b); Serial.print("\t");
}
