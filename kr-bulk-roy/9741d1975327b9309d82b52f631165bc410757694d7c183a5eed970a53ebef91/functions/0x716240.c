
/* WARNING: Removing unreachable block (ram,0x00716313) */
/* WARNING: Removing unreachable block (ram,0x0071636b) */
/* WARNING: Removing unreachable block (ram,0x00716414) */
/* WARNING: Removing unreachable block (ram,0x007163e8) */

void FUN_00716240(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint uVar10;
  int *unaff_FS_OFFSET;
  int local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00906a08;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_14;
  puVar9 = (undefined4 *)0x0;
  local_c = 0;
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    puVar5 = puVar3 + 10;
    if (puVar5 < puVar9) {
      if (puVar9 == (undefined4 *)0x0) {
        FUN_00797980(1);
      }
      else {
        *puVar9 = *(undefined4 *)(((int)puVar5 >> 2) * 4);
      }
    }
    else if (puVar9 == (undefined4 *)0x0) {
      FUN_00797980(1);
    }
    else {
      *puVar9 = *puVar5;
    }
    puVar9 = puVar9 + 1;
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x2d);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x2d);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  uVar10 = 0;
  if ((int)puVar9 >> 2 != 0) {
    do {
      piVar4 = *(int **)(uVar10 * 4);
      FUN_00718ee0(piVar4 + 0xf);
      piVar7 = piVar4 + 7;
      if (0xf < (uint)piVar4[0xc]) {
        piVar7 = (int *)*piVar7;
      }
      piVar8 = piVar4;
      if (0xf < (uint)piVar4[5]) {
        piVar8 = (int *)*piVar4;
      }
      FUN_00718fb0(piVar8,piVar7,piVar4[0xe]);
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)((int)puVar9 >> 2));
  }
  *unaff_FS_OFFSET = local_14;
  return;
}

