/*
 * globales.h
 *
 *  Created on: 29/4/2016
 *      Author: utnso
 */

#ifndef SRC_GLOBALES_H_
#define SRC_GLOBALES_H_

#include <pthread.h>
#include <commons/collections/list.h>
#include <commons/log.h>

#define ARCHIVOLOG "UMC.log"

char *puerto_umc, *ip_swap, *puerto_swap;

int cantidad_marcos, tamanio_marco, cantidad_maxima_marcos, entradas_TLB,
		retardo, algoritmo;

int socket_swap, socket_nucleo, socket_conexiones_nuevas;

int proceso_actual;

int numero_operacion_actual;

pthread_mutex_t semaforo_mutex_cpu;

void * memoria;

t_list * tabla_de_paginas;

t_list * tlb;

t_list * control_de_marcos;

pthread_t hilo_nucleo, hilo_cpu;

t_log * log;

t_log * log2;

#endif /* SRC_GLOBALES_H_ */
