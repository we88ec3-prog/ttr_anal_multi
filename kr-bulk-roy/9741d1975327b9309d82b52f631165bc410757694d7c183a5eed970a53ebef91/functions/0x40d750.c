
void FUN_0040d750(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  FUN_0064eb70();
  FUN_0043c570(0x2b5c);
  FUN_005d24d0();
  FUN_0040f570(0x2f44);
  FUN_0040f570(0x332c);
  FUN_0040f570(0x3714);
  FUN_00661400();
  FUN_0040e370(20000);
  FUN_0040e370(30000);
  FUN_0043c570(24000);
  FUN_0043c570(34000);
  iVar2 = *(int *)(in_ECX + 0x90);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar2 + 0xa4) = 1;
  iVar2 = *(int *)(in_ECX + 0x98);
  piVar1 = (int *)(iVar2 + 8);
  *piVar1 = *piVar1 + 0x6b;
  piVar1 = (int *)(iVar2 + 0x10);
  *piVar1 = *piVar1 + 0x6b;
  FUN_00746f70();
  return;
}

