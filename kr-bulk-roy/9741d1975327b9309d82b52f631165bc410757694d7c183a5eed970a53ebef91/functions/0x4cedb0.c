
/* WARNING: Removing unreachable block (ram,0x004cf099) */
/* WARNING: Removing unreachable block (ram,0x004cf0b9) */
/* WARNING: Removing unreachable block (ram,0x004cf0c0) */
/* WARNING: Removing unreachable block (ram,0x004cf0da) */
/* WARNING: Removing unreachable block (ram,0x004cf0e2) */
/* WARNING: Removing unreachable block (ram,0x004cf0ea) */
/* WARNING: Removing unreachable block (ram,0x004cf10b) */
/* WARNING: Removing unreachable block (ram,0x004cf114) */
/* WARNING: Removing unreachable block (ram,0x004cf123) */
/* WARNING: Removing unreachable block (ram,0x004cf12f) */
/* WARNING: Removing unreachable block (ram,0x004cf14e) */

void FUN_004cedb0(int param_1)

{
  ushort *puVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  bool bVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint local_6c;
  char *local_60;
  char *local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined **local_50;
  undefined4 local_4c;
  undefined **local_44 [3];
  undefined1 local_38 [4];
  undefined4 *local_34;
  undefined4 local_30;
  undefined1 local_28 [4];
  undefined4 *local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091e3a2;
  local_14 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xffffff80;
  ExceptionList = &local_14;
  uVar9 = 0;
  if (*(int *)(param_1 + 0x438) != 0) {
    if ((*(int *)(param_1 + 0x15c) == 0) || (*(int *)(param_1 + 0x370) == 0)) {
      uVar10 = 0;
    }
    else {
      uVar10 = *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0xb4);
    }
    local_20 = 0;
    local_24 = (undefined4 *)FUN_00891268(0x10,uVar7);
    if (local_24 == (undefined4 *)0x0) {
      local_60 = (char *)0x0;
      std::exception::exception((exception *)&local_50,&local_60);
      local_50 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&local_50,&DAT_00c857a8);
    }
    *local_24 = local_24;
    local_24[1] = local_24;
    local_24[2] = local_24;
    *(undefined1 *)((int)local_24 + 0xe) = 1;
    *(undefined1 *)((int)local_24 + 0xf) = 1;
    local_c = 0;
    local_30 = 0;
    local_34 = (undefined4 *)FUN_00891268(0x10,uVar7);
    if (local_34 == (undefined4 *)0x0) {
      local_5c = (char *)0x0;
      std::exception::exception((exception *)local_44,&local_5c);
      local_44[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_44,&DAT_00c857a8);
    }
    *local_34 = local_34;
    local_34[1] = local_34;
    local_34[2] = local_34;
    *(undefined1 *)((int)local_34 + 0xe) = 1;
    *(undefined1 *)((int)local_34 + 0xf) = 1;
    local_c = CONCAT31(local_c._1_3_,1);
    iVar2 = *(int *)(param_1 + 0x438);
    if (*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8) >> 2 != 0) {
      do {
        uVar8 = FUN_0055e5b0(*(int *)(iVar2 + 8) + uVar9 * 4);
        FUN_00412b40(local_38,uVar8);
        iVar2 = *(int *)(param_1 + 0x438);
        uVar9 = uVar9 + 1;
      } while (uVar9 < (uint)(*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8) >> 2));
    }
    uVar7 = 0;
    iVar2 = *(int *)(param_1 + 0x43c);
    if (*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8) >> 2 != 0) {
      do {
        uVar8 = FUN_0055e5b0(*(int *)(iVar2 + 8) + uVar7 * 4);
        FUN_00412b40(local_28,uVar8);
        iVar2 = *(int *)(param_1 + 0x43c);
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)(*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8) >> 2));
    }
    iVar2 = *(int *)(param_1 + 0x43c);
    bVar6 = false;
    local_6c = 0;
    if (*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8) >> 2 != 0) {
      do {
        puVar1 = (ushort *)(*(int *)(iVar2 + 8) + local_6c * 4);
        FUN_004cf5c0(&local_58,puVar1);
        FUN_004cfc90(local_58,local_54,local_5c);
        if ((DAT_00fe1bc0 & 1) == 0) {
          DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
          local_c._0_1_ = 2;
          FUN_007bef00();
          _atexit((_func_4879 *)&LAB_00bcec50);
          local_c = CONCAT31(local_c._1_3_,1);
        }
        local_50 = (undefined **)(uint)*puVar1;
        local_4c = 0;
        FUN_004dd400(&DAT_00fe1b60,&local_60,&local_50);
        if ((local_60 != DAT_00fe1b64) && (*(int *)(local_60 + 0x18) != 0)) {
          if ((*(int *)(param_1 + 0x15c) != 0) && (*(int *)(param_1 + 0x370) != 0)) {
            FUN_007a7620(*(int *)(param_1 + 0x15c),*(undefined4 *)(*(int *)(local_60 + 0x18) + 0x20)
                        );
          }
          bVar6 = true;
        }
        iVar2 = *(int *)(param_1 + 0x43c);
        local_6c = local_6c + 1;
      } while (local_6c < (uint)(*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8) >> 2));
    }
    iVar2 = *(int *)(param_1 + 0x438);
    local_6c = 0;
    if (*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8) >> 2 != 0) {
      do {
        iVar5 = local_6c * 4;
        FUN_004cf5c0(&local_50,*(int *)(iVar2 + 8) + iVar5);
        FUN_004cfc90(local_50,local_4c,local_5c);
        iVar2 = *(int *)(*(int *)(param_1 + 0x438) + 8);
        puVar3 = (undefined2 *)(iVar2 + iVar5);
        if ((*(int *)(param_1 + 0x15c) != 0) && (*(int *)(param_1 + 0x370) != 0)) {
          FUN_007a7240(*(int *)(param_1 + 0x15c),*puVar3,*(undefined1 *)(iVar2 + 2 + iVar5),
                       *(undefined1 *)((int)puVar3 + 3));
        }
        bVar6 = true;
        iVar2 = *(int *)(param_1 + 0x438);
        local_6c = local_6c + 1;
      } while (local_6c < (uint)(*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8) >> 2));
    }
    if (((bVar6) && (*(int *)(param_1 + 0x15c) != 0)) && (*(int *)(param_1 + 0x370) != 0)) {
      FUN_007a6830(uVar10);
    }
    puVar3 = *(undefined2 **)(param_1 + 0x438);
    puVar4 = *(undefined2 **)(param_1 + 0x43c);
    *puVar4 = *puVar3;
    *(undefined4 *)(puVar4 + 2) = *(undefined4 *)(puVar3 + 2);
    FUN_00482ac0(puVar3 + 4);
    *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)(puVar3 + 0xc);
    local_c = CONCAT31(local_c._1_3_,3);
    FUN_0081cd10(*local_34,local_34);
    FUN_0089120c(local_34);
    local_c = 4;
    FUN_0081cd10(*local_24,local_24);
    FUN_0089120c(local_24);
  }
  ExceptionList = local_14;
  return;
}

