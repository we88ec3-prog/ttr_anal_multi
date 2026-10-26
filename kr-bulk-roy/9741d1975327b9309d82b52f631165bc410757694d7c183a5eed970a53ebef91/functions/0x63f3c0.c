
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063f3c0(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int unaff_EDI;
  
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  uVar4 = DAT_00fdf3b4 - DAT_00fdf3b0 >> 2;
  uVar2 = 0;
  if (uVar4 != 0) {
    do {
      iVar5 = *(int *)(DAT_00fdf3b0 + uVar2 * 4);
      if (*(int *)(iVar5 + 8) == unaff_EDI) goto LAB_0063f40f;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar4);
  }
  iVar5 = 0;
LAB_0063f40f:
  iVar1 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
  if (iVar1 != 0) {
    for (piVar3 = *(int **)(iVar1 + 0xa8); piVar3 != *(int **)(iVar1 + 0xac); piVar3 = piVar3 + 1) {
      piVar6 = (int *)*piVar3;
      if (piVar6[8] == unaff_EDI) goto LAB_0063f442;
    }
  }
  piVar6 = (int *)0x0;
LAB_0063f442:
  if ((iVar5 != 0) && (piVar6 != (int *)0x0)) {
    FUN_0063e770(piVar6);
    (**(code **)(*piVar6 + 200))();
  }
  return;
}

