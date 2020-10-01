from math import pi

import odrive
from odrive.enums import *

def fuzzy_controller(pos_err, derivate_err, errMax=pi/12, outMax=40):
    
