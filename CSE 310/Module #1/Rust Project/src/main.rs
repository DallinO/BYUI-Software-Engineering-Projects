use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    println!("Guess the number!");

    // Generate random number
    let secret_number  = rand::thread_rng().gen_range(1, 101);
    // Main game loop
    loop {
        println!("Please input your guess.");

        let mut guess = String::new();
        // Check the user input for correct type
        io::stdin().read_line(&mut guess)
            .expect("failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(msg) => {
                println!("{}", msg);
                continue;
            },
        };

        println!("You guessed: {}", guess);
        // Compare the user input to the random number
        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            },
        }
    }
}