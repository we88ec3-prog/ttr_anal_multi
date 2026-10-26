
void FUN_0062f780(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926c28;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = 1;
  if (1 < (uint)(*(int *)(param_1 + 0x118) - *(int *)(param_1 + 0x114) >> 2)) {
    do {
      local_24 = 0;
      if (0 < (int)local_28) {
        do {
          iVar5 = *(int *)(param_1 + 0x114);
          iVar1 = local_28 * 4;
          if ((*(int *)(iVar5 + local_28 * 4) != 0) &&
             (iVar2 = local_24 * 4, *(int *)(iVar2 + iVar5) != 0)) {
            if ((DAT_00fe17b8 & 1) == 0) {
              DAT_00fe17b8 = DAT_00fe17b8 | 1;
              local_8 = 0;
              FUN_0050caf0(uVar4);
              _atexit((_func_4879 *)&LAB_00bce7e0);
              local_8 = 0xffffffff;
            }
            local_20 = *(int *)(*(int *)(iVar5 + iVar1) + 0x24);
            FUN_0062db10(&local_20);
            if (local_2c == DAT_00fe17f4) {
              local_14 = 0;
            }
            else {
              local_14 = local_2c + 0x10;
            }
            iVar5 = *(int *)(param_1 + 0x114);
            if ((DAT_00fe17b8 & 1) == 0) {
              DAT_00fe17b8 = DAT_00fe17b8 | 1;
              local_8 = 1;
              FUN_0050caf0(uVar4);
              _atexit((_func_4879 *)&LAB_00bce7e0);
              local_8 = 0xffffffff;
            }
            local_20 = *(int *)(*(int *)(iVar5 + iVar2) + 0x24);
            FUN_0062db10(&local_20);
            if (local_30 == DAT_00fe17f4) {
              local_18 = 0;
            }
            else {
              local_18 = local_30 + 0x10;
            }
            iVar5 = *(int *)(param_1 + 0x114);
            if ((DAT_00fe17b8 & 1) == 0) {
              DAT_00fe17b8 = DAT_00fe17b8 | 1;
              local_8 = 2;
              FUN_0050caf0();
              _atexit((_func_4879 *)&LAB_00bce7e0);
              local_8 = 0xffffffff;
            }
            local_20 = *(int *)(*(int *)(iVar5 + iVar1) + 0x24);
            FUN_005366c0(&local_20);
            if (local_34 == DAT_00fe17e4) {
              local_1c = 0;
            }
            else {
              local_1c = local_34 + 0x10;
            }
            iVar5 = *(int *)(param_1 + 0x114);
            if ((DAT_00fe17b8 & 1) == 0) {
              DAT_00fe17b8 = DAT_00fe17b8 | 1;
              local_8 = 3;
              FUN_0050caf0();
              _atexit((_func_4879 *)&LAB_00bce7e0);
              local_8 = 0xffffffff;
            }
            local_20 = *(int *)(*(int *)(iVar5 + iVar2) + 0x24);
            FUN_005366c0(&local_20);
            if (local_38 == DAT_00fe17e4) {
              local_20 = 0;
            }
            else {
              local_20 = local_38 + 0x10;
            }
            if (local_14 == 0) {
              if (local_18 != 0) {
                iVar5 = *(int *)(param_1 + 0x114);
                goto LAB_0062fa39;
              }
            }
            else if (local_18 != 0) {
              iVar5 = *(int *)(param_1 + 0x114);
              if (*(int *)(*(int *)(*(int *)(param_1 + 0x114) + iVar2) + 0x20) <=
                  *(int *)(*(int *)(*(int *)(param_1 + 0x114) + iVar1) + 0x20)) {
                if (*(int *)(*(int *)(iVar5 + iVar1) + 0x20) !=
                    *(int *)(*(int *)(iVar5 + iVar2) + 0x20)) goto LAB_0062fa45;
                if (*(int *)(local_14 + 4) < *(int *)(local_18 + 4)) {
                  iVar5 = *(int *)(param_1 + 0x114);
                }
                else {
                  if ((((*(int *)(local_14 + 4) != *(int *)(local_18 + 4)) || (local_1c == 0)) ||
                      (local_20 == 0)) || (*(int *)(local_20 + 4) <= *(int *)(local_1c + 4)))
                  goto LAB_0062fa45;
                  iVar5 = *(int *)(param_1 + 0x114);
                }
              }
LAB_0062fa39:
              uVar3 = *(undefined4 *)(iVar5 + iVar1);
              *(undefined4 *)(iVar5 + iVar1) = *(undefined4 *)(iVar5 + iVar2);
              *(undefined4 *)(iVar5 + iVar2) = uVar3;
            }
          }
LAB_0062fa45:
          local_24 = local_24 + 1;
        } while (local_24 < (int)local_28);
      }
      local_28 = local_28 + 1;
    } while (local_28 < (uint)(*(int *)(param_1 + 0x118) - *(int *)(param_1 + 0x114) >> 2));
  }
  ExceptionList = local_10;
  return;
}

