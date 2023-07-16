# Purpose  
  ## Idea
  Idea is to mimic the working of submarines using cheaper alternatives, make it hopefully consise enough to carry out small operations

  ## Problems it can solve
  1. Underwater exploration
  2. Small scaled rescue operation      
# How to clone
   [Clone Github link](https://github.com/soumya530G/underwaterexploration.git) 

# Basic Working of the Project  



<img width="422" alt="final" src="https://github.com/soumya530G/underwaterexploration/assets/78527655/8e152a95-83b1-4131-8d10-9005ce780acc">


  ![image_text]([Media\final.png](https://github.com/soumya530G/underwaterexploration/blob/master/obj_code/Media/final.png) "final model")
  ## Lead screw mechanism
  ![image_text]([Media\lead_screw2.jpg](https://github.com/soumya530G/underwaterexploration/blob/master/obj_code/Media/lead_screw2.jpg) "lead screw mechanism")

A lead screw mechanism is a simple but effective way to translate rotational motion into linear motion. It is commonly used in a variety of applications, including CNC machines, 3D printers, and other types of machinery.
At its most basic, a lead screw mechanism consists of a threaded rod, called the lead screw, and a nut that is threaded onto the lead screw. When the lead screw is rotated, the nut moves along the length of the screw. By attaching a load to the nut, the rotational motion of the lead screw can be used to move the load linearly.

[See how it works]([Media\leadscrew.mp4](https://github.com/soumya530G/underwaterexploration/blob/master/obj_code/Media/leadscrew.mp4))
  ## Atmospheric pressure in syringes

Syringes are medical devices that are used to inject or withdraw fluids from the   body. They consist of a barrel and a plunger. When the plunger is pushed, the fluid in the barrel is forced out, and when the plunger is pulled, fluid is drawn into the barrel.

Here's a detailed explanation of how the ballast tank (syringe arrangement) works:

1. The Barrel: The barrel is the cylindrical body of the syringe that holds the fluid to be injected or withdrawn. It is usually made of plastic and is marked with volume measurements that allow the user to accurately measure the amount of fluid being injected or withdrawn.

2. The Plunger: The plunger is a long, slender rod that fits snugly inside the barrel of the syringe. It is used to apply pressure to the fluid in the barrel, either to push it out through the needle or to draw it in from a separate container. The plunger is usually made of plastic, and has a rubber tip or seal that creates a tight seal between the plunger and the inside of the barrel.

To use a syringe, the plunger is either pushed or pulled to push forward or withdraw fluid. When the plunger is pushed, the fluid in the barrel is forced out, and when the plunger is pulled, fluid is drawn into the barrel.

# Utilities (with each ones function and image in the project and cost)
  ## Hardware
   1. Camera
   2. Micro controllers (Arduino)
   3. Limit Switch
   4. BLDC motor and driver (L298)
   5. Nylon discs
   6. Threadbar and nuts
   7. Vaccum syringes and pipes
   8. DC motor
   9. Bluetooth module
   10. Servo motor
   11. Battery
   12. IMU sensor
   13. Ultra-sonic sensor
   14. Propeller: new design as per defence brochures etc

   ## Software  
   1. Arduino IDE
   2. MITAppInventor
   3. VSCode
   4. APIs
   5. AutoCAD    

# Circuit Diagram      
  ![image_text]([Media\circuit_proteus.png](https://github.com/soumya530G/underwaterexploration/blob/master/obj_code/Media/circuit_proteus.png) "circuit")  

# Codes in action
  ## Arduino
  (For hardware control through micro controllers)
  ## MITAppInventor
  (For UI) ![image_text]([Media\ui.png](https://github.com/soumya530G/underwaterexploration/blob/master/obj_code/Media/ui.png) "UI")
  ## Object Detection
  ![obj_detect]([Media\obj.png](https://github.com/soumya530G/underwaterexploration/blob/master/obj_code/Media/obj.png))


# Integration
  ## Full working
This project demonstrates the working of an underwater exploration robot. It's based on the concept of a ballast tank upon which the submarines are based. This project includes an amalgamantion of hardware and software components wherein the hardware components are integrated and made to operate by the emedded software system consisting of a micro controller (Arduino UNO), bluetooth module (HC05) etc, further advancements are made to this project by including object detection for the purpose of underwater exploration and for performing small-scaled rescue operations.
The robot works on the principle of center of gravity wherein, vessel's center of gravity can be changed by adding or removing water. We've used servo motors to actuate limit switches which would then change the motion and direction of DC motors, as we're using linear motions caused by DC motors to our advantage which would then move the discs attached to water containing syringes thereby adding or removing water from them and changing the center of gravity of the whole robot. The servo motors take in angles from arduino for which I've developed an app with an interactive UI which interacts with arduino through bluetooth module. For a safer use I've added various functions with fixed angles in it.

  ## Working video link:
[Video](https://github.com/soumya530G/underwaterexploration/blob/master/obj_code/Media/VIDEO-2023-04-26-17-41-25.mp4)

# Future Scope
  ## Things to improve upon
   1. In order to avoid damage from external objects / marine life I'm planning on designing a stronger outer hull for the robot, this can also help in preventing damage to electrical equipments due to water
   2. An efficient fin system needs to be added for direction control

  ## Things that can be done
   1. A system similar to that for GPS can be installed in the robot such that whenever it recognizes an object while producing an alarm it can also send the exact coordinates, this might get difficult as often times it's hard to get the exact location underwater
   2. An external gripper or similar end effector could be attached in order to carry out rescue operations wherein humans cannot possibly go
   3. The dataset on which the model for object detection is trained could be made more accurate, this would require a system with a higher GPU.

# How to reach me
[LinkedIn](https://www.linkedin.com/in/soumyagupta8/) | [Github](https://github.com/soumya530G) | [Email](soumyamns002@gmail.com)
