
void FUN_0070dda0(int param_1,int param_2)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  int in_ECX;
  
  param_1 = param_1 - param_2;
  piVar1 = *(int **)(in_ECX + 0x30);
  iVar2 = *in_EAX;
  if ((iVar2 == 0xd) || (iVar2 == 0xe)) {
    param_1 = param_1 + 1;
    if (param_1 < 0) {
      param_1 = 0;
    }
    FUN_007121b0(param_1);
    if (1 < param_1) {
      iVar2 = piVar1[9] + param_1 + -1;
      if ((int)(uint)*(byte *)(*piVar1 + 0x4b) < iVar2) {
        if (0xf9 < iVar2) {
                    /* WARNING: Subroutine does not return */
          FUN_006ff130(piVar1[3],"function or expression too complex",
                       *(undefined4 *)(piVar1[3] + 0x10));
        }
        *(char *)(*piVar1 + 0x4b) = (char)iVar2;
      }
      piVar1[9] = piVar1[9] + param_1 + -1;
    }
  }
  else {
    if (iVar2 != 0) {
      FUN_00712630();
    }
    if (0 < param_1) {
      FUN_00712030();
      FUN_00711c00(param_1);
      return;
    }
  }
  return;
}

