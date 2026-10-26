
int * FUN_00539110(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar1 = FUN_005391e0();
  if (iVar1 != *(int *)(unaff_ESI + 4)) {
    puVar2 = (undefined4 *)(iVar1 + 0xc);
    if (7 < *(uint *)(iVar1 + 0x20)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    iVar3 = FUN_0044df20(0,puVar2,*(undefined4 *)(iVar1 + 0x1c));
    if (-1 < iVar3) {
      *param_1 = iVar1;
      return param_1;
    }
  }
  *param_1 = *(int *)(unaff_ESI + 4);
  return param_1;
}

