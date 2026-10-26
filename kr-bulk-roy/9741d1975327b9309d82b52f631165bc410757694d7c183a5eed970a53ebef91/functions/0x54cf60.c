
void FUN_0054cf60(void)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uStack_20;
  uint auStack_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00943dc8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
  if (iVar5 == 0) {
    ExceptionList = local_14;
    return;
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  uStack_20 = DAT_00fbab30;
  FUN_0082ef00(&uStack_20);
  if ((auStack_1c[0] == DAT_00fab13c) || (*(int *)(auStack_1c[0] + 0x10) == 0)) {
    DAT_00fbab30 = (uint)*(ushort *)(iVar5 + 4);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  switch(DAT_00f9392c) {
  default:
    uVar1 = *(ushort *)(iVar5 + 4);
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      uStack_c = 2;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      uStack_c = 0xffffffff;
    }
    break;
  case 0xffffffff:
  case 0:
  case 1:
  case 5:
  case 7:
  case 0x17:
  case 0x18:
    DAT_00fbab30 = (uint)*(ushort *)(iVar5 + 4);
    ExceptionList = local_14;
    return;
  }
  auStack_1c[0] = (uint)uVar1;
  FUN_0082ef00(auStack_1c);
  if (uStack_20 == DAT_00fab13c) {
    iVar9 = 0;
  }
  else {
    iVar9 = *(int *)(uStack_20 + 0x10);
  }
  bVar2 = false;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    uStack_c = 3;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    uStack_c = 0xffffffff;
  }
  iVar3 = DAT_00fb7258;
  if ((iVar9 != 0) && (*(char *)(iVar9 + 0xbc) != '\0')) {
    bVar2 = true;
    DAT_00fbab30 = DAT_00fbab44;
    if (DAT_00fbab48 != '\0') {
      DAT_00fbab48 = '\0';
      if (DAT_00fb7258 == 0) goto LAB_0054d3c7;
      uVar6 = FUN_00539a70();
      uVar10 = 0;
      auStack_1c[0] = uVar6;
      if (uVar6 != 0) {
        do {
          if (((((uVar10 < (uint)(*(int *)(iVar3 + 0x2c) - *(int *)(iVar3 + 0x28) >> 2)) &&
                (iVar9 = *(int *)(*(int *)(iVar3 + 0x28) + uVar10 * 4),
                *(char *)(iVar9 + 10) != '\0')) && (iVar9 != 0)) &&
              ((piVar7 = (int *)FUN_0054b8e0(), uVar6 = auStack_1c[0], piVar7 != (int *)0x0 &&
               (cVar4 = FUN_004c6ea0(piVar7), uVar6 = auStack_1c[0], cVar4 == '\0')))) &&
             (*piVar7 != *(int *)(iVar5 + 0x9c))) {
            DAT_00fbab30 = piVar7[1];
            DAT_00fbab2c = uVar10;
            DAT_00fbab44 = DAT_00fbab30;
            break;
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar6);
      }
    }
  }
  if (iVar3 != 0) {
    piVar7 = (int *)FUN_00444960();
    if ((*piVar7 == 0) &&
       ((*(int *)(iVar5 + 0x158) == 0 || (*(int *)(*(int *)(iVar5 + 0x158) + 0x34) != 0)))) {
      iVar5 = FUN_00444960();
      if (*(char *)(iVar5 + 0x7eb) != '\x01') {
        ExceptionList = local_14;
        return;
      }
      uVar10 = FUN_00539a70();
      uVar6 = DAT_00fbab2c + 1;
      if (uVar10 <= uVar6) {
        uVar6 = 0;
      }
      uVar8 = DAT_00fbab2c;
      auStack_1c[0] = uVar10;
      if (uVar6 == DAT_00fbab2c) {
        ExceptionList = local_14;
        return;
      }
      while ((((uint)(*(int *)(iVar3 + 0x2c) - *(int *)(iVar3 + 0x28) >> 2) <= uVar6 ||
              (iVar5 = *(int *)(*(int *)(iVar3 + 0x28) + uVar6 * 4), *(char *)(iVar5 + 10) == '\0'))
             || ((iVar5 == 0 ||
                 ((piVar7 = (int *)FUN_0054b8e0(), uVar10 = auStack_1c[0], uVar8 = DAT_00fbab2c,
                  piVar7 == (int *)0x0 ||
                  (cVar4 = FUN_004c6ea0(piVar7), uVar10 = auStack_1c[0], uVar8 = DAT_00fbab2c,
                  cVar4 != '\0'))))))) {
        if (uVar6 < uVar10) {
          uVar6 = uVar6 + 1;
        }
        if (uVar6 == uVar8) {
          ExceptionList = local_14;
          return;
        }
      }
    }
    else {
      if (!bVar2) {
        iVar9 = FUN_00404ba0();
        piVar7 = *(int **)(iVar3 + 0x28);
        uVar6 = *(int *)(iVar3 + 0x2c) - (int)piVar7 >> 2;
        uVar10 = 0;
        if (uVar6 != 0) {
          do {
            if ((*(char *)(*piVar7 + 10) != '\0') && (*(int *)*piVar7 == *(int *)(iVar9 + 0x5f50)))
            goto LAB_0054d397;
            uVar10 = uVar10 + 1;
            piVar7 = piVar7 + 1;
          } while (uVar10 < uVar6);
        }
        uVar10 = 0xffffffff;
LAB_0054d397:
        DAT_00fbab2c = -(uint)(uVar10 != 0xffffffff) & uVar10;
        DAT_00fbab30 = (uint)*(ushort *)(iVar5 + 4);
        ExceptionList = local_14;
        return;
      }
      iVar9 = FUN_00444960();
      if (*(char *)(iVar9 + 0x7eb) != '\x01') {
        ExceptionList = local_14;
        return;
      }
      uVar10 = FUN_00539a70();
      uVar6 = DAT_00fbab2c + 1;
      if (uVar10 <= uVar6) {
        uVar6 = 0;
      }
      uVar8 = DAT_00fbab2c;
      auStack_1c[0] = uVar10;
      if (uVar6 == DAT_00fbab2c) {
        ExceptionList = local_14;
        return;
      }
      while (((((uint)(*(int *)(iVar3 + 0x2c) - *(int *)(iVar3 + 0x28) >> 2) <= uVar6 ||
               (iVar9 = *(int *)(*(int *)(iVar3 + 0x28) + uVar6 * 4), *(char *)(iVar9 + 10) == '\0')
               ) || (iVar9 == 0)) ||
             (((piVar7 = (int *)FUN_0054b8e0(), uVar10 = auStack_1c[0], uVar8 = DAT_00fbab2c,
               piVar7 == (int *)0x0 ||
               (cVar4 = FUN_004c6ea0(piVar7), uVar10 = auStack_1c[0], uVar8 = DAT_00fbab2c,
               cVar4 != '\0')) || (*piVar7 == *(int *)(iVar5 + 0x9c)))))) {
        if (uVar6 < uVar10) {
          uVar6 = uVar6 + 1;
        }
        else {
          uVar6 = 0;
        }
        if (uVar6 == uVar8) {
          ExceptionList = local_14;
          return;
        }
      }
    }
    DAT_00fbab30 = piVar7[1];
    DAT_00fbab2c = uVar6;
    DAT_00fbab44 = piVar7[1];
    ExceptionList = local_14;
    return;
  }
LAB_0054d3c7:
  DAT_00fbab30 = (uint)*(ushort *)(iVar5 + 4);
  DAT_00fbab2c = 0;
  ExceptionList = local_14;
  return;
}

