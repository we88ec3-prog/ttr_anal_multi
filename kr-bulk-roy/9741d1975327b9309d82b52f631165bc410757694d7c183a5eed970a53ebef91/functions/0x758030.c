
void FUN_00758030(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a7d0;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007578f0(local_14);
  FUN_004026e0(param_1,0,0xffffffff);
  puVar1 = *(undefined4 **)(param_1 + 0x1c);
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      FUN_00757940(in_ECX,0x7b,0x7d);
      local_38 = 7;
      local_3c = 0;
      local_4c = (uint)local_4c._2_2_ << 0x10;
      FUN_00402160(&DAT_00bfb894,1);
      local_8 = 0;
      local_1c = 7;
      local_20 = 0;
      local_30 = (uint)local_30._2_2_ << 0x10;
      FUN_00402160(&DAT_00c059b8,2);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_00759330(in_ECX,&local_30,&local_4c);
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      local_1c = 7;
      local_20 = 0;
      local_30 = local_30 & 0xffff0000;
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    iVar3 = *(int *)(in_ECX + 0x1c);
    iVar4 = FUN_00404fd0(iVar3,*(undefined4 *)(iVar3 + 4));
    if (*(int *)(in_ECX + 0x20) == 0x1ffffffe) break;
    *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 1;
    *(int *)(iVar3 + 4) = iVar4;
    **(int **)(iVar4 + 4) = iVar4;
    puVar2 = (undefined4 *)*puVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}

