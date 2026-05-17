library(tuneR)
library(seewave)

# Reproductor para linux
setWavPlayer("aplay")

# Cargar el audio base
if (file.exists("basico.wav")) {
  audio_basico <- readWave("basico.wav")
} else {
  stop("Error: No se encuentra 'basico.wav'.")
}

# Filtro de frecuencia
audio_filtrado <- bwfilter(audio_basico, f = audio_basico@samp.rate, 
                           from = 10000, to = 11000, bandpass = FALSE)

# Convertir el resultado de vuelta a un objeto de clase Wave
audio_filtrado_wave <- Wave(left = audio_filtrado, samp.rate = audio_basico@samp.rate, bit = audio_basico@bit)

plot(audio_filtrado_wave, main = "Forma de onda - Audio Filtrado (10kHz - 20kHz)")

writeWave(audio_filtrado_wave, "filtrado.wav")