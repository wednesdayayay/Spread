# Spread
A video colorizer for the Raspberry pi

using a rapsberry Pi 3b

MIDI
17,18,19
try the controls they are not named as they control several different things each

thanks to Tim Caldwell with https://github.com/langolierz/r_e_c_u_r as I used his basic colorizer shader as a base for this. Then I added extra desnity of controls and wrapped it up in an openframeworks bow.

my old colorizer is all still in there commented out for now I'll be adding it back in and mixing or switching between the two (plus a third straight up grayscale to HSV) for the next version but since I was going to upload a new .iso for the newest Scrawl version I thought I'd put this one up too.

my colorizer works more as a series of keys within eachother where each key colors the same USB grabbed video with a different color. That allows for alpha blending between those layers (currently 7) which then makes for some interested ghosty/flowy type feedback possibilities that I don't think most people would expect in a colorizer. Randomizing colors per layers is possible. I've also been playing with the idea that each layer of key may have a different strobe amount (if turned on)








/// if you use this and post it somewhere let me know I'd love to see what gets done with it #spreadsynth if you don't mind :)

