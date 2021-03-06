#include <math.h>
#include "bstring.h"
#include "berror.h"
#include "bparser.h"
#include "bnumber.h"

static TValue * primitive_Number_toExponential(bean_State * B, TValue * thisVal, TValue * args UNUSED, int argc UNUSED) {
  assert_with_message(ttisnumber(thisVal), "The calling object must be number.");
  char buff[MAX_STRING_BUFFER];
  TValue * ret = TV_MALLOC;
  bean_Number value = nvalue(thisVal);
  sprintf(buff, "%e", value);

  TString * ts = beanS_newlstr(B, buff, strlen(buff));
  setsvalue(ret, ts);
  return ret;
}

static TValue * primitive_Number_toFixed(bean_State * B, TValue * thisVal, TValue * args, int argc) {
  assert_with_message(ttisnumber(thisVal), "The calling object must be number.");

  char * buff;
  char * template = "%%.%df";
  char * format = malloc(sizeof(char) * strlen(template));
  if (argc >= 1) {
    assert_with_message(ttisnumber(&args[0]), "The paramter which you passed must be a number.");
  }

  long bit = (long)fabs(argc > 0 ? nvalue(&args[0]) : 2);
  assert_with_message(bit > 0, "The paramter which you passed must be a positive number.");
  TValue * ret = TV_MALLOC;
  sprintf(format, template, bit);
  bean_Number value = nvalue(thisVal);

  /* Auto enlarge if space not enough */
  size_t i = 0;
  size_t size = MAX_STRING_BUFFER;
  size_t result;

  do {
    size = size * (++i);
    buff = malloc(size);
    result = snprintf(buff, size, format, value);
  } while(result >= size);

  TString * ts = beanS_newlstr(B, buff, strlen(buff));
  setsvalue(ret, ts);
  return ret;
}

TValue * init_Number(bean_State * B) {
  global_State * G = B->l_G;
  TValue * proto = TV_MALLOC;
  Hash * h = init_hash(B);
  sethashvalue(proto, h);
  set_prototype_function(B, "toFixed", 7, primitive_Number_toFixed, hhvalue(proto));
  set_prototype_function(B, "toExponential", 13, primitive_Number_toExponential, hhvalue(proto));

  TValue * number = TV_MALLOC;
  setsvalue(number, beanS_newlstr(B, "Number", 6));
  hash_set(B, G->globalScope->variables, number, proto);

  return proto;
}
