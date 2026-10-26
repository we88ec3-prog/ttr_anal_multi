
void FUN_00629910(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int *local_50;
  char *local_4c;
  undefined1 local_48 [4];
  int local_44;
  undefined4 local_40;
  undefined4 *local_3c;
  int local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined **local_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00926ce6;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_c = 0;
    FUN_006ccd20(DAT_00d61f20 ^ (uint)&stack0xffffffa0);
    _atexit((_func_4879 *)&LAB_00bce3c0);
  }
  local_c = 0xffffffff;
  if (DAT_00fc1804 != 0) {
    local_38 = 0;
    puVar2 = (undefined4 *)FUN_00891268(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      local_4c = (char *)0x0;
      std::exception::exception((exception *)local_24,&local_4c);
      local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c857a8);
    }
    *puVar2 = puVar2;
    puVar2[1] = puVar2;
    local_c = 1;
    local_50 = (int *)*DAT_00fc1800;
    piVar6 = DAT_00fc1800;
    local_3c = puVar2;
    if (local_50 != DAT_00fc1800) {
      do {
        if (local_50[5] == *(int *)(param_1 + 0x24c)) {
          local_40 = param_2;
          local_44 = local_50[4];
          iVar3 = FUN_00404fd0(puVar2,puVar2[1]);
          if (local_38 == 0x1ffffffe) {
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("list<T> too long");
          }
          local_38 = local_38 + 1;
          puVar2[1] = iVar3;
          **(int **)(iVar3 + 4) = iVar3;
          puVar4 = (undefined4 *)FUN_00535c60(&DAT_00fc17fc,local_48,local_50);
          local_50 = (int *)*puVar4;
          piVar6 = DAT_00fc1800;
        }
        else {
          FUN_00406870();
        }
      } while (local_50 != piVar6);
    }
    for (puVar4 = (undefined4 *)*puVar2; puVar4 != puVar2; puVar4 = (undefined4 *)*puVar4) {
      local_30 = puVar4[2];
      local_28 = puVar4[3];
      local_2c = local_30;
      uVar5 = FUN_00821c50();
      FUN_00517bf0(&DAT_00fc17fc,uVar5);
    }
    puVar4 = (undefined4 *)*puVar2;
    *puVar2 = puVar2;
    puVar2[1] = puVar2;
    while (puVar4 != puVar2) {
      puVar1 = (undefined4 *)*puVar4;
      FUN_0089120c(puVar4);
      puVar4 = puVar1;
    }
    FUN_0089120c(puVar2);
  }
  ExceptionList = local_14;
  return;
}

