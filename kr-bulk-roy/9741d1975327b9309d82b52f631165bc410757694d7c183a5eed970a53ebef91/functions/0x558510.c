
void FUN_00558510(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (iVar4 != 0) {
    puVar1 = (undefined4 *)*param_1;
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      if (*(int **)puVar2[2] != (int *)0x0) {
        iVar4 = **(int **)puVar2[2];
        sVar3 = FUN_008fed10(0,0xffffffff);
        sVar3 = FUN_008fed10((int)sVar3);
        (**(code **)(iVar4 + 0x20))((int)sVar3);
      }
    }
  }
  return;
}

