# Cargar librerías
library(tuneR)
library(seewave)

# Leer ficheros
audio_nombre <- readWave("nombre.wav")
audio_apellido <- readWave("apellido.wav")

# Dibujar la onda
plot(audio_nombre, main = "Forma de onda - Nombre")
plot(audio_apellido, main = "Forma de onda - Apellido")

# INfo de las cabeceras
cat("--- CABECERA DEL AUDIO: NOMBRE ---\n")
print(audio_nombre)
str(audio_nombre)

cat("\n--- CABECERA DEL AUDIO: APELLIDO ---\n")
print(audio_apellido)
str(audio_apellido)

# Union de sonidos (nombre + apellido)
audio_basico <- bind(audio_nombre, audio_apellido)

# Dibujar la onda combinada y reproducir
plot(audio_basico, main = "Forma de onda - Nombre y Apellido Unidos")
listen(audio_basico)

# Guardaw sonido completo
writeWave(audio_basico, "basico.wav")

