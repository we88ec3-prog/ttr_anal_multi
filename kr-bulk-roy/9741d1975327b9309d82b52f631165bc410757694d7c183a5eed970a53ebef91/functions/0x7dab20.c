
/* WARNING: Removing unreachable block (ram,0x007dab69) */

void FUN_007dab20(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = -1;
  puStack_c = &LAB_0091c731;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xd4) != 1) {
    iVar1 = *(int *)(in_ECX + 0x1c);
    iVar2 = FUN_00407e70(0,local_14);
    if (iVar2 != 0 || iVar1 != 0) {
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      FUN_00403040(in_ECX + 0xb4,0,0xffffffff);
      local_8 = 0;
      FUN_00401ed0(in_ECX + 0xc,0,0xffffffff);
      piVar3 = (int *)FUN_00891268(0x2c);
      local_8._0_1_ = 1;
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        *piVar3 = (uint)*(ushort *)(in_ECX + 8) * 1000;
        piVar3[1] = 0;
        piVar3[2] = 0;
        piVar3[3] = 1;
        piVar3[9] = 0xf;
        piVar3[8] = 0;
        *(undefined1 *)(piVar3 + 4) = 0;
        FUN_00403040(local_30,0,0xffffffff);
      }
      if ((DAT_00fd94d8 & 1) == 0) {
        DAT_00fd94d8 = DAT_00fd94d8 | 1;
        local_8._0_1_ = 2;
        FUN_007b5430();
        _atexit((_func_4879 *)&LAB_00bce660);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_007b61d0(&DAT_00fd9420,piVar3,in_ECX + 4);
      *(undefined4 *)(in_ECX + 0xd4) = 1;
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

