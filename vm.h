#ifndef _BEAN_VM_H
#define _BEAN_VM_H

typedef enum {
  OP_BEAN_PUSH_NIL=2,
  OP_BEAN_PUSH_FALSE,
  OP_BEAN_PUSH_TRUE,
  OP_BEAN_PUSH_STR,
  OP_BEAN_PUSH_NUM,
  OP_BEAN_BINARY_OP,
  OP_BEAN_VARIABLE_GET,
  OP_BEAN_VARIABLE_DEFINE,
  OP_BEAN_SET_ARG,
  OP_BEAN_IN_STACK,
  OP_BEAN_RETURN,
  OP_BEAN_FUNCTION_DEFINE,
  OP_BEAN_SET_FUNCTION_NAME,
  OP_BEAN_FUNCTION_PUSH_SCOPE,
  OP_BEAN_FUNCTION_CALL0,
  OP_BEAN_FUNCTION_CALL1,
  OP_BEAN_FUNCTION_CALL2,
  OP_BEAN_FUNCTION_CALL3,
  OP_BEAN_FUNCTION_CALL5,
  OP_BEAN_FUNCTION_CALL6,
  OP_BEAN_FUNCTION_CALL7,
  OP_BEAN_FUNCTION_CALL8,
  OP_BEAN_FUNCTION_CALL9,
  OP_BEAN_FUNCTION_CALL10,
  OP_BEAN_FUNCTION_CALL11,
  OP_BEAN_FUNCTION_CALL12,
  OP_BEAN_FUNCTION_CALL13,
  OP_BEAN_FUNCTION_CALL14,
  OP_BEAN_FUNCTION_CALL15,
  OP_BEAN_ARRAY_PUSH,
  OP_BEAN_ARRAY_ITEM,
  OP_BEAN_HASH_NEW,
  OP_BEAN_HASH_KEY,
  OP_BEAN_HASH_VALUE,
  OP_BEAN_HANDLE_PREFIX,
  OP_BEAN_HANDLE_SUFFIX,
  OP_BEAN_BINARY_OP_WITH_ASSIGN,
  OP_BEAN_UNARY,
  OP_BEAN_DROP,
  OP_BEAN_JUMP,
  OP_BEAN_JUMP_FALSE,
  OP_BEAN_JUMP_FALSE_PUSH_BACK,
  OP_BEAN_JUMP_TRUE,
  OP_BEAN_JUMP_TRUE_PUSH_BACK,
  OP_BEAN_LOOP,
  OP_BEAN_LOOP_CONTINUE,
  OP_BEAN_LOOP_BREAK,
  OP_BEAN_NEW_SCOPE,
  OP_BEAN_END_SCOPE,
  OP_BEAN_NEW_FUNCTION_SCOPE,
  OP_BEAN_CREATE_FRAME,
  OP_BEAN_DROP_FRAME,
  OP_BEAN_SELF_GET,
  OP_BEAN_NEXT_STEP,
  OP_BEAN_HASH_ATTRIBUTE_ASSIGN,
  OP_BEAN_INDEX_OR_ATTRIBUTE_ASSIGN
} OpCode;

int executeInstruct();

#endif
