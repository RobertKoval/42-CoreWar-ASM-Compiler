cmake_minimum_required(VERSION 3.9)
project(CoreWarASMv3 C)

set(CMAKE_C_STANDARD 11)

add_executable(CoreWarASMv3 src/asm_main.c includes/asm.h src/asm_error_manager.c
        src/asm_tokenizer.c src/asm_token_manager.c src/asm_validate_token.c
        src/asm_utillity.c src/asm_validate_token2.c src/asm_check_code_structure.c
        src/asm_check_operation.c src/asm_op.c src/asm_label_fix.c src/asm_write_file.c src/asm_check_symbols.c src/asm_op_argtype_checker.c)

target_link_libraries(CoreWarASMv3 ${CMAKE_SOURCE_DIR}/libft/libft.a)