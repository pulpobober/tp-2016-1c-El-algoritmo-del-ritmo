/*
 * nucleo.c
 *
 *  Created on: 29/4/2016
 *      Author: utnso
 */
#include "nucleo.h"

void atender_nucleo() {

	t_paquete * paquete_nuevo;

	int pid, paginas_requeridas, tamanio_codigo;
	char * codigo;

	while (1) {

		paquete_nuevo = recibir(socket_nucleo);

		pthread_mutex_lock(&semaforo_mutex_cpu);

		switch (paquete_nuevo->codigo_operacion) {
		case INICIALIZAR:

			memcpy(&pid, paquete_nuevo->data, sizeof(int));
			memcpy(&paginas_requeridas, paquete_nuevo->data + sizeof(int),
					sizeof(int));

			log_info(log, "Las paginas requeridas son %d.\n", paginas_requeridas);

			memcpy(&tamanio_codigo, paquete_nuevo->data + sizeof(int) * 2,
					sizeof(int));

			codigo = malloc(tamanio_codigo);

			memcpy(codigo, paquete_nuevo->data + sizeof(int) * 3,
					tamanio_codigo);

			if (puede_iniciar_proceso(pid, paginas_requeridas, codigo)) {

				inicializar_programa(pid, paginas_requeridas);

				log_info(log, "Se pudo inicializar el proceso.\n");

				enviar(socket_nucleo, EXITO, sizeof(int), &pid);

			} else {

				log_info(log, "No se pudo inicializar el proceso.\n");

				enviar(socket_nucleo, FRACASO, sizeof(int), &pid);
			}

			free(codigo);

			break;

		case FINALIZAR:

			pid = *(int *) paquete_nuevo->data;
			finalizar_proceso(pid);

			break;

		}

		liberar_paquete(paquete_nuevo);
		pthread_mutex_unlock(&semaforo_mutex_cpu);

	}
}
