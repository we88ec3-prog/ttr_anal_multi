
void FUN_00455b00(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x11c) + 0xcc);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xdc) != 0)) {
    FUN_004557d0();
    FUN_00455840();
    return;
  }
  FUN_004557d0();
  FUN_00455840();
  return;
}

