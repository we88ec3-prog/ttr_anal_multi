
void FUN_00597040(int param_1,int param_2,undefined1 param_3,undefined1 param_4)

{
  int *piVar1;
  int iVar2;
  
  if (((*(uint *)(param_2 + 0x28) >> 8 & 1) == 0) && (*(int *)(param_1 + 0xf0) == 0)) {
    iVar2 = 0;
    piVar1 = (int *)(param_1 + 0xc4);
    while (FUN_00848020(&param_2), param_1 == *piVar1) {
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 4;
      if (2 < iVar2) {
        return;
      }
    }
    if (param_1 != -0x10) {
      if (iVar2 == 0) {
        *(undefined1 *)(param_1 + 0x14) = param_3;
        *(undefined1 *)(param_1 + 0x15) = param_4;
        *(undefined1 *)(param_1 + 0x16) = 1;
        FUN_00597250(param_1);
        FUN_00596ec0(param_1,param_2);
      }
      else {
        if (iVar2 == 1) {
          *(undefined1 *)(param_1 + 0x14) = param_3;
          *(undefined1 *)(param_1 + 0x15) = param_4;
          *(undefined1 *)(param_1 + 0x16) = 1;
          *(undefined1 *)(param_1 + 0x18) = 0;
          *(undefined4 *)(param_1 + 0x1c) = 0;
          FUN_00596ec0(param_1,param_2);
          return;
        }
        if (iVar2 == 2) {
          *(undefined1 *)(param_1 + 0x16) = 1;
          FUN_00596ec0(param_1,param_2);
          return;
        }
      }
    }
  }
  return;
}

