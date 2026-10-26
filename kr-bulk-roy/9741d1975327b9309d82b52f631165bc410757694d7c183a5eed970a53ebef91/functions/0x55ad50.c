
void FUN_0055ad50(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  void **ppvVar5;
  uint uVar6;
  int *piVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093379b;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar1 = (undefined4 *)*param_1;
  ppvVar5 = &local_10;
  local_10 = ExceptionList;
  for (puVar2 = (undefined4 *)*puVar1; ExceptionList = ppvVar5, puVar2 != puVar1;
      puVar2 = (undefined4 *)*puVar2) {
    iVar3 = puVar2[2];
    if (iVar3 != 0) {
      if (*(int *)(iVar3 + 0x28) != 0) {
        FUN_0049bf30(uVar6);
        FUN_0089120c(*(undefined4 *)(iVar3 + 0x28));
      }
      *(undefined4 *)(iVar3 + 0x28) = 0;
      *(undefined4 *)(iVar3 + 0x2c) = 0;
      *(undefined4 *)(iVar3 + 0x30) = 0;
      FUN_0046fba0();
      FUN_0089120c(*(undefined4 *)(iVar3 + 0x10));
      *(undefined4 *)(iVar3 + 0x10) = 0;
      FUN_0089120c(iVar3);
    }
    ppvVar5 = ExceptionList;
  }
  piVar4 = (int *)*param_1;
  piVar7 = (int *)*piVar4;
  *piVar4 = (int)piVar4;
  *(int *)(*param_1 + 4) = *param_1;
  param_1[1] = 0;
  if (piVar7 != (int *)*param_1) {
    do {
      piVar4 = (int *)*piVar7;
      FUN_0089120c(piVar7);
      piVar7 = piVar4;
    } while (piVar4 != (int *)*param_1);
  }
  puVar1 = (undefined4 *)param_1[3];
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = Graphics::CImage::vftable;
    local_8 = 0;
    FUN_00739120(puVar1);
    if (puVar1[4] != 0) {
      FUN_0089120c(puVar1[4]);
    }
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    FUN_0089120c(puVar1);
    param_1[3] = 0;
  }
  ExceptionList = local_10;
  return;
}

