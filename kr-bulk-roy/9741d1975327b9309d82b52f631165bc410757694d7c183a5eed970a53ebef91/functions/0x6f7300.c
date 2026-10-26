
void FUN_006f7300(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  
  iVar1 = *(int *)(in_EAX + 0x10);
  FUN_006fd860(*(undefined4 *)(in_EAX + 0x20));
  FUN_006faef0();
  FUN_00700880();
  uVar2 = FUN_00700880();
  *(undefined4 *)(iVar1 + 0x34) = uVar2;
  *(undefined4 *)(iVar1 + 0x3c) = 0;
  FUN_00700880();
  FUN_00700880();
  (**(code **)(iVar1 + 0xc))(*(undefined4 *)(iVar1 + 0x10));
  return;
}

