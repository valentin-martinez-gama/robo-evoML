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
from evo_Models import greekModel

import pandas as pd
import numpy as np
import json


# 0 - Generate greekModel class with dummy odrv0

odrv0 = None
run_name = "Test_3_Evo_RES"

eswa_model = greekModel.greek_Model(odrv0, run_name, res_dir='results/')


""" 
1 - Process data generated during custom evolutionary algorithm gain optimization and turn into a NN training set
    ML.traj_traning(odrv0, robot_eswa_model, num_evos=5, traj_file)

"""
eswa_model.build_ML_training_set()


""" 
2 - Load trained optimal gains Neural Network and get prediction for new controller gains based on scenario encountered in a past run.
    ML.execute_ML_file(odrv0, eswa_model, ML_file="NN_model", traj_file="trajectory.json", num_execs=1)
    eswa_model.do_model_predict()


"""
eswa_model.ML_model = ML.load_net('model1_accu95')

sample_inputs = np.matrix(
    pd.read_csv(f'results/{run_name}.csv').iloc[12, 6:46]
)

pred_A0_gains, pred_A1_gains = eswa_model.do_model_predict(test_X_val=sample_inputs)


""" 
3 - Generate plots that show the average error across a trajectory.
    This is a example reconstructed from historical data of some of the plots that the program would generate after executing a trajectory
    and optimizaing the gains to visually share some data on how the run went.
"""

with open('Datasets/Test_3_Evo_RES.json', 'r') as json_file:
    for line in json_file:
            data = json.loads(line)
            sample = data['winner']
            break

individual_trajectory = eswa_model.Individual(0, pred_A0_gains, pred_A1_gains, eswa_model.outer, dummy=True)
individual_trajectory.traj_data = sample['traj_data']
individual_trajectory.stat_data = {
    'pos_estimate_a0':[],
    'pos_estimate_a1':[],
    'pos_set_a0':[],
    'pos_set_a1':[],
}

eswa_model.print_indiv_group_trajs([individual_trajectory])


""" 
End of demo
"""