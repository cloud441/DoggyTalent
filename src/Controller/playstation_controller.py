import pygame

from .controller import Controller

class PlaystationController(Controller):

    def __init__(self) -> None:
        super().__init__()

        pygame.init()
        pygame.joystick.init()

        if pygame.joystick.get_count() == 0:
            raise Exception("No valid controller detected.")

        self.joystick = pygame.joystick.Joystick(0)
        self.joystick.init()


    def get_steer(self) -> float:

        return self.joystick.get_axis(0)



    def get_throttle(self) -> float:

        axis_forward = (self.joystick.get_axis(5) + 1) / 2
        axis_backward = -(self.joystick.get_axis(2) + 1) / 2

        return axis_forward + axis_backward




    def stop(self) -> bool:
        for event in pygame.event.get():
            if event.type == pygame.JOYBUTTONDOWN:
                button_b = self.joystick.get_button(5)
                if button_b == 1:
                    return True
