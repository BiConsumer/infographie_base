#version 460

//Position est un vecteur ? 3 composante
//Position est une donn?e qui entre dans ce shader (in)
//La donn?e est l'attribut 0 du VAO courant
//S'il y avait plusieurs attributs activ?s, la donn?e aurait tous les attributs
layout(location = 0) in vec3 position;

//Le programme du vertex shader
//Le programme est ex?cut? POUR CHAQUE DONN?ES. 
//Il y aura effectivement plein instances de ce programme ? la fois
//Chaque instance fait les m?mes traitement sur in intrant diff?rent
//ex: la premi?re instance traite le premier sommet, la deuxi?me instance traite le deuxi?me sommet, etc.
void main() {
    //gl_Position place un sommet qui sera envoy? au prochain stade du programme de shader
    //Dit autrement, le sommet est envoy? dans la rendering pipeline
    gl_Position = vec4(position, 1.0);
}