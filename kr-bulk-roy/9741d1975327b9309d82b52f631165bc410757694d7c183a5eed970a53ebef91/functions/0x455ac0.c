
void FUN_00455ac0(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x118) + 0xcc);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xdc), iVar1 != 0)) {
    FUN_004556d0(in_EAX,*(undefined4 *)(iVar1 + 0x20));
    FUN_00455840();
    return;
  }
  FUN_004556d0(in_EAX,0xffffffff);
  FUN_00455840();
  return;
}

