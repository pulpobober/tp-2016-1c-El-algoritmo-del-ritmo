#include "./inicializar.h"

bool puede_iniciar_proceso(int pid, int cantidad_paginas, char * codigo) {

	log_info(log,
			"x1b[34mSe envia la peticion para crear el nuevo proceso cuya id es: %d y la cantidad de paginas son %d\n\x1b[0m",
			pid, cantidad_paginas);

	log_info(log, "El codigo es %s.\n", codigo);

	return swap_inicializar_proceso(pid, cantidad_paginas, codigo);

}

void inicializar_programa(int pid, int paginas_requeridas) {

	int var;

	log_info(log, "Las paginas requeridas por el proceso %d son %d\n", pid,
			paginas_requeridas);

	for (var = 0; var < paginas_requeridas; ++var) {

		list_add(tabla_de_paginas, crear_nueva_entrada(pid, var));

	}

	log_info(log, "Se inicializa con exito el proceso %d en memoria\n", pid);

}
