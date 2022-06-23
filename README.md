<div align="center">
©
  <h1>rz</h1>

  <strong>A command line tool for adding license text to your source files so you can focus on production</strong>

</div> 
<hr>
<br>

## Commands

### Name
`$ rt -n yourname`
Name specifies your name as it should appear in the license. If **name** is not specified, it'll insert the $USER environment variable.

### Year
`$ rt -y 2022`
Year specifies the year as it should appear in the license. If **year** is not specified, it'll insert the current year.

### License
`$ rt -l MIT`
License specifies the license to insert into your document. Use common abbreviations like **MIT** or **Apache2**.

- [MIT](https://opensource.org/licenses/MIT)
- [Apache 2 || Apache2 || Apache](https://opensource.org/licenses/Apache-2.0)

### Input (required)
`$ rt -i sourcecode.ts`
Input specifies the file to prepend your license onto. It's good if you already have your code, and just want to add a license before.

### Output
`$ rt -i sourcecode.ts -o newsourcecode.ts`
Output specifies the file to write your license (plus any input specified with `-i`) to. If not provided it just assumes you want to replace your input with your output.

### Prefix Line
`$ rt -pl "// "`
Prefix Line specifies what to prefix before each line of your output. Think the specific comment charachters for your source langauge.

### Suffix Line
`$ rt -sl '-->'`
Suffix Line specifies what to Suffix after each line of your output. Think the closing brackets of a html comment. **Great for markdown!**

#### Example
```go
// main.go
package main

import "fmt"

func main() {
    fmt.Println("Hello, World!")
}
```
```sh
$ rt -i main.go -pl "// " -l MIT -n "Your Name"
```
```go
// Copyright ©2022 Your Name

// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

// main.go
package main

import "fmt"

func main() {
    fmt.Println("Hello, World!")
}
```
<!-- 
## Installation -->
