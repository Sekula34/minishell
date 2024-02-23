# minishell

42 school patner project for which we reverse engineered bash with some limitations.

## Installation
git clone git@github.com:Sekula34/minishell.git minishell  
cd minishell  
make

## Usage
Run with ./minishell.
Use just like bash.

Supports:
- quotes
- redirections
- heredoc
- pipes
- enviroment variables
- $?
- ctrl-C, ctrl-D and ctrl-\

These programms are built in by us:
- echo with option -n
- cd with only a relative or absolute path 
- pwd with no options
- export with no options
- unset with no options
- env with no options or arguments
- exit with no options

## Tests
We mainly used this tester from github: https://github.com/zstenger93/42_minishell_tester.
Other than that we tested by hand;


Made by Filip Seles and Willem van der Vorst