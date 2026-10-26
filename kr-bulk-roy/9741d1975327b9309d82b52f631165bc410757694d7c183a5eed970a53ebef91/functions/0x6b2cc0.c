
void FUN_006b2cc0(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int aiStack_5c [2];
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_3c;
  uint uStack_28;
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094269c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)aiStack_5c;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffff98);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  iVar1 = *(int *)(DAT_00fab130 + 0x5eac);
  if (iVar1 != in_ECX[0x27]) {
    (**(code **)(*in_ECX + 0x16c))(iVar1);
    in_ECX[0x27] = iVar1;
  }
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 1;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_c = 0xffffffff;
  }
  iVar1 = DAT_00fb7258;
  uVar6 = 0;
  if (DAT_00fb7258 == 0) {
    uVar5 = FUN_0040e460(&DAT_00bf2bf8);
    local_c = 3;
    FUN_00757800(uVar5);
    local_c = 0xffffffff;
    if (7 < uStack_40) {
      FUN_0089120c(uStack_54);
    }
    uStack_54 = uStack_54 & 0xffff0000;
    uStack_40 = 7;
    uStack_44 = 0;
    (**(code **)(*(int *)in_ECX[0x20] + 200))();
    in_ECX[0x28] = 0;
    in_ECX[0x29] = 0;
  }
  else {
    piVar7 = *(int **)(DAT_00fb7258 + 0x28);
    uVar3 = *(int *)(DAT_00fb7258 + 0x2c) - (int)piVar7 >> 2;
    if (uVar3 != 0) {
      do {
        if ((*(char *)(*piVar7 + 10) != '\0') && (*(char *)(*piVar7 + 6) != '\0')) {
          uVar3 = *(uint *)(DAT_00fb7258 + 0x28);
          puVar2 = *(uint **)(uVar3 + uVar6 * 4);
          if (puVar2 != (uint *)0x0) {
            iVar4 = FUN_00404ba0();
            uVar3 = *(uint *)(iVar4 + 0x5f50);
            if (*puVar2 == uVar3) {
              uVar3 = CONCAT31((int3)(uVar3 >> 8),1);
              goto LAB_006b2dbe;
            }
          }
          break;
        }
        uVar6 = uVar6 + 1;
        piVar7 = piVar7 + 1;
      } while (uVar6 < uVar3);
    }
    uVar3 = uVar3 & 0xffffff00;
LAB_006b2dbe:
    (**(code **)(*(int *)in_ECX[0x25] + 0x94))(uVar3);
    piVar7 = *(int **)(iVar1 + 0x28);
    iVar8 = 0;
    for (iVar4 = *(int *)(iVar1 + 0x2c) - (int)piVar7 >> 2; iVar4 != 0; iVar4 = iVar4 + -1) {
      if (*(char *)(*piVar7 + 10) != '\0') {
        iVar8 = iVar8 + 1;
      }
      piVar7 = piVar7 + 1;
    }
    aiStack_5c[0] = *(int *)(iVar1 + 0x20);
    if ((in_ECX[0x28] != iVar8) || (in_ECX[0x29] != aiStack_5c[0])) {
      uVar5 = FUN_0040e460(&DAT_00bf2bf8);
      puStack_10 = (undefined1 *)0x2;
      FUN_00757800(uVar5);
      puStack_10 = (undefined1 *)0xffffffff;
      if (7 < uStack_28) {
        FUN_0089120c(uStack_3c);
      }
      (**(code **)(*(int *)in_ECX[0x20] + 200))();
      in_ECX[0x28] = iVar8;
      in_ECX[0x29] = aiStack_5c[0];
    }
  }
  ExceptionList = pvStack_18;
  __security_check_cookie(uStack_20 ^ (uint)&stack0xffffffa0);
  return;
}

