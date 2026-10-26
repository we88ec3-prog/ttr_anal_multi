
void FUN_00485200(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined1 local_60 [4];
  undefined4 *local_5c;
  undefined1 local_50 [4];
  undefined4 *local_4c;
  int local_48;
  undefined **local_40 [7];
  char *local_24;
  int *local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910bbc;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00485810(*(undefined4 *)(*(int *)(param_1 + 4) + 4));
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  uVar4 = DAT_00fc1094 & 1;
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  if (uVar4 == 0) {
    DAT_00fc1094 = DAT_00fc1094 | 1;
    local_8 = 0;
    FUN_0052f7e0(uVar6);
    _atexit((_func_4879 *)&LAB_00bcdc80);
    local_8 = 0xffffffff;
  }
  piVar9 = (int *)*DAT_00fc109c;
  local_20 = DAT_00fc109c;
  if (piVar9 == DAT_00fc109c) {
    ExceptionList = local_10;
    return;
  }
  do {
    puVar2 = (undefined1 *)piVar9[3];
    local_48 = 0;
    local_1c = puVar2;
    puVar7 = (undefined4 *)FUN_00891268(0x14);
    if (puVar7 == (undefined4 *)0x0) {
      local_24 = (char *)0x0;
      std::exception::exception((exception *)local_40,&local_24);
      local_40[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_40,&DAT_00c857a8);
    }
    *puVar7 = puVar7;
    puVar7[1] = puVar7;
    puVar7[2] = puVar7;
    *(undefined1 *)(puVar7 + 4) = 1;
    *(undefined1 *)((int)puVar7 + 0x11) = 1;
    local_8._1_3_ = 0;
    local_4c = puVar7;
    if ((DAT_00fc1094 & 1) == 0) {
      DAT_00fc1094 = DAT_00fc1094 | 1;
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      FUN_0052f7e0(uVar6);
      _atexit((_func_4879 *)&LAB_00bcdc80);
    }
    local_8._0_1_ = 1;
    uVar8 = FUN_00530330();
    local_18 = FUN_005303d0();
    if ((DAT_00fb11a8 & 1) == 0) {
      DAT_00fb11a8 = DAT_00fb11a8 | 1;
      local_8._0_1_ = 3;
      FUN_00813890();
      _atexit((_func_4879 *)&LAB_00bccec0);
      local_8._0_1_ = 1;
    }
    FUN_00817340(&DAT_00fb11ac,puVar2,local_50,uVar8,local_18);
    if (local_48 != 0) {
      uVar8 = FUN_00486090();
      local_8._0_1_ = 4;
      uVar8 = FUN_00486490(uVar8);
      FUN_004860b0(param_1,uVar8);
      local_1c = local_60;
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_004ca160(*local_5c,local_5c);
      FUN_0089120c(local_5c);
    }
    local_8 = 6;
    FUN_004ca160(*local_4c,local_4c);
    local_8 = 0xffffffff;
    FUN_0089120c(local_4c);
    if (*(char *)((int)piVar9 + 0x15) == '\0') {
      piVar3 = (int *)piVar9[2];
      if (*(char *)((int)piVar3 + 0x15) == '\0') {
        cVar1 = *(char *)(*piVar3 + 0x15);
        piVar9 = piVar3;
        piVar3 = (int *)*piVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar9 = piVar3;
          piVar3 = (int *)*piVar3;
        }
      }
      else {
        cVar1 = *(char *)(piVar9[1] + 0x15);
        piVar5 = (int *)piVar9[1];
        piVar3 = piVar9;
        while ((piVar9 = piVar5, cVar1 == '\0' && (piVar3 == (int *)piVar9[2]))) {
          cVar1 = *(char *)(piVar9[1] + 0x15);
          piVar5 = (int *)piVar9[1];
          piVar3 = piVar9;
        }
      }
    }
  } while (piVar9 != local_20);
  ExceptionList = local_10;
  return;
}

