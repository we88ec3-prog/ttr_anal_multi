
undefined4 FUN_008c23a0(int *param_1,int *param_2)

{
  int *piVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  piVar1 = (int *)*param_2;
  psVar2 = (short *)param_2[1];
  if (param_1 == (int *)0x0) {
    return 6;
  }
  if (*param_1 == 0) {
    return 6;
  }
  if (param_1[1] == 0) {
    return 6;
  }
  if (psVar2 != (short *)0x0) {
    if ((psVar2[1] == 0) || (*psVar2 < 1)) {
      return 0;
    }
    if (((*(int *)(psVar2 + 6) != 0) && (*(int *)(psVar2 + 2) != 0)) &&
       ((int)psVar2[1] == *(short *)(*(int *)(psVar2 + 6) + -2 + *psVar2 * 2) + 1)) {
      uVar3 = param_2[2];
      iVar4 = param_1[4];
      if ((uVar3 & 2) != 0) {
LAB_008c244e:
        if ((uVar3 & 1) == 0) {
          return 0x13;
        }
        if ((uVar3 & 2) == 0) {
          *(undefined4 *)(iVar4 + 0x400) = 0;
          *(undefined4 *)(iVar4 + 0x404) = 0;
          *(int *)(iVar4 + 0x408) = piVar1[1];
          iVar6 = *piVar1;
        }
        else if ((uVar3 & 4) == 0) {
          *(undefined4 *)(iVar4 + 0x400) = 0xffff8000;
          *(undefined4 *)(iVar4 + 0x404) = 0xffff8000;
          iVar6 = 0x7fff;
          *(undefined4 *)(iVar4 + 0x408) = 0x7fff;
        }
        else {
          *(int *)(iVar4 + 0x400) = param_2[8];
          *(int *)(iVar4 + 0x404) = param_2[9];
          *(int *)(iVar4 + 0x408) = param_2[10];
          iVar6 = param_2[0xb];
        }
        *(int *)(iVar4 + 0x40c) = iVar6;
        iVar4 = FUN_008c1270();
        *(undefined4 *)(iVar4 + 0x3d4) = *(undefined4 *)psVar2;
        *(undefined4 *)(iVar4 + 0x3d8) = *(undefined4 *)(psVar2 + 2);
        *(undefined4 *)(iVar4 + 0x3dc) = *(undefined4 *)(psVar2 + 4);
        *(undefined4 *)(iVar4 + 0x3e0) = *(undefined4 *)(psVar2 + 6);
        *(undefined4 *)(iVar4 + 0x3e4) = *(undefined4 *)(psVar2 + 8);
        *(undefined4 *)(iVar4 + 0x34) = 0;
        *(undefined4 *)(iVar4 + 0x28) = 1;
        *(int *)(iVar4 + 0x4e0) = param_1[2];
        *(undefined4 *)(iVar4 + 0x4d0) = 0;
        if ((*(byte *)(param_2 + 2) & 2) != 0) {
          *(int *)(iVar4 + 0x4d4) = param_2[3];
          *(int *)(iVar4 + 0x4d8) = param_2[7];
          uVar5 = FUN_008c2030();
          return uVar5;
        }
        *(int *)(iVar4 + 1000) = *piVar1;
        *(int *)(iVar4 + 0x3ec) = piVar1[1];
        *(int *)(iVar4 + 0x3f0) = piVar1[2];
        *(int *)(iVar4 + 0x3f4) = piVar1[3];
        *(int *)(iVar4 + 0x3f8) = piVar1[4];
        *(int *)(iVar4 + 0x3fc) = piVar1[5];
        *(code **)(iVar4 + 0x4d4) = FUN_008c1ce0;
        *(int *)(iVar4 + 0x4d8) = iVar4;
        uVar5 = FUN_008c2030();
        return uVar5;
      }
      if (piVar1 != (int *)0x0) {
        if (piVar1[1] == 0) {
          return 0;
        }
        if (*piVar1 == 0) {
          return 0;
        }
        if (piVar1[3] != 0) goto LAB_008c244e;
      }
      return 6;
    }
  }
  return 0x14;
}

