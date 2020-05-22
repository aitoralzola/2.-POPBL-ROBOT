#ifndef funtzioak
#define funtzioak

typedef struct Posizioa {
    int x;
    int y;
}POSIZIOA;

#define INF 999

int hasiPrograma();
void barrua();
void terraza();
void matrizeaOsatu(char* str);
int mahaiaItzuliBarruan();
int getNearest();
void dijkstra();
void init();
void pantailaratu();
POSIZIOA saguarenPosizioa();

#endif