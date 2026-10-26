
void FUN_00711010(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EDI;
  undefined1 auStack_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  int local_28 [7];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_38;
  *(undefined4 *)(unaff_EDI + 8) = *(undefined4 *)(unaff_EDI + 4);
  if (*(int *)(unaff_EDI + 0x20) == 0x11f) {
    uVar2 = FUN_006ffec0(unaff_EDI + 0x18);
    *(undefined4 *)(unaff_EDI + 0x10) = uVar2;
  }
  else {
    *(undefined4 *)(unaff_EDI + 0x10) = *(undefined4 *)(unaff_EDI + 0x20);
    *(undefined4 *)(unaff_EDI + 0x14) = *(undefined4 *)(unaff_EDI + 0x24);
    *(undefined4 *)(unaff_EDI + 0x18) = *(undefined4 *)(unaff_EDI + 0x28);
    *(undefined4 *)(unaff_EDI + 0x1c) = *(undefined4 *)(unaff_EDI + 0x2c);
    *(undefined4 *)(unaff_EDI + 0x20) = 0x11f;
  }
  FUN_0070fc00();
  if (local_28[0] == 1) {
    local_28[0] = 3;
  }
  FUN_00712bb0(local_28);
  if (*(int *)(unaff_EDI + 0x10) != 0x112) {
    FUN_006f7c30(*(undefined4 *)(unaff_EDI + 0x34),"\'%s\' expected",&DAT_00c42c94);
                    /* WARNING: Subroutine does not return */
    FUN_006ff130();
  }
  *(undefined4 *)(unaff_EDI + 8) = *(undefined4 *)(unaff_EDI + 4);
  if (*(int *)(unaff_EDI + 0x20) == 0x11f) {
    uVar2 = FUN_006ffec0(unaff_EDI + 0x18);
    *(undefined4 *)(unaff_EDI + 0x10) = uVar2;
  }
  else {
    *(undefined4 *)(unaff_EDI + 0x10) = *(undefined4 *)(unaff_EDI + 0x20);
    *(undefined4 *)(unaff_EDI + 0x14) = *(undefined4 *)(unaff_EDI + 0x24);
    *(undefined4 *)(unaff_EDI + 0x18) = *(undefined4 *)(unaff_EDI + 0x28);
    *(undefined4 *)(unaff_EDI + 0x1c) = *(undefined4 *)(unaff_EDI + 0x2c);
    *(undefined4 *)(unaff_EDI + 0x20) = 0x11f;
  }
  iVar1 = *(int *)(unaff_EDI + 0x30);
  local_30 = 0xffffffff;
  local_2a = 0;
  local_2c = *(undefined1 *)(iVar1 + 0x32);
  local_2b = 0;
  local_34 = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 **)(iVar1 + 0x14) = &local_34;
  FUN_00711b20();
  FUN_0070de40();
  __security_check_cookie(local_c ^ (uint)auStack_38);
  return;
}

