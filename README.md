# Euler CLI
Euler CLI (Command Line Interface) Solution

C++ 20 Standard

## How to run

Get the code:
```
    git clone https://github.com/Simik31/Sudoku_CLI.git
```

Open [`Euler_CLI.sln`](Euler_CLI.sln) in [Visual Studio](https://visualstudio.microsoft.com/ "Get Visual Studio") to build and run the project.

---

## Run with different Command Arguments

To change `Command Arguments`

 1. Right click on `Euler_CLI` Project in Solution Explorer
 2. Click on `Properties`
 3. Under `Configuration Properties` select `Debugging`
 4. Change `Command Arguments`

 Available arguments
 
 <details>
<summary>Test</summary>
Run tests on utils namespace

```
    test
    t
```

> ! No test implemented yet :/
    
</details>

<details>
<summary>Run all problems</summary>

```
    run --all
    run -a
    r --all
    r -a
```

</details>
   
<details>
<summary>Run single problem</summary>

```
    run --id ID
    r --id ID
```

> Run problem number ID (must be valid integer)
</details>

## License

Copyright &copy; 2022 Simik31. All rights reserved.

Licensed under the [WTFPL License](LICENSE.md).
