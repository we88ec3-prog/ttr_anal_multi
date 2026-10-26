
int * FUN_007c6700(int *param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == -0x5eed0000) {
    uVar5 = 0;
    iVar1 = param_1[0x37] - param_1[0x36] >> 2;
    if (0 < iVar1) {
      do {
        if (uVar5 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
          uVar3 = *(undefined4 *)(param_1[0x36] + uVar5 * 4);
        }
        else {
          uVar3 = 0;
        }
        piVar2 = (int *)FUN_007c6700(uVar3,param_2);
        if (piVar2 != (int *)0x0) {
          return piVar2;
        }
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < iVar1);
    }
    iVar1 = (**(code **)(*param_1 + 0x34))();
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        uVar3 = (**(code **)(*param_1 + 0x30))(iVar4,param_2);
        piVar2 = (int *)FUN_007c6700(uVar3);
        if (piVar2 != (int *)0x0) {
          return piVar2;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  else if (iVar1 == -0x5edf0000) {
    iVar1 = 0;
    iVar4 = param_1[0x1f] - param_1[0x1e] >> 2;
    if (0 < iVar4) {
      do {
        piVar2 = (int *)FUN_007c6700(*(undefined4 *)(param_1[0x1e] + iVar1 * 4),param_2);
        if (piVar2 != (int *)0x0) {
          return piVar2;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < iVar4);
    }
    uVar5 = 0;
    iVar1 = param_1[0x23] - param_1[0x22] >> 2;
    if (0 < iVar1) {
      while( true ) {
        if ((uint)(param_1[0x23] - param_1[0x22] >> 2) <= uVar5) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        piVar2 = (int *)FUN_007c6700(*(undefined4 *)(param_1[0x22] + uVar5 * 4),param_2);
        if (piVar2 != (int *)0x0) break;
        uVar5 = uVar5 + 1;
        if (iVar1 <= (int)uVar5) {
          return (int *)0x0;
        }
      }
      return piVar2;
    }
  }
  else if (iVar1 == -0x5edc0000) {
    piVar2 = param_1 + 2;
    if (0xf < (uint)param_1[7]) {
      piVar2 = (int *)*piVar2;
    }
    iVar1 = __stricmp((char *)piVar2,param_2);
    if (iVar1 == 0) {
      return param_1;
    }
  }
  return (int *)0x0;
}

