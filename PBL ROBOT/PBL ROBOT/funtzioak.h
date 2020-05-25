#ifndef funtzioak
#define funtzioak

typedef struct Posizioa {
    int x;
    int y;
    struct Posizioa* ptrHurrengoa;
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
void memoriaErreserbatu();
void memoriaGarbitu();
POSIZIOA saguarenPosizioa();

#endif