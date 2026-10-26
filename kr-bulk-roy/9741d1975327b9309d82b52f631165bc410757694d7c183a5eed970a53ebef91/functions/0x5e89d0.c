
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e89d0(void)

{
  int iVar1;
  int *in_ECX;
  int local_44;
  int local_40;
  uint local_3c;
  undefined4 uStack_38;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0092e162;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_44;
  ExceptionList = &local_14;
  if ((DAT_00fab0d8 & 1) == 0) {
    DAT_00fab0d8 = DAT_00fab0d8 | 1;
    local_c = 0;
    FUN_004dd4a0(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
    DAT_00fab0ec = 0;
    _DAT_00fab0f0 = 0;
    _DAT_00fab0f4 = 0;
    _atexit((_func_4879 *)&LAB_00bccdb0);
  }
  local_c = 0xffffffff;
  local_40 = in_ECX[0x5a];
  local_3c = in_ECX[0x5b];
  FUN_004dd400(&DAT_00fab0dc,&local_44,&local_40);
  if (local_44 == DAT_00fab0e0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(local_44 + 0x18);
  }
  in_ECX[0x62] = iVar1;
  if (in_ECX[0x61] != 0) {
    FUN_005e1a60();
    (**(code **)(*in_ECX + 0x188))();
    (**(code **)(*(int *)in_ECX[0x65] + 0x94))(1);
    FUN_00749d00();
    uStack_28 = 7;
    uStack_2c = 0;
    local_3c = local_3c & 0xffff0000;
    puStack_10 = (undefined1 *)0x1;
    if ((DAT_00fab100 & 1) == 0) {
      DAT_00fab100 = DAT_00fab100 | 1;
      puStack_10._0_1_ = 2;
      puStack_10._1_3_ = 0;
      FUN_0049d6a0();
      _atexit((_func_4879 *)&LAB_00bcce20);
      puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,1);
      if ((DAT_00fab100 & 1) == 0) {
        DAT_00fab100 = DAT_00fab100 | 1;
        puStack_10._0_1_ = 4;
        FUN_0049d6a0();
        _atexit((_func_4879 *)&LAB_00bcce20);
        puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,1);
      }
    }
    (**(code **)(*in_ECX + 400))();
    (**(code **)(*in_ECX + 0x18c))();
    (**(code **)(*in_ECX + 0x198))();
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_44);
  return;
}

