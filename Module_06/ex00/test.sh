#!/bin/bash

# Цвета для вывода
BLUE=$(tput setaf 4)
CYAN=$(tput setaf 6)
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
YELLOW=$(tput setaf 3)
RESET=$(tput sgr0)

EXEC="./convert"

# Проверяем, существует ли исполняемый файл
if [ ! -f "$EXEC" ]; then
    echo -e "${RED}Ошибка: $EXEC не найден!${RESET}"
    echo -e "${YELLOW}Попробуй сначала скомпилировать: make re${RESET}"
    exit 1
fi

echo "${BLUE}Running tests for ScalarConverter...${RESET}"
echo "========================================="

# Тестовые входные данные и ожидаемые результаты
test_inputs=(
    "0"
    "-42"
    "42"
    "2147483647"
    "-2147483648"
    "nan"
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
)

expected_outputs=(
    "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0"
    "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0"
    "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
    "char: impossible\nint: 2147483647\nfloat: 2147483648.0f\ndouble: 2147483647.0"  # исправленный float
    "char: impossible\nint: -2147483648\nfloat: -2147483648.0f\ndouble: -2147483648.0"
    "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan"
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
)

success=0
fail=0

for i in "${!test_inputs[@]}"; do
    input="${test_inputs[$i]}"
    expected="${expected_outputs[$i]}"

    echo -e "${CYAN}Test input: \"$input\"${RESET}"
    
    # Запускаем тест и обрабатываем переносы строк, пробелы и символы `\r`
    output=$($EXEC "$input" 2>&1 | tr -d '\r' | sed 's/[[:space:]]*$//')

    # Проверяем совпадение с ожидаемым результатом
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



# # Цвета для вывода
# BLUE=$(tput setaf 4)
# CYAN=$(tput setaf 6)
# GREEN=$(tput setaf 2)
# RED=$(tput setaf 1)
# YELLOW=$(tput setaf 3)
# RESET=$(tput sgr0)

# EXEC="./convert"

# # Проверяем, существует ли исполняемый файл
# if [ ! -f "$EXEC" ]; then
#     echo -e "${RED}Ошибка: $EXEC не найден!${RESET}"
#     echo -e "${YELLOW}Попробуй сначала скомпилировать: make re${RESET}"
#     exit 1
# fi

# echo "${BLUE}Running tests for ScalarConverter...${RESET}"
# echo "========================================="


# # Тестовые входные данные и ожидаемые результаты
# test_inputs=(
#     "0"
#     "-42"
#     "42"
#     "2147483647"
#     "-2147483648"
#     "nan"
#     "+inf"
#     "-inf"
#     "42.0f"
#     "0.0"
#     "-4.2"
#     "4.2"
#     "42.0"
#     "nanf"
#     "+inff"
#     "-inff"
#     "'a'"
#     "'Z'"
#     "'*'"
#     "' '"
#     ""
#     "   "
#     "not_a_number"
#     "99999999999999999999999999999999999999999"
# )

# expected_outputs=(
#     "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0"
#     "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0"
#     "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
#     "char: impossible\nint: 2147483647\nfloat: 2147483647.0f\ndouble: 2147483647.0"
#     "char: impossible\nint: -2147483648\nfloat: -2147483648.0f\ndouble: -2147483648.0"
#     "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan"
#     "char: impossible\nint: impossible\nfloat: inff\ndouble: inf"
#     "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf"
#     "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
#     "char: impossible\nint: impossible\nfloat: 0.0f\ndouble: 0.0"
#     "char: impossible\nint: impossible\nfloat: -4.2f\ndouble: -4.2"
#     "char: impossible\nint: impossible\nfloat: 4.2f\ndouble: 4.2"
#     "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
#     "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan"
#     "char: impossible\nint: impossible\nfloat: inff\ndouble: inf"
#     "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf"
#     "char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0"
#     "char: 'Z'\nint: 90\nfloat: 90.0f\ndouble: 90.0"
#     "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
#     "char: ' '\nint: 32\nfloat: 32.0f\ndouble: 32.0"
#     "Invalid Type!"
#     "Invalid Type!"
#     "Invalid Type!"
#     "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible"
# )

# success=0
# fail=0

# for i in "${!test_inputs[@]}"; do
#     input="${test_inputs[$i]}"
#     expected="${expected_outputs[$i]}"

#     echo -e "${CYAN}Test input: \"$input\"${RESET}"
#     output=$($EXEC "$input" 2>&1 | tr -d '\r') # Удаляем возможные символы `\r` для корректного сравнения

#     if [ "$output" == "$expected" ]; then
#         echo -e "Result: ${GREEN}OK ✅${RESET}"
#         ((success++))
#     else
#         echo -e "Result: ${RED}FAIL ❌${RESET}"
#         echo -e "${YELLOW}Expected:${RESET}\n$expected"
#         echo -e "${RED}Got:${RESET}\n$output"
#         ((fail++))
#     fi

#     echo "-----------------------------------------"
# done

# echo -e "${BLUE}Test Summary:${RESET}"
# echo -e "✅ ${GREEN}Success:${RESET} $success"
# echo -e "❌ ${RED}Failed:${RESET} $fail"

# exit $fail




# BLUE=$(tput setaf 4)
# CYAN=$(tput setaf 6)
# GREEN=$(tput setaf 2)
# RED=$(tput setaf 1)
# YELLOW=$(tput setaf 3)
# RESET=$(tput sgr0)

# echo "${BLUE}Running tests for ScalarConverter...${RESET}"
# echo "========================================="

# test_inputs=("0" "-42" "42" "2147483647" "-2147483648" "nan" "+inf" "-inf" "42.0f")
# expected_outputs=(
#     "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0"
#     "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0"
#     "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
#     "char: impossible\nint: 2147483647\nfloat: 2147483647.0f\ndouble: 2147483647.0"
#     "char: impossible\nint: -2147483648\nfloat: -2147483648.0f\ndouble: -2147483648.0"
#     "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan"
#     "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf"
#     "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf"
#     "char: impossible\nint: impossible\nfloat: 42.0f\ndouble: 42.0"
# )

# success=0
# fail=0

# for i in "${!test_inputs[@]}"; do
#     input="${test_inputs[$i]}"
#     expected="${expected_outputs[$i]}"

#     echo "${CYAN}Test input: \"$input\"${RESET}"
#     output=$(./scalar_converter "$input" 2>&1)

#     if [ "$output" == "$expected" ]; then
#         echo -e "Result: ${GREEN}OK ✅${RESET}"
#         ((success++))
#     else
#         echo -e "Result: ${RED}FAIL ❌${RESET}"
#         echo -e "${YELLOW}Expected:${RESET}\n$expected"
#         echo -e "${RED}Got:${RESET}\n$output"
#         ((fail++))
#     fi

#     echo "-----------------------------------------"
# done

# echo -e "${BLUE}Test Summary:${RESET}"
# echo -e "✅ ${GREEN}Success:${RESET} $success"
# echo -e "❌ ${RED}Failed:${RESET} $fail"



# EXEC="./convert"
# TESTS=(
#   "0"
#   "-42"
#   "42"
#   "2147483647"
#   "-2147483648"
#   "0.0"
#   "-4.2"
#   "4.2"
#   "42.0"
#   "0.0f"
#   "-4.2f"
#   "4.2f"
#   "42.0f"
#   "nan"
#   "nanf"
#   "+inf"
#   "-inf"
#   "+inff"
#   "-inff"
#   "'a'"
#   "'Z'"
#   "'*'"
#   "' '"
#   ""
#   "   "
#   "not_a_number"
# )

# echo "Running tests for ScalarConverter..."

# for test in "${TESTS[@]}"; do
#   echo "---------------------------------"
#   echo "Test input: \"$test\""
#   OUTPUT=$($EXEC "$test" 2>&1)
#   echo "$OUTPUT"
#   echo "---------------------------------"
# done

# EXPECTED_RESULTS=(
#   "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0"
#   "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0"
#   "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
#   "char: impossible\nint: 2147483647\nfloat: 2147483647.0f\ndouble: 2147483647.0"
#   "char: impossible\nint: -2147483648\nfloat: -2147483648.0f\ndouble: -2147483648.0"
#   "char: impossible\nint: impossible\nfloat: 0.0f\ndouble: 0.0"
#   "char: impossible\nint: impossible\nfloat: -4.2f\ndouble: -4.2"
#   "char: impossible\nint: impossible\nfloat: 4.2f\ndouble: 4.2"
#   "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
#   "char: impossible\nint: impossible\nfloat: 0.0f\ndouble: 0.0"
#   "char: impossible\nint: impossible\nfloat: -4.2f\ndouble: -4.2"
#   "char: impossible\nint: impossible\nfloat: 4.2f\ndouble: 4.2"
#   "char: impossible\nint: impossible\nfloat: 42.0f\ndouble: 42.0"
#   "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan"
#   "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan"
#   "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf"
#   "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf"
#   "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf"
#   "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf"
#   "char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0"
#   "char: 'Z'\nint: 90\nfloat: 90.0f\ndouble: 90.0"
#   "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
#   "char: ' '\nint: 32\nfloat: 32.0f\ndouble: 32.0"
#   "Invalid Type!"
#   "Invalid Type!"
#   "Invalid Type!"
# )

# for i in "${!TESTS[@]}"; do
#   OUTPUT=$($EXEC "${TESTS[$i]}" 2>&1)
#   if [[ "$OUTPUT" == "${EXPECTED_RESULTS[$i]}" ]]; then
#     echo -e "Test ${i} [${TESTS[$i]}]: \e[32mOK\e[0m"
#   else
#     echo -e "Test ${i} [${TESTS[$i]}]: \e[31mFAIL\e[0m"
#     echo "Expected:"
#     echo -e "${EXPECTED_RESULTS[$i]}"
#     echo "Got:"
#     echo -e "$OUTPUT"
#   fi
# done
