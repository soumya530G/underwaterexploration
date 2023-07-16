import cv2
import numpy as np
import os
import winsound

if not os.path.exists("yolov3.weights"):
    from init import init
    init.weights()

net = cv2.dnn.readNet('yolov3.weights', 'yolov3.cfg')

classes = []
with open("coco.names", "r") as f:
    classes = f.read().splitlines()

cap = cv2.VideoCapture(0)
font = cv2.FONT_HERSHEY_PLAIN
colors = np.random.uniform(0, 255, size=(100, 3))

user_input = input("CSV list of all objects to find: ")
user_objects = [obj.strip() for obj in user_input.split(",")]

while True:
    _, img = cap.read()
    height, width, _ = img.shape

    blob = cv2.dnn.blobFromImage(img, 1/255, (416, 416), (0,0,0), swapRB=True, crop=False)
    net.setInput(blob)
    output_layers_names = net.getUnconnectedOutLayersNames()
    layerOutputs = net.forward(output_layers_names)

    boxes = []
    confidences = []
    class_ids = []

    for output in layerOutputs:
        for detection in output:
            scores = detection[5:]
            class_id = np.argmax(scores)
            confidence = scores[class_id]
            if confidence > 0.2:
                center_x = int(detection[0]*width)
                center_y = int(detection[1]*height)
                w = int(detection[2]*width)
                h = int(detection[3]*height)

                x = int(center_x - w/2)
                y = int(center_y - h/2)

                boxes.append([x, y, w, h])
                confidences.append(float(confidence))
                class_ids.append(class_id)

    indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.2, 0.4)

    if len(indexes) > 0:
        for i in indexes.flatten():
            if classes[class_ids[i]] in user_objects:
                x, y, w, h = boxes[i]
                label = str(classes[class_ids[i]])
                confidence = confidences[i]
                color = colors[i]
                cv2.rectangle(img, (x, y), (x+w, y+h), color, 2)
                cv2.putText(img, label + " " + str(round(confidence, 2)), (x, y+20), font, 2, (255, 255, 255), 2)

                if confidence > 0.75:
                    winsound.Beep(1000, 200)

    cv2.imshow('Image', img)
    key = cv2.waitKey(1)
    if key == 27 or key == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
