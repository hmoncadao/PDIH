mport RPi.GPIO as GPIO
import time
import os
from picamera2 import Picamera2
from picamera2.encoders import H264Encoder

# Sensor PIR
pin_sensor_movimiento = 17

GPIO.setmode(GPIO.BCM)
GPIO.setup(pin_sensor_movimiento, GPIO.IN)

print("Calibrando sensor PIR... (30s)")
time.sleep(30)
print("Sensor listo!")

# Cámara
camera = Picamera2()
camera.configure(camera.create_video_configuration())

encoder = H264Encoder()

# Creación de carpetas
carpeta_capturas = "capturas/"
carpeta_videos = "videos/"

os.makedirs(carpeta_capturas, exist_ok=True)
os.makedirs(carpeta_videos, exist_ok=True)

camera.start()

try:
    while True:

        if GPIO.input(pin_sensor_movimiento):
            print("Movimiento detectado!")

            fecha = time.strftime("%Y-%m-%d_%H-%M-%S")

            ruta_captura = carpeta_capturas + fecha + ".jpg"
            ruta_video = carpeta_videos + fecha + ".mp4"

            # Foto
            camera.capture_file(ruta_captura)

            # Video
            print("Grabando video...")
            camera.start_recording(encoder, ruta_video)

            start_time = time.time()

	    while time.time() - start_time < 10 and GPIO.input(pin_sensor_movimiento):
                time.sleep(0.1)

            camera.stop_recording()

            print("Guardado:", fecha)

        else:
            print("No se ha detectado movimiento.")
            time.sleep(2)

except KeyboardInterrupt:
    print("Programa interrumpido.")

finally:
    GPIO.cleanup()
    camera.stop()
