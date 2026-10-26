
void FUN_0040d8e0(int param_1)

{
  ushort uVar1;
  float fVar2;
  float *pfVar3;
  code *pcVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined1 auStack_98 [20];
  undefined4 uStack_84;
  undefined1 auStack_6c [4];
  float fStack_68;
  float fStack_64;
  undefined1 *puStack_60;
  float *pfStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00945a38;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_6c;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    uStack_84 = 0x40d941;
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if ((DAT_00fba7a4 != (int *)0x0) &&
     (pfVar3 = (float *)(**(code **)(*DAT_00fba7a4 + 0x20))(), pfStack_5c = pfVar3,
     pfVar3 != (float *)0x0)) {
    if ((pfVar3[0x56] == 0.0) || (*(int *)((int)pfVar3[0x56] + 0x34) != 0)) {
      pcVar4 = *(code **)(**(int **)(param_1 + 0x80) + 0x128);
      (*(int **)(param_1 + 0x80))[0x34] = 0;
      (*pcVar4)();
      puStack_60 = auStack_98;
      FUN_0040e460(&DAT_00bf2bf8);
      FUN_0040eff0(*(undefined4 *)(param_1 + 0x80));
      (**(code **)(**(int **)(param_1 + 0x80) + 200))();
      pcVar4 = *(code **)(**(int **)(param_1 + 0x84) + 0x128);
      (*(int **)(param_1 + 0x84))[0x34] = 0;
      (*pcVar4)();
      puStack_60 = auStack_98;
      FUN_0040e460(&DAT_00bf2bf8);
      FUN_0040eff0(*(undefined4 *)(param_1 + 0x84));
      (**(code **)(**(int **)(param_1 + 0x84) + 200))();
      pcVar4 = *(code **)(**(int **)(param_1 + 0x88) + 0x128);
      (*(int **)(param_1 + 0x88))[0x34] = 0;
      (*pcVar4)();
      puStack_60 = auStack_98;
      FUN_0040e460(&DAT_00bf2bf8);
      FUN_0040eff0(*(undefined4 *)(param_1 + 0x88));
      pcVar4 = *(code **)(**(int **)(param_1 + 0x88) + 200);
    }
    else {
      puStack_60 = auStack_98;
      FUN_0040e460(&DAT_00bf2bf8);
      FUN_0040eff0(*(undefined4 *)(param_1 + 0x80));
      (**(code **)(**(int **)(param_1 + 0x80) + 200))();
      fVar2 = pfVar3[0xef];
      if ((int)fVar2 < 1) {
        piVar6 = *(int **)(param_1 + 0x80);
        piVar6[0x34] = 0;
      }
      else {
        fStack_64 = pfVar3[0xf2];
        piVar6 = *(int **)(param_1 + 0x80);
        piVar6[0x34] = (int)((float)(int)fStack_64 / (float)(int)fVar2);
        fStack_68 = fVar2;
      }
      (**(code **)(*piVar6 + 0x128))();
      puStack_60 = auStack_98;
      FUN_0040e460(&DAT_00bf2bf8);
      FUN_0040eff0(*(undefined4 *)(param_1 + 0x84));
      (**(code **)(**(int **)(param_1 + 0x84) + 200))();
      fVar2 = pfVar3[0xf0];
      if ((int)fVar2 < 1) {
        piVar6 = *(int **)(param_1 + 0x84);
        piVar6[0x34] = 0;
      }
      else {
        fStack_64 = pfVar3[0xf3];
        piVar6 = *(int **)(param_1 + 0x84);
        piVar6[0x34] = (int)((float)(int)fStack_64 / (float)(int)fVar2);
        fStack_68 = fVar2;
      }
      (**(code **)(*piVar6 + 0x128))();
      puStack_60 = auStack_98;
      FUN_0040e460(&DAT_00bf2bf8);
      FUN_0040eff0(*(undefined4 *)(param_1 + 0x88));
      (**(code **)(**(int **)(param_1 + 0x88) + 200))();
      fVar2 = pfVar3[0xf1];
      if ((int)fVar2 < 1) {
        piVar6 = *(int **)(param_1 + 0x88);
        piVar6[0x34] = 0;
      }
      else {
        fStack_64 = pfVar3[0xf4];
        piVar6 = *(int **)(param_1 + 0x88);
        piVar6[0x34] = (int)((float)(int)fStack_64 / (float)(int)fVar2);
        fStack_68 = fVar2;
      }
      pcVar4 = *(code **)(*piVar6 + 0x128);
    }
    (*pcVar4)();
    uVar1 = *(ushort *)(pfVar3 + 0x22);
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 1;
      FUN_005c3de0();
      uStack_84 = 0x40dc48;
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = 0xffffffff;
    }
    fStack_64 = (float)(&DAT_00f943f0)[uVar1];
    if (((*(char *)(*(int *)(param_1 + 0x90) + 0xa4) != '\0') &&
        (piVar6 = *(int **)(*(int *)(param_1 + 0x90) + 0x94), piVar6 != (int *)0x0)) &&
       (iVar5 = (**(code **)(*piVar6 + 4))(), iVar5 == 0xbf6b)) {
      FUN_0077b200();
    }
    (**(code **)(**(int **)(param_1 + 0x90) + 200))();
    FUN_0040ef80();
    local_c = 2;
    uStack_84 = 0x40dcd2;
    FUN_00757800();
    local_c = 0xffffffff;
    if (7 < uStack_24) {
      uStack_84 = 0x40dceb;
      FUN_0089120c();
    }
    (**(code **)(**(int **)(param_1 + 0x8c) + 200))();
    piVar6 = (int *)(param_1 + 0x9c);
    fStack_68 = 2.8026e-45;
    do {
      if ((*(uint *)(*piVar6 + 0x28) >> 7 & 1) != 0) {
        FUN_0040f230();
      }
      piVar6 = piVar6 + 1;
      fStack_68 = (float)((int)fStack_68 + -1);
    } while (fStack_68 != 0.0);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 3;
      FUN_004e1590();
      uStack_84 = 0x40dd4c;
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    iVar5 = *(int *)(param_1 + 0x98);
    *(undefined4 *)(iVar5 + 0xe0) = DAT_00f93930;
    *(undefined4 *)(iVar5 + 0xdc) = 2;
    uStack_84 = 0x40dd7f;
    FUN_0068b260();
    if (*(char *)(param_1 + 0xb4) == '\0') {
      if (DAT_00fba7cc == 0) {
        uStack_84 = 0x40dd9f;
        iVar5 = FUN_00891268();
        if (iVar5 == 0) {
          DAT_00fba7cc = 0;
        }
        else {
          DAT_00fba7cc = FUN_006df3d0();
        }
      }
      pfVar3 = (float *)(param_1 + 0xb0);
      pfStack_5c = (float *)(param_1 + 0xac);
      fStack_64 = 1.0 / (float)*(int *)(DAT_00fba7cc + 0x1360);
      if (*pfVar3 + fStack_64 < *pfStack_5c) {
        uStack_58 = 0x37;
        puVar7 = (undefined4 *)(param_1 + 0xa4);
        fStack_68 = 2.8026e-45;
        do {
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c = 4;
            uStack_84 = 0x40de36;
            FUN_00584c40();
            uStack_84 = 0x40de40;
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_c = 0xffffffff;
          }
          uStack_84 = 0x40de5e;
          FUN_005740f0();
          if (puStack_60 == DAT_00fe5ac8) {
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          FUN_004068f0();
          local_c = 5;
          uStack_84 = 0x40dea6;
          FUN_00757800();
          local_c = 0xffffffff;
          if (7 < uStack_40) {
            uStack_84 = 0x40debf;
            FUN_0089120c();
          }
          uStack_54 = uStack_54 & 0xffff0000;
          uStack_40 = 7;
          uStack_44 = 0;
          (**(code **)(*(int *)*puVar7 + 200))();
          puVar7 = puVar7 + 1;
          fStack_68 = (float)((int)fStack_68 + -1);
        } while (fStack_68 != 0.0);
      }
      *pfVar3 = *pfVar3 + fStack_64;
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_6c);
  return;
}

