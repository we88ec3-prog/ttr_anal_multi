
void FUN_00674b00(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_a0 [12];
  undefined4 uStack_94;
  int iStack_90;
  undefined1 **ppuStack_8c;
  uint uVar7;
  int iStack_74;
  uint uStack_70;
  undefined1 *puStack_6c;
  int iStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_48;
  uint uStack_44;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0094871c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_74;
  ExceptionList = &local_14;
  *(undefined4 *)(*(int *)(param_1 + 0x110) + 0xd4) = 0;
  if (*(int *)(param_1 + 0x1b4) != 0) {
    iVar1 = *(int *)(param_1 + 0xf4);
    if (*(char *)(iVar1 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      ppuStack_8c = (undefined1 **)0x674b6d;
      FUN_006edb10();
    }
    *(undefined4 *)(iVar1 + 0x168) = 0;
    *(undefined4 *)(iVar1 + 0x160) = 0;
    *(undefined4 *)(iVar1 + 0x164) = 0;
    *(undefined4 *)(iVar1 + 0x14c) = 0;
    (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
    iVar1 = *(int *)(param_1 + 0xf8);
    if (*(char *)(iVar1 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      ppuStack_8c = (undefined1 **)0x674bc5;
      FUN_006edb10();
    }
    *(undefined4 *)(iVar1 + 0x168) = 0;
    *(undefined4 *)(iVar1 + 0x160) = 0;
    *(undefined4 *)(iVar1 + 0x164) = 0;
    *(undefined4 *)(iVar1 + 0x14c) = 0;
    (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
    iVar1 = *(int *)(param_1 + 0xfc);
    if (*(char *)(iVar1 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      ppuStack_8c = (undefined1 **)0x674c1d;
      FUN_006edb10();
    }
    *(undefined4 *)(iVar1 + 0x168) = 0;
    *(undefined4 *)(iVar1 + 0x160) = 0;
    *(undefined4 *)(iVar1 + 0x164) = 0;
    *(undefined4 *)(iVar1 + 0x14c) = 0;
    (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
    ppuStack_8c = (undefined1 **)0x674c68;
    FUN_00749920();
    (**(code **)(**(int **)(param_1 + 0x110) + 200))();
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      uStack_c = 0;
      FUN_004e1590();
      ppuStack_8c = (undefined1 **)0x674c9b;
      _atexit((_func_4879 *)&LAB_00bccc80);
      uStack_c = 0xffffffff;
    }
    puStack_6c = auStack_a0;
    FUN_00412df0();
    uStack_c = 1;
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      uStack_c._0_1_ = 2;
      uStack_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      uStack_c = CONCAT31(uStack_c._1_3_,1);
    }
    iStack_74 = 0x1a;
    FUN_005740f0(&iStack_74);
    if (uStack_70 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar3 = (undefined4 *)(uStack_70 + 0x10);
    if (7 < *(uint *)(uStack_70 + 0x24)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    uStack_c = 0xffffffff;
    FUN_00424c80(puVar3);
    uStack_c = 3;
    ppuStack_8c = (undefined1 **)0x674d67;
    FUN_00757800();
    uStack_c = 0xffffffff;
    if (7 < uStack_24) {
      ppuStack_8c = (undefined1 **)0x674d7c;
      FUN_0089120c();
    }
    (**(code **)(**(int **)(param_1 + 0x128) + 200))();
    ppuStack_8c = (undefined1 **)0x674da2;
    (**(code **)(**(int **)(param_1 + 0x138) + 0xa0))();
    ppuStack_8c = (undefined1 **)0x674db2;
    (**(code **)(**(int **)(param_1 + 0x138) + 200))();
    *(undefined4 *)(param_1 + 0x1b8) = 0;
    *(undefined4 *)(param_1 + 0x1bc) = 0;
    *(undefined4 *)(param_1 + 0x1c0) = 0;
    *(undefined4 *)(param_1 + 0x1c4) = 0;
    iVar1 = *(int *)(*(int *)(param_1 + 0x104) + 0x24c);
    iVar6 = *(int *)(param_1 + 0x1b4) + 0x20;
    iStack_74 = iVar6;
    if ((iVar1 != 0) &&
       (ppuStack_8c = *(undefined1 ***)(iVar1 + 0xcc), ppuStack_8c != (undefined1 **)0x0)) {
      iStack_90 = 0x674df7;
      FUN_006438f0();
    }
    ppuStack_8c = (undefined1 **)0x674e07;
    FUN_00757710();
    ppuStack_8c = &puStack_6c;
    uStack_94 = 0x674e12;
    iStack_90 = iVar6;
    FUN_005383a0();
    puStack_10 = (undefined1 *)0x4;
    uVar5 = iStack_68 - (int)puStack_6c >> 2;
    uVar7 = 0;
    uStack_70 = uVar5;
    if (uVar5 != 0) {
      do {
        ppuStack_8c = (undefined1 **)0x674e4f;
        uStack_5c = FUN_00538e60();
        puStack_10._0_1_ = 5;
        iVar1 = *(int *)(param_1 + 0x104);
        iVar6 = *(int *)(iVar1 + 0x24c);
        if (iVar6 != 0) {
          iVar6 = *(int *)(iVar6 + 0xcc);
          if (iVar6 == 0) {
            iVar6 = -1;
          }
          else {
            ppuStack_8c = *(undefined1 ***)(iVar6 + 0xe4);
            iStack_90 = 0x674e7e;
            iVar6 = FUN_0075d370();
          }
          iVar1 = *(int *)(*(int *)(iVar1 + 0x24c) + 0xcc);
          if (iVar1 != 0) {
            for (piVar4 = *(int **)(iVar1 + 0xa8);
                (piVar4 != *(int **)(iVar1 + 0xac) && (*(int *)(*piVar4 + 0x20) != iVar6));
                piVar4 = piVar4 + 1) {
            }
          }
          ppuStack_8c = (undefined1 **)uStack_5c;
          iStack_90 = 0x674ec7;
          FUN_00757800();
          uVar5 = uStack_70;
        }
        puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,4);
        if (7 < uStack_44) {
          ppuStack_8c = (undefined1 **)uStack_58;
          iStack_90 = 0x674ee1;
          FUN_0089120c();
        }
        uVar7 = uVar7 + 1;
        uStack_44 = 7;
        uStack_48 = 0;
        uStack_58 = uStack_58 & 0xffff0000;
      } while (uVar7 < uVar5);
    }
    ppuStack_8c = *(undefined1 ***)(*(int *)(param_1 + 0x104) + 0x24c);
    if (ppuStack_8c != (undefined1 **)0x0) {
      iStack_90 = 0x674f24;
      FUN_00749920();
    }
    ppuStack_8c = (undefined1 **)0x674f34;
    (**(code **)(**(int **)(param_1 + 0x104) + 200))();
    uStack_c = 0xffffffff;
    if (iStack_68 != 0) {
      ppuStack_8c = (undefined1 **)0x674f4a;
      FUN_0089120c();
    }
    ppuStack_8c = (undefined1 **)param_1;
    iStack_68 = 0;
    uStack_64 = 0;
    uStack_60 = 0;
    iStack_90 = 0x674f60;
    FUN_00674fb0();
    puVar3 = (undefined4 *)**(int **)(param_1 + 0x1b4);
    if (puVar3 == (undefined4 *)(*(int **)(param_1 + 0x1b4))[1]) {
      *(undefined4 *)(param_1 + 0x1c8) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x1c8) = *puVar3;
    }
    FUN_006767d0();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&iStack_74);
  return;
}

