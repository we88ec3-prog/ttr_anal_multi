
void FUN_007464b0(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  
  iVar3 = param_1;
  if ((*(uint *)(unaff_ESI + 0x28) >> 0xf & 1) == 0) {
    if ((*(uint *)(param_1 + 0x28) >> 0xf & 1) != 0) {
      FUN_00746b80();
    }
  }
  else if ((*(uint *)(param_1 + 0x28) >> 0xf & 1) == 0) {
    FUN_00746b30();
  }
  if ((*(byte *)(unaff_ESI + 0x2a) & 1) == 0) {
    if ((*(byte *)(iVar3 + 0x2a) & 1) != 0) {
      FUN_00746c10();
    }
  }
  else if ((*(byte *)(iVar3 + 0x2a) & 1) == 0) {
    FUN_00746bd0();
  }
  if ((*(uint *)(iVar3 + 0x28) >> 0xc & 1) == 0) {
    iVar3 = *(int *)(unaff_ESI + 100);
    iVar1 = FUN_0074d700(iVar3,*(undefined4 *)(iVar3 + 4),&param_1);
    iVar2 = *(int *)(unaff_ESI + 0x68);
    if (iVar2 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
  }
  else {
    iVar3 = **(int **)(unaff_ESI + 100);
    iVar1 = FUN_0074d700(iVar3,*(undefined4 *)(iVar3 + 4),&param_1);
    iVar2 = *(int *)(unaff_ESI + 0x68);
    if (iVar2 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
  }
  *(int *)(unaff_ESI + 0x68) = iVar2 + 1;
  *(int *)(iVar3 + 4) = iVar1;
  **(int **)(iVar1 + 4) = iVar1;
  return;
}

