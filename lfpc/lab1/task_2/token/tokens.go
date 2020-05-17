package tokens

type TokenType string

const (
	TNT = "TNT"
	EOF  = "EOF"

	IDENTIFS = "IDENT"
	INT      = "INT"

	// Operators
	EQUAL  = "="
	MULT   = "*"
	DIVIDE = "/"
	PLUS   = "+"
	MINUS  = "-"
	BIGGER = ">"
	SMALLER   = "<"

	// Delimiters
	SEMICOLON = ";"
	COMMA     = ","

	LPAR   = "("
	RPAR   = ")"
	LBRACE = "["
	RBRACE = "]"

	// Keywords
	FUN    = "FUNCTION"
	LET    = "LET"
	IF     = "IF"
	ELSE   = "ELSE"
	TRUE   = "TRUE"
	FALSE  = "FALSE"
	RETURN = "RETURN"
	NOT    = "NOT"
)

type Token struct {
	Type  TokenType
	Input string
}

var keywords = map[string]TokenType{
	"function": FUN,
	"let":      LET,
	"if":       IF,
	"else":     ELSE,
	"true":     TRUE,
	"false":    FALSE,
	"return":   RETURN,
	"not":      NOT,
}

func LookupIdent(ident string) TokenType {
	if tk, ok := keywords[ident]; ok {
		return tk
	}
	return IDENTIFS
}
