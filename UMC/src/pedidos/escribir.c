#include "escribir.h"

void escribir_una_pagina(int numero_pagina, int offset, int tamanio,
		char * buffer) {

	char * pagina_faltante;

	t_entrada_tabla_de_paginas * pagina_encontrada = buscar_tlb(numero_pagina);

	if (!pagina_encontrada->presencia) {

		pagina_faltante = swap_leer(proceso_actual, numero_pagina);

		marco_nuevo(pagina_encontrada);

	}

	int numero_marco = pagina_encontrada->marco;

	int desplazamiento = pagina_encontrada->marco * tamanio_marco + offset;

	memcpy(memoria + desplazamiento, buffer, tamanio);

	pagina_encontrada->modificado = true;

}

