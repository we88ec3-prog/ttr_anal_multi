
void FUN_00741650(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 in_ECX;
  int *unaff_FS_OFFSET;
  undefined **local_68 [4];
  undefined4 *local_58;
  undefined4 local_54;
  char *local_4c [2];
  undefined2 local_44 [8];
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_28 [16];
  uint local_18;
  int local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911e32;
  local_10 = *unaff_FS_OFFSET;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_18 = uVar2;
  iVar3 = FUN_00741a90(in_ECX);
  if (iVar3 != *(int *)(param_1 + 4)) {
    cVar1 = FUN_007418b0(uVar2);
    if (cVar1 == '\0') goto LAB_0074176a;
  }
  local_54 = 0;
  local_58 = (undefined4 *)FUN_00891268(0xa0);
  if (local_58 == (undefined4 *)0x0) {
    local_4c[0] = (char *)0x0;
    std::exception::exception((exception *)local_68,local_4c);
    local_68[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_68,&DAT_00c857a8);
  }
  *local_58 = local_58;
  local_58[1] = local_58;
  local_58[2] = local_58;
  *(undefined1 *)(local_58 + 0x27) = 1;
  *(undefined1 *)((int)local_58 + 0x9d) = 1;
  local_8 = 0;
  local_44[0] = 0;
  local_30 = 7;
  local_34 = 0;
  FUN_00741800(in_ECX,0);
  local_8._0_1_ = 1;
  FUN_00742260(local_28);
  local_8._0_1_ = 2;
  uVar4 = FUN_00742c00(local_44);
  FUN_00742340(iVar3,uVar4);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0073f080(local_44);
  local_8 = 3;
  FUN_0073f170(local_4c,*local_58,local_58);
  FUN_0089120c(local_58);
LAB_0074176a:
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

