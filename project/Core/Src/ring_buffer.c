

#include "ring_buffer.h"


//Definición de la función
void ring_buffer_init(ring_buffer_t *ring_buffer, uint8_t *buffer, uint16_t capacity)
{
	ring_buffer->buffer = buffer;      /*Apuntador*/
	ring_buffer->capacity = capacity;  /**/

	ring_buffer->head = 0; 			   /**/
	ring_buffer->tail = 0;			   /**/
	ring_buffer->is_full = 0;		   /**/
}

uint8_t ring_buffer_put(ring_buffer_t *ring_buffer, uint8_t data)
{
	ring_buffer->buffer[ring_buffer->head] = data; //Poner en el buffer, el dato en la cabeza.
	ring_buffer->head = (ring_buffer->head + 1) % ring_buffer->capacity;//Aumentar el contador para que ponga datos en las siguientes casillas
																	  //Y realizar el modulo para que el indice vuelva a 0.
	//Condición para mover la cola una posición.
	if (ring_buffer->is_full != 0)
	{
		ring_buffer->tail = (ring_buffer->tail + 1) % ring_buffer->capacity;
	}

	//Condición para saber si la cabeza es igual a la cola -> Activar bandera is_full
	if (ring_buffer->head == ring_buffer->tail)
	{
		ring_buffer->is_full = 1;
		return 0;
	}
	return 1;
}

uint8_t ring_buffer_get(ring_buffer_t *ring_buffer, uint8_t *data)
{
	if (ring_buffer_is_empty(ring_buffer) == 0)   //((ring_buffer->is_full != 0) || (ring_buffer->tail != ring_buffer->head))
	{
		*data = ring_buffer->buffer[ring_buffer->tail]; //En la dirección de la variable, se escribe lo que hay en el buffer en la cola.
		ring_buffer->tail = (ring_buffer->tail + 1) % ring_buffer->capacity;
		ring_buffer->is_full = 0; 						//Se libera un espacio -> Se limpia la bandera de full
		return 1;
	}
	return 0;
}

uint16_t ring_buffer_size(ring_buffer_t *ring_buffer)
{
	uint16_t size = 0;

	if((ring_buffer->is_full == 0) && (ring_buffer->tail <= ring_buffer->head))
	{
		size = ring_buffer->head - ring_buffer->tail;
	}
	else
	{
		size = ring_buffer->head + (ring_buffer->capacity - ring_buffer->tail);
	}

	return size;
}

/**
 * @brief this function checks if the buffer is empty
 */
uint8_t ring_buffer_is_empty(ring_buffer_t *ring_buffer)
{
	return (ring_buffer->is_full == 0) && (ring_buffer->tail == ring_buffer->head);
}

/**
 * @brief this function checks if the buffer is full
 */
uint8_t ring_buffer_is_full(ring_buffer_t *ring_buffer)
{
	return ring_buffer->is_full;
}

/**
 * @brief this function resets the buffer to be empty
 */
void ring_buffer_reset(ring_buffer_t *ring_buffer)
{
	ring_buffer->tail = 0;
	ring_buffer->head = 0;
	ring_buffer->is_full = 0;
}
