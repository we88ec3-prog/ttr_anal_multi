
void FUN_008cd050(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 in_stack_00000010;
  int local_8;
  
  iVar2 = *(int *)(in_EAX + 0x18);
  iVar3 = *(int *)(in_EAX + 0x20);
  local_8 = iVar3;
  if (iVar2 != 0) {
    do {
      iVar1 = FUN_008ccac0();
      if (((iVar1 != 0) || (iVar1 = FUN_008ccac0(), iVar1 != 0)) ||
         (iVar1 = FUN_008ccac0(), iVar1 != 0)) break;
      iVar3 = iVar3 + 0x10;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    local_8 = iVar3;
    if (iVar2 != 0) goto LAB_008cd0c0;
  }
  iVar2 = FUN_008ccbd0(in_stack_00000010,&local_8);
  if (iVar2 != 0) {
    return;
  }
LAB_008cd0c0:
  iVar2 = FUN_008ccb00();
  if ((iVar2 == 0) && (iVar2 = FUN_008ccb00(), iVar2 == 0)) {
    FUN_008ccb00();
  }
  return;
}

