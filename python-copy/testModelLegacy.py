import cv2
import torch
from pathlib import Path
from PIL import Image
import numpy as np
import time

# Importar el modelo de YOLOv5
model = torch.hub.load('ultralytics/yolov5', 'yolov5s', pretrained=True)

# Definir las clases de objetos que puede detectar el modelo
CLASSES = ['person', 'bicycle', 'car', 'motorbike', 'aeroplane', 'bus', 'train', 'truck', 'boat',
           'traffic light', 'fire hydrant', 'stop sign', 'parking meter', 'bench', 'bird', 'cat',
           'dog', 'horse', 'sheep', 'cow', 'elephant', 'bear', 'zebra', 'giraffe', 'backpack',
           'umbrella', 'handbag', 'tie', 'suitcase', 'frisbee', 'skis', 'snowboard', 'sports ball',
           'kite', 'baseball bat', 'baseball glove', 'skateboard', 'surfboard', 'tennis racket',
           'bottle', 'wine glass', 'cup', 'fork', 'knife', 'spoon', 'bowl', 'banana', 'apple',
           'sandwich', 'orange', 'broccoli', 'carrot', 'hot dog', 'pizza', 'donut', 'cake', 'chair',
           'sofa', 'pottedplant', 'bed', 'diningtable', 'toilet', 'tvmonitor', 'laptop', 'mouse',
           'remote', 'keyboard', 'cell phone'
           ]

# Función para detectar y dibujar los objetos en la imagen de entrada
def detect_objects(img):
    results = model(img)  # Hacer la detección de objetos con el modelo personalizado
    results.print()  # Mostrar las predicciones en la consola (opcional)
    result_data = results.pandas().xyxy[0]  # Obtener las coordenadas y etiquetas de las detecciones
    return result_data

# Abrir la cámara
cap = cv2.VideoCapture(0)

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
    result_data = detect_objects(img)

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

    end_time = time.time()
    fps = 1 / (end_time - start_time)
    print(f"FPS: {fps:.2f}")

# Liberar la cámara y cerrar todas las ventanas
cap.release()
cv2.destroyAllWindows()