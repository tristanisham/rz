use std::env;

use license::{Apache2, BSD2, BSD3, MIT};
mod cli;
mod license;

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut infile: String = String::from("");
    let mut outfile = String::from("");
    let mut name: Option<String> = None;
    let mut year: Option<String> = None;
    let mut license: String = String::from("");
    let mut prefix: Option<String> = None;
    let mut suffix: Option<String> = None;

    for i in 1..args.len() {
        match args[i].as_str() {
            "help" | "--h" | "-h" => {
                cli::help();
                break;
            }
            "version" | "--v" | "-v" => {
                cli::version();
                break;
            }
            _ => (),
        }
        if args[1..].len() >= i + 1 {
            match args[i].as_str() {
                "-i" => {
                    infile = args[i + 1].clone();
                }
                "-n" => {
                    name = Some(args[i + 1].clone());
                }
                "-y" => {
                    year = Some(args[i + 1].clone());
                }
                "-l" => {
                    license = args[i + 1].clone();
                }
                "-o" => outfile = args[i + 1].clone(),
                "-pl" => {
                    prefix = Some(args[i + 1].clone());
                }
                "-sl" => {
                    suffix = Some(args[i + 1].clone());
                }
                _ => (),
            }
        }
    }
    if outfile.is_empty() {
        outfile = infile.clone();
    } else if infile.is_empty() {
        eprintln!("{infile} must not be empty. $ rt -i <file>");
        std::process::exit(1);
    }

    match license.as_str() {
        "MIT" | "mit" => {
            let copy = MIT::new(name, year);
            license::write_out(copy, infile, outfile, prefix, suffix).unwrap();
        }
        "Apache" | "Apache2" | "Apache2.0" | "apache" => {
            let copy = Apache2::new(name, year);
            license::write_out(copy, infile, outfile, prefix, suffix).unwrap();
        }
        "BSD3" | "BSD-3" | "bsd3" => {
            let copy = BSD3::new(name, year);
            license::write_out(copy, infile, outfile, prefix, suffix).unwrap();
        }
        "BSD2" | "BSD-2" | "bsd2" => {
            let copy = BSD2::new(name, year);
            license::write_out(copy, infile, outfile, prefix, suffix).unwrap();
        }
        _ => ()
    }
}
