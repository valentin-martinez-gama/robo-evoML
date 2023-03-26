# robo-evoML
Use ML to mimic optimization through evolutionary algorithm on 5 bar parallel robot using Odrive controler.

The following are the main components of the codebase:

- Logic and control functions for the control loop implementation using Odriver under the Odrive_control folder
- The differential evolution algorithm logic and it’s implementation on top of the ODrive controller are contained in the evo_ML.py file
- The methodology used to generate data training set out of implementing multiple evolutionary iterations on multiple trajectories is in the ML_training.py file
- ML.py and ML_data.py contain supporting initialization and data processsing functions.
- The Trajecotries folder contains the trajectories to be followed as pairs of angular setpoints for the two motors. All of them to be uniformely spaced in time.
- Datasets and Keras Model contrain the input data used for NN training and the resulting trained model implemented


***

This library also contains the same, or slightly changed, code used in [Robo control with Odrive](https://github.com/valenmgama/robo-control)

#### Python library and functions for controlling brushless motors for robot applications using [Odrive controller.](https://www.semanticscholar.org/paper/Development-of-a-Five-Bar-Parallel-Robot-With-Large-Campos-Bourbonnais/4f945b3db879c18c8fdf2b01860d8a9b2f9a274d?p2df)
In this library you will find various modules and functions that execute start-up, rutine or personlized processes for the use of a 5-bar parallel robot. It is based on the core Odrive platform, and it is intended to simplify and streamline configuration, calibration and movement execution processes.

Added to this base functionality there is a function to optimize controller gains to minimize error in the execution of a planned trajectory for both motors. This is achieved through a Genetic algorithm. This optimization process was the original goal of the project and thus there are many useful functions around it. 
Including tests for bus speed between computer and Odrive, Pandas scripts for saving and manipulating robot data, and plotting of robot activity.

#### Matlab/Simulink dynamic model of the robot used in design and simulations
In the _Matlab-Simulink/SimulacionParalelo_ folder you will find all files related and used for Matlab/Simulink model of the robot. The original approach was to train optimze the controller gains through simulation with this model but be advised that it took one hour of computing to simulate 1 second of robot movement.

---

This functions are meant to be used as a starting point and as inspiration for your own project which will probably be a little different in one way or another. This project wouldn't have been possible without the amazing work and attentive support of the Odrive team who started the Odrive controller project.

Desclaimer: This project is meant to be use as a guideline and should work fine were you to build a robot configuration like ours. However users are personally responsible for adapting functions to their setup and needs and remember to always be very careful with yourself and others when testing high power motor controllers. Happy engineering :)
