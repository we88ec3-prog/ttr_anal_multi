
int * FUN_005c8e60(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar1 = FUN_005c9050();
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

