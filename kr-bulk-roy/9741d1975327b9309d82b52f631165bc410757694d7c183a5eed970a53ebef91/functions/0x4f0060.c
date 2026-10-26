
undefined4 FUN_004f0060(int param_1,int param_2)

{
  undefined4 *puVar1;
  char cVar2;
  code *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iStack_24;
  int iStack_20;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092f938;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  cVar2 = *(char *)(param_2 + 0xb);
  if (cVar2 == '\x01') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      uStack_c = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    uStack_c = 0xffffffff;
    FUN_00402160();
    uStack_c = 1;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      uStack_c._0_1_ = 2;
      uStack_c._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      uStack_c = CONCAT31(uStack_c._1_3_,1);
    }
    FUN_005740f0();
    if (iStack_20 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    piVar5 = (int *)(iStack_20 + 0x10);
    piVar8 = piVar5;
    if (7 < *(uint *)(iStack_20 + 0x24)) {
      piVar5 = (int *)*piVar5;
      piVar8 = piVar5;
    }
    do {
      iVar6 = *piVar5;
      piVar5 = (int *)((int)piVar5 + 2);
    } while ((short)iVar6 != 0);
  }
  else {
    if (cVar2 != '\x02') {
      if ((cVar2 == '\0') && (iVar6 = FUN_004ef160(), iVar6 != 0)) {
        puVar1 = (undefined4 *)(iVar6 + 0x68 + (uint)*(byte *)(param_2 + 10) * 0x18);
        FUN_00404c10();
        puVar7 = (undefined4 *)FUN_0051d6d0();
        if (*(char *)(param_1 + 0x1a) == '\0') {
          if (*(byte *)(puVar1 + 4) < 2) {
            FUN_004054c0();
            FUN_00402250();
            uStack_c = 6;
            uVar4 = 0xae;
            FUN_005854b0(0xae);
            FUN_00585330(uVar4);
            FUN_004ed610();
          }
          else {
            FUN_004054c0();
            FUN_00402250();
            uStack_c = 5;
            if (7 < (uint)puVar7[5]) {
              puVar7 = (undefined4 *)*puVar7;
            }
            uVar4 = 0xad;
            FUN_005854b0(0xad,puVar7);
            FUN_00585330(uVar4);
            FUN_00498f10();
          }
          uStack_c = 0xffffffff;
          FUN_0058b270(0xca);
        }
        else {
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
          iVar6 = FUN_00891268();
          if (iVar6 == 0) {
            FUN_00404aa0();
            FUN_00750020();
          }
          else {
            FUN_00753d00();
            FUN_00404aa0();
            FUN_00750020();
          }
        }
        puVar1[2] = 0;
        puVar1[3] = 0;
        *puVar1 = 0;
        *(undefined1 *)(puVar1 + 4) = 0;
      }
      goto LAB_004f03e8;
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      uStack_c = 3;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    uStack_c = 0xffffffff;
    FUN_00402160();
    uStack_c = 4;
    iVar6 = FUN_005854b0();
    FUN_005740f0();
    if (iStack_24 == *(int *)(iVar6 + 4)) {
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    piVar5 = (int *)(iStack_24 + 0x10);
    piVar8 = piVar5;
    if (7 < *(uint *)(iStack_24 + 0x24)) {
      piVar5 = (int *)*piVar5;
      piVar8 = piVar5;
    }
    do {
      iVar6 = *piVar5;
      piVar5 = (int *)((int)piVar5 + 2);
    } while ((short)iVar6 != 0);
  }
  FUN_00402160(piVar8,(int)piVar5 - ((int)piVar8 + 2) >> 1);
  uStack_c = 0xffffffff;
  FUN_0058b270(0xca);
LAB_004f03e8:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    uStack_c = 7;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    uStack_c = 0xffffffff;
  }
  FUN_0058aee0();
  ExceptionList = pvStack_14;
  return 0;
}

