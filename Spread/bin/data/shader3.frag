#version 150


uniform sampler2DRect u_tex0;
uniform float u_threshold3;
uniform float u_spread;
uniform vec3 u_color3;

in vec2 texCoordVarying;
out vec4 outputColor;

void main(){
	vec4 tex = texture(u_tex0, texCoordVarying);
	float difference = length(u_color3 - tex.rgb);

    if(difference < u_threshold3){
    //if(difference > u_threshold - .2){
    //if(difference > u_threshold3 - .1 && difference < u_threshold3 + .1){
    //if(difference > u_threshold3 - u_spread
      // && difference < u_threshold3 + u_spread){
    discard;
	} else {
		outputColor = tex;
	}
}








