
uint FUN_006dd2d0(int param_1,byte param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined **local_30 [3];
  char *local_24;
  int local_20;
  undefined4 local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f483;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar6 = *(int *)(param_1 + 0xb8) - *(int *)(param_1 + 0xb4);
  iVar1 = iVar6 >> 0x1f;
  iVar6 = iVar6 / 0xc + iVar1;
  uVar4 = 0;
  local_18 = 0;
  if (iVar6 != iVar1) {
    local_14 = 0;
    do {
      puVar7 = (undefined4 *)(*(int *)(param_1 + 0xb4) + local_14);
      if ((DAT_00f8d9a8 & 1) == 0) {
        DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
        local_8 = 0;
        DAT_00f8d9b4 = 0;
        iVar5 = FUN_00891268(0x18,uVar3);
        if (iVar5 == 0) {
          local_24 = (char *)0x0;
          std::exception::exception((exception *)local_30,&local_24);
          local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_30,&DAT_00c857a8);
        }
        DAT_00f8d9b0 = iVar5;
        *(int *)iVar5 = iVar5;
        *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
        *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
        *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
        *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_00521080(&DAT_00f8d9bc);
        _atexit((_func_4879 *)&LAB_00bccc50);
        local_8 = 0xffffffff;
      }
      local_1c = *puVar7;
      FUN_008438c0(&local_1c);
      if (((local_20 != DAT_00f8d9b0) && (*(int *)(local_20 + 0x10) != 0)) &&
         (*(uint *)(*(int *)(local_20 + 0x10) + 8) == (uint)param_2)) {
        iVar1 = *(int *)(param_1 + 0xb4) + local_18 * 0xc;
        *param_3 = *(undefined4 *)(*(int *)(param_1 + 0xb4) + local_18 * 0xc);
        param_3[1] = *(undefined4 *)(iVar1 + 4);
        uVar2 = *(undefined4 *)(iVar1 + 8);
        param_3[2] = uVar2;
        ExceptionList = local_10;
        return CONCAT31((int3)((uint)uVar2 >> 8),1);
      }
      local_14 = local_14 + 0xc;
      uVar4 = local_18 + 1;
      local_18 = uVar4;
    } while (uVar4 < (uint)(iVar6 - iVar1));
  }
  ExceptionList = local_10;
  return uVar4 & 0xffffff00;
}

