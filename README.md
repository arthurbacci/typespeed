# typespeed

Really simple typing speed (CPS) calculator using ANSI C

## Usage

```
typespeed [file]
```

`file` is the file the program will take random lines from for you to type, it can be anything. You can try giving it a book, or maybe your `~/bash_history` if you want to train typing commands. Zsh users can try `history | sed -e 's/\s*\S*\s*\(.*\)\s*/\1/' | awk '{$1=$1};NF' > myfile.txt` and then `typespeed myfile.txt`.
