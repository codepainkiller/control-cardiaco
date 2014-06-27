#include <cstdlib>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <conio.h>
using namespace std;

struct encabezado
{
    int PrimerReg;
    int NroRegs;
    bool band;
} e;

struct regDatos
{
    int NroReg;
    char nomUser[10];
    char apellido[10];
    int edad;
    char dni[10];
    char codPulsera[10];
    char direccion[20];
    int SgteReg;
} r,q,s;

struct buffer
{
    int NR;
    char clave[15];
    int ptr;
} ram;

void escribir(char []);
void leer(char []);
void agregar(char []);

int main()
{
    int op=0;
    char nomarch[50],indice[30];
// cout<<"Nombre del archivo a crear /abrir: ";
// gets(nomarch);
    strcpy(nomarch,"registro");
    strcat(nomarch,".txt");
// strcpy(indice,"indice");
    strcat(indice,nomarch);

    cout<<"Archivo: "<<indice;
    getch();
    system("cls");
    do
    {
        system("cls");
        cout<<"   SISTEMA DE CONTROL CARDIACO  "<<endl<<endl;
        cout<<"[1] Ingreso de datos  pacientes         "<<endl;
        cout<<"[2] Leer datos pacientes                "<<endl;
        cout<<"[3] Terminar                            "<<endl<<endl;
        cout<<"Ingrese el numero de opcion: ";
        cin>>op;
        switch(op)
        {
        case 1:
            escribir(nomarch)        ;
            break;
        case 2:
            leer(nomarch)            ;
            break;
        case 3:
            break;
        default:
        {};
        break;
        }
    }
    while(op!=3);

    system("PAUSE");
    return EXIT_SUCCESS;
}
void escribir(char nomarch[])
{
    system("cls");

    int fd,fdi,le,lr;

    le=sizeof(struct encabezado);
    lr=sizeof(struct regDatos);

    if((fd=open(nomarch,O_TEXT))<0)
    {
        // no existe archivo entonces hay que crearlo
        //-------------------------creando el archivo----------------------------

        if((fd=creat(nomarch,S_IWRITE|S_IREAD))<0)
        {
            cout<<"El archivo no se puede crear"<<fd<<endl;
            return;
        }
        else
        {
            cout<<"creando archivo Primera vez ......."<<endl;
            lseek(fd,le,0);
            e.PrimerReg=-1;
            e.NroRegs=0;

            r.NroReg=++e.NroRegs;
            cin.ignore();
            cout<<"Ingrese el nombre del usuario :      ";
            gets(r.nomUser);
            fflush(stdin);
            cout<<"Ingrese el apellido del usuario:     ";
            gets(r.apellido);
            fflush(stdin);
            cout<<"Ingrese el edad:                     ";
            fflush(stdin);
            cin>>r.edad;
            fflush(stdin);
            cout<<"Ingrese DNI del usuario:             ";
            fflush(stdin);
            gets(r.dni);
            cout<<"Ingrese el codigo pulsera:           ";
            gets(r.codPulsera);
            fflush(stdin);
            cout<<"Ingrese direccion de usuario:        ";
            gets(r.direccion);
            fflush(stdin);
            if(e.PrimerReg==-1)            // si regDatos esta vacio(lista==NULL)
            {
                r.SgteReg=e.PrimerReg;     //q->sgte=lista
                e.PrimerReg=r.NroReg;      //lista=q;
                //graba encabezado
                lseek(fd,0,0);
                write(fd,&e,le);
                //graba primer registro
                write(fd,&r,lr);
                close(fd);
                fflush(stdin);
                system("PAUSE");
            }
        }
    }
    else
    {
        cout<<"agregando  regDatoss!!!!...";
        agregar(nomarch);
    }
}

void leer(char nomarch[])
{
    system("cls") ;
    int le,lr,m,fd,pos;
    le=sizeof(struct encabezado);
    lr=sizeof(struct regDatos);
    if((fd=open(nomarch,O_TEXT))<0)
    {
        cout<<"El archivo no se puede abrir";
        return;
    }
    read(fd,&e,le);
    m=e.PrimerReg;

    cout<<endl<<"Cantidad de usuarios           "<<e.NroRegs<<endl<<endl;

//m irá valiendo el valor de cada puntero

    cout<<"NroRego.  usuario         edad        DNI        CodPulsera       direccion    "<<endl;
    cout<<"_______________________________________________________________________________"<<endl;

    while(m!=-1)
    {
        fflush(stdin);
        pos=(m-1)*lr+le;
        lseek(fd,pos,0);
        read(fd,&r,lr);
        cout<<r.NroReg;
        cout<<setw(10)<<r.nomUser;
        cout<<setw(9)<<r.apellido;
        cout<<setw(9)<<r.edad;
        cout<<setw(15)<<r.dni;
        cout<<setw(8)<<r.codPulsera;
        cout<<setw(24)<<r.direccion<<endl;
        m=r.SgteReg;
    }
    cout<<"_______________________________________________________________________________"<<endl;
    close(fd);
    fflush(stdin);
    system("PAUSE");
}

void agregar(char nomarch[])
{
    system("cls");

    int fd,pos,lr,le,m,band;
    lr=sizeof(struct regDatos);
    le=sizeof(struct encabezado);
    if((fd=open(nomarch,O_RDWR))<0)
    {
        cout<<"El archivo no se puede abrir";
        return;
    }
    read(fd,&e,le);
    cout<<"              Datos de cabecera "<<endl;
    cout<<"PrimerRegimer regDatos    "<<e.PrimerReg<<endl;
    cout<<"Cantidad de regDatos      "<<e.NroRegs<<endl;
    cout<<"_____________________________________"<<endl<<endl;
    r.NroReg=++e.NroRegs;
    cout<<"NroRego de regDatos             ===>> "<<r.NroReg<<endl;
    cin.ignore();
    cout<<"Ingrese el nombre del usuario :      ";
    gets(r.nomUser);
    fflush(stdin);
    cout<<"Ingrese el apellido del usuario:     ";
    gets(r.apellido);
    fflush(stdin);
    cout<<"Ingrese el edad:                     ";
    fflush(stdin);
    cin>>r.edad;
    fflush(stdin);
    cout<<"Ingrese DNI del usuario:             ";
    gets(r.dni);
    cout<<"Ingrese el codigo pulsera:           ";
    gets(r.codPulsera);
    fflush(stdin);
    cout<<"Ingrese direccion de usuario:        ";
    gets(r.direccion);
    fflush(stdin);

    m=e.PrimerReg;
    band=0;
    while(m!=-1)                           //cuando no es el primer registro
    {
        fflush(stdin);

        pos=(m-1)*lr+le;
        lseek(fd,pos,0);
        read(fd,&s,lr);
        if((strcmp(r.nomUser,s.nomUser))>0)    //r es el nuevo
        {
            band=1;
            q=s;                               // ultima posicion que entro;
        }
        else
        {
            break;
        }
        m=s.SgteReg;                          //m = s.SgteReg  del archivo que se esta abierto
    }


    if(band==0)                           //cuando hay cambio en el PrimerRegimero regDatos   nuevo < qntiguo
    {
        r.SgteReg   = e.PrimerReg;         // r.sgteReg = e.PrimerRegDatos
        e.PrimerReg = r.NroReg;            // e.PrimerRegDatos=r.NroRegDatos
    }

    if(band==1)                            ///hay cambio en otro registro
    {
        r.SgteReg=q.SgteReg;                //r.sgteReg = q.sgteReg
        q.SgteReg=r.NroReg;                 //q.sgteReg =  r.NroRegoregDqtos.

        //graba el cambio del puntero
        pos=(q.NroReg-1)*lr+le;
        lseek(fd,pos,0);
        write(fd,&q,lr);
    }

//graba registro actual
    pos=(r.NroReg-1)*lr+le;
    lseek(fd,pos,0);
    write(fd,&r,lr);

//graba encabezado
    lseek(fd,0,0);
    write(fd,&e,le);
    close(fd);
    system("PAUSE");
}
