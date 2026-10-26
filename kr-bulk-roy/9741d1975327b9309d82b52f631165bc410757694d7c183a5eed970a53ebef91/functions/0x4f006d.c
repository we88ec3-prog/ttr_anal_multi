
undefined4 FUN_004f006d(void)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  code *pcVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int unaff_EBP;
  int *piVar10;
  int local_14;
  int local_10;
  void *local_4;
  
  local_4 = ExceptionList;
  ExceptionList = &local_4;
  iVar7 = *(int *)(unaff_EBP + 8);
  iVar3 = *(int *)(unaff_EBP + 0xc);
  cVar2 = *(char *)(iVar3 + 0xb);
  if (cVar2 == '\x01') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    FUN_00402160();
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
    }
    FUN_005740f0();
    if (local_10 == DAT_00fe5b10) {
      pcVar4 = (code *)swi(3);
      uVar5 = (*pcVar4)();
      return uVar5;
    }
    piVar6 = (int *)(local_10 + 0x10);
    piVar10 = piVar6;
    if (7 < *(uint *)(local_10 + 0x24)) {
      piVar6 = (int *)*piVar6;
      piVar10 = piVar6;
    }
    do {
      iVar7 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 2);
    } while ((short)iVar7 != 0);
  }
  else {
    if (cVar2 != '\x02') {
      if ((cVar2 == '\0') && (iVar8 = FUN_004ef160(), iVar8 != 0)) {
        puVar1 = (undefined4 *)(iVar8 + 0x68 + (uint)*(byte *)(iVar3 + 10) * 0x18);
        FUN_00404c10();
        puVar9 = (undefined4 *)FUN_0051d6d0();
        if (*(char *)(iVar7 + 0x1a) == '\0') {
          if (*(byte *)(puVar1 + 4) < 2) {
            FUN_004054c0();
            FUN_00402250();
            uVar5 = 0xae;
            FUN_005854b0(0xae);
            FUN_00585330(uVar5);
            FUN_004ed610();
          }
          else {
            FUN_004054c0();
            FUN_00402250();
            if (7 < (uint)puVar9[5]) {
              puVar9 = (undefined4 *)*puVar9;
            }
            uVar5 = 0xad;
            FUN_005854b0(0xad,puVar9);
            FUN_00585330(uVar5);
            FUN_00498f10();
          }
          FUN_0058b270(0xca);
        }
        else {
          piVar6 = (int *)(iVar7 + 0x1c);
          *piVar6 = *piVar6 + -1;
          iVar7 = FUN_00891268();
          if (iVar7 == 0) {
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
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    FUN_00402160();
    iVar7 = FUN_005854b0();
    FUN_005740f0();
    if (local_14 == *(int *)(iVar7 + 4)) {
      pcVar4 = (code *)swi(3);
      uVar5 = (*pcVar4)();
      return uVar5;
    }
    piVar6 = (int *)(local_14 + 0x10);
    piVar10 = piVar6;
    if (7 < *(uint *)(local_14 + 0x24)) {
      piVar6 = (int *)*piVar6;
      piVar10 = piVar6;
    }
    do {
      iVar7 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 2);
    } while ((short)iVar7 != 0);
  }
  FUN_00402160(piVar10,(int)piVar6 - ((int)piVar10 + 2) >> 1);
  FUN_0058b270(0xca);
LAB_004f03e8:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  FUN_0058aee0();
  ExceptionList = local_4;
  return 0;
}

