"""
 Python file for calling main functions used for executing research steps and generating data for 

    Neural-optimal tuning of a controller for a parallel robot
    Daniel Blanck, Carlos Cruz Villar, Hector Cervantes, Gerardo Oritz, Valentin Martinez Gama
    ESWA

 """


""" 
Non Code Ocean executable functions give the inability to connect to ethe USB COM ports for communication with ODrive controller

1. Install odrive package
    pip install odrive

2. Connect robot's Odrive controller to computer using USB COM cable

3. Run odrivetool on terminal, wait for tool to connect.
    odrivetool

4. Import ML and base model class into odrivetool terminal
    import ML
    from evo_models import greekModel

5. Create model object, this will automatically initizalize the robot
   eswa_model = greekModel.greekModel(odrv0, "test_name")

4. Call any of the functions avaiable to the model class:

    - ML.traj_traning(odrv0, eswa_model, num_evos=5, traj_file)

    Use differential evolution model to optimize controller gains for a given trajectory.
    Process data run to build a ML training data set for NN


    - ML.execute_ML_file(odrv0, eswa_model, ML_file="NN_model", traj_file="trajectory.json", num_execs=1)
    
    Run the robot through a trajectory utilizing the NN to tune controller gains as it goes.
    Generate plot to show trajectory results and errors

"""



""" 
Ocean Code Executable functions
Odrive agnostic functions that will process the data, and generate results

"""

import ML
from evo_models import greekModel

# 1 - Generate greekModel class with dummy odrv0

odrv0 = None
eswa_model = greekModel.greekModel(odrv0, "Test_3_Evo_RES")

""" 
1 - Process data generated during custom evolutionary algorithm gain optimization and turn into a NN training set
    ML.traj_traning(odrv0, robot_eswa_model, num_evos=5, traj_file)

"""
eswa_model.build_ML_training_set(data_dir = 'results/')

""" 
2 - 

"""
# nn_file = ML.load_net('model1_accu95')


