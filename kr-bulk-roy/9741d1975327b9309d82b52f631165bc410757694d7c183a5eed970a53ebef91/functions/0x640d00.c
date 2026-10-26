
void FUN_00640d00(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  short *psVar5;
  short *psVar6;
  uint uVar7;
  int iVar8;
  int in_ECX;
  int *piVar9;
  int iVar10;
  undefined1 auStack_7c [4];
  int *local_78;
  int *local_74;
  int *local_70;
  int *local_6c;
  int local_68;
  undefined4 uStack_64;
  undefined4 uStack_54;
  uint uStack_50;
  undefined4 *puStack_48;
  undefined4 *puStack_44;
  undefined4 uStack_40;
  uint auStack_38 [4];
  int iStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093daf0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_7c;
  ExceptionList = &local_14;
  local_68 = in_ECX;
  FUN_0074a980(DAT_00d61f20 ^ (uint)&stack0xffffff78);
  piVar9 = (int *)(in_ECX + 0x130);
  local_74 = piVar9;
  FUN_00677fa0(200);
  FUN_00643bf0();
  FUN_00643ce0(400);
  FUN_00643ce0(500);
  local_6c = (int *)(in_ECX + 0x134);
  FUN_00677fa0(600);
  iVar10 = 0;
  if ((*(int *)(*piVar9 + 0x24c) != 0) &&
     (iVar1 = *(int *)(*(int *)(*piVar9 + 0x24c) + 0xcc), iVar1 != 0)) {
    FUN_006438f0(iVar1);
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_78 = (int *)0x236;
  FUN_005740f0(&local_78);
  if (local_70 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  local_78 = local_70 + 4;
  if (7 < (uint)local_70[9]) {
    local_78 = (int *)*local_78;
  }
  if (*(int *)(*piVar9 + 0x24c) != 0) {
    iVar1 = *(int *)(*(int *)(*piVar9 + 0x24c) + 0xcc);
    if (iVar1 != 0) {
      iVar10 = FUN_00412c70(*(undefined4 *)(iVar1 + 0xe4));
    }
    FUN_00757710();
  }
  uVar7 = DAT_00fe5ae4 & 1;
  *(undefined4 *)(iVar10 + 0x154) = DAT_00d65888;
  if (uVar7 == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 1;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_70 = (int *)0x237;
  FUN_005740f0(&local_70);
  if (local_78 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(int *)(*local_74 + 0x24c) == 0) {
    iVar10 = 0;
  }
  else {
    iVar10 = *(int *)(*(int *)(*local_74 + 0x24c) + 0xcc);
    if (iVar10 == 0) {
      iVar10 = 0;
      FUN_00757710();
    }
    else {
      iVar10 = FUN_00412c70(*(undefined4 *)(iVar10 + 0xe4));
      FUN_00757710();
    }
  }
  uVar7 = DAT_00fe5ae4 & 1;
  *(undefined4 *)(iVar10 + 0x154) = DAT_00d6588c;
  if (uVar7 == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_70 = (int *)0x238;
  FUN_005740f0(&local_70);
  if (local_78 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(int *)(*local_74 + 0x24c) == 0) {
    iVar10 = 0;
  }
  else {
    iVar10 = *(int *)(*(int *)(*local_74 + 0x24c) + 0xcc);
    if (iVar10 == 0) {
      iVar10 = 0;
      FUN_00757710();
    }
    else {
      iVar10 = FUN_00412c70(*(undefined4 *)(iVar10 + 0xe4));
      FUN_00757710();
    }
  }
  uVar7 = DAT_00fe5ae4 & 1;
  *(undefined4 *)(iVar10 + 0x154) = DAT_00d65890;
  if (uVar7 == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 3;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_70 = (int *)0x239;
  FUN_005740f0(&local_70);
  if (local_74 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar10 = *(int *)(*(int *)(local_68 + 0x130) + 0x24c);
  if (iVar10 == 0) {
    iVar10 = 0;
  }
  else {
    iVar10 = *(int *)(iVar10 + 0xcc);
    if (iVar10 == 0) {
      iVar10 = 0;
      FUN_00757710();
    }
    else {
      iVar10 = FUN_00412c70(*(undefined4 *)(iVar10 + 0xe4));
      FUN_00757710();
    }
  }
  uVar7 = DAT_00fe5ae4 & 1;
  *(undefined4 *)(iVar10 + 0x154) = DAT_00d65894;
  if (uVar7 == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 4;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_70 = (int *)0x23c;
  FUN_005740f0(&local_70);
  if (local_74 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar10 = *(int *)(*(int *)(local_68 + 0x130) + 0x24c);
  if (iVar10 == 0) {
    iVar10 = 0;
  }
  else {
    iVar10 = *(int *)(iVar10 + 0xcc);
    if (iVar10 == 0) {
      iVar10 = 0;
      FUN_00757710();
    }
    else {
      iVar10 = FUN_00412c70(*(undefined4 *)(iVar10 + 0xe4));
      FUN_00757710();
    }
  }
  *(undefined4 *)(iVar10 + 0x154) = DAT_00d65898;
  iVar10 = *(int *)(*(int *)(local_68 + 0x130) + 0x24c);
  if (iVar10 != 0) {
    FUN_00749920(iVar10);
  }
  (**(code **)(**(int **)(local_68 + 0x130) + 200))();
  uVar7 = DAT_00faaf7c & 1;
  *(undefined4 *)(*(int *)(local_68 + 0x138) + 0x144) = 0x32;
  local_74 = (int *)0x3;
  if (uVar7 == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c = 5;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c = 0xffffffff;
  }
  FUN_0058ee60(&DAT_00faaf80);
  FUN_0075cd30(*(undefined4 *)(local_68 + 0x130));
  FUN_00402160(&DAT_00bed1fc,0);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c = 6;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c = 0xffffffff;
  }
  FUN_0058ef10(&DAT_00faaf80,L"LastWhisper");
  uStack_50 = 7;
  uStack_54 = 0;
  uStack_64 = (uint)uStack_64._2_2_ << 0x10;
  puStack_48 = (undefined4 *)0x0;
  puStack_44 = (undefined4 *)0x0;
  uStack_40 = 0;
  local_c = 7;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 8;
    local_c._1_3_ = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = CONCAT31(local_c._1_3_,7);
  }
  psVar5 = &DAT_00f938f2;
  do {
    psVar6 = psVar5;
    psVar5 = psVar6 + 1;
  } while (*psVar6 != 0);
  FUN_00402160(&DAT_00f938f2,(int)(psVar6 + -0x7c9c79) >> 1);
  FUN_00582940(&uStack_64);
  local_78 = (int *)0x0;
  if ((*(int *)(*local_6c + 0x24c) != 0) &&
     (iVar10 = *(int *)(*(int *)(*local_6c + 0x24c) + 0xcc), iVar10 != 0)) {
    FUN_006438f0(iVar10);
  }
  FUN_00757710();
  iVar10 = 0;
  local_74 = (int *)0x0;
  while( true ) {
    uVar7 = ((int)puStack_44 - (int)puStack_48) / 0x1c;
    if (10 < uVar7) {
      uVar7 = 10;
    }
    if (uVar7 <= local_74) break;
    uStack_24 = 7;
    iStack_28 = 0;
    auStack_38[0] = auStack_38[0] & 0xffff0000;
    FUN_004026e0((int)puStack_48 + iVar10,0,0xffffffff);
    local_c._0_1_ = 9;
    if (iStack_28 != 0) {
      FUN_0049c120();
      iVar1 = *local_6c;
      iVar8 = *(int *)(iVar1 + 0x24c);
      if (iVar8 != 0) {
        iVar8 = *(int *)(iVar8 + 0xcc);
        if (iVar8 == 0) {
          iVar8 = -1;
        }
        else {
          iVar8 = FUN_0075d370(*(undefined4 *)(iVar8 + 0xe4));
        }
        iVar1 = *(int *)(*(int *)(iVar1 + 0x24c) + 0xcc);
        if (iVar1 != 0) {
          for (piVar9 = *(int **)(iVar1 + 0xa8);
              (piVar9 != *(int **)(iVar1 + 0xac) && (*(int *)(*piVar9 + 0x20) != iVar8));
              piVar9 = piVar9 + 1) {
          }
        }
        FUN_00757800(auStack_38);
      }
      local_78 = (int *)((int)local_78 + 1);
    }
    local_c = CONCAT31(local_c._1_3_,7);
    if (7 < uStack_24) {
      FUN_0089120c(auStack_38[0]);
    }
    local_74 = (int *)((int)local_74 + 1);
    iVar10 = iVar10 + 0x1c;
  }
  if (0 < (int)local_78) {
    if (*(int *)(*local_6c + 0x24c) != 0) {
      FUN_00749920(*(int *)(*local_6c + 0x24c));
    }
    piVar9 = local_6c;
    FUN_0075cd30(*local_6c);
    (**(code **)(*(int *)*piVar9 + 200))();
  }
  puVar4 = puStack_44;
  puVar3 = puStack_48;
  if (puStack_48 != (undefined4 *)0x0) {
    for (; puVar3 != puVar4; puVar3 = puVar3 + 7) {
      if (7 < (uint)puVar3[5]) {
        FUN_0089120c(*puVar3);
      }
      puVar3[5] = 7;
      puVar3[4] = 0;
      *(undefined2 *)puVar3 = 0;
    }
    FUN_0089120c(puStack_48);
  }
  puStack_48 = (undefined4 *)0x0;
  puStack_44 = (undefined4 *)0x0;
  uStack_40 = 0;
  if (7 < uStack_50) {
    FUN_0089120c(uStack_64);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_7c);
  return;
}

