/*
 * nucleo.h
 *
 *  Created on: 28/4/2016
 *      Author: utnso
 */

#ifndef NUCLEO_H_
#define NUCLEO_H_
#include <math.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>



#include <semaphore.h>

//#include <event.h>
 #include <linux/inotify.h>

#include <event.h>
#include <sys/time.h>


#include <commons/collections/node.h>
#include <commons/collections/queue.h>
#include <commons/collections/list.h>
#include <commons/config.h>


#include <parser/metadata_program.h>

#include <signal.h>
#include <theDebuggers/socketLibrary.h>
//#include "../../COMUNES/nsockets.c"
//#include "../../COMUNES/estructurasControl.h"

//#include "../../COMUNES/nsockets.h"
//#include "../../COMUNES/estructurasControl.c"

#include <theDebuggers/estructurasControl.h>

#include <commons/log.h>


#define PUERTO "9997"
#define BACKLOG 5     // Define cuantas conexiones vamos a mantener pendientes al mismo tiempo
#define PACKAGESIZE 1024  // Define cual va a ser el size maximo del paquete a enviar

typedef struct{
	int32_t id;
	int32_t size;
	void* data;
}t_header;


typedef struct {
  char* PUERTO_PROG;
  char* PUERTO_CPU;
  int QUANTUM;
  int QUANTUM_SLEEP;
  char** SEM_IDS;
  char** SEM_INIT;
  char** IO_IDS;
  char** IO_SLEEP;
  char** IO_SLEEP2;
  char** SHARED_VARS;
  int STACK_SIZE;

//Mias
  char* IP_UMC;
  char* PUERTO_UMC;
  int TAMPAG;


  int* VALOR_SHARED_VARS;
  int* VALOR_SEM;
  int* VALOR_IO;

  long long*VALOR_IO_EXPIRED_TIME;



} CONF_NUCLEO;


typedef struct __attribute__((packed)){
    int QUANTUM;
   int QUANTUM_SLEEP;
  int TAMPAG;
  int STACK_SIZE;
 } t_datos_kernel;
 



typedef struct {
  int socket_CPU;
  int socket_CONSOLA;
  t_pcb *pcb;
  int unidadesBloqueado; //Borrar estos?
  char semaforoBloqueado;
  bool abortado;


} t_proceso;




void abortar(t_proceso*proceso);
void escribeVariable(char *variable);
int *pideVariable(char *variable);
void * nalloc(int tamanio);

void liberaSemaforo(char *semaforo);
int *pideSemaforo(char *semaforo);
void  bloqueoSemaforo(t_proceso *proceso,char *semaforo);
void bloqueoIoManager(t_proceso *proceso, char *ioString, int unidadesBloqueado);



int *convertirConfig0(char **ana1);

//long long *punteroConCero(char **ana1);
int *convertirConfigInt(char **ana1, char **ana2);

void get_config_nucleo ();

void intHandler(int dummy);

void conectarUmc(void);

void *hilo_PLP(void *arg);
void *hilo_PCP(void *arg);


void dibujarPantalla(void);

t_proceso* dameProceso(t_queue *cola, int sock );
void mandarAEjecutar(t_proceso *proceso, int sock);

void *hilo_mock(void *arg);



#define CLOCKID CLOCK_REALTIME
#define SIG SIGUSR1

static int makeTimer( timer_t *timerID, int expireMS, int intervalMS );







void *hilo_mock_consola(void *arg);
void *hilo_mock_cpu(void *arg);

void analizarIO(int sig, siginfo_t *si, void *uc);


void *hilo_CONEXION_CONSOLA(void *arg);
void *hilo_CONEXION_CPU(void *arg);


void *hilo_HANDLER_CONEXIONES_CPU(void *arg);
void *hilo_HANDLER_CONEXIONES_CONSOLA(void *arg);

long long current_timestamp(void);

#endif /* NUCLEO_H_ */
