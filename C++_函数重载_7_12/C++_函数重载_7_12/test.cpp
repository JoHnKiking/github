#define _CRT_SECURE_NO_WARNINGS 1
void print(const char* str, int width);
void print(double d, int width);
void print(long l, int width);
void print(int i, int width);
void print (const char *str);


void dribble(char* bits);
void dribble(const char* cbits); 
void dabble(char* bits);
void drivel(const char* bits);


const char p1¡¾20] = "How's the weather?"; 
char p2[20] = "How's business?"; 
dribble(p1);    //dribble(const char *);
dribble(p2);    // dribble(char *);
dabble(p1);    // no match
dabble(p2);    // dabble(char *);
drivel(p1);     //drivel(const char*);
drivel(p2);     //drivel(const char*);

unsigned int year = 3210; 
print(year, 6);//ambiguous cal1

double cube(double x); 
double cube(double& x);

void sink(double& rl);
void sank(const double& r2);
void sunk(double&& r3);

void staff(double& rs); 
void staff(const double& rcs); 
void stove(double& rl); 
void stove(const double& r2); 
void stove(double&& r3);

double x = 55.5; 
const double y = 32.0; 
stove(x);         // calls stove(double &)
stove(y);         //calls stove(const double &)
stove(x + y);   // calls stove(double &&)


char* left(const char* str, unsigned n);
char* left(const char* str);

