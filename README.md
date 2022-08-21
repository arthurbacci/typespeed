# typespeed

Really simple typing speed (CPS) calculator using ANSI C

## Usage

```
typespeed [file]
```

`file` is the file the program will take random lines from for you to type, it can be anything. You can try giving it a book, or maybe your `~/bash_history` if you want to train typing commands. Zsh users can try `history | sed -e 's/\s*\S*\s*\(.*\)\s*/\1/' | awk '{$1=$1};NF' > myfile.txt` and then `typespeed myfile.txt`.

## Why not `cat myfile.txt | typespeed -`?

`typespeed` works by seeking the file, it never loads the entire file, only line by line (making it very memory friendly, it doesn't even needs to use the heap). Pipes aren't seekable, the only way of doing so would be to read them until the end, put it into a buffer, and then seek into it. Since the only advantage of pipes is laziness, there's no sense in doing this.
