
void FUN_0076cd50(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = *(int *)(param_1 + 0xa4);
  if ((iVar2 != 0) || (*(int *)(param_1 + 0xa8) != param_2)) {
    puVar3 = *(undefined4 **)(param_1 + 100);
    iVar6 = *(int *)(param_1 + 0xa8) - param_2;
    for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
      iVar5 = puVar4[2];
      piVar1 = (int *)(iVar5 + 8);
      *piVar1 = *piVar1 + iVar2;
      piVar1 = (int *)(iVar5 + 0x10);
      *piVar1 = *piVar1 + iVar2;
      iVar5 = puVar4[2];
      piVar1 = (int *)(iVar5 + 0xc);
      *piVar1 = *piVar1 + iVar6;
      piVar1 = (int *)(iVar5 + 0x14);
      *piVar1 = *piVar1 + iVar6;
    }
    FUN_00746f70();
  }
  *(int *)(param_1 + 0xa8) = param_2;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  return;
}

