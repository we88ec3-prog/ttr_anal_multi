
void FUN_0049d470(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int *piVar9;
  int *piVar10;
  int in_EDX;
  int *piVar11;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936f3c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(*(int *)(in_EDX + 0x158) + 8) != 3) {
    fVar2 = *(float *)(in_EDX + 0xa0);
    fVar3 = *(float *)(in_EDX + 0xa4);
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0;
      FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    fVar8 = DAT_00fb90bc * *(float *)(in_EDX + 0xb4);
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    piVar11 = (int *)*DAT_00fab13c;
    piVar10 = DAT_00fab13c;
    if (piVar11 != DAT_00fab13c) {
      do {
        iVar4 = piVar11[4];
        if ((((*(char *)(iVar4 + 4) == '\x03') && (*(int *)(iVar4 + 0x11c) == 0)) &&
            ((*(ushort *)(iVar4 + 0xe2) & 0x8000) == 0)) &&
           (fVar6 = *(float *)(iVar4 + 0xa0) - fVar2, fVar7 = *(float *)(iVar4 + 0xa4) - fVar3,
           fVar6 * fVar6 + fVar7 * fVar7 < fVar8 * fVar8 + 100.0)) {
          FUN_0074a200();
          piVar10 = DAT_00fab13c;
        }
        if (*(char *)((int)piVar11 + 0x15) == '\0') {
          piVar5 = (int *)piVar11[2];
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar5 + 0x15);
            piVar11 = piVar5;
            piVar5 = (int *)*piVar5;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar5 + 0x15);
              piVar11 = piVar5;
              piVar5 = (int *)*piVar5;
            }
          }
          else {
            cVar1 = *(char *)(piVar11[1] + 0x15);
            piVar9 = (int *)piVar11[1];
            piVar5 = piVar11;
            while ((piVar11 = piVar9, cVar1 == '\0' && (piVar5 == (int *)piVar11[2]))) {
              cVar1 = *(char *)(piVar11[1] + 0x15);
              piVar9 = (int *)piVar11[1];
              piVar5 = piVar11;
            }
          }
        }
      } while (piVar11 != piVar10);
    }
  }
  ExceptionList = local_14;
  return;
}

