
void FUN_007100b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined4 local_2c;
  int local_28 [7];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_4c;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  iVar1 = *(int *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0x20) == 0x11f) {
    uVar5 = FUN_006ffec0(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x10) = uVar5;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x20) = 0x11f;
  }
  local_48 = *(int *)(iVar1 + 0x18);
  *(int *)(iVar1 + 0x1c) = local_48;
  FUN_0070fc00(param_1,local_28,0);
  if (local_28[0] == 1) {
    local_28[0] = 3;
  }
  FUN_00712bb0(local_28);
  local_40 = 0xffffffff;
  local_3a = 1;
  local_3c = *(undefined1 *)(iVar1 + 0x32);
  local_3b = 0;
  local_44 = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 **)(iVar1 + 0x14) = &local_44;
  if (*(int *)(param_1 + 0x10) == 0x103) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
    if (*(int *)(param_1 + 0x20) == 0x11f) {
      uVar5 = FUN_006ffec0(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x10) = uVar5;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x20) = 0x11f;
    }
    iVar2 = *(int *)(param_1 + 0x30);
    local_34 = 0xffffffff;
    local_2e = 0;
    local_30 = *(undefined1 *)(iVar2 + 0x32);
    local_2f = 0;
    local_38 = *(undefined4 *)(iVar2 + 0x14);
    *(undefined4 **)(iVar2 + 0x14) = &local_38;
    FUN_00711b20(param_1);
    FUN_0070de40();
    local_2c = *(undefined4 *)(iVar1 + 0x20);
    *(undefined4 *)(iVar1 + 0x20) = 0xffffffff;
    local_4c = FUN_00713370(0x7fff8016,*(undefined4 *)(*(int *)(iVar1 + 0xc) + 8));
    FUN_00711fe0();
    if (local_48 == *(int *)(iVar1 + 0x18)) {
      *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x18);
      FUN_00711fe0();
    }
    else {
      FUN_00711f00(iVar1,local_48,0xff,local_48);
    }
    if (*(int *)(param_1 + 0x10) == 0x106) {
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
      if (*(int *)(param_1 + 0x20) == 0x11f) {
        uVar5 = FUN_006ffec0(param_1 + 0x18);
        *(undefined4 *)(param_1 + 0x10) = uVar5;
      }
      else {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
        *(undefined4 *)(param_1 + 0x20) = 0x11f;
      }
      FUN_0070de40();
      *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar1 + 0x18);
      FUN_00711fe0();
      __security_check_cookie(local_c ^ (uint)&local_4c);
      return;
    }
    if (param_2 != *(int *)(param_1 + 4)) {
      uVar4 = FUN_006f7c30(*(undefined4 *)(param_1 + 0x34),
                           "\'%s\' expected (to close \'%s\' at line %d)",&DAT_00c42cc0,"while",
                           param_2);
      uVar5 = *(undefined4 *)(param_1 + 0x10);
      goto LAB_0071018f;
    }
    puVar3 = &DAT_00c42cc0;
  }
  else {
    puVar3 = &DAT_00c42cd4;
  }
  uVar4 = FUN_006f7c30(*(undefined4 *)(param_1 + 0x34),"\'%s\' expected",puVar3);
  uVar5 = *(undefined4 *)(param_1 + 0x10);
LAB_0071018f:
                    /* WARNING: Subroutine does not return */
  FUN_006ff130(param_1,uVar4,uVar5);
}

