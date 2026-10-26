
char * FUN_00703950(int param_1)

{
  char *in_EAX;
  char *in_ECX;
  int iVar1;
  
  if ((*in_EAX == '\0') || (in_EAX[1] == '\0')) {
    FUN_006f5f30(*(undefined4 *)(param_1 + 8),"unbalanced pattern");
  }
  if (*in_ECX == *in_EAX) {
    iVar1 = 1;
    while (in_ECX = in_ECX + 1, in_ECX < *(char **)(param_1 + 4)) {
      if (*in_ECX == in_EAX[1]) {
        iVar1 = iVar1 + -1;
        if (iVar1 == 0) {
          return in_ECX + 1;
        }
      }
      else if (*in_ECX == *in_EAX) {
        iVar1 = iVar1 + 1;
      }
    }
  }
  return (char *)0x0;
}

