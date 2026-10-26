
/* WARNING: Removing unreachable block (ram,0x006dc3ae) */
/* WARNING: Removing unreachable block (ram,0x006dc3c5) */
/* WARNING: Removing unreachable block (ram,0x006dc3ce) */
/* WARNING: Removing unreachable block (ram,0x006dc3fd) */
/* WARNING: Removing unreachable block (ram,0x006dc423) */
/* WARNING: Removing unreachable block (ram,0x006dc42e) */
/* WARNING: Removing unreachable block (ram,0x006dc439) */
/* WARNING: Removing unreachable block (ram,0x006dc43e) */
/* WARNING: Removing unreachable block (ram,0x006dc443) */
/* WARNING: Removing unreachable block (ram,0x006dc44c) */
/* WARNING: Removing unreachable block (ram,0x006dc46d) */
/* WARNING: Removing unreachable block (ram,0x006dc49a) */
/* WARNING: Removing unreachable block (ram,0x006dc4a1) */
/* WARNING: Removing unreachable block (ram,0x006dc4b1) */
/* WARNING: Removing unreachable block (ram,0x006dc4ba) */
/* WARNING: Removing unreachable block (ram,0x006dc6db) */

void FUN_006dc350(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined **local_34 [3];
  undefined4 local_28;
  undefined4 local_24;
  char *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar2 = param_1;
  puStack_c = &LAB_0091980c;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 0x10) == 0) {
    return;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_007a76b0(*(int *)(param_1 + 0x10));
  local_14 = (*(int *)(param_1 + 0xb8) - *(int *)(param_1 + 0xb4)) / 0xc;
  uVar9 = 0;
  if (local_14 != 0) {
    param_1 = 0;
    do {
      iVar1 = *(int *)(iVar2 + 0xb4);
      if ((DAT_00f8d9a8 & 1) == 0) {
        DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
        local_8._0_1_ = 4;
        DAT_00f8d9b4 = 0;
        puVar4 = (undefined4 *)FUN_00891268(0x18);
        if (puVar4 == (undefined4 *)0x0) {
          local_20 = (char *)0x0;
          std::exception::exception((exception *)local_34,&local_20);
          local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_34,&DAT_00c857a8);
        }
        DAT_00f8d9b0 = puVar4;
        *puVar4 = puVar4;
        DAT_00f8d9b0[1] = DAT_00f8d9b0;
        DAT_00f8d9b0[2] = DAT_00f8d9b0;
        *(undefined1 *)(DAT_00f8d9b0 + 5) = 1;
        *(undefined1 *)((int)DAT_00f8d9b0 + 0x15) = 1;
        local_8._0_1_ = 5;
        FUN_00521080(&DAT_00f8d9bc);
        _atexit((_func_4879 *)&LAB_00bccc50);
        local_8 = (uint)local_8._1_3_ << 8;
      }
      iVar1 = *(int *)(iVar1 + param_1);
      cVar3 = *(char *)((int)DAT_00f8d9b0[1] + 0x15);
      puVar4 = (undefined4 *)DAT_00f8d9b0[1];
      local_1c = DAT_00f8d9b0;
      while (puVar7 = puVar4, cVar3 == '\0') {
        if ((int)puVar7[3] < iVar1) {
          puVar4 = (undefined4 *)puVar7[2];
          puVar7 = local_1c;
        }
        else {
          puVar4 = (undefined4 *)*puVar7;
        }
        cVar3 = *(char *)((int)puVar4 + 0x15);
        local_1c = puVar7;
      }
      if ((local_1c == DAT_00f8d9b0) || (iVar1 < (int)local_1c[3])) {
        local_18 = DAT_00f8d9b0;
        ppuVar5 = &local_18;
      }
      else {
        ppuVar5 = &local_1c;
      }
      if ((*ppuVar5 != DAT_00f8d9b0) && (iVar1 = (*ppuVar5)[4], iVar1 != 0)) {
        iVar6 = 0;
        if (*(int *)(iVar1 + 8) - 1U < 0x2b) {
          iVar6 = FUN_00520f40();
        }
        if (iVar6 == param_2) {
          puVar7 = *(undefined4 **)(iVar2 + 0xb8);
          puVar4 = (undefined4 *)(*(int *)(iVar2 + 0xb4) + 0xc + uVar9 * 0xc);
          if (puVar4 != puVar7) {
            puVar8 = puVar4 + -3;
            do {
              *puVar8 = *puVar4;
              puVar8[1] = puVar4[1];
              puVar8[2] = puVar4[2];
              puVar4 = puVar4 + 3;
              puVar8 = puVar8 + 3;
            } while (puVar4 != puVar7);
          }
          *(int *)(iVar2 + 0xb8) = *(int *)(iVar2 + 0xb8) + -0xc;
          break;
        }
      }
      param_1 = param_1 + 0xc;
      uVar9 = uVar9 + 1;
    } while (uVar9 < local_14);
  }
  if (param_2 == 10) {
    local_28 = 0;
    local_24 = 0;
    local_20 = (char *)0x0;
    cVar3 = FUN_006dd2d0(iVar2,1,&local_28);
    if (cVar3 == '\0') {
      ExceptionList = local_10;
      return;
    }
    uVar10 = *(undefined4 *)(iVar2 + 0x10);
  }
  else {
    if (param_2 != 0xb) {
      ExceptionList = local_10;
      return;
    }
    local_28 = 0;
    local_24 = 0;
    local_20 = (char *)0x0;
    cVar3 = FUN_006dd2d0(iVar2,2,&local_28);
    if (cVar3 != '\0') {
      FUN_007a7240(*(undefined4 *)(iVar2 + 0x10),local_28,local_24,local_20);
    }
    cVar3 = FUN_006dd2d0(iVar2,0x2b,&local_28);
    if (cVar3 == '\0') {
      ExceptionList = local_10;
      return;
    }
    uVar10 = *(undefined4 *)(iVar2 + 0x10);
  }
  FUN_007a7240(uVar10,local_28,local_24,local_20);
  ExceptionList = local_10;
  return;
}

