
/* WARNING: Removing unreachable block (ram,0x008710be) */

void FUN_00871060(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  bool bVar9;
  
  bVar9 = true;
  piVar7 = DAT_00fe3518;
  if (*(char *)(DAT_00fe3518[1] + 0x2d) == '\0') {
    uVar1 = *(uint *)(param_2 + 0x1c);
    piVar8 = (int *)DAT_00fe3518[1];
    do {
      piVar7 = piVar8;
      uVar2 = piVar7[7];
      uVar5 = uVar1;
      if (uVar2 <= uVar1) {
        uVar5 = uVar2;
      }
      uVar5 = FUN_00407e70(uVar5);
      if (uVar5 == 0) {
        if (uVar1 < uVar2) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = (uint)(uVar1 != uVar2);
        }
      }
      bVar9 = (int)uVar5 < 0;
      if (bVar9) {
        piVar8 = (int *)*piVar7;
      }
      else {
        piVar8 = (int *)piVar7[2];
      }
    } while (*(char *)((int)piVar8 + 0x2d) == '\0');
  }
  if (bVar9) {
    if (piVar7 == (int *)*DAT_00fe3518) {
      bVar9 = true;
      goto LAB_0087112e;
    }
    FUN_00574e80();
  }
  iVar3 = param_2;
  cVar4 = FUN_0049ae30();
  if (cVar4 == '\0') {
    if (0xf < *(uint *)(iVar3 + 0x20)) {
      FUN_0089120c(*(undefined4 *)(iVar3 + 0xc));
    }
    *(undefined4 *)(iVar3 + 0x20) = 0xf;
    *(undefined4 *)(iVar3 + 0x1c) = 0;
    *(undefined1 *)(iVar3 + 0xc) = 0;
    FUN_0089120c(iVar3);
    *param_1 = piVar7;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_0087112e:
  puVar6 = (undefined4 *)FUN_008711c0(&param_2,bVar9);
  *param_1 = *puVar6;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}

