

use std::collections::HashSet;
use std::io::{self, BufRead};
use std::cmp;
fn main(){

    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    


    let tc = lines.next().unwrap().unwrap().trim().parse().unwrap();


    for _ in 0..tc{
        let mut hash_set: HashSet<i32> = HashSet::new();
        let line = lines.next().unwrap().unwrap();
        let n:i32 = line.trim().parse().unwrap();

        let next_line = lines.next().unwrap().unwrap();
        let nums: Vec<i32> = next_line.split_whitespace()
                                 .map(|x| x.parse().unwrap())
                                 .collect();
        
        for num in &nums{ 
            hash_set.insert(*num);
        }

        let pivot = hash_set.len(); 
        
        let mut answer:i32 =i32::MAX;
        for num in &nums{ 
            if *num >= (pivot as i32){
                answer = cmp::min(*num,answer);
            }
        }

        println!("{}", answer);
         
    }
    
}
