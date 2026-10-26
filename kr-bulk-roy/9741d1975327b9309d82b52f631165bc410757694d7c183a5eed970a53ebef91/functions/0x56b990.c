
void FUN_0056b990(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_10;
  undefined4 local_8;
  
  FUN_00542210();
  iVar2 = FUN_004d8460();
  if (local_8 != *(uint *)(iVar2 + 8)) {
    do {
      if (local_10 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *local_10;
      }
      uVar3 = local_8;
      if (*(uint *)(iVar2 + 8) <= local_8) {
        uVar3 = local_8 - *(uint *)(iVar2 + 8);
      }
      piVar1 = (int *)(*(int *)(*(int *)(iVar2 + 4) + uVar3 * 4) + 0x20c);
      *piVar1 = *piVar1 + 1;
      local_8 = local_8 + 1;
      iVar2 = FUN_004d8460();
    } while (local_8 != *(uint *)(iVar2 + 8));
  }
  FUN_0056b8b0();
  return;
}

