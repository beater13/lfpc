package lexer

import "Lexer/tokens"


type Lexer struct {
	input        string
	position     int
	nextPosition int
	ch           byte
}

//New function
func New(input string) *Lexer {
	lex := &Lexer{input: input}
	lex.readChar()
	return lex
}

//NextToken fun
func (lex *Lexer) NextToken() token.Token {
	var tk token.Token

	lex.skipWhitespace()

	switch lex.ch {

	case '=':
		tk = newToken(token.EQUAL, lex.ch)

	case '*':
		tk = newToken(token.MULT, lex.ch)

	case '/':
		tk = newToken(token.DIVIDE, lex.ch)

	case '+':
		tk = newToken(token.PLUS, lex.ch)

	case '-':
		tk = newToken(token.MINUS, lex.ch)

	case '>':
		tk = newToken(token.BIGGER, lex.ch)

	case '<':
		tk = newToken(token.SMALLER, lex.ch)

	case ';':
		tk = newToken(token.SEMICOLON, lex.ch)

	case ',':
		tk = newToken(token.COMMA, lex.ch)

	case '(':
		tk = newToken(token.LPAR, lex.ch)

	case ')':
		tk = newToken(token.RPAR, lex.ch)

	case '{':
		tk = newToken(token.LBRACE, lex.ch)

	case '}':
		tk = newToken(token.RBRACE, lex.ch)

	case 0:
		tk.Input = ""
		tk.Type = token.EOF
	default:
		if isLetter(lex.ch) {
			tk.Input = lex.readIdentifier()
			tk.Type = token.LookupIdent(tk.Input)
			return tk
		} else if isDigit(lex.ch) {
			tk.Type = token.INT
			tk.Input = lex.readNumber()
			return tk
		} else {
			tk = newToken(token.TNT, lex.ch)
		}
	}
	lex.readChar()
	return tk
}

func (lex *Lexer) skipWhitespace() {
	for lex.ch == ' ' || lex.ch == '\t' || lex.ch == '\n' || lex.ch == '\r' {
		lex.readChar()
	}
}

func (lex *Lexer) readChar() {
	if lex.nextPosition >= len(lex.input) {
		lex.ch = 0
	} else {
		lex.ch = lex.input[lex.nextPosition]
	}
	lex.position = lex.nextPosition
	lex.nextPosition++
}

func (lex *Lexer) readIdentifier() string {
	position := lex.position
	for isLetter(lex.ch) {
		lex.readChar()
	}
	return lex.input[position:lex.position]
}

func isLetter(ch byte) bool {
	return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_'
}

func (lex *Lexer) readNumber() string {
	position := lex.position
	for isDigit(lex.ch) {
		l.readChar()
	}
	return lex.input[position:lex.position]
}

func isDigit(ch byte) bool {
	return '0' <= ch && ch <= '9'
}

func newToken(tokenType token.TokenType, ch byte) token.Token {
	return token.Token{Type: tokenType, Input: string(ch)}
}
