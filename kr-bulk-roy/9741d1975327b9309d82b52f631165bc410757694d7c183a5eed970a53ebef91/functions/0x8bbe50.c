
undefined4 FUN_008bbe50(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x60) != 0)) {
    piVar1 = (int *)(*(int *)(param_1 + 0x80) + 0x38);
    *piVar1 = *piVar1 + -1;
    if (0 < *(int *)(*(int *)(param_1 + 0x80) + 0x38)) {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x60);
    uVar3 = *(undefined4 *)(iVar2 + 8);
    uVar5 = FUN_008ba070(iVar2 + 0x10,param_1);
    iVar4 = (int)uVar5;
    if (iVar4 != 0) {
      FUN_008ba0c0((int)((ulonglong)uVar5 >> 0x20),iVar4);
      FUN_008b9f80(uVar3,iVar4);
      FUN_008bb670(uVar3,param_1,iVar2);
      return 0;
    }
  }
  return 0x23;
}

