#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    int cantJug;
    int fichasMax;
    char tipoSonido[128];
    char salon[128];
    char juego[63];
    char nacionalidad[128];
}Arcade;

Arcade* arcade_new();
Arcade* arcade_newParametros(char* idStr,char* nacionalidadStr,char* tipoSonidoStr, char* cantJugStr, char* fichasMaxStr, char* salonStr, char* juegoStr);
void arcade_delete(Arcade* this, int indice);

int arcade_setId(Arcade* this,int id);
int arcade_getId(Arcade* this,int* id);

int arcade_setNacionalidad(Arcade* this,char* nacionalidad);
int arcade_getNacionalidad(Arcade* this,char* nacionalidad);

int arcade_setCantJug(Arcade* this,int cantJug);
int arcade_getCantJug(Arcade* this,int* cantJug);

int arcade_setFichasMax(Arcade* this,int fichasMax);
int arcade_getFichasMax(Arcade* this,int* fichasMax);

int arcade_setTipoSonido(Arcade* this,char* tipoSonido);
int arcade_getTipoSonido(Arcade* this,char* tipoSonido);

int arcade_setSalon(Arcade* this,char* salon);
int arcade_getSalon(Arcade* this,char* salon);

int arcade_setJuego(Arcade* this,char* juego);
int arcade_getJuego(Arcade* this,char* juego);

int arcade_funcionSort(void* pEmpleado1, void* pEmpleado2);
int arcade_modificar(Arcade* this, int indice);
int arcade_List(Arcade* this);
int arcade_imprimir(Arcade* auxArcade, int indice);
Arcade* arcade_newParametrosAdd(int idStr,char* nacionalidadStr,char* tipoSonidoStr, int cantJugStr, int fichasMaxStr, char* salonStr, char* juegoStr);


#endif // employee_H_INCLUDED
