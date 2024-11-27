#include <iostream>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <tuple>
#include <vector>

class SpiralMatrixCoder3D {
public:
    
    // Función para codificar un punto (x, y, z) en un código único.
    static int encode3D(int x, int y, int z) {
        // Excluir puntos centrales
        if (x == 0 && y == 0) {
            return -1;  // Devuelve un valor inválido para indicar exclusión
        }

        // Identificar plano y posición inicial
        int initial_position;
        if (z == 1) {
            initial_position = 1;  // Plano z = 1
        }
        else if (z == 0) {
            initial_position = 9;  // Plano z = 0
        }
        else if (z == -1) {
            initial_position = 17;  // Plano z = -1
        }
        else {
            throw std::invalid_argument("Point is outside the cube of side 3.");
        }

        // Calcular la capa del punto en 2D
        int max_dist = std::max(std::abs(x), std::abs(y));
        int layer_length = (max_dist << 1) + 1;  // Longitud del lado de la capa
        int layer_start = (layer_length - 2) * (layer_length - 2);  // Posición inicial de la capa

        // Determinar la posición en espiral en 2D
        int index_2d = 0;
        if (x == max_dist) {  // Lado derecho
            index_2d = layer_start + max_dist - y;
        }
        else if (y == -max_dist) {  // Lado inferior
            index_2d = layer_start + max_dist + (layer_length - 1) - x;
        }
        else if (x == -max_dist) {  // Lado izquierdo
            index_2d = layer_start + max_dist + 2 * (layer_length - 1) + y;
        }
        else {  // Lado superior
            index_2d = layer_start + max_dist + 3 * (layer_length - 1) + x;
        }

        // Calcular la posición final
        return initial_position + index_2d - 1;
    }

};
