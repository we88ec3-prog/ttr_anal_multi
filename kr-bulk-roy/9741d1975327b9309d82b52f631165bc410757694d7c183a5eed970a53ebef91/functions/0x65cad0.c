
void FUN_0065cad0(uint *param_1,uint param_2,uint *param_3,uint param_4)

{
  char *in_EDX;
  uint uVar1;
  
  while ((param_1 != param_3 || (param_2 != param_4))) {
    uVar1 = 1 << ((byte)param_2 & 0x1f);
    if (*in_EDX == '\0') {
      *param_1 = *param_1 & ~uVar1;
    }
    else {
      *param_1 = *param_1 | uVar1;
    }
    if (param_2 < 0x1f) {
      param_2 = param_2 + 1;
    }
    else {
      param_1 = param_1 + 1;
      param_2 = 0;
    }
  }
  return;
}

