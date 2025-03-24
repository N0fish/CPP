#!/bin/bash

BLUE=$(tput setaf 4)
CYAN=$(tput setaf 6)
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
YELLOW=$(tput setaf 3)
RESET=$(tput sgr0)

EXEC="./RPN"

if [ ! -f "$EXEC" ]; then
    echo -e "${RED}Error: $EXEC not found!${RESET}"
    echo -e "${YELLOW}Try compiling first: make re${RESET}"
    exit 1
fi

echo "${BLUE}Running tests for RPN...${RESET}"
echo "========================================="

test_inputs=(
	"8 9 * 9 - 9 - 9 - 4 - 1 +"      # 42
    "7 7 * 7 -"                      # 42
    "1 2 * 2 / 2 * 2 4 - +"          # 0
    "3 4 +"                          # 7
    "5 1 2 + 4 * + 3 -"              # 14
    "5 1 2 + 4 * + 0003 -"           # Invalid expression
    ""                               # Invalid expression
    "1 +"                            # Not enough operands
    "3 4 5 +"                        # Too many operands
    "4 0 /"                          # Division by zero
    "( 1 + 1 )"                      # Invalid symbols
    "10 2 +"                         # Too large number
    "2 3 &"                          # Invalid operator
    "2 a +"                          # Invalid token
    "0 0 +"                          # 0
)

expected_outputs=(
	"✔️ Result: 42"
    "✔️ Result: 42"
    "✔️ Result: 0"
    "✔️ Result: 7"
    "✔️ Result: 14"
    "✖️ Error: Invalid expression"
    "✖️ Error: Invalid expression"
    "✖️ Error: Not enough operands"
    "✖️ Error: Too many operands"
    "✖️ Error: Division by zero"
    "✖️ Error: Invalid expression"
    "✖️ Error: Invalid expression"
    "✖️ Error: Invalid expression"
    "✖️ Error: Invalid expression"
    "✔️ Result: 0"
)

success=0
fail=0

for i in "${!test_inputs[@]}"; do
    input="${test_inputs[$i]}"
    expected="${expected_outputs[$i]}"

    echo -e "${CYAN}Test input: \"$input\"${RESET}"
    
    output=$($EXEC "$input" 2>&1 | tr -d '\r' | sed 's/[[:space:]]*$//')

    if diff -w <(echo -e "$expected") <(echo -e "$output") >/dev/null; then
        echo -e "Result: ${GREEN}OK ✅${RESET}"
        echo -e "${YELLOW}Output:${RESET}\n$output"
        ((success++))
    else
        echo -e "Result: ${RED}FAIL ❌${RESET}"
        echo -e "${YELLOW}Expected:${RESET}\n$expected"
        echo -e "${RED}Got:${RESET}\n$output"
        ((fail++))
    fi

    echo "-----------------------------------------"
done

echo -e "${BLUE}Test Summary:${RESET}"
echo -e "✅ ${GREEN}Success:${RESET} $success"
echo -e "❌ ${RED}Failed:${RESET} $fail"

exit $fail