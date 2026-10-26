
void FUN_0045fa00(int param_1,undefined4 param_2,undefined4 param_3,int param_4,byte param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00913501;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x108) - *(int *)(*(int *)(param_1 + 4) + 0x104);
  iVar1 = iVar4 >> 0x1f;
  iVar4 = iVar4 / 0x18 + iVar1;
  local_1c = 0;
  if (iVar4 != iVar1) {
    local_18 = 0;
    do {
      iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x104) + local_18;
      if (*(int *)(iVar5 + 8) == param_4) {
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_8 = 0;
          FUN_0051c120(uVar2);
          _atexit((_func_4879 *)&LAB_00bccc90);
          local_8 = 0xffffffff;
        }
        local_20 = param_4;
        FUN_008438c0(&local_20);
        if (local_24 == DAT_00f8d91c) {
          ExceptionList = local_10;
          return;
        }
        iVar3 = *(int *)(local_24 + 0x10);
        if (iVar3 == 0) {
          ExceptionList = local_10;
          return;
        }
        if ((DAT_00f8d9a8 & 1) == 0) {
          DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
          local_8 = 1;
          FUN_00523540();
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_00521080(&DAT_00f8d9bc);
          _atexit((_func_4879 *)&LAB_00bccc50);
          local_8 = 0xffffffff;
        }
        local_20 = *(int *)(iVar3 + 0x20);
        FUN_008438c0(&local_20);
        if (local_28 == DAT_00f8d9b0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(local_28 + 0x10);
        }
        if (*(int *)(iVar5 + 0xc) < *(int *)(iVar3 + 0xc)) {
          *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + (uint)param_5;
          ExceptionList = local_10;
          return;
        }
      }
      local_18 = local_18 + 0x18;
      local_1c = local_1c + 1;
    } while (local_1c < (uint)(iVar4 - iVar1));
  }
  FUN_005f84f0();
  ExceptionList = local_10;
  return;
}

