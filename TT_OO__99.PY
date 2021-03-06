# LunarLander2d.py
# Copyright Warren Sande, 2011

# Based on LunarLander, Copyright Warren Sande, 2009# Released under MIT license   http://www.opensource.org/licenses/mit-license.php

# LunarLander 2D
# simulation game of landing a spacecraft

"""The original LunarLander in "Hello World! Computer Programmingfor Kids and Other Beginners"was a very simple 1-D (y-axis, vertical motion only)version of Lunar Lander, just to demonstrate a simplegravity simulaiton using Pygame.

LunarLander 2D adds the x-axis (sideways motion).You can now rotate the lander usingthe right/left arrow keys, more likethe original arcade version.It also changes the thrust control from amouse-based (dragging the slider) to key-based(press/hold the spacebar).

Instead of the moonsurface image,it uses a simple landing pad rectangle.

"""

# initialize - get everything ready
import pygame, sys
from math import *
pygame.init()
#wider screen than LunarLander, since we have sideways motion
screen = pygame.display.set_mode([800,600])
screen.fill([0, 0, 0])
ground  = 540   #landing pad is ay 
y = 540
start = 90      # starting location 90 pixels from top of window
clock = pygame.time.Clock()
img1 = pygame.image.load('C:\\Users\\uleku\\landing.jpg')

ship_mass = 5000.0
fuel = 190.0
fps = 30  
#defaultx_loc = 20  # x-location in meters = dist from center of landing pad
y_loc = 40  # y-location in meters = height above the landing pad
x_loc = 40
x_offset = 40    # offsets so that when ship location is (0,0), ship is
y_offset = -108  #   just touching landing pad, and centered.

x_speed = 2000.0   #pixels/framey_speed = -800.0
y_speed = 0
x_velocity = x_speed/(10.0*fps)  #m/s
y_velocity = y_speed/(10.0*fps)

gravity = 1.5
thrust = 0
delta_v = 10
scale = 10   #scale factor from pixels to meters
throttle_down = False
left_down = False
right_down = False
#held_down = False
count = 0
x_pos = 0
y_pos = 0



# sprite for the shipclass 
class ShipClass(pygame.sprite.Sprite):
  def __init__(self, image_file, position):

      pygame.sprite.Sprite.__init__(self)
      self.imageMaster = pygame.image.load(image_file)
      self.image = self.imageMaster
      self.rect = self.image.get_rect()
      self.position = position
      self.rect.centerx, self.rect.centery = self.position
      self.angle = 0


  def update(self):
      self.rect.centerx, self.rect.centery = self.position
      oldCenter = self.rect.center
      self.image = pygame.transform.rotate(self.imageMaster, self.angle)
      self.rect = self.image.get_rect()
      self.rect.center = oldCenter

# calcualte position, motion, acceleration, fuel



def calculate_velocity():
  global ship, thrust, fuel, x_velocity, y_velocity, x_loc, y_loc
  global tot_velocity, scale, x_pos, y_pos, x_speed, y_speed

  delta_t = 1/fps

  #Calculate thrust based on spacebar being held down
  if throttle_down:
      thrust = thrust + 100
      if thrust > 1000:
          thrust = 1000
  else:
      if thrust > 0:
          thrust = thrust - 200
          if thrust < 0:
              thrust = 0
   #fuel -= thrust /(10 * fps)  # use up fuel
  if fuel < 0:
    fuel = 0.0  
  if fuel < 0.1:
    thrust = 0.0
  fuel -= thrust /(10 * fps)  # use up fuel 
  ythrust = thrust * cos(ship.angle*(pi/180))
  xthrust = thrust * sin(ship.angle*(pi/180))
  y_delta_v = delta_t * (-gravity + 50 * ythrust / (ship_mass + fuel))
  y_velocity = y_velocity + y_delta_v
  x_delta_v = delta_t * (-50 * xthrust/(ship_mass + fuel))
  x_velocity = x_velocity + x_delta_v
  x_speed = x_velocity * 10.0/fps   #speed in pixels/frame, velocity in m/s
  y_speed = y_velocity * 10.0/fps
  y_loc = y_loc + y_velocity/fps    # loc in meters, velocity in m/s
  x_loc = x_loc - x_velocity/fps
  tot_velocity = sqrt(x_velocity**2 + y_velocity**2)
  ship.position[0] = x_pos = screen.get_width()/2 - (scale * x_loc) + x_offset
  ship.position[1] = y_pos = screen.get_height() - (scale * y_loc) + y_offset
 # @delta_v = x_delta_v

  if right_down:
      ship.angle = ship.angle - 2
  if left_down:
      ship.angle = ship.angle + 2
  ship.update()

# display the text with the speed, height, etc. 
def display_stats():
  vv_str = "vertical speed:  %.1f m/s" % y_velocity    # in m/s
  hv_str = "horizontal speed %.1f m/s" % x_velocity    # in m/s
  tv_str = "Total Velocity %.1f m/s" % tot_velocity    # in m/s
  h_str = "height:   %.1f m" % y_loc                   #in meters
  x_str = "position: %.1f m" % x_loc
  ang_str = "Angle: %.1f" % ship.angle
  t_str = "thrust:   %i  kg" % thrust
  a_str = "acceleration: %.1f m/s/s" % (delta_v * fps)
  f_str = "fuel:  %i" % fuel

  vv_font = pygame.font.Font(None, 26)  
  vv_surf = vv_font.render(vv_str, 1, (255, 255, 255))  
  screen.blit(vv_surf, [10, 50])

  hv_font = pygame.font.Font(None, 26)  #horizontal speed  hv_surf = hv_font.render(hv_str, 1, (255, 255, 255))  screen.blit(hv_surf, [10, 70])

  hv_font = pygame.font.Font(None, 26)  
  hv_surf = hv_font.render(hv_str, 1, (255, 255, 255))  
  screen.blit(hv_surf, [10, 90])

  h_font = pygame.font.Font(None, 26)   #y-location (height)  h_surf = h_font.render(h_str, 1, (255, 255, 255))  screen.blit(h_surf, [10, 120])

  x_font = pygame.font.Font(None, 26)   #x_location  x_surf = x_font.render(x_str, 1, (255, 255, 255))  screen.blit(x_surf, [10, 150])

  ang_font = pygame.font.Font(None, 26)  #angle  ang_surf = ang_font.render(ang_str, 1, (255, 255, 255))  screen.blit(ang_surf, [10, 180])

  t_font = pygame.font.Font(None, 26)   #thrust  t_surf = t_font.render(t_str, 1, (255, 255, 255))  screen.blit(t_surf, [10, 210])

  a_font = pygame.font.Font(None, 26)   
  a_surf = a_font.render(a_str, 1, (255, 255, 255))  
  screen.blit(a_surf, [10, 240])

  f_font = pygame.font.Font(None, 26)   
  f_surf = f_font.render(f_str, 1, (255, 255, 255))  
  screen.blit(f_surf, [60, 330])

# display the ship's flames - size depends on the amount of thrust 
def display_flames():
  fsize = thrust / 30  #flame size
  # for rotation, need to do some trig to draw the flame triangles
  #   in the correct orientation
  # points a-f are the 6 vertices of the 2 flame triangles 

  # calcualte polar coordinates of un-rotated flames 
  a_len = sqrt(43*43 + 17*17)
  b_len = sqrt( (43+fsize)*(43+fsize) + 13*13)
  c_len = sqrt(43*43 + 9*9)
  d_len = c_len
  e_len = b_len
  f_len = a_len
  a_ang_orig = atan2(-17.0,-43.0)
  b_ang_orig = atan2(-13.0,(-43-fsize))
  c_ang_orig = atan2(-9.0,-43.0)
  d_ang_orig = atan2(9.0,-43.0)
  e_ang_orig = atan2(13.0,(-43.0-fsize))
  f_ang_orig = atan2(17.0,-43.0)

  # rotate flame by same angle as ship rotation
  a_ang_rot = a_ang_orig + (270-ship.angle)*(pi/180)
  b_ang_rot = b_ang_orig + (270-ship.angle)*(pi/180)
  c_ang_rot = c_ang_orig + (270-ship.angle)*(pi/180)
  d_ang_rot = d_ang_orig + (270-ship.angle)*(pi/180)
  e_ang_rot = e_ang_orig + (270-ship.angle)*(pi/180)
  f_ang_rot = f_ang_orig + (270-ship.angle)*(pi/180)

  # calculate x-y coordinates of rotated flames 
  ax = int(a_len * cos(a_ang_rot))
  ay = int(a_len * sin(a_ang_rot))
  bx = int(b_len * cos(b_ang_rot))
  by = int(b_len * sin(b_ang_rot))
  cx = int(c_len * cos(c_ang_rot))
  cy = int(c_len * sin(c_ang_rot))
  dx = int(d_len * cos(d_ang_rot))
  dy = int(d_len * sin(d_ang_rot))
  ex = int(e_len * cos(e_ang_rot))
  ey = int(e_len * sin(e_ang_rot))
  fx = int(f_len * cos(f_ang_rot))
  fy = int(f_len * sin(f_ang_rot))

  #draw the flames
  pygame.draw.polygon(screen, [255, 109, 14],
                     [(x_pos + ax, y_pos + ay),
                      (x_pos + bx, y_pos + by),
                      (x_pos + cx, y_pos + cy)], 0)
  pygame.draw.polygon(screen, [255, 109, 14],
                     [(x_pos + dx, y_pos + dy),
                      (x_pos + ex, y_pos + ey),
                      (x_pos + fx, y_pos + fy)], 0)

# display final stats when the game is over
def display_final():
  global x_velocity, y_velocity, tot_velocity, ship #, fuelbar
  final1 = "Game over"
  final2 = "You landed at:"
  final3 = "%.1f m/s horizontal" % x_velocity
  final4 = "%.1f m/s vertical" % y_velocity
  final5 = "%.1f m/s Total" % tot_velocity
  final6 = "%.1f degrees" % ship.angle
  screen.fill([0, 0, 0])
  pygame.draw.rect(screen, [0, 0, 255], [80, 350, 24, 100], 2)
  pygame.draw.rect(screen, [0,255,0], [84,448-fuelbar,18, fuelbar], 0)
  drawTerrain()
  screen.blit(ship.image, ship.rect)

  if (abs(tot_velocity) < 2 and abs(ship.angle) < 5):
      final7 = "Nice landing!"
      final7 = "Nice landing!"
      final8 = "continue to NEXT Level ???"
      f8_font = pygame.font.Font(None, 76)
      f8_surf = f8_font.render(final8, 1, (255, 255, 255))
      screen.blit(f8_surf, [20, 290])
      f7_font = pygame.font.Font(None, 96)
      f7_surf = f7_font.render(final7, 1, (255, 255, 255))
      screen.blit(f7_surf, [20, 210])
      pygame.display.flip()
      while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit(); #sys.exit() if sys is imported
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_0:
                    d = {'C:\\Users\\uleku\\troll2.jpg': [500, 230]}
                    execfile("C:\\Users\\uleku\\new4wA.py",d)
                if event.key == pygame.K_1:
                    print("Doing whatever")
  elif (abs(tot_velocity) < 55 and  abs(ship.angle < 10)):
      final7 = "Ouch!  A bit rough, but you survived."
      final8 = "SCORE NOT HIGH ENOUGH ....Replay Level."
      f8_font = pygame.font.Font(None, 46)
      f8_surf = f8_font.render(final8, 1, (255, 255, 255))
      screen.blit(f8_surf, [20, 290])
      f7_font = pygame.font.Font(None, 56)
      f7_surf = f7_font.render(final7, 1, (255, 255, 255))
      screen.blit(f7_surf, [20, 210])
      pygame.display.flip()      
      while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit(); #sys.exit() if sys is imported
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_0:
                    d = {'C:\\Users\\uleku\\troll2.jpg': [500, 230]}
                    execfile("C:\\Users\\uleku\\new3wA.py",d)
                if event.key == pygame.K_1:
                    print("Doing whatever")
      
  else:
      final7 = "Yikes!  You crashed a 30 Billion dollar ship."
      final8 = "How are you getting home?"
  pygame.draw.rect(screen, [0, 0, 0], [5, 5, 350, 280],0)
  f1_font = pygame.font.Font(None, 70)
  f1_surf = f1_font.render(final1, 1, (255, 255, 255))
  screen.blit(f1_surf, [20, 50])
  f2_font = pygame.font.Font(None, 40)
  f2_surf = f2_font.render(final2, 1, (255, 255, 255))
  screen.blit(f2_surf, [20, 110])
  f3_font = pygame.font.Font(None, 26)
  f3_surf = f3_font.render(final3, 1, (255, 255, 255))
  screen.blit(f3_surf, [20, 150])
  f4_font = pygame.font.Font(None, 26)
  f4_surf = f4_font.render(final4, 1, (255, 255, 255))
  screen.blit(f4_surf, [200, 150])
  f5_font = pygame.font.Font(None, 26)
  f5_surf = f5_font.render(final5, 1, (255, 255, 255))
  screen.blit(f5_surf, [380, 150])
  f6_font = pygame.font.Font(None, 26)
  f6_surf = f6_font.render(final6, 1, (255, 255, 255))
  screen.blit(f6_surf, [20, 180])
  f7_font = pygame.font.Font(None, 26)
  f7_surf = f7_font.render(final7, 1, (255, 255, 255))
  screen.blit(f7_surf, [20, 210])
  f8_font = pygame.font.Font(None, 26)
  f8_surf = f8_font.render(final8, 1, (255, 255, 255))
  screen.blit(f8_surf, [20, 240])
  screen.blit(inst1_surf, [50, 550])
  screen.blit(inst2_surf, [20, 575])
  screen.blit(inst3_surf, [50, 600])
  pygame.display.flip()

# draw the landing pad.
# note:  This could be made more complex, but just a
#          simple landing pad for now.f
def drawTerrain():
  poi_list = [(525,375),(576,365),(550,475),(500,625),(480,540)]
  p_L2 = [(525,400),(550,420),(576,525),(630,475),(700,350),(850,540),(480,540)]
  p_L3 = [(0,545),(75,500),(150,405),(176,440),(200,540),(250,455),(350,470),(400,535)]
  screen.blit(img1,(400,530))#pygame.draw.rect(screen, [180, 180, 180], [400, 535, 90, 5],5)  
  #pygame.draw.polygon(screen, [250, 220, 250], poi_list,5)
  pygame.draw.polygon(screen, [190, 225, 250], p_L3,5)
  pygame.draw.polygon(screen, [190, 225, 250], p_L2,5)
# make an instance of the ship sprite
ship = ShipClass('C:\\Users\\uleku\\troll3.jpg', [500, 230])

# main loop
while True:
  clock.tick(30)
  fps = clock.get_fps()
  if fps < 1:
       fps = 30
  count += 1
  if y_loc > 0.01:
      calculate_velocity()
      screen.fill([0, 0, 0])
      display_stats()
      pygame.draw.rect(screen, [0, 0, 255], [80, 350, 24, 100], 2)
      fuelbar = 96 * fuel / 5000
      pygame.draw.rect(screen, [0,255,0], [84,448-fuelbar,18, fuelbar], 0)
      drawTerrain()
      display_flames()
      screen.blit(ship.image, ship.rect)
      instruct1 = "Land softly without running out of fuel"
      instruct2 = "Good landing: < 5 m/s    Great landing:  < 2m/s"
      instruct3 = "And you must be within 10 degrees of vertical"
      inst1_font = pygame.font.Font(None, 24)
      inst1_surf = inst1_font.render(instruct1, 1, (255, 255, 255))
      screen.blit(inst1_surf, [50, 550])
      inst2_font = pygame.font.Font(None, 24)
      inst2_surf = inst1_font.render(instruct2, 1, (255, 255, 255))
      screen.blit(inst2_surf, [20, 575])
      inst3_font = pygame.font.Font(None, 24)
      inst3_surf = inst3_font.render(instruct3, 1, (255, 255, 255))
      screen.blit(inst3_surf, [50, 600])
      pygame.display.flip()

  else:  #game over - print final score
      display_final()

  for event in pygame.event.get():
      if event.type == pygame.QUIT:
          sys.exit()
      elif event.type == pygame.KEYDOWN:
          if event.key == pygame.K_SPACE: 
              throttle_down = True
          if event.key == pygame.K_RIGHT:
              right_down = True
          if event.key == pygame.K_LEFT:
              left_down = True
          if event.key == pygame.K_UP:
              final14 = "Game over\\\\RESTART"
              f14_font = pygame.font.Font(None, 66)
              f14_surf = f14_font.render(final14, 1, (255, 255, 255))
              screen.blit(f14_surf, [200, 150])
              pygame.display.flip()
                 
      elif event.type == pygame.KEYUP:
          if event.key == pygame.K_SPACE:
              throttle_down = False
          if event.key == pygame.K_RIGHT:
              right_down = False
          if event.key == pygame.K_LEFT:
              left_down = False
          if event.key == pygame.K_UP:
              final14 = "Game over\\\\RESTART"
              f14_font = pygame.font.Font(None, 66)
              f14_surf = f14_font.render(final14, 1, (255, 255, 255))
              screen.blit(f14_surf, [200, 150])
              pygame.display.flip()
              drawTerrain()   
