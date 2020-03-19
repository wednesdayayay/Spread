


//#version 150
//written originally by Tim Caldwell
//updated by Nichole Picon 

precision highp float;

varying vec2 v_texcoord;
uniform sampler2D u_tex0;
uniform vec2 u_resolution;
uniform float u_time;
uniform float u_x0;
uniform float u_x1;
uniform float u_x2;
uniform float u_x3;
uniform vec3 u_color;

//out vec4 outputColor;

uniform int intDiv;

vec3 rgb2grayscale(vec3 c)
{
    return(vec3(dot(c, vec3(0.299, 0.587, 0.114))));
}

vec3 rgb2hsv(vec3 c)
{
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));
    
    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

void main(){
    
    vec2 pos = v_texcoord;
    vec4 color = texture2D(u_tex0, pos);
    
    vec3 gray = rgb2grayscale(color.rgb);
    vec3 hsv = rgb2hsv(color.rgb);
    
   
    //const int intDiv = 5;
    const int intDiv = 20;
    float divisions = float(intDiv);
    //float lum = (gray.x + gray.y + gray.z) / 3.0;
    float lum = (gray.x + gray.y + gray.z) / (3.0*u_x2);
    vec3 newColor = vec3(0.0, 0.7, 0.7);
    for (int i = 0; i < intDiv; i++ ){
        //if( lum >= float(i)/divisions && lum < (float(i)+1.0)/(divisions){
        if( lum >= float(i)/divisions && lum < (float(i)+1.0*u_x1)/(divisions*u_x2)){
            //newColor.x = mod((float(i)/divisions + u_x0*0.2)/u_x1 + u_x2,1.0);}
            newColor.x = mod((float(i)/divisions*u_x0)/u_x1 + u_x2,1.0*u_x0);}
        
    }
    
    
    //main colorizer
   gl_FragColor = vec4(hsv2rgb(newColor*u_x1)/u_x2,color.a+(hsv.z/u_x0));

    
    
    
    //HSV from Grayscale
    //outputColor = vec4((hsv2rgb(gray*u_x0)*u_x1)/u_x2, color.a);
    
    
    //grayscale
    //outputColor = vec4(gray,color.a);
    
}





