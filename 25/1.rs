use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() {
    let mut dial: i16 = 50;
    let mut times_zero: u16 = 0;
    // File hosts.txt must exist in the current path
    if let Ok(lines) = read_lines("./1.txt") {
        // Consumes the iterator, returns an (Optional) String
        for line in lines.map_while(Result::ok) {
            print!("{} + {} = ", dial, line);
            if let Some(end) = line.strip_prefix('R') {
                dial += &end.parse().unwrap();
                if dial > 99 {
                    dial %= 100
                }
                println!("{}", dial);
            } else {
                dial -= &line[1..].parse().unwrap();
                if dial < 0 {
                    // rem_euclid
                    dial = ((dial % 100) + 100) % 100
                }
                println!("{}", dial)
            }
            if dial == 0 {
                times_zero += 1;
            }
        }
    }
    println!("result: {}", times_zero); //not 6, not 55

}

// The output is wrapped in a Result to allow matching on errors.
// Returns an Iterator to the Reader of the lines of the file.
fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where
    P: AsRef<Path>,
{
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}
