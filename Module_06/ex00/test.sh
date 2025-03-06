#!/bin/bash

BLUE=$(tput setaf 4)
CYAN=$(tput setaf 6)
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
YELLOW=$(tput setaf 3)
RESET=$(tput sgr0)

EXEC="./convert"

if [ ! -f "$EXEC" ]; then
    echo -e "${RED}Error: $EXEC not found!${RESET}"
    echo -e "${YELLOW}Try compiling first: make re${RESET}"
    exit 1
fi

echo "${BLUE}Running tests for ScalarConverter...${RESET}"
echo "========================================="

test_inputs=(
    "0"
    "-42"
    "42"
    "2147483647"
    "-2147483648"
    "nan"
    "inf"
    "+inf"
    "-inf"
    "42.0f"
    "0.0"
    "0.0f"
    "-4.2"
    "-4.2f"
    "4.2"
    "42.0"
    "nanf"
    "+inff"
    "-inff"
    "'a'"
    "'Z'"
    "'*'"
    "' '"
    ""
    "   "
    "not_a_number"
    "99999999999999999999999999999999999999999"
    "42.f"
    "0.f"
    ".f"
    "..f"
    "42.."
    "42.f0"
    "42.0.0f"
    "1e309"
    "-1e309"
    "2.22507e-308"   # DBL_MIN
    "1.79769e+308"   # DBL_MAX
    "2.22045e-16"    # DBL_EPSILON
)

expected_outputs=(
    "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0"
    "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0"
    "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
    "char: impossible\nint: 2147483647\nfloat: 2147483648.0f\ndouble: 2147483647.0"
    "char: impossible\nint: -2147483648\nfloat: -2147483648.0f\ndouble: -2147483648.0"
    "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan"
    "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf"
    "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf"
    "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf"
    "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
    "char: impossible\nint: impossible\nfloat: 0.0f\ndouble: 0.0"
    "char: impossible\nint: impossible\nfloat: 0.0f\ndouble: 0.0"
    "char: impossible\nint: impossible\nfloat: -4.2f\ndouble: -4.2"
    "char: impossible\nint: impossible\nfloat: -4.2f\ndouble: -4.2"
    "char: impossible\nint: impossible\nfloat: 4.2f\ndouble: 4.2"
    "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
    "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan"
    "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf"
    "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf"
    "char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0"
    "char: 'Z'\nint: 90\nfloat: 90.0f\ndouble: 90.0"
    "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
    "char: ' '\nint: 32\nfloat: 32.0f\ndouble: 32.0"
    "Invalid Type!"
    "Invalid Type!"
    "Invalid Type!"
    "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible"
    "Invalid Type!"
    "Invalid Type!"
    "Invalid Type!"
    "Invalid Type!"
    "Invalid Type!"
    "Invalid Type!"
    "Invalid Type!"
    "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf"
    "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf"
    "char: impossible\nint: impossible\nfloat: 0.0f\ndouble: 2.22507e-308" # DBL_MIN
    "char: impossible\nint: impossible\nfloat: impossible\ndouble: 1.79769e+308" # DBL_MAX
    "char: impossible\nint: impossible\nfloat: 0.0f\ndouble: 2.22045e-16" # DBL_EPSILON
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