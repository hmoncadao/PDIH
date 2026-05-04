from picamera2 import Picamera2
import time

camera = Picamera2()
camera.start()

time.sleep(2)

nombre_archivo = "test_imagen.jpg"
camera.capture_file(nombre_archivo)

print("Imagen capturada correctamente:", nombre_archivo)

camera.stop()
