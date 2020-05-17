package reader

import (
	"bufio"
	"compiler/lexer"
	"fmt"
	"go/token"
	"io"
)

func Start(in io.Reader, out io.Writer) {
	scanner := bufio.NewScanner(in)

	for {
		scanned := scanner.Scan()
		if !scanned {
			return
		}

		line := scanner.Text()
		lex := lexer.New(line)

		for tk := lex.NextToken(); tk.Type != token.EOF; tk = lex.NextToken() {
			fmt.Printf("%+v\n", tk)
		}
	}
}
