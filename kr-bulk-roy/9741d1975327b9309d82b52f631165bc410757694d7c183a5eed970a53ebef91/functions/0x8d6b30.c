
undefined4 FUN_008d6b30(void)

{
  char in_AL;
  
  if ((((in_AL != ' ') && (in_AL != '\t')) && (in_AL != '\r')) &&
     (((in_AL != '\n' && (in_AL != '\f')) && (in_AL != '\0')))) {
    return 0;
  }
  return 1;
}

