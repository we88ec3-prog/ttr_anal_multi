
/* WARNING: Removing unreachable block (ram,0x007d95b5) */

void FUN_007d9430(void)

{
  int iVar1;
  void *_Dst;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  uint local_38;
  int local_34;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920814;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x108) == 1) {
    *(undefined4 *)(in_ECX + 0x108) = 0;
    if ((DAT_00fd94d8 & 1) == 0) {
      DAT_00fd94d8 = DAT_00fd94d8 | 1;
      local_8 = 0;
      FUN_007b5430(uVar3);
      _atexit((_func_4879 *)&LAB_00bce660);
    }
    local_8 = 0xffffffff;
    FUN_007b5f30(in_ECX + 4);
    if (*(int *)(in_ECX + 0x114) != *(int *)(in_ECX + 0x118)) {
      local_38 = 0;
      if (*(int *)(in_ECX + 0x118) - *(int *)(in_ECX + 0x114) >> 2 != 0) {
        local_34 = 0;
        uVar2 = local_8;
        do {
          local_8 = uVar2;
          uVar5 = 0;
          iVar1 = *(int *)(local_34 + *(int *)(in_ECX + 0xc0));
          FUN_00403040(in_ECX + 0xd0,0,0xffffffff);
          local_8 = 1;
          if (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 5 != 0) {
            iVar4 = 0;
            do {
              if (iVar1 == *(int *)(iVar4 + *(int *)(in_ECX + 8))) {
                FUN_00401ed0(iVar4 + *(int *)(in_ECX + 8) + 4,0,0xffffffff);
              }
              uVar5 = uVar5 + 1;
              iVar4 = iVar4 + 0x20;
            } while (uVar5 < (uint)(*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 5));
          }
          if ((DAT_00fd94d8 & 1) == 0) {
            DAT_00fd94d8 = DAT_00fd94d8 | 1;
            local_8._0_1_ = 2;
            FUN_007b5430();
            _atexit((_func_4879 *)&LAB_00bce660);
            local_8 = CONCAT31(local_8._1_3_,1);
          }
          FUN_007b67e0(&DAT_00fd9420);
          *(undefined4 *)(*(int *)(in_ECX + 0x114) + local_38 * 4) = 0;
          local_8 = 0xffffffff;
          uVar2 = local_8;
          local_8 = 0xffffffff;
          local_34 = local_34 + 0x14;
          local_38 = local_38 + 1;
        } while (local_38 < (uint)(*(int *)(in_ECX + 0x118) - *(int *)(in_ECX + 0x114) >> 2));
      }
      _Dst = *(void **)(in_ECX + 0x114);
      if (_Dst != *(void **)(in_ECX + 0x118)) {
        FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0x118),0);
        *(void **)(in_ECX + 0x118) = _Dst;
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

