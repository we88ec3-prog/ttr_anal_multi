
void FUN_00732e00(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  
  iVar2 = *(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1);
  do {
    if (iVar2 != 0) {
      return;
    }
    iVar2 = FUN_00733980(param_1);
    if (iVar2 < 1) {
      if (in_ECX == (int *)0x0) {
        return;
      }
      while (iVar2 = (**(code **)(*in_ECX + 0x10))(), iVar2 == 0) {
        in_ECX = (int *)in_ECX[4];
        if (in_ECX == (int *)0x0) {
          return;
        }
      }
      iVar2 = (**(code **)(*in_ECX + 0x10))();
      if (iVar2 == 0) {
        return;
      }
      FUN_00732010(0xe,0,0,0);
      return;
    }
    FUN_00429630(1,iVar2);
    if (iVar2 == 0x3e) {
      uVar1 = param_2[4] - 2;
      if ((uint)param_2[4] <= uVar1) {
LAB_00732ed7:
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid string position");
      }
      puVar3 = param_2;
      if (0xf < (uint)param_2[5]) {
        puVar3 = (undefined4 *)*param_2;
      }
      if (*(char *)((int)puVar3 + uVar1) == '-') {
        uVar1 = param_2[4] - 3;
        if ((uint)param_2[4] <= uVar1) goto LAB_00732ed7;
        puVar3 = param_2;
        if (0xf < (uint)param_2[5]) {
          puVar3 = (undefined4 *)*param_2;
        }
        if (*(char *)((int)puVar3 + uVar1) == '-') {
          return;
        }
      }
    }
    iVar2 = *(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1);
  } while( true );
}

