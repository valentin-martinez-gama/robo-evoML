### Para copiar archivo adentro de la libreria de Odrive ###
if __name__ == '__main__':
    import shutil
    shutil.copy(__file__, 'env/Lib/site-packages/odrive/roboDrive.py')

import odrive.utils as utils

def print_inidividauls_trajs(chosen):
    time_axis = []
    accumulated_time = 0
    estimatess = []
    inputss = []
    errorss = []
    for indiv in chosen:
        time_axis.extend([t+accumulated_time for t in indiv.data['time_axis']])
        accumulated_time = time_axis[-1]
        estimatess.extend(indiv.data['pos_estimate_a1'])
        inputss.extend(indiv.data['input_pos'])
        errorss.extend(list(np.subtract(np.array(i),np.array(e))))
    plt.plot(time_axis, estimatess)
    plt.plot(time_axis, inputss)
    plt.plot(time_axis, errorss)
    plt.xlabel("Muestreo")
    plt.ylabel("Posición")
    plt.legend(["Posición Actual", "Referencia", "Error"])
    plt.show()


def pos_plotter(odrvAxis):
     utils.start_liveplotter(lambda: [odrvAxis.encoder.pos_estimate,
     odrvAxis.controller.pos_setpoint,
     odrvAxis.controller.pos_setpoint - odrvAxis.encoder.pos_estimate])


def change_plotter_rate(new_data_rate, new_plot_rate, new_num_samples):
    utils.data_rate = new_data_rate
    utils.plot_rate = new_plot_rate
    utils.num_samples = new_num_samples

change_plotter_rate(100, 100, 500)
