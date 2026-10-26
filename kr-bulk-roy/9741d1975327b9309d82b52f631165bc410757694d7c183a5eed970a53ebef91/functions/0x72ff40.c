
void FUN_0072ff40(FILE *param_1,int param_2)

{
  int *piVar1;
  int in_ECX;
  
  if (0 < param_2) {
    do {
      _fprintf(param_1,"    ");
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  piVar1 = (int *)(in_ECX + 0x20);
  if (0xf < *(uint *)(in_ECX + 0x34)) {
    piVar1 = (int *)*piVar1;
  }
  _fprintf(param_1,"<%s>",piVar1);
  return;
}

