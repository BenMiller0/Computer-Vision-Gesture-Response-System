# Computer Vision Attraction

## 🌌 Overview
Welcome, Padawan!
This project harnesses the power of computer vision and real-world sensing to interact with the environment, like using the Force. Leveraging PyTorch, an Raspberry Pi 5 (RPI 5), an RPI AI Camera, and ultrasonic sensors with Arduino, this setup detects objects, measures distance, and reacts in real time.

This project is being developed by the Themed Entertianment Assosiation at UC San Diego. This repo is contians our entire code base!

Read the project writeup: https://docs.google.com/document/d/1kpoB31zEmDLjaXF0QDtf82j2QZSI7rFvFMhreXqOvS8/edit?usp=sharing

## ⚙️ Tech Stack
🐍 Python

🧠 Raspberry Pi AI Camera - Visual inputs and on board AI accelerator

💻 Raspberry Pi 5 - The base of hardware operations

🌊 Arduino - Handling sensor data from ultrasonic sensors

📡 Ultrasonic Sensors - Measure distances and sends to aurdino

```
├── aurdino              # Aurdino code
│   ├── droid            # Runs the mouse droid animatronic
│   ├── rgbstrip         # Runs rgb stripe "scanner"
│   └── ultrasonic1      # Runs ultrasonic sensor that moves rock
├── python               # Python code
│   ├── scene2_tv        # Will run the media and sensors of scene 2 
│   └── scene3_tv        # Code that will run the media and sensors of scene 3
├── test_scripts         # Contains all test code 
│   └── test code        # Test code
├── computervision.py    # Runs computer vision program
├── imx500_network_higherhrnet_coco.rpk  # COCO model
└── README.md            # What your currently reading!
```

## 🚀 Project Features
Pose estimation 

Real-time Distance Sensing using ultrasonic sensors

Reaction Logic Move or trigger actions based on gestures and proximity

Star Wars-inspired behavior logic (Force push/pull concepts)
