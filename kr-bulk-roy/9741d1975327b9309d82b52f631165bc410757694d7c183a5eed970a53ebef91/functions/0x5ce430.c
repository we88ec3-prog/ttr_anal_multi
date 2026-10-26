
void FUN_005ce430(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  bool bVar8;
  undefined4 uStack_4c;
  undefined4 *puStack_48;
  undefined4 *puStack_44;
  undefined4 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093f44c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_4c;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if ((DAT_00fba7a4 != (int *)0x0) && (iVar3 = (**(code **)(*DAT_00fba7a4 + 0x1c))(0), iVar3 != 0))
  {
    uVar7 = (uint)*(ushort *)(iVar3 + 0x88);
    iVar3 = FUN_00404ba0();
    if ((uVar7 < 10) &&
       (((iVar3 = *(int *)(iVar3 + 0x6924) + uVar7 * 0x210, *(int *)(iVar3 + 0x5c) != 0 &&
         (iVar3 != 0)) && (iVar1 = iVar3 + 500, iVar1 != 0)))) {
      uStack_4c = CONCAT31(uStack_4c._1_3_,
                           *(undefined1 *)((uint)(*(char *)(iVar3 + 0x1f6) != '\0') + iVar1));
      (**(code **)(**(int **)(param_1 + 0x30c) + 0x19c))(uVar7,uStack_4c);
      (**(code **)(**(int **)(param_1 + 0x310) + 0x19c))
                (uVar7,*(undefined1 *)((uint)(*(char *)(iVar3 + 0x1f6) == '\0') + iVar1));
      (**(code **)(**(int **)(param_1 + 0x30c) + 200))();
      (**(code **)(**(int **)(param_1 + 0x310) + 200))();
    }
    uStack_24 = 7;
    uStack_28 = 0;
    uStack_38 = (ushort *)((uint)uStack_38._2_2_ << 0x10);
    local_c = 0;
    if ((DAT_00fdfb10 & 1) == 0) {
      DAT_00fdfb10 = DAT_00fdfb10 | 1;
      local_c = 2;
      FUN_00590760();
      _atexit((_func_4879 *)&LAB_00bce760);
    }
    puStack_48 = (undefined4 *)0x0;
    puStack_44 = (undefined4 *)0x0;
    uStack_40 = 0;
    local_c = CONCAT31(local_c._1_3_,3);
    FUN_006d4dc0(0x16,2);
    FUN_00402160(&DAT_00bed1fc,0);
    puVar6 = puStack_48;
    if (puStack_48 == puStack_44) {
      FUN_0041f490(&uStack_38);
    }
    else {
      FUN_00594a80(*puStack_48);
      puVar6 = puStack_48;
    }
    local_c = CONCAT31(local_c._1_3_,1);
    if (puVar6 != (undefined4 *)0x0) {
      FUN_0089120c(puVar6);
    }
    puVar5 = uStack_38;
    if (uStack_24 < 8) {
      puVar5 = (ushort *)&uStack_38;
    }
    if (*(uint *)(param_1 + 0x32c) < 8) {
      puVar4 = (ushort *)(param_1 + 0x318);
    }
    else {
      puVar4 = *(ushort **)(param_1 + 0x318);
    }
    do {
      uVar2 = *puVar4;
      bVar8 = uVar2 < *puVar5;
      if (uVar2 != *puVar5) {
LAB_005ce666:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_005ce66b;
      }
      if (uVar2 == 0) break;
      uVar2 = puVar4[1];
      bVar8 = uVar2 < puVar5[1];
      if (uVar2 != puVar5[1]) goto LAB_005ce666;
      puVar4 = puVar4 + 2;
      puVar5 = puVar5 + 2;
    } while (uVar2 != 0);
    iVar3 = 0;
LAB_005ce66b:
    if (iVar3 != 0) {
      FUN_00757800(&uStack_38);
      (**(code **)(**(int **)(param_1 + 0x314) + 200))();
      FUN_004026e0(&uStack_38,0,0xffffffff);
    }
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&uStack_4c);
  return;
}

