use std::io::{self, Read};

fn next_int() -> i64 {
    let stdin = io::stdin();
    let mut handle = stdin.lock();
    let mut word = String::new();

    for byte_result in handle.bytes() {
        match byte_result {
            Ok(byte) => {
                let c = byte as char;
                if c.is_whitespace() {
                    if !word.is_empty() {
                        break;
                    } else {
                        continue;
                    }
                }
                word.push(c);
            }
            Err(e) => {
                eprintln!("Error reading byte: {}", e);
                break;
            }
        }
    }
    word.trim().parse().unwrap()
}

fn solve() {
    let n: i64 = next_int();
    let k: i64 = next_int();

    let mut arr = Vec::with_capacity(n as usize);
    for _ in 0..n {
        arr.push(next_int());
    }

    if k < 2 {
        let first = arr[0];
        let last = arr[arr.len() - 1];

        let (maxv, other_maxv) = if first > last {
            let mut other = 0;
            for (idx, &val) in arr.iter().enumerate() {
                if idx == 0 {
                    continue;
                }
                other = other.max(val);
            }
            (first, other)
        } else {
            let mut other = 0;
            for (idx, &val) in arr.iter().enumerate() {
                if idx == arr.len() - 1 {
                    continue;
                }
                other = other.max(val);
            }
            (last, other)
        };

        println!("{}", maxv + other_maxv);
        return;
    }

    arr.sort_unstable();
    let k_usize = k as usize;
    let sum_k: i64 = arr[arr.len() - (k_usize + 1)..].iter().sum();
    println!("{}", sum_k);
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut tc: i64 = line.trim().parse().unwrap();

    while tc > 0 {
        solve();
        tc -= 1;
    }
}
