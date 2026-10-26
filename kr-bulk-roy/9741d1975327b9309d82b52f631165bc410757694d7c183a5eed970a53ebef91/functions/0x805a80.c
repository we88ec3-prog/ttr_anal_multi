
void FUN_00805a80(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  int unaff_EDI;
  
  iVar2 = param_1;
  for (puVar1 = (undefined4 *)**(undefined4 **)(unaff_EDI + 0x28);
      puVar1 != *(undefined4 **)(unaff_EDI + 0x28); puVar1 = (undefined4 *)*puVar1) {
    if (puVar1[2] == param_1) {
      return;
    }
  }
  DVar3 = GetTickCount();
  *(DWORD *)(iVar2 + 0xa0c0) = DVar3;
  iVar2 = *(int *)(unaff_EDI + 0x28);
  iVar4 = FUN_0074d700(iVar2,*(undefined4 *)(iVar2 + 4),&param_1);
  if (*(int *)(unaff_EDI + 0x2c) != 0x3ffffffe) {
    *(int *)(unaff_EDI + 0x2c) = *(int *)(unaff_EDI + 0x2c) + 1;
    *(int *)(iVar2 + 4) = iVar4;
    **(int **)(iVar4 + 4) = iVar4;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}

