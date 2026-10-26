
void FUN_006af510(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint local_7c;
  int *local_78;
  int iStack_74;
  undefined4 *puStack_70;
  undefined4 *puStack_6c;
  undefined4 *puStack_68;
  undefined4 *puStack_60;
  undefined4 *puStack_5c;
  undefined4 *puStack_58;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009427dd;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_7c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff78;
  ExceptionList = &local_14;
  iVar4 = *(int *)(param_1 + 0xf0);
  *(undefined4 *)(param_1 + 300) = param_2;
  local_78 = (int *)param_1;
  if (((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) &&
     (iVar4 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))(uVar3), iVar4 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0xf0) + 200))();
  (**(code **)(**(int **)(param_1 + 0xf0) + 200))();
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    uStack_c = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    uStack_c = 0xffffffff;
  }
  FUN_004f6a30(local_7c);
  FUN_00757710();
  (**(code **)(**(int **)(param_1 + 0x100) + 200))();
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  iVar9 = DAT_00fab130;
  iStack_74 = DAT_00fab130;
  _eh_vector_constructor_iterator_
            (&puStack_70,0x10,2,(_func_void_void_ptr *)&LAB_00689330,FUN_00418290);
  uStack_c = 2;
  iVar4 = *(int *)(iVar9 + 0x5efc);
  local_7c = 0;
  if (*(int *)(iVar9 + 0x5f00) - iVar4 >> 2 != 0) {
    do {
      piVar6 = *(int **)(iVar9 + 0x5ee8);
      uVar3 = *(int *)(iVar9 + 0x5eec) - (int)piVar6 >> 2;
      uVar7 = 0;
      if (uVar3 != 0) {
        puVar1 = (undefined4 *)(iVar4 + local_7c * 4);
        do {
          if (*piVar6 == **(int **)(iVar4 + local_7c * 4)) {
            if ((puVar1 < puStack_5c) && (puStack_60 <= puVar1)) {
              iVar4 = (int)puVar1 - (int)puStack_60;
              if (puStack_5c == puStack_58) {
                FUN_004deab0();
              }
              if (puStack_5c != (undefined4 *)0x0) {
                *puStack_5c = puStack_60[iVar4 >> 2];
              }
              puStack_5c = puStack_5c + 1;
              iVar9 = iStack_74;
            }
            else {
              if (puStack_5c == puStack_58) {
                FUN_004deab0();
              }
              if (puStack_5c != (undefined4 *)0x0) {
                *puStack_5c = *puVar1;
              }
              puStack_5c = puStack_5c + 1;
              iVar9 = iStack_74;
            }
            goto LAB_006af7d8;
          }
          uVar7 = uVar7 + 1;
          piVar6 = piVar6 + 1;
          iVar9 = iStack_74;
        } while (uVar7 < uVar3);
      }
      puVar1 = (undefined4 *)(iVar4 + local_7c * 4);
      if ((puVar1 < puStack_6c) && (puStack_70 <= puVar1)) {
        iVar4 = (int)puVar1 - (int)puStack_70;
        if (puStack_6c == puStack_68) {
          FUN_004deab0();
        }
        if (puStack_6c != (undefined4 *)0x0) {
          *puStack_6c = puStack_70[iVar4 >> 2];
        }
      }
      else {
        if (puStack_6c == puStack_68) {
          FUN_004deab0();
        }
        if (puStack_6c != (undefined4 *)0x0) {
          *puStack_6c = *puVar1;
        }
      }
      puStack_6c = puStack_6c + 1;
LAB_006af7d8:
      iVar4 = *(int *)(iVar9 + 0x5efc);
      local_7c = local_7c + 1;
    } while (local_7c < (uint)(*(int *)(iVar9 + 0x5f00) - iVar4 >> 2));
  }
  FUN_008613c0(puStack_70,puStack_6c,(int)puStack_6c - (int)puStack_70 >> 2,FUN_006b0c10);
  FUN_008613c0(puStack_60,puStack_5c,(int)puStack_5c - (int)puStack_60 >> 2,FUN_006b0c10);
  uVar3 = (int)puStack_5c - (int)puStack_60 >> 2;
  uVar7 = (int)puStack_6c - (int)puStack_70 >> 2;
  if (uVar3 < uVar7) {
    uVar3 = uVar7;
  }
  iVar4 = *(int *)(*(int *)((int)local_78 + 0x120) + 0xcc);
  local_7c = uVar3;
  if (iVar4 != 0) {
    FUN_00408920(iVar4,uVar3);
  }
  uVar7 = 0;
  iStack_50 = 0;
  iStack_4c = 0;
  iStack_48 = 0;
  iStack_44 = 0;
  iStack_40 = 0;
  iStack_3c = 0;
  if (uVar3 != 0) {
    do {
      if (uVar7 < (uint)((int)puStack_6c - (int)puStack_70 >> 2)) {
        FUN_006aec80();
        iVar4 = puStack_70[uVar7];
        iStack_50 = iStack_50 + (uint)*(ushort *)(iVar4 + 4);
        iStack_48 = iStack_48 + (uint)*(ushort *)(iVar4 + 8);
        iStack_40 = iStack_40 + (uint)*(ushort *)(iVar4 + 6);
      }
      else {
        FUN_006aec80();
      }
      if (uVar7 < (uint)((int)puStack_5c - (int)puStack_60 >> 2)) {
        FUN_006aefb0();
        iVar4 = puStack_60[uVar7];
        iStack_4c = iStack_4c + (uint)*(ushort *)(iVar4 + 4);
        iStack_44 = iStack_44 + (uint)*(ushort *)(iVar4 + 8);
        iStack_3c = iStack_3c + (uint)*(ushort *)(iVar4 + 6);
      }
      else {
        FUN_006aefb0();
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < local_7c);
  }
  uVar5 = FUN_0040ef80();
  piVar6 = local_78;
  uStack_c._0_1_ = 3;
  FUN_00757800(uVar5);
  uStack_c._0_1_ = 2;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  (**(code **)(**(int **)((int)piVar6 + 0x104) + 200))();
  uVar5 = FUN_0040ef80();
  uStack_c._0_1_ = 4;
  FUN_00757800(uVar5);
  uStack_c._0_1_ = 2;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  (**(code **)(**(int **)((int)piVar6 + 0x108) + 200))();
  uVar5 = FUN_0040ef80();
  uStack_c._0_1_ = 5;
  FUN_00757800(uVar5);
  uStack_c._0_1_ = 2;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  (**(code **)(**(int **)((int)piVar6 + 0x10c) + 200))();
  uVar5 = FUN_0040ef80();
  uStack_c._0_1_ = 6;
  FUN_00757800(uVar5);
  uStack_c._0_1_ = 2;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  (**(code **)(**(int **)((int)piVar6 + 0x110) + 200))();
  uVar5 = FUN_0040ef80();
  uStack_c._0_1_ = 7;
  FUN_00757800(uVar5);
  uStack_c._0_1_ = 2;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  (**(code **)(**(int **)((int)piVar6 + 0x114) + 200))();
  uVar5 = FUN_0040ef80();
  uStack_c._0_1_ = 8;
  FUN_00757800(uVar5);
  uStack_c._0_1_ = 2;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  (**(code **)(**(int **)((int)piVar6 + 0x118) + 200))();
  uVar5 = FUN_0040ef80();
  uStack_c._0_1_ = 9;
  FUN_00757800(uVar5);
  uStack_c._0_1_ = 2;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  (**(code **)(**(int **)((int)piVar6 + 0x124) + 200))();
  uVar5 = FUN_0040ef80();
  uStack_c._0_1_ = 10;
  FUN_00757800(uVar5);
  uStack_c = CONCAT31(uStack_c._1_3_,2);
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  uStack_38 = uStack_38 & 0xffff0000;
  uStack_24 = 7;
  uStack_28 = 0;
  (**(code **)(**(int **)((int)piVar6 + 0x128) + 200))();
  piVar8 = *(int **)((int)piVar6 + 0x120);
  puVar1 = (undefined4 *)piVar8[0x19];
  local_78 = piVar8;
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar4 = puVar2[2];
    if ((*(int *)(iVar4 + 0x60) != 0) && ((*(int **)(iVar4 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar4 + 0x1c) + 0x30))(iVar4);
      piVar8 = local_78;
    }
  }
  (**(code **)(*piVar8 + 0x128))();
  (**(code **)(**(int **)((int)piVar6 + 0x120) + 200))();
  if ((*(int *)((int)piVar6 + 300) == 1) || (*(int *)((int)piVar6 + 300) == 0)) {
    piVar6 = (int *)FUN_00891268(0x14);
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      *piVar6 = (int)FoxUI::FXUIEvent::vftable;
      piVar6[1] = -1;
      piVar6[2] = -1;
      piVar6[3] = 0;
      piVar6[4] = 0xf4304;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      uStack_c._0_1_ = 0xb;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      uStack_c = CONCAT31(uStack_c._1_3_,2);
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar6);
    }
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x10))(1);
    }
  }
  uStack_c = 0xffffffff;
  _eh_vector_destructor_iterator_(&puStack_70,0x10,2,FUN_00418290);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_7c);
  return;
}

