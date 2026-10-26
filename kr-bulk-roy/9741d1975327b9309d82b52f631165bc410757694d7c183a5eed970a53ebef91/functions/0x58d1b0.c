
void FUN_0058d1b0(int param_1)

{
  undefined4 ****ppppuVar1;
  int iVar2;
  undefined4 uVar3;
  char *_Str1;
  int iVar4;
  char ****_Str2;
  undefined1 local_b0 [8];
  int local_a8;
  undefined4 local_a4 [5];
  uint local_90;
  uint local_88 [4];
  undefined4 local_78;
  uint local_74;
  undefined4 ***local_6c [4];
  undefined4 local_5c;
  uint local_58;
  uint local_50 [4];
  undefined4 local_40;
  uint local_3c;
  char ***local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091fa36;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_a8 = param_1;
  FUN_004297b0(local_18);
  ppppuVar1 = (undefined4 ****)local_6c[0];
  if (local_58 < 0x10) {
    ppppuVar1 = local_6c;
  }
  iVar2 = FUN_0072e2e0(ppppuVar1);
  if (0xf < local_58) {
    FUN_0089120c(local_6c[0]);
  }
  local_58 = 0xf;
  local_5c = 0;
  local_6c[0] = (undefined4 ***)((uint)local_6c[0] & 0xffffff00);
  if (iVar2 != 0) {
    local_a8 = local_a8 + 4;
    do {
      iVar4 = local_a8;
      FUN_00764d80(local_a4,&DAT_00bed1fc);
      local_8 = 0;
      FUN_00764d80(local_88,&DAT_00bed1fc);
      local_8._0_1_ = 1;
      local_50[0] = local_50[0] & 0xffff0000;
      local_3c = 7;
      local_40 = 0;
      FUN_004026e0(local_a4,0,0xffffffff);
      local_8._0_1_ = 2;
      local_20 = 7;
      local_24 = 0;
      local_34[0] = (char ***)((uint)local_34[0] & 0xffff0000);
      FUN_004026e0(local_88,0,0xffffffff);
      local_8._0_1_ = 3;
      uVar3 = FUN_005394c0(local_50);
      FUN_00539230(iVar4,local_b0,uVar3);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (7 < local_20) {
        FUN_0089120c(local_34[0]);
      }
      local_20 = 7;
      local_24 = 0;
      local_34[0] = (char ***)((uint)local_34[0] & 0xffff0000);
      if (7 < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      FUN_004297b0();
      _Str2 = (char ****)local_34[0];
      if (local_20 < 0x10) {
        _Str2 = local_34;
      }
      for (iVar2 = *(int *)(iVar2 + 0x40); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x40)) {
        _Str1 = (char *)(iVar2 + 0x20);
        if (0xf < *(uint *)(iVar2 + 0x34)) {
          _Str1 = *(char **)_Str1;
        }
        iVar4 = __stricmp(_Str1,(char *)_Str2);
        if (iVar4 == 0) goto LAB_0058d372;
      }
      iVar2 = 0;
LAB_0058d372:
      if (0xf < local_20) {
        FUN_0089120c(local_34[0]);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34[0] = (char ***)((uint)local_34[0] & 0xffffff00);
      if (7 < local_74) {
        FUN_0089120c(local_88[0]);
      }
      local_8 = 0xffffffff;
      local_74 = 7;
      local_78 = 0;
      local_88[0] = local_88[0] & 0xffff0000;
      if (7 < local_90) {
        FUN_0089120c(local_a4[0]);
      }
    } while (iVar2 != 0);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

