
void FUN_0041e6b0(int param_1)

{
  uint uVar1;
  int in_ECX;
  undefined4 ***pppuVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 **local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939936;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar3 = 0;
    do {
      if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0xec + iVar3 * 4) + 0x20))
      goto LAB_0041e7df;
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffff0000);
      local_8 = 0;
      switch(iVar3) {
      case 0:
        uVar4 = 0x7e;
        break;
      case 1:
        uVar4 = 0x7f;
        goto LAB_0041e734;
      case 2:
        uVar4 = 0x80;
        break;
      case 3:
        uVar4 = 0x81;
        goto LAB_0041e734;
      case 4:
        uVar4 = 0x82;
        break;
      case 5:
        uVar4 = 0x83;
LAB_0041e734:
        FUN_00585620(uVar4,uVar1);
        FUN_00585330(uVar4);
        goto LAB_0041e777;
      case 6:
        uVar4 = 0x84;
        break;
      default:
        goto switchD_0041e727_default;
      }
      FUN_00585620(uVar4,uVar1);
      FUN_00585330(uVar4);
LAB_0041e777:
      FUN_0041f490(local_30);
      if (local_20 != 0) {
        pppuVar2 = (undefined4 ***)local_30[0];
        if (local_1c < 8) {
          pppuVar2 = local_30;
        }
        if ((DAT_00fb11e0 & 1) == 0) {
          DAT_00fb11e0 = DAT_00fb11e0 | 1;
          local_8._0_1_ = 1;
          FUN_004d4d10();
          _atexit((_func_4879 *)&LAB_00bccef0);
          local_8 = (uint)local_8._1_3_ << 8;
        }
        FUN_004d5ae0(&DAT_00fb11e8,0,pppuVar2);
      }
switchD_0041e727_default:
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
LAB_0041e7df:
      iVar3 = iVar3 + 1;
    } while (iVar3 < 7);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

