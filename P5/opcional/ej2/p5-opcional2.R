library(tuneR)
library(seewave)

setWavPlayer("aplay")

if (file.exists("basico.wav")) {
  audio_basico <- readWave("basico.wav")
} else {
  stop("Error: No se encuentra 'basico.wav'.")
}

# Parametros para el eco
retraso_segundos <- 0.4
atenuacion <- 0.4

# Calculamos num muestras equivalen al retraso deseado
muestras_retraso <- round(retraso_segundos * audio_basico@samp.rate)

# Extraemos el vector numerico del audio original (basico)
senial_original <- audio_basico@left

# Senial de eco: 0s + senial atenuada 
senial_eco <- c(rep(0, muestras_retraso), senial_original * atenuacion)

# Suma de seniales (misma long)
senial_original_extendida <- c(senial_original, rep(0, muestras_retraso))
senial_final_eco <- senial_original_extendida + senial_eco

# Convertimos a clase wave
audio_eco_wave <- Wave(left = as.integer(señal_final_eco), 
                       samp.rate = audio_basico@samp.rate, 
                       bit = audio_basico@bit)

plot(audio_eco_wave, main = "Forma de onda - Audio con Eco")

writeWave(audio_eco_wave, "eco.wav")

# Al reves
audio_alreves <- revw(audio_basico, f = audio_basico@samp.rate, output = "Wave")

plot(audio_alreves, main = "Forma de onda - Audio del Revés")

writeWave(audio_alreves, "alreves.wav")