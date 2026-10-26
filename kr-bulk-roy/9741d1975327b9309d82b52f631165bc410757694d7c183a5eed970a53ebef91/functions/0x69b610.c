
void FUN_0069b610(void)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x98) + 0xcc);
  if ((iVar1 == 0) || (iVar1 = *(int *)(iVar1 + 0xdc), iVar1 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(uint *)(iVar1 + 0x20);
  }
  if (uVar2 < (uint)(*(int *)(in_EAX + 0x168) - *(int *)(in_EAX + 0x164) >> 2)) {
    FUN_0069b1c0(**(undefined4 **)(*(int *)(in_EAX + 0x164) + uVar2 * 4));
    FUN_0069ad20();
  }
  return;
}

