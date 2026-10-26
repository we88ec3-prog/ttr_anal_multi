
void FUN_00710320(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  char local_37;
  undefined1 local_36;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  int local_28 [7];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_4c;
  local_4c = *(int *)(param_1 + 0x30);
  local_44 = *(int *)(local_4c + 0x18);
  *(int *)(local_4c + 0x1c) = local_44;
  local_2a = 1;
  local_30 = 0xffffffff;
  local_2c = *(undefined1 *)(local_4c + 0x32);
  local_2b = 0;
  local_34 = *(undefined4 *)(local_4c + 0x14);
  *(undefined4 **)(local_4c + 0x14) = &local_34;
  local_3c = 0xffffffff;
  local_36 = 0;
  local_38 = *(undefined1 *)(local_4c + 0x32);
  local_37 = '\0';
  local_40 = *(undefined4 *)(local_4c + 0x14);
  *(undefined4 **)(local_4c + 0x14) = &local_40;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 0x20) == 0x11f) {
    uVar2 = FUN_006ffec0(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x10) = uVar2;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x20) = 0x11f;
  }
  FUN_00711b20(param_1);
  if (*(int *)(param_1 + 0x10) == 0x114) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
    if (*(int *)(param_1 + 0x20) == 0x11f) {
      uVar2 = FUN_006ffec0(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x10) = uVar2;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x20) = 0x11f;
    }
    FUN_0070fc00(param_1,local_28,0);
    if (local_28[0] == 1) {
      local_28[0] = 3;
    }
    FUN_00712bb0(local_28);
    if (local_37 == '\0') {
      FUN_0070de40();
      iVar1 = *(int *)(param_1 + 0x30);
      if (local_44 == *(int *)(iVar1 + 0x18)) {
        *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x18);
        FUN_00711fe0();
      }
      else {
        FUN_00711f00(iVar1,local_44,0xff,local_44);
      }
    }
    else {
      FUN_00710010();
      *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x1c) =
           *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x18);
      FUN_00711fe0();
      iVar1 = local_4c;
      FUN_0070de40();
      *(undefined4 *)(iVar1 + 0x20) = 0xffffffff;
      local_48 = FUN_00713370(0x7fff8016,*(undefined4 *)(*(int *)(iVar1 + 0xc) + 8));
      FUN_00711fe0();
      iVar1 = *(int *)(param_1 + 0x30);
      if (local_44 == *(int *)(iVar1 + 0x18)) {
        *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x18);
        FUN_00711fe0();
      }
      else {
        FUN_00711f00(iVar1,local_44,0xff,local_44);
      }
    }
    FUN_0070de40();
    __security_check_cookie(local_c ^ (uint)&local_4c);
    return;
  }
  if (param_2 != *(int *)(param_1 + 4)) {
    uVar2 = FUN_006f7c30(*(undefined4 *)(param_1 + 0x34),
                         "\'%s\' expected (to close \'%s\' at line %d)","until","repeat",param_2);
                    /* WARNING: Subroutine does not return */
    FUN_006ff130(param_1,uVar2,*(undefined4 *)(param_1 + 0x10));
  }
  uVar2 = FUN_006f7c30(*(undefined4 *)(param_1 + 0x34),"\'%s\' expected","until");
                    /* WARNING: Subroutine does not return */
  FUN_006ff130(param_1,uVar2,*(undefined4 *)(param_1 + 0x10));
}

