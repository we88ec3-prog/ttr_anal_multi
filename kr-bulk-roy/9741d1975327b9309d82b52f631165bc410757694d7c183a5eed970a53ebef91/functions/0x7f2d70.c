
void FUN_007f2d70(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *******pppppppuVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 ******local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00913c08;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = *(int *)(in_ECX + 0x84);
  local_14 = uVar2;
  if ((iVar4 != 0) && (param_1 == 0)) {
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (undefined4 ******)((uint)local_30[0] & 0xffffff00);
    local_8 = 0;
    FUN_00403040(iVar4 + 0x7c,0,0xffffffff);
    if (*(int *)(iVar4 + 0x78) != 0) {
      local_34 = 0xffffffff;
      pppppppuVar3 = (undefined4 *******)local_30[0];
      if (local_1c < 0x10) {
        pppppppuVar3 = local_30;
      }
      iVar4 = FUN_007d32d0(&local_34,pppppppuVar3);
      if ((iVar4 != 0) && (iVar4 = FUN_007d3340(uVar2), iVar4 != 0)) {
        FUN_007cc3a0(&local_38,&local_40,&local_3c);
        puVar1 = *(undefined4 **)(in_ECX + 0x84);
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        iVar4 = *(int *)(in_ECX + 0x84);
        *(undefined4 *)(iVar4 + 0xc) = local_40;
        *(undefined4 *)(iVar4 + 0x10) = local_3c;
        *(undefined4 *)(iVar4 + 0x14) = local_38;
        *(undefined4 *)(*(int *)(in_ECX + 0x84) + 0x18) = 0x3f800000;
        FUN_007d8a50(*(undefined4 *)(in_ECX + 0x84));
      }
    }
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

