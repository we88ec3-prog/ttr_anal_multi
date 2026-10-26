
void FUN_0070fe00(void)

{
  int iVar1;
  int in_EAX;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  
  iVar1 = *(int *)(in_EAX + 0x30);
  local_c = 0xffffffff;
  local_6 = 0;
  local_8 = *(undefined1 *)(iVar1 + 0x32);
  local_7 = 0;
  local_10 = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 **)(iVar1 + 0x14) = &local_10;
  FUN_00711b20();
  FUN_0070de40();
  return;
}

