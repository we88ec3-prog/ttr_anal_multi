
void FUN_006b0c40(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  uint local_7c;
  int *local_78;
  int local_74;
  undefined4 *local_70;
  undefined4 *local_6c;
  undefined4 *local_68;
  undefined4 *local_60;
  undefined4 *local_5c;
  undefined4 *local_58;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  undefined4 uStack_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00942731;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_7c;
  ExceptionList = &local_14;
  local_74 = in_ECX;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffff78);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  piVar6 = (int *)DAT_00fab130;
  local_c = 0xffffffff;
  local_78 = (int *)DAT_00fab130;
  _eh_vector_constructor_iterator_
            (&local_70,0x10,2,(_func_void_void_ptr *)&LAB_00689330,FUN_00418290);
  local_c = 1;
  iVar7 = *(int *)((int)piVar6 + 0x5efc);
  local_7c = 0;
  if (*(int *)((int)piVar6 + 0x5f00) - iVar7 >> 2 != 0) {
    do {
      piVar5 = *(int **)((int)piVar6 + 0x5ee8);
      uVar2 = *(int *)((int)piVar6 + 0x5eec) - (int)piVar5 >> 2;
      uVar4 = 0;
      if (uVar2 != 0) {
        puVar1 = (undefined4 *)(iVar7 + local_7c * 4);
        do {
          if (*piVar5 == **(int **)(iVar7 + local_7c * 4)) {
            if ((puVar1 < local_5c) && (local_60 <= puVar1)) {
              iVar7 = (int)puVar1 - (int)local_60;
              if (local_5c == local_58) {
                FUN_004deab0();
              }
              if (local_5c != (undefined4 *)0x0) {
                *local_5c = local_60[iVar7 >> 2];
              }
              local_5c = local_5c + 1;
              in_ECX = local_74;
            }
            else {
              if (local_5c == local_58) {
                FUN_004deab0();
              }
              if (local_5c != (undefined4 *)0x0) {
                *local_5c = *puVar1;
              }
              local_5c = local_5c + 1;
              in_ECX = local_74;
            }
            goto LAB_006b0e2c;
          }
          uVar4 = uVar4 + 1;
          piVar5 = piVar5 + 1;
          in_ECX = local_74;
        } while (uVar4 < uVar2);
      }
      puVar1 = (undefined4 *)(iVar7 + local_7c * 4);
      if ((puVar1 < local_6c) && (local_70 <= puVar1)) {
        iVar7 = (int)puVar1 - (int)local_70;
        if (local_6c == local_68) {
          FUN_004deab0();
        }
        if (local_6c != (undefined4 *)0x0) {
          *local_6c = local_70[iVar7 >> 2];
        }
      }
      else {
        if (local_6c == local_68) {
          FUN_004deab0();
        }
        if (local_6c != (undefined4 *)0x0) {
          *local_6c = *puVar1;
        }
      }
      local_6c = local_6c + 1;
LAB_006b0e2c:
      iVar7 = *(int *)((int)local_78 + 0x5efc);
      local_7c = local_7c + 1;
      piVar6 = local_78;
    } while (local_7c < (uint)(*(int *)((int)local_78 + 0x5f00) - iVar7 >> 2));
  }
  FUN_008613c0(local_70,local_6c,(int)local_6c - (int)local_70 >> 2,FUN_006b0c10);
  FUN_008613c0(local_60,local_5c,(int)local_5c - (int)local_60 >> 2,FUN_006b0c10);
  local_7c = (int)local_6c - (int)local_70 >> 2;
  uVar2 = (int)local_5c - (int)local_60 >> 2;
  if (local_7c <= uVar2) {
    local_7c = uVar2;
  }
  iVar7 = *(int *)(*(int *)(in_ECX + 0xf0) + 0xcc);
  uVar2 = 0;
  if (iVar7 != 0) {
    FUN_00408920(iVar7,local_7c);
  }
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  if (local_7c != 0) {
    do {
      if (uVar2 < (uint)((int)local_6c - (int)local_70 >> 2)) {
        FUN_006aec80();
        iVar7 = local_70[uVar2];
        local_50 = local_50 + (uint)*(ushort *)(iVar7 + 4);
        local_48 = local_48 + (uint)*(ushort *)(iVar7 + 8);
        local_40 = local_40 + (uint)*(ushort *)(iVar7 + 6);
      }
      else {
        FUN_006aec80();
      }
      if (uVar2 < (uint)((int)local_5c - (int)local_60 >> 2)) {
        FUN_006aefb0();
        iVar7 = local_60[uVar2];
        local_4c = local_4c + (uint)*(ushort *)(iVar7 + 4);
        local_44 = local_44 + (uint)*(ushort *)(iVar7 + 8);
        local_3c = local_3c + (uint)*(ushort *)(iVar7 + 6);
      }
      else {
        FUN_006aefb0();
      }
      uVar2 = uVar2 + 1;
      in_ECX = local_74;
    } while (uVar2 < local_7c);
  }
  uVar3 = FUN_0040ef80();
  local_c._0_1_ = 2;
  FUN_00757800(uVar3);
  local_c._0_1_ = 1;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
  uVar3 = FUN_0040ef80();
  local_c._0_1_ = 3;
  FUN_00757800(uVar3);
  local_c._0_1_ = 1;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  uVar3 = FUN_0040ef80();
  local_c._0_1_ = 4;
  FUN_00757800(uVar3);
  local_c._0_1_ = 1;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  (**(code **)(**(int **)(in_ECX + 0xfc) + 200))();
  uVar3 = FUN_0040ef80();
  local_c._0_1_ = 5;
  FUN_00757800(uVar3);
  local_c._0_1_ = 1;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
  uVar3 = FUN_0040ef80();
  local_c._0_1_ = 6;
  FUN_00757800(uVar3);
  local_c._0_1_ = 1;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  (**(code **)(**(int **)(in_ECX + 0x104) + 200))();
  uVar3 = FUN_0040ef80();
  local_c._0_1_ = 7;
  FUN_00757800(uVar3);
  local_c._0_1_ = 1;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
  uVar3 = FUN_0040ef80();
  local_c._0_1_ = 8;
  FUN_00757800(uVar3);
  local_c._0_1_ = 1;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  (**(code **)(**(int **)(in_ECX + 0x10c) + 200))();
  uVar3 = FUN_0040ef80();
  local_c._0_1_ = 9;
  FUN_00757800(uVar3);
  local_c = CONCAT31(local_c._1_3_,1);
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  local_38 = local_38 & 0xffff0000;
  local_24 = 7;
  uStack_28 = 0;
  (**(code **)(**(int **)(in_ECX + 0x110) + 200))();
  piVar6 = *(int **)(in_ECX + 0xf0);
  piVar5 = (int *)piVar6[0x19];
  piVar8 = (int *)*piVar5;
  local_78 = piVar5;
  if (piVar8 != piVar5) {
    do {
      iVar7 = piVar8[2];
      if ((*(int *)(iVar7 + 0x60) != 0) && ((*(int **)(iVar7 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar7 + 0x1c) + 0x30))(iVar7);
        piVar5 = local_78;
      }
      piVar8 = (int *)*piVar8;
    } while (piVar8 != piVar5);
  }
  (**(code **)(*piVar6 + 0x128))();
  (**(code **)(**(int **)(in_ECX + 0xf0) + 200))();
  local_c = 0xffffffff;
  _eh_vector_destructor_iterator_(&local_70,0x10,2,FUN_00418290);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_7c);
  return;
}

