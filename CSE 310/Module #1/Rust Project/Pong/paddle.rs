use piston_window::types::Color;
use piston_window::{rectangle, Context, G2d};
const PADDLE_COLOUR: Color = [1., 1., 1., 1.];
const PADDLE_WIDTH: f64 = 10.;
const PADDLE_HEIGHT: f64 = 100.;
pub struct Paddle {
    pos_x: f64,
    pos_y: f64,
    is_user: bool,
}
impl Paddle {
    pub fn new(pos_x: f64, pos_y: f64, is_user: bool) -> Paddle {
        Paddle {
            pos_x: pos_x,
            pos_y: pos_y,
            is_user: is_user,
        }
    }
    
    pub fn display(&self, con: &Context, g: &mut G2d) {
        rectangle(
            PADDLE_COLOUR,
            [self.pos_x, self.pos_y, 
             PADDLE_WIDTH, PADDLE_HEIGHT,
            con.transform]
        );
    }
}