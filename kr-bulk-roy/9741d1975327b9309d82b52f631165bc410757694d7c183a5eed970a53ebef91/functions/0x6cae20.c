
void FUN_006cae20(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  code *pcVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uStack_6c;
  int local_68;
  int local_64;
  uint local_60;
  int local_5c;
  uint uStack_58;
  undefined4 uStack_48;
  uint uStack_44;
  undefined4 uStack_38;
  uint uStack_24;
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009422ec;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_6c;
  ExceptionList = &local_14;
  local_5c = in_ECX;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xffffff88);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_c = 0xffffffff;
  local_64 = -0x108 - in_ECX;
  local_68 = DAT_00fb7258;
  local_60 = 0;
  piVar5 = (int *)(in_ECX + 0x108);
  iVar3 = DAT_00fb7258;
  do {
    if ((((iVar3 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - *(int *)(iVar3 + 0x28) >> 2) <= local_60)
         ) || (puVar8 = *(undefined4 **)(*(int *)(iVar3 + 0x28) + local_64 + (int)piVar5),
              *(char *)((int)puVar8 + 10) == '\0')) || (puVar8 == (undefined4 *)0x0)) {
      (**(code **)(*(int *)piVar5[-4] + 0xd4))();
      (**(code **)(*(int *)*piVar5 + 0xd4))();
    }
    else {
      (**(code **)(*(int *)piVar5[-4] + 0xd0))();
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 1;
        FUN_004f3d80();
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_c = 0xffffffff;
      }
      FUN_004f6a30(*puVar8);
      FUN_00757710();
      (**(code **)(*(int *)piVar5[-4] + 200))();
      (**(code **)(*(int *)*piVar5 + 0xd0))();
      iVar3 = *piVar5;
      if (((*(char *)(iVar3 + 0xa4) != '\0') && (*(int **)(iVar3 + 0x94) != (int *)0x0)) &&
         (iVar2 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
        *(undefined1 *)(*(int *)(iVar3 + 0x94) + 0x4c) = 1;
      }
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        local_c = 2;
        FUN_005c3de0();
        _atexit((_func_4879 *)&LAB_00bccc30);
        local_c = 0xffffffff;
      }
      if (((*(char *)(*piVar5 + 0xa4) != '\0') &&
          (piVar1 = *(int **)(*piVar5 + 0x94), piVar1 != (int *)0x0)) &&
         (iVar3 = (**(code **)(*piVar1 + 4))(), iVar3 == 0xbf6b)) {
        FUN_0077b200();
      }
      (**(code **)(*(int *)*piVar5 + 200))();
      iVar3 = local_68;
    }
    iVar2 = DAT_00fe1b58;
    local_60 = local_60 + 1;
    piVar5 = piVar5 + 1;
  } while (local_60 < 4);
  FUN_006caaf0(*(undefined4 *)(local_5c + 0x118));
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 3;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_68 = 0x15;
  FUN_005740f0(&local_68);
  if (local_64 == DAT_00fe5ac8) {
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  uVar4 = FUN_00498f60();
  local_c = 4;
  FUN_00757800(uVar4);
  local_c = 0xffffffff;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  if (*(char *)(iVar2 + 0xc) == '\x01') {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 5;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c = 0xffffffff;
    }
    local_68 = 0x159;
    FUN_005740f0(&local_68);
    if (local_64 == DAT_00fe5ac8) {
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 6;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c = 0xffffffff;
    }
    local_68 = 0x15a;
    FUN_005740f0(&local_68);
    if (local_64 == DAT_00fe5ac8) {
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
  }
  FUN_00757710();
  (**(code **)(**(int **)(local_5c + 0xf0) + 200))();
  (**(code **)(**(int **)(local_5c + 0xf4) + 0x94))(*(char *)(iVar2 + 0xf) != '\0');
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    puStack_10 = (undefined1 *)0x7;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  uVar7 = *(uint *)(DAT_00fab130 + 0x5eb0);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    puStack_10 = (undefined1 *)0x8;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  iVar3 = *(int *)(DAT_00fab130 + 0x5eac);
  if ((DAT_00fe18fc & 1) == 0) {
    DAT_00fe18fc = DAT_00fe18fc | 1;
    puStack_10 = (undefined1 *)0x9;
    FUN_004fa330();
    _atexit((_func_4879 *)&LAB_00bce900);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1a70);
  uStack_6c = iVar3 << 0x10 | uVar7 & 0xffff;
  piVar5 = (int *)FUN_004fac60(&uStack_6c);
  iVar3 = *piVar5;
  if (iVar3 == DAT_00fe1904) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1a70);
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1a70);
    if (iVar3 != -0x10) {
      puVar10 = (undefined4 *)(local_60 + 0x120);
      puVar8 = (undefined4 *)(iVar3 + 0x18);
      local_64 = 5;
      do {
        if ((int)puVar8[7] < 1) {
          FUN_00757710();
        }
        else {
          puVar9 = puVar8;
          if (7 < (uint)puVar8[5]) {
            puVar9 = (undefined4 *)*puVar8;
          }
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            puStack_10 = (undefined1 *)0xa;
            FUN_00584c40(&DAT_00fe5ac4);
            _atexit((_func_4879 *)&LAB_00bcf390);
            puStack_10 = (undefined1 *)0xffffffff;
          }
          uStack_6c = 0xd;
          FUN_005740f0(&uStack_6c);
          if (local_68 == DAT_00fe5ac8) {
            pcVar6 = (code *)swi(3);
            (*pcVar6)();
            return;
          }
          uVar4 = FUN_00483f00(puVar9);
          puStack_10 = (undefined1 *)0xb;
          FUN_00757800(uVar4);
          puStack_10 = (undefined1 *)0xffffffff;
          if (7 < uStack_44) {
            FUN_0089120c(uStack_58);
          }
          uStack_44 = 7;
          uStack_48 = 0;
          uStack_58 = uStack_58 & 0xffff0000;
        }
        (**(code **)(*(int *)*puVar10 + 200))();
        FUN_006caaf0(puVar10[5]);
        puVar10 = puVar10 + 1;
        puVar8 = puVar8 + 9;
        local_64 = local_64 + -1;
      } while (local_64 != 0);
      local_64 = 0;
      goto LAB_006cb3b4;
    }
  }
  puVar8 = (undefined4 *)(local_5c + 0x134);
  iVar3 = 5;
  do {
    FUN_00757710();
    (**(code **)(*(int *)puVar8[-5] + 200))();
    FUN_00757710();
    (**(code **)(*(int *)*puVar8 + 200))();
    puVar8 = puVar8 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
LAB_006cb3b4:
  uStack_6c = (*(int *)(DAT_00fe1b58 + 0x18) - *(int *)(DAT_00fe1b58 + 0x14)) / 5;
  uVar11 = 0;
  uVar7 = 0;
  puVar8 = (undefined4 *)(local_60 + 0x148);
  do {
    if (uVar11 < uStack_6c) {
      if (uVar11 < (uint)((*(int *)(DAT_00fe1b58 + 0x18) - *(int *)(DAT_00fe1b58 + 0x14)) / 5)) {
        puVar10 = (undefined4 *)(*(int *)(DAT_00fe1b58 + 0x14) + uVar7);
      }
      else {
        puVar10 = (undefined4 *)0x0;
      }
      uVar4 = *puVar10;
      pcVar6 = *(code **)(*(int *)*puVar8 + 0x1ac);
    }
    else {
      pcVar6 = *(code **)(*(int *)*puVar8 + 0x1ac);
      uVar4 = 0xffffffff;
    }
    (*pcVar6)(0xffffffff,uVar4,0,0,0);
    (**(code **)(*(int *)*puVar8 + 200))();
    uVar7 = uVar7 + 5;
    uVar11 = uVar11 + 1;
    puVar8 = puVar8 + 1;
  } while (uVar7 < 0xf);
  ExceptionList = pvStack_18;
  __security_check_cookie(uStack_20 ^ (uint)&stack0xffffff90);
  return;
}

