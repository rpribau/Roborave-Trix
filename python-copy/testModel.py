import cv2
import torch
from pathlib import Path
from PIL import Image
import numpy as np
import time
import serial

# Cargar el modelo personalizado desde el archivo .pt
model = torch.hub.load('ultralytics/yolov5', 'custom', path='python-copy/best.pt')

# Clases específicas que puede detectar el modelo
CLASSES = ['candle']

# Función para detectar y dibujar los objetos en la imagen de entrada
def detect_objects(img, arduino):
    results = model(img)  # Hacer la detección de objetos con el modelo personalizado
    results.print()  # Mostrar las predicciones en la consola (opcional)
    result_data = results.pandas().xyxy[0]  # Obtener las coordenadas y etiquetas de las detecciones

    for _, row in result_data.iterrows():
        x_min, y_min, x_max, y_max = row[["xmin", "ymin", "xmax", "ymax"]]
        x_min, y_min, x_max, y_max = int(x_min), int(y_min), int(x_max), int(y_max)
    
    # # Controlar los LEDs del Arduino
    # if 'wall' in result_data["name"].values:
    #     arduino.write(b'1')  # Enviar comando para encender el LED en el puerto 3 (wall)
    # else:
    #     arduino.write(b'0')  # Enviar comando para apagar el LED en el puerto 3 (wall)

    # if 'candle-on' in result_data["name"].values:
    #     arduino.write(b'2')  # Enviar comando para encender el LED en el puerto 2 (candle)
    # else:
    #     arduino.write(b'3')  # Enviar comando para apagar el LED en el puerto 2 (candle)
    
    # if 'candle-off' in result_data["name"].values:
    #     arduino.write(b'4') # Enviar comando para encender el LED en el puerto 4 (candle-off)
    # else:
    #     arduino.write(b'5') # Enviar comando para apagar el LED en el puerto 4 (candle-off)
        
    return result_data

def coordenadas_a_bytes(x_min, x_max):
    x_med = (x_min + x_max) / 2
    x_med = x_med / 4
    print(x_med * 4)
    coordenadas_str = f"{x_med:.0f}"
    return coordenadas_str.encode('utf-8')

# Abrir la cámara
cap = cv2.VideoCapture(1) # 0 es cámara de la pc, 1 es webcam

# Inicializar conexión con el Arduino
arduino = serial.Serial('/dev/cu.usbmodem1201', 9600)  # Reemplaza 'COM3' con el puerto serial correcto

while True:
    start_time = time.time()
    ret, frame = cap.read()

    if not ret:
        break

    # Convertir el marco de BGR (OpenCV) a RGB (YOLOv5)
    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    # Convertir el marco a un objeto de imagen de PIL
    img = Image.fromarray(frame_rgb)

    # Realizar la detección de objetos
    result_data = detect_objects(img, arduino)

    # Dibujar los objetos detectados en el marco
    for _, row in result_data.iterrows():
        x_min, y_min, x_max, y_max, conf, class_name = row[["xmin", "ymin", "xmax", "ymax", "confidence", "name"]]
        x_min, y_min, x_max, y_max = int(x_min), int(y_min), int(x_max), int(y_max)
        label = f"{class_name} {conf:.2f}"
        cv2.rectangle(frame, (x_min, y_min), (x_max, y_max), (0, 255, 0), 2)
        cv2.putText(frame, label, (x_min, y_min - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 1)

    # Mostrar el resultado
    cv2.imshow('Custom YOLOv5 Real-Time Object Detection', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

    if 'candle' in result_data["name"].values:
        arduino.write(coordenadas_a_bytes(x_min, x_max))
        time.sleep(1)

    end_time = time.time()
    fps = 1 / (end_time - start_time)
    print(f"FPS: {fps:.2f}")

# Cerrar conexión con el Arduino
arduino.close()

# Liberar la cámara y cerrar todas las ventanas
cap.release()
cv2.destroyAllWindows()