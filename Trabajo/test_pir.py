from gpiozero import MotionSensor
from time import sleep

pir = MotionSensor(17)

print("Calibrando Sensor PIR (60s)...")
sleep(60)

print("Listo. Acércate al sensor")

while True:
    if pir.motion_detected:
        print("MOVIMIENTO DETECTADO")
    sleep(0.2)
