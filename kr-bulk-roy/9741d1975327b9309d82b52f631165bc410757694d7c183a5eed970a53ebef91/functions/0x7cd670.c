
void FUN_007cd670(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *in_ECX;
  uint uVar8;
  int *piVar9;
  uint *puVar10;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092bb8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (int *)in_ECX[10];
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  piVar9 = (int *)in_ECX[9];
  iVar7 = DAT_00fb7740;
  do {
    DAT_00fb7740 = iVar7;
    if (piVar9 == piVar1) {
      iVar6 = (**(code **)(*in_ECX + 4))();
      iVar2 = *(int *)(iVar6 * 0x2004 + 0x2000 + iVar7);
      iVar7 = iVar6 * 0x2004 + iVar7;
      if (iVar2 < 0x800) {
        *(int **)(iVar7 + iVar2 * 4) = in_ECX;
        piVar1 = (int *)(iVar7 + 0x2000);
        *piVar1 = *piVar1 + 1;
      }
      ExceptionList = local_10;
      return;
    }
    iVar7 = *piVar9;
    iVar2 = piVar9[1];
    puVar10 = &DAT_00fb7774 + iVar7 * 4;
    piVar3 = (int *)(&DAT_00fb7778)[iVar7 * 4];
    local_14 = iVar2;
    if ((&local_14 < piVar3) && (piVar4 = (int *)*puVar10, piVar4 <= &local_14)) {
      if (piVar3 == (int *)(&DAT_00fb777c)[iVar7 * 4]) {
        uVar5 = (int)piVar3 - (int)piVar4 >> 2;
        if (0x3ffffffe < uVar5) {
LAB_007cd805:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("vector<T> too long");
        }
        uVar5 = uVar5 + 1;
        uVar8 = (int)(&DAT_00fb777c)[iVar7 * 4] - (int)piVar4 >> 2;
        if (uVar8 < uVar5) {
          if (0x3fffffff - (uVar8 >> 1) < uVar8) {
            uVar8 = 0;
          }
          else {
            uVar8 = uVar8 + (uVar8 >> 1);
          }
          if (uVar8 < uVar5) {
            uVar8 = uVar5;
          }
          FUN_00797980(uVar8);
        }
      }
      if ((undefined4 *)(&DAT_00fb7778)[iVar7 * 4] != (undefined4 *)0x0) {
        *(undefined4 *)(&DAT_00fb7778)[iVar7 * 4] =
             *(undefined4 *)(*puVar10 + ((int)&local_14 - (int)piVar4 >> 2) * 4);
      }
    }
    else {
      if (piVar3 == (int *)(&DAT_00fb777c)[iVar7 * 4]) {
        uVar5 = (int)((int)piVar3 - *puVar10) >> 2;
        if (0x3ffffffe < uVar5) goto LAB_007cd805;
        uVar5 = uVar5 + 1;
        uVar8 = (int)((int)(&DAT_00fb777c)[iVar7 * 4] - *puVar10) >> 2;
        if (uVar8 < uVar5) {
          if (0x3fffffff - (uVar8 >> 1) < uVar8) {
            uVar8 = 0;
          }
          else {
            uVar8 = uVar8 + (uVar8 >> 1);
          }
          if (uVar8 < uVar5) {
            uVar8 = uVar5;
          }
          FUN_00797980(uVar8);
        }
      }
      if ((int *)(&DAT_00fb7778)[iVar7 * 4] != (int *)0x0) {
        *(int *)(&DAT_00fb7778)[iVar7 * 4] = iVar2;
      }
    }
    (&DAT_00fb7778)[iVar7 * 4] = (&DAT_00fb7778)[iVar7 * 4] + 4;
    piVar9 = piVar9 + 2;
    iVar7 = DAT_00fb7740;
  } while( true );
}

