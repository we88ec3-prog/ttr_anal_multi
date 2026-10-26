
void FUN_00805af0(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  *(int *)(unaff_ESI + 0x44) = *(int *)(unaff_ESI + 0x44) + -1;
  iVar1 = *(int *)(unaff_ESI + 0x48);
  iVar2 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
  if (*(int *)(unaff_ESI + 0x4c) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(unaff_ESI + 0x4c) = *(int *)(unaff_ESI + 0x4c) + 1;
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}

