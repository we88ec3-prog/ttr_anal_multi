
undefined4 FUN_004af920(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  undefined4 *local_8;
  
  iVar3 = *(int *)(param_1 + 2);
  iVar1 = FUN_0040f060();
  local_c = iVar3;
  FUN_008438c0(&local_c);
  if (local_8 != *(undefined4 **)(iVar1 + 0x1c)) {
    local_8 = (undefined4 *)local_8[4];
    iVar3 = 0;
    if (local_8 != (undefined4 *)0x0) {
      local_c = 0;
      iVar1 = FUN_00404ba0();
      if (*(int *)(param_1 + 2) == *(int *)(iVar1 + 0x5f50)) {
        (**(code **)(*DAT_00fba7a4 + 0x14))();
        (**(code **)(*DAT_00fba7a4 + 0xc))();
        local_c = 1;
      }
      if ('\0' < *(char *)(param_1 + 6)) {
        do {
          uVar4 = (uint)*(ushort *)(param_1 + 7 + iVar3 * 4);
          local_10 = uVar4;
          iVar1 = FUN_0040f060();
          FUN_0082ef00(&local_10);
          if ((local_14 == *(int *)(iVar1 + 0xc)) || (iVar1 = *(int *)(local_14 + 0x10), iVar1 == 0)
             ) {
            FUN_006edb60("Cannot Find In CharList");
          }
          else if ((*(short *)(param_1 + 7 + iVar3 * 4) == *(short *)(param_1 + 9 + iVar3 * 4)) ||
                  (local_c == 0)) {
            if (iVar3 == 0) {
              *(undefined4 *)(iVar1 + 0x98) = 1;
              local_8[1] = uVar4;
              local_10 = uVar4;
              iVar2 = FUN_0040f060();
              FUN_0082ef00(&local_10);
              if ((local_18 == *(int *)(iVar2 + 0xc)) || (*(int *)(local_18 + 0x10) == 0)) {
                local_8[2] = 0;
              }
              else {
                local_8[2] = (uint)*(ushort *)(*(int *)(local_18 + 0x10) + 0x88);
              }
            }
            else {
              *(undefined4 *)(iVar1 + 0x98) = 0;
            }
            *(undefined4 *)(iVar1 + 0x9c) = *local_8;
            if (local_c != 0) {
              (**(code **)(*DAT_00fba7a4 + 4))(iVar1);
            }
          }
          else {
            FUN_0040f060();
            (**(code **)(*DAT_00fba7a4 + 8))(*(undefined2 *)(param_1 + 9 + iVar3 * 4),iVar1);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(char *)(param_1 + 6));
      }
      if (local_c != 0) {
        (**(code **)(*DAT_00fba7a4 + 0x10))();
      }
      return 0x100;
    }
  }
  FUN_006edb60(&DAT_00c06a40,*(undefined4 *)(param_1 + 2));
  return 0x80004005;
}

