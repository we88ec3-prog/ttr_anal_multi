
void FUN_007d9790(undefined4 param_1)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  uint local_11c;
  undefined4 local_118;
  uint local_114 [4];
  undefined4 local_104;
  uint local_100;
  undefined1 local_f8 [152];
  undefined1 local_60 [68];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091c8e6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_11c;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffed8;
  ExceptionList = &local_14;
  local_118 = param_1;
  local_11c = 0;
  if (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 5 != 0) {
    iVar2 = 0;
    do {
      FUN_0072e420(local_f8,"FileInfo");
      local_c = 0;
      FUN_00730d80(local_60,&DAT_00c444f4,*(undefined4 *)(iVar2 + *(int *)(in_ECX + 8)),uVar1);
      FUN_0072e770(local_f8,&DAT_00bfb82c);
      local_100 = 0xf;
      local_104 = 0;
      local_114[0] = local_114[0] & 0xffffff00;
      FUN_00402a70(&DAT_00c0d66c,4);
      local_c._0_1_ = 1;
      FUN_0072e890(local_114,iVar2 + 4 + *(int *)(in_ECX + 8));
      local_c = (uint)local_c._1_3_ << 8;
      if (0xf < local_100) {
        FUN_0089120c(local_114[0]);
      }
      local_100 = 0xf;
      local_104 = 0;
      local_114[0] = local_114[0] & 0xffffff00;
      FUN_0072e1e0();
      local_c = 0xffffffff;
      FUN_0072e520();
      local_11c = local_11c + 1;
      iVar2 = iVar2 + 0x20;
    } while (local_11c < (uint)(*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 5));
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_11c);
  return;
}

