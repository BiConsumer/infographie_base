#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <format>
#include "shader_utils.hpp"

int main() {
    std::cout << "Starting program" << std::endl;
    // ## SECTION GLFW ##
    // init glfw et regarde pour erreurs

    // configurer la fen?tre et contexte OpenGL ? cr?er

    // dimension de la fen?tre ? cr?er exprim?e en pixels

    // cr?er une fen?tre et contexte OpenGL
    //(pas besoin d'un smart pointer et de son overhead. L'interface GLFW
    // s'attend a des raw pointers de toute mani?re)

    // choisir le contexte associ? ? la fen?tre window

    // ## SECTION GLAD ##
    // load les fonctions OpenGL pour le contexte actuel
    // glfwGetProcAddress est un pointeur de fonction qui retourne
    // l'addresse d'une fonction OpenGL selon le contexte actuel
    //  Load OpenGL functions, gladLoadGL returns the loaded version, 0 on
    //  error.

    // ## SECTION COMPILATION SHADER ##

    // ## SECTION DATA ##

    // #1.
    // cr?er un tableau de handles ? des VAOs. Un seul VAO pour l'instant.
    // pourquoi un tableau alors ? Plusieurs VAOs dans l'avenir.
    //
    // #2.
    // cr?er un tableau de handles ? des VBOs
    //
    // les handles sont des GLuint (nombre entier).
    // l'entier sera utilis? pour faire r?f?rence ? un VAO/VBO sp?cifique qui
    // sera cr?er les handles ne sont pas encore d?finis. Ils le seront aux
    // prochaines ?tapes

    // #3.
    // cr?er un VAO et stocker son nouveau handle associ? dans vaoHandles

    // #4.
    // cr?er un buffer dans la VRAM et stocker son nouveau handle associ? dans
    // vboHandles

    // #5.
    // obtenir les handles

    // #5.
    // transf?rer les donn?es de sommets de la RAM vers le VBO dans la VRAM

    // #6.
    // associer le VBO au VAO
    // un VAO peut ?tre associ? ? plusieurs VBO (binding index)
    // Ici : le buffer est associ? au binding index 0
    //     : l'offset est 0
    //     : chaque sommet a 3 float de donn??s

    // #7.
    // cr?er un attribut pour le VAO. Il faut d?crire le format de chaque
    // attribut Ici : l'attribut est le premier attribut (0) est repr?sentera
    // une position
    //     : nombre de composante pour l'attribut est 3 (x,y,z)
    //     : chaque composante est un float
    //     : ne pas normaliser les valeurs
    //     : la distance entre composante dans le buffer est 0 (elles sont
    //     continues dans la m?moire)

    // associer l'attribut 0 du VAO avec le VBO au binding index 0

    // #8.
    // activer l'attribut 0 (position)

    // #9.
    // Lorsqu'on dessine avec glDraw, on va dessiner le VAO pr?sentement actif
    // On active le VAO d?sir? avec glBindVertexArray

    // ## SECTION BOUCLE DE JEU ##

    // clean up

    return EXIT_SUCCESS;
}
