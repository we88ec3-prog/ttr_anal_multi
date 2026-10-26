
void FUN_00710ea0(int param_1)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  
  iVar1 = *(int *)(in_EAX + 0x30);
  local_c = 0xffffffff;
  local_6 = 1;
  local_8 = *(undefined1 *)(iVar1 + 0x32);
  local_7 = 0;
  local_10 = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 **)(iVar1 + 0x14) = &local_10;
  *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
  if (*(int *)(in_EAX + 0x20) == 0x11f) {
    uVar2 = FUN_006ffec0(in_EAX + 0x18);
    *(undefined4 *)(in_EAX + 0x10) = uVar2;
  }
  else {
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_EAX + 0x20);
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
    *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
    *(undefined4 *)(in_EAX + 0x20) = 0x11f;
  }
  uVar2 = FUN_0070d950();
  iVar1 = *(int *)(in_EAX + 0x10);
  if (iVar1 != 0x2c) {
    if (iVar1 == 0x3d) {
      FUN_00710810();
      goto LAB_00710f51;
    }
    if (iVar1 != 0x10b) {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130();
    }
  }
  FUN_00710b90(uVar2);
LAB_00710f51:
  if (*(int *)(in_EAX + 0x10) != 0x106) {
    if (param_1 == *(int *)(in_EAX + 4)) {
      FUN_006f7c30(*(undefined4 *)(in_EAX + 0x34),"\'%s\' expected",&DAT_00c42cc0);
                    /* WARNING: Subroutine does not return */
      FUN_006ff130();
    }
    FUN_006f7c30(*(undefined4 *)(in_EAX + 0x34),"\'%s\' expected (to close \'%s\' at line %d)",
                 &DAT_00c42cc0,&PTR_LAB_00c42cbc,param_1);
                    /* WARNING: Subroutine does not return */
    FUN_006ff130();
  }
  *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
  if (*(int *)(in_EAX + 0x20) != 0x11f) {
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_EAX + 0x20);
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
    *(undefined4 *)(in_EAX + 0x20) = 0x11f;
    *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
    FUN_0070de40();
    return;
  }
  uVar2 = FUN_006ffec0(in_EAX + 0x18);
  *(undefined4 *)(in_EAX + 0x10) = uVar2;
  FUN_0070de40();
  return;
}

