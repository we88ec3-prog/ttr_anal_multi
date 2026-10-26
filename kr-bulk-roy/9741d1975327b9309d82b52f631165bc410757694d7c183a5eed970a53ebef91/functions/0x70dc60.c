
undefined4 FUN_0070dc60(int *param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  ushort *puVar4;
  
  if (param_1 == (int *)0x0) {
    param_3[4] = 0xffffffff;
    param_3[5] = 0xffffffff;
    *param_3 = 8;
    param_3[2] = 0xff;
  }
  else {
    iVar1 = *(byte *)((int)param_1 + 0x32) - 1;
    if (-1 < iVar1) {
      puVar4 = (ushort *)((int)param_1 + iVar1 * 2 + 0xac);
      do {
        if (param_2 == *(int *)(*(int *)(*param_1 + 0x18) + (uint)*puVar4 * 0xc)) {
          if (-1 < iVar1) {
            param_3[4] = 0xffffffff;
            param_3[5] = 0xffffffff;
            *param_3 = 6;
            param_3[2] = iVar1;
            if ((param_4 == 0) && (piVar3 = (int *)param_1[5], piVar3 != (int *)0x0)) {
              while (iVar1 < (int)(uint)*(byte *)(piVar3 + 2)) {
                piVar3 = (int *)*piVar3;
                if (piVar3 == (int *)0x0) {
                  return 6;
                }
              }
              *(undefined1 *)((int)piVar3 + 9) = 1;
            }
            return 6;
          }
          break;
        }
        puVar4 = puVar4 + -1;
        iVar1 = iVar1 + -1;
      } while (-1 < iVar1);
    }
    iVar1 = FUN_0070dc60(param_1[2],param_2,param_3,0);
    if (iVar1 != 8) {
      uVar2 = FUN_0070db50(param_1,param_2,param_3);
      param_3[2] = uVar2;
      *param_3 = 7;
      return 7;
    }
  }
  return 8;
}

