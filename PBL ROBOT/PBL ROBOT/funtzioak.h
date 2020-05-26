#ifndef funtzioak
#define funtzioak

typedef struct Posizioa {
    int x;
    int y;
}POSIZIOA;

typedef struct Mahaiak {
    int x;
    int y;
    struct Mahaiak* ptrHurrengoa;
}MAHAIAK;

#define INF 999

int hasiPrograma();
void barrua();
void terraza();
void matrizeaOsatu(char* str);
int mahaiaItzuliBarruan();
int mahaiaItzuliTerraza();
int getNearest();
void dijkstra();
void init();
void pantailaratu(MAHAIAK* buruMahai, int* robot, int end);
void memoriaErreserbatu();
void memoriaGarbitu(MAHAIAK** burua);
void mahaienPosizioa(MAHAIAK** burua, char* mahaiak);
void irudiakJarri(int* robot, int* fondoa);
void irudiakEzabatu(int* pertsona, int* fondoa, int* errobota);
void pertsonaKokatu(int* pertsona, MAHAIAK* ptrAux);
void mugimendua(MAHAIAK* ptrAux, int* robot);
MAHAIAK* mahaiaAurkitu(MAHAIAK* buruMahai, int parnode);
POSIZIOA mugitu(POSIZIOA pos, MAHAIAK* ptrAux);
MAHAIAK* pertsonaMugitu(MAHAIAK* burua);
POSIZIOA saguarenPosizioa();

#endif