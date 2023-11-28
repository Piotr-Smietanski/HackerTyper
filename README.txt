
    __  __           __            ______                     
   / / / /___ ______/ /_____  ____/_  __/_  ______  ___  _____
  / /_/ / __ `/ ___/ //_/ _ \/ ___// / / / / / __ \/ _ \/ ___/
 / __  / /_/ / /__/ ,< /  __/ /   / / / /_/ / /_/ /  __/ /    
/_/ /_/\__,_/\___/_/|_|\___/_/   /_/  \__, / .___/\___/_/     
                                     /____/_/                 


HackerTyper is a toy program that simulate hacking scenes from movies.
Defult operation mode prints segments of text without user interaction.
When it encounter non-graphical character it waits for a moment before
printing next segment. By default program quit upon reaching end of input
file unless option "-l" is specified. You can also specify colors of font,
background and style of font but your terminal have to support it.
Only "-f" argument is mandatory which is a path to a file that will be
printed.

//----------------------------------------------------------------------
```
Arguments:
        -h
                Displays this help.
        -l
                Loops output infinitely.
        -i
                Interactive mode. Waits for key press before printing segment.
        -f file
                Uses file content as source.
        -d delay
                Changes delay in miliseconds between printing segments in non-interactive mode.
                default 50000
        -fc color
                Changes font color. options are:
                black, red, green, yellow, blue, cyan, aqua, white,
                black_dark, red_dark, green_dark, yellow_dark, blue_dark, cyan_dark, aqua_dark, white_dark
        -fbc color
                Changes background color. Options are:
                black, red, green, yellow, blue, cyan, aqua, white
        -fs style
                Changes font style. Options are:
                regular, bold, thin, cursive, underline, blink
```
//----------------------------------------------------------------------
