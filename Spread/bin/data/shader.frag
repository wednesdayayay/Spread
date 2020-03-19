#version 150


uniform sampler2DRect u_tex0;
uniform float u_threshold;
uniform vec3 u_color;

in vec2 texCoordVarying;
out vec4 outputColor;

void main(){
	vec4 tex = texture(u_tex0, texCoordVarying);
	float difference = length(u_color - tex.rgb);

    //if(difference < u_threshold + .2){
   // if(difference > u_threshold - .2){
        if(difference < u_threshold){
   // if(difference > u_threshold - .1 && difference < u_threshold + .1){
		discard;
	} else {
		outputColor = tex;
	}
}








