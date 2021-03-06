/*
 * swap.h
 *
 *  Created on: 19/5/2016
 *      Author: utnso
 */

#ifndef SRC_PEDIDOS_INTERFACES_SWAP_H_
#define SRC_PEDIDOS_INTERFACES_SWAP_H_

#include <stdbool.h>
#include <string.h>

#include <commons/log.h>
#include <theDebuggers/socketLibrary.h>

#include "../../tabla_de_paginas/estructuras.h"
#include "../../globales.h"

#define SWAP_INICIALIZAR 1
#define SWAP_FINALIZAR 2
#define SWAP_LEER 3
#define SWAP_ESCRIBIR 4

#define SWAP_EXITO 1
#define SWAP_FALLO -1

bool swap_inicializar_proceso(int pid, int cantidad_paginas, char * codigo);
void swap_finalizar_proceso(int pid);
void * swap_leer(int proceso_actual, int numero_pagina);
void swap_escribir(t_entrada_tabla_de_paginas * entrada);

#endif /* SRC_PEDIDOS_INTERFACES_SWAP_H_ */
