#version 460

//location 0 est le backbuffer du framebuffer courant 
//(sinon le seul color buffer dans le cas de single buffering au lieu de double buffering)
layout(location = 0) out vec4 fragColor;

//Le programme du fragment shader
//Le programme est ex?cut? POUR CHAQUE FRAGMENT r?sultant du rasterization 
//des triangles form?es par les sommets affect?s ? gl_Position dans le vertex shader. 

//Il y aura effectivement plein instances de ce programme ? la fois
//Chaque instance fait les m?mes traitement sur in intrant diff?rent
//ex: la premi?re instance traite le premier fragment, la deuxi?me instance traite le deuxi?me fragment, etc.
void main() {
    fragColor = vec4(1.0f, 0.5f, 0.6f, 1.0f); //RGBA (A pour alpha -> la transparence. 1.0 -> compl?tement opaque)
}
