pub fn version() {
    println!("rz v0.1.5 - 6/24/2022");
}

pub fn help() {
    version();
    println!("
    Commands
    
    Name
    `$ rz -n yourname`
    Name specifies your name as it should appear in the license. If name is not specified, it'll insert the $USER environment variable.
    
    Year
    `$ rz -y 2022`
    Year specifies the year as it should appear in the license. If year is not specified, it'll insert the current year.
    
    License
    `$ rz -l MIT`
    License specifies the license to insert into your document. Use common abbreviations like MIT or Apache2.
    
    - MIT https://opensource.org/licenses/MIT
    - Apache 2 || Apache2 || Apache https://opensource.org/licenses/Apache-2.0
    - BSD3 || BSD-3 || bsd3 https://opensource.org/licenses/BSD-3-Clause
    - BSD3 || BSD-2 || bsd2 https://opensource.org/licenses/BSD-2-Clause
    
    
    Input (required)
    `$ rz -i sourcecode.ts`
    Input specifies the file to prepend your license onto. It's good if you already have your code, and just want to add a license before.
    
    Output
    `$ rz -i sourcecode.ts -o newsourcecode.ts`
    Output specifies the file to write your license (plus any input specified with `-i`) to. If not provided it just assumes you want to replace your input with your output.
    
    Prefix Line
    `$ rz -pl `
    Prefix Line specifies what to prefix before each line of your output. Think the specific comment charachters for your source langauge.
    
    Suffix Line
    `$ rz -sl '-->'`
    Suffix Line specifies what to Suffix after each line of your output. Think the closing brackets of a html comment. Great for markdown!")
}