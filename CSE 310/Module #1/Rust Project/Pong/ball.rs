use piston_window::types::Color;
use piston_window::{ellipse, Context, G2d};
const BALL_COLOUR: Color = [1., 1., 1., 1.];
const RADIUS: f64 = 10.;
pub struct Ball {
    pos_x: f64,
    pos_y: f64,
    vel_x: f64,
    vel_y: f64,
    width: f64,
    height: f64,
}
impl Ball {
    pub fn new(pos_x: f64, pos_y: f64, 
               canvas_dim: [f64; 2]) -> Ball {
        Ball {
            pos_x: pos_x,
            pos_y: pos_y,
            vel_x: 5.,
            vel_y: 5.,
            width: canvas_dim[0],
            height: canvas_dim[1],
       }
    }
    
    pub fn display(&mut self, con: &Context, g: &mut G2d) {
        self.update();
        ellipse(
            BALL_COLOUR,
            [self.pos_x, self.pos_y, RADIUS, RADIUS],
            con.transform, g
        );
    }
    fn update(&mut self) {
        if (self.pos_y <= 0.) | (self.pos_y >= self.height) {
            self.vel_y *= -1.;
        }
        if (self.pos_x <= 0.) | (self.pos_x >= self.width) {
            self.vel_x *= -1.;
            self.pos_x = self.width / 2.;
            self.pos_y = self.height / 2.;
        }
       self.pos_x += self.vel_x;
       self.pos_y += self.vel_y;
    }
}