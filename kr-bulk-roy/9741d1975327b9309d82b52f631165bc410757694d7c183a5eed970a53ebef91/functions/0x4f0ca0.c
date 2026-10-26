
void FUN_004f0ca0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 local_10;
  undefined4 local_8;
  
  FUN_00542210();
  iVar1 = FUN_004d8460();
  if (local_8 != *(uint *)(iVar1 + 8)) {
    do {
      if (local_10 == (int *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *local_10;
      }
      uVar2 = local_8 >> 2;
      if (*(uint *)(iVar1 + 8) <= uVar2) {
        uVar2 = uVar2 - *(uint *)(iVar1 + 8);
      }
      iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 4) + uVar2 * 4) + (local_8 & 3) * 4);
      if (iVar1 != 0) {
        FUN_004f0e50();
        FUN_0089120c(iVar1);
      }
      local_8 = local_8 + 1;
      iVar1 = FUN_004d8460();
    } while (local_8 != *(uint *)(iVar1 + 8));
  }
  FUN_007b6d70();
  return;
}

