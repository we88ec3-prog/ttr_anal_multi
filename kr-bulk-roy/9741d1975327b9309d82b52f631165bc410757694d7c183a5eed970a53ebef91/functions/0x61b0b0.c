
void FUN_0061b0b0(byte param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int unaff_EDI;
  int *piStack_40;
  undefined4 local_3c;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093df04;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&piStack_40;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((((param_1 < 10) &&
       (iVar5 = (uint)param_1 * 0x210 + DAT_00f94304, *(int *)(iVar5 + 0x5c) != 0)) && (iVar5 != 0))
     && (iVar5 != -0x1d4)) {
    iVar7 = *(int *)(*(int *)(unaff_EDI + 0xec) + 0xcc);
    if (iVar7 != 0) {
      FUN_00408920(iVar7,*(undefined4 *)(iVar5 + 0x1dc));
    }
    local_3c = *(undefined4 *)(iVar5 + 0x1d8);
    iVar7 = 0;
    (**(code **)(**(int **)(unaff_EDI + 0xf4) + 0x94))(*(int *)(iVar5 + 0x1dc) == 0);
    piVar8 = (int *)**(int **)(iVar5 + 0x1d8);
    if (piVar8 != piStack_40) {
      do {
        if (piVar8[4] != 0) {
          iVar5 = *(int *)(*(int *)(unaff_EDI + 0xec) + 0xcc);
          if (((iVar5 == 0) || (iVar7 < 0)) ||
             (*(int *)(iVar5 + 0xac) - *(int *)(iVar5 + 0xa8) >> 2 <= iVar7)) {
            iVar5 = 0;
          }
          else {
            iVar5 = *(int *)(*(int *)(iVar5 + 0xa8) + iVar7 * 4);
          }
          iVar7 = iVar7 + 1;
          if (iVar5 != 0) {
            FUN_0061aed0(*(undefined2 *)(piVar8[4] + 4));
          }
        }
        if (*(char *)((int)piVar8 + 0x15) == '\0') {
          piVar2 = (int *)piVar8[2];
          if (*(char *)((int)piVar2 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar8 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x15);
              piVar8 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar8[1] + 0x15);
            piVar3 = (int *)piVar8[1];
            piVar2 = piVar8;
            while ((piVar8 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar8[2]))) {
              cVar1 = *(char *)(piVar8[1] + 0x15);
              piVar3 = (int *)piVar8[1];
              piVar2 = piVar8;
            }
          }
        }
      } while (piVar8 != piStack_40);
    }
    FUN_00749920(*(undefined4 *)(unaff_EDI + 0xec));
    (**(code **)(**(int **)(unaff_EDI + 0xec) + 200))();
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  uVar6 = FUN_00412df0();
  local_c = 2;
  FUN_00757800(uVar6);
  local_c = 0xffffffff;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  uStack_38 = uStack_38 & 0xffff0000;
  uStack_24 = 7;
  uStack_28 = 0;
  (**(code **)(**(int **)(unaff_EDI + 0xf0) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&piStack_40);
  return;
}

