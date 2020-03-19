#version 150


uniform sampler2DRect u_tex0;
uniform float u_threshold5;
uniform float u_spread;
uniform vec3 u_color5;

in vec2 texCoordVarying;
out vec4 outputColor;

void main(){
	vec4 tex = texture(u_tex0, texCoordVarying);
	float difference = length(u_color5 - tex.rgb);

    if(difference < u_threshold5){
    //if(difference > u_threshold - .2){
    //if(difference > u_threshold5 - .1 && difference < u_threshold5 + .1){
    //if(difference > u_threshold5 - u_spread
      //      && difference < u_threshold5 + u_spread){
		discard;
	} else {
		outputColor = tex;
	}
}








