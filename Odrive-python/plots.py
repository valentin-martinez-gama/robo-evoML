### Para copiar archivo adentro de la libreria de Odrive ###
if __name__ == '__main__':
    import shutil
    shutil.copy(__file__, 'env/Lib/site-packages/odrive/roboDrive.py')

import odrive.utils as utils

def pos_plotter(odrvAxis):
     utils.start_liveplotter(lambda: [odrvAxis.encoder.pos_estimate,
     odrvAxis.controller.pos_setpoint,
     odrvAxis.controller.pos_setpoint - odrvAxis.encoder.pos_estimate])


def change_plot_rate(new_data_rate, new_plot_rate, new_num_samples):
    utils.data_rate = new_data_rate
    utils.plot_rate = new_plot_rate
    utils.num_samples = new_num_samples

change_plot_rate(100, 100, 500)
