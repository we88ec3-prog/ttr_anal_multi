
undefined4 FUN_00731560(char param_1,int param_2)

{
  char *in_EAX;
  int _C;
  int _C_00;
  char *in_ECX;
  int iVar1;
  
  if ((in_EAX == (char *)0x0) || (*in_EAX == '\0')) {
    return 0;
  }
  if (param_1 == '\0') {
    do {
      if (*in_ECX == '\0') {
        return 1;
      }
      if (*in_EAX != *in_ECX) break;
      in_EAX = in_EAX + 1;
      in_ECX = in_ECX + 1;
    } while (*in_EAX != '\0');
  }
  else {
    iVar1 = (int)in_EAX - (int)in_ECX;
    do {
      if (*in_ECX == '\0') {
        return 1;
      }
      _C = (int)in_ECX[iVar1];
      if ((param_2 != 1) || (_C < 0x80)) {
        _C = _tolower(_C);
      }
      _C_00 = (int)*in_ECX;
      if ((param_2 != 1) || (_C_00 < 0x80)) {
        _C_00 = _tolower(_C_00);
      }
    } while ((_C == _C_00) && (in_ECX = in_ECX + 1, in_ECX[iVar1] != '\0'));
  }
  if (*in_ECX == '\0') {
    return 1;
  }
  return 0;
}

