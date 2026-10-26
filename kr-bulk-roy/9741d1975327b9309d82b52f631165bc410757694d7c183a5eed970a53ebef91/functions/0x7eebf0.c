
void FUN_007eebf0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EDI;
  undefined4 local_30;
  int local_2c;
  int local_24;
  int local_20;
  undefined4 local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093228c;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(unaff_EDI + 0x14) = 0;
  *(undefined4 *)(unaff_EDI + 0x18) = 0;
  local_18 = 0;
  if (*(int *)(unaff_EDI + 8) - *(int *)(unaff_EDI + 4) >> 4 != 0) {
    local_14 = 0;
    do {
      iVar5 = *(int *)(unaff_EDI + 4) + local_14;
      (**(code **)(**(int **)(iVar5 + 4) + 4))(uVar2);
      iVar3 = (**(code **)(**(int **)(iVar5 + 4) + 4))();
      if (*(int *)(iVar3 + 4) == -0x5edc0000) {
        iVar3 = *(int *)(iVar5 + 4);
        if (*(int **)(iVar3 + 0x74) != (int *)0x0) {
          iVar4 = (**(code **)(**(int **)(iVar3 + 0x74) + 0x24))();
          if (iVar4 == 0) {
            iVar3 = *(int *)(iVar3 + 0x74);
          }
          else {
            iVar4 = (**(code **)(**(int **)(iVar3 + 0x74) + 0x38))();
            if (iVar4 < 1) goto LAB_007eecaa;
            iVar3 = (**(code **)(**(int **)(iVar3 + 0x74) + 0x28))(0);
          }
          if (iVar3 != 0) {
            uVar1 = *(undefined4 *)(iVar3 + 0x164);
            if ((DAT_00fb79e8 & 1) == 0) {
              DAT_00fb79e8 = DAT_00fb79e8 | 1;
              local_8 = 0;
              FUN_00798de0();
              _atexit((_func_4879 *)&LAB_00bcd2e0);
              local_8 = 0xffffffff;
              if ((DAT_00fb79e8 & 1) == 0) {
                DAT_00fb79e8 = DAT_00fb79e8 | 1;
                local_8 = 1;
                FUN_00798de0();
                _atexit((_func_4879 *)&LAB_00bcd2e0);
                local_8 = 0xffffffff;
              }
            }
            iVar3 = FUN_00840100(DAT_00fb76a8 + 0x188,uVar1);
            if (iVar3 != 0) {
              local_1c = 0x1b;
              FUN_008438c0(&local_1c);
              iVar3 = *(int *)(iVar3 + 4);
              if (local_20 != iVar3) {
                local_2c = *(int *)(local_20 + 0x10);
              }
              local_1c = 0x16;
              FUN_008438c0(&local_1c);
              if (local_24 != iVar3) {
                local_30 = *(undefined4 *)(local_24 + 0x10);
              }
              *(int *)(iVar5 + 0xc) = local_2c;
              *(undefined4 *)(iVar5 + 8) = local_30;
              if (local_2c == 0) {
                *(int *)(unaff_EDI + 0x18) = *(int *)(unaff_EDI + 0x18) + 1;
              }
              else {
                *(int *)(unaff_EDI + 0x14) = *(int *)(unaff_EDI + 0x14) + 1;
              }
              goto LAB_007eeda7;
            }
          }
        }
LAB_007eecaa:
        *(undefined4 *)(iVar5 + 0xc) = 0;
        *(undefined4 *)(iVar5 + 8) = 1;
        *(int *)(unaff_EDI + 0x18) = *(int *)(unaff_EDI + 0x18) + 1;
      }
      else {
        *(undefined4 *)(iVar5 + 8) = 1;
        *(undefined4 *)(iVar5 + 0xc) = 0;
        *(int *)(unaff_EDI + 0x18) = *(int *)(unaff_EDI + 0x18) + 1;
      }
LAB_007eeda7:
      local_14 = local_14 + 0x10;
      local_18 = local_18 + 1;
    } while (local_18 < (uint)(*(int *)(unaff_EDI + 8) - *(int *)(unaff_EDI + 4) >> 4));
  }
  ExceptionList = local_10;
  return;
}

