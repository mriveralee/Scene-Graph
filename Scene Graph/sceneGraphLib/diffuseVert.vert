#version 150

//there's no rules about the prefixes but they do help
//keep track of things
//uniform mat4 u_modelMatrix;
//uniform mat4 u_projMatrix;

uniform float u_scr_width;
uniform float u_scr_height;
uniform mat3 u_modelMatrix;

//in vec4 vs_normal;
in vec3 vs_position;
in vec3 vs_color;

out vec3 fs_normal;
out vec3 fs_light_vector;
out vec3 fs_color;

void main() { 
	const vec3 lightPos = vec3(150.0, 0.0, 200.0);
    
    // Set the color and normal as just the input from the VBOs,
	// they only get interesting after they've been interpolated by the rasterizer
    fs_color = vs_color;
    fs_normal = vec3(0.0, 0.0, 1.0);

 	// calculate the final position of the vertices
	vec3 temp_position = u_modelMatrix * vs_position; 
	  
    // Set up our vector for the light
    fs_light_vector = vec3(lightPos - vec3(temp_position.xy, 0.0));

	//built-in things to pass down the pipeline
    gl_Position = vec4(temp_position.x/u_scr_width, temp_position.y/u_scr_height, 0.0, 1.0);
}