
/* WARNING: Removing unreachable block (ram,0x0066d6a2) */
/* WARNING: Removing unreachable block (ram,0x0066d6b3) */
/* WARNING: Removing unreachable block (ram,0x0066d6b5) */

int * FUN_0066d660(int *param_1,int *param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (param_1 != param_2) {
    iVar3 = param_2[1] - *param_2 >> 0x1f;
    iVar4 = (param_2[1] - *param_2) / 0x60 + iVar3;
    uVar5 = iVar4 - iVar3;
    if (iVar4 == iVar3) {
      if (*param_1 != param_1[1]) {
        param_1[1] = *param_1;
        return param_1;
      }
    }
    else {
      uVar1 = (param_1[1] - *param_1) / 0x60;
      if (uVar5 <= uVar1) {
        FUN_0066dac0(param_2[1]);
        param_1[1] = ((param_2[1] - *param_2) / 0x60) * 0x60 + *param_1;
        return param_1;
      }
      if (uVar5 <= (uint)((param_1[2] - *param_1) / 0x60)) {
        FUN_0066dac0(uVar1 * 0x60 + *param_2);
        iVar3 = FUN_00508080(param_2[1],param_2);
        param_1[1] = iVar3;
        return param_1;
      }
      if (*param_1 != 0) {
        FUN_0089120c(*param_1);
      }
      cVar2 = FUN_00508040();
      if (cVar2 != '\0') {
        iVar3 = FUN_00508080(param_2[1],param_2);
        param_1[1] = iVar3;
      }
    }
  }
  return param_1;
}

