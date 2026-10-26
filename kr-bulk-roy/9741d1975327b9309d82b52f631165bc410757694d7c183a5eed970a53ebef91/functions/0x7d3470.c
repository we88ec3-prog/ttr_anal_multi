
void FUN_007d3470(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *in_ECX;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint auStack_30 [4];
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0092baee;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar4 = DAT_00fb7740;
  local_c = 0xffffffff;
  if (0.99 <= (float)in_ECX[0x17]) {
    if (*(int *)(in_ECX[0x1d] + 0x18) != 0) {
      iVar3 = in_ECX[1];
      if (iVar3 == 0) {
        iVar3 = (**(code **)(*in_ECX + 4))();
      }
      iVar2 = *(int *)(iVar3 * 0x2004 + 0x2000 + iVar4);
      iVar4 = iVar3 * 0x2004 + iVar4;
      if (iVar2 < 0x800) {
        *(int **)(iVar4 + iVar2 * 4) = in_ECX;
        piVar1 = (int *)(iVar4 + 0x2000);
        *piVar1 = *piVar1 + 1;
      }
    }
    if (*(int *)(in_ECX[0x1d] + 0x14) == 0) goto LAB_007d3606;
    if (DAT_00fb7990 != 0) {
      if (DAT_00fb7990 != 1) goto LAB_007d3606;
      local_20 = in_ECX[0xb];
      local_1c = in_ECX[0xc];
      auStack_30[3] = in_ECX[10];
      FUN_0079bc80();
    }
  }
  else {
    iVar3 = in_ECX[1];
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*in_ECX + 4))();
    }
    iVar2 = *(int *)(iVar3 * 0x2004 + 0x2000 + iVar4);
    iVar4 = iVar3 * 0x2004 + iVar4;
    if (iVar2 < 0x800) {
      *(int **)(iVar4 + iVar2 * 4) = in_ECX;
      piVar1 = (int *)(iVar4 + 0x2000);
      *piVar1 = *piVar1 + 1;
    }
    if (DAT_00fb7990 != 0) {
      if (DAT_00fb7990 != 1) goto LAB_007d3606;
      auStack_30[3] = in_ECX[10];
      local_20 = in_ECX[0xb];
      local_1c = in_ECX[0xc];
      FUN_0079bc80();
    }
  }
  FUN_0079a3c0();
LAB_007d3606:
  auStack_30[2] = in_ECX[0x23] - in_ECX[0x22] >> 2;
  auStack_30[1] = 0;
  puVar9 = DAT_00fb7774;
  if (auStack_30[2] != 0) {
    do {
      uVar5 = *(uint *)(in_ECX[0x22] + auStack_30[1] * 4);
      auStack_30[0] = uVar5;
      if ((auStack_30 < DAT_00fb7778) && (puVar9 <= auStack_30)) {
        puVar8 = puVar9;
        if (DAT_00fb7778 == DAT_00fb777c) {
          uVar5 = (int)DAT_00fb7778 - (int)puVar9 >> 2;
          if (0x3ffffffe < uVar5) {
LAB_007d374d:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar5 = uVar5 + 1;
          uVar6 = (int)DAT_00fb777c - (int)puVar9 >> 2;
          if (uVar6 < uVar5) {
            if (0x3fffffff - (uVar6 >> 1) < uVar6) {
              uVar6 = 0;
            }
            else {
              uVar6 = uVar6 + (uVar6 >> 1);
            }
            if (uVar6 < uVar5) {
              uVar6 = uVar5;
            }
            FUN_00797980(uVar6);
            puVar8 = DAT_00fb7774;
          }
        }
        if (DAT_00fb7778 != (uint *)0x0) {
          *DAT_00fb7778 = puVar8[(int)auStack_30 - (int)puVar9 >> 2];
          puVar8 = DAT_00fb7774;
        }
      }
      else {
        if (DAT_00fb7778 == DAT_00fb777c) {
          uVar6 = (int)DAT_00fb7778 - (int)puVar9 >> 2;
          if (0x3ffffffe < uVar6) goto LAB_007d374d;
          uVar6 = uVar6 + 1;
          uVar7 = (int)DAT_00fb777c - (int)puVar9 >> 2;
          if (uVar7 < uVar6) {
            if (0x3fffffff - (uVar7 >> 1) < uVar7) {
              uVar7 = 0;
            }
            else {
              uVar7 = uVar7 + (uVar7 >> 1);
            }
            if (uVar7 < uVar6) {
              uVar7 = uVar6;
            }
            FUN_00797980(uVar7);
            puVar9 = DAT_00fb7774;
          }
        }
        puVar8 = puVar9;
        if (DAT_00fb7778 != (uint *)0x0) {
          *DAT_00fb7778 = uVar5;
          puVar8 = DAT_00fb7774;
        }
      }
      auStack_30[1] = auStack_30[1] + 1;
      DAT_00fb7778 = DAT_00fb7778 + 1;
      puVar9 = puVar8;
    } while (auStack_30[1] < auStack_30[2]);
  }
  ExceptionList = local_14;
  return;
}

