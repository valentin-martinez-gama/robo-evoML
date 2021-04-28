from evo_Models.alfaModel import evo_Model


class beta_Model(evo_Model):
    def __init__(self, odrv, training_tag):
        evo_Model.__init__(self, odrv, training_tag)

        print("Input_delay = " + str(self.input_delay))
        print("Data_delay = " + str(self.data_delay))


def create_beta_Model(odrv, training_tag):
    beta_Model = evo_Model(odrv, training_tag)
    return beta_Model
