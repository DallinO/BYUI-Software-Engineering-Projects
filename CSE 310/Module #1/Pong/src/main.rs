extern crate piston_window;
use piston_window::*;
use piston_window::types::Color;
const WIDTH: u32 = 640;
const HEIGHT: u32 = 480;
const BACKGROUND_COLOUR: Color = [0.5, 0.5, 0.5, 1.0];
fn main() {
    let mut window: PistonWindow = WindowSettings::new("Rusty Pong",
                                                  [WIDTH, HEIGHT])
        .exit_on_esc(true)
        .build()
        .unwrap();
    while let Some(event) = window.next() {
        window.draw_2d(&e, |context, graphics, _device| {
            clear(BACKGROUND_COLOUR, graphics);
        });
    }
}
