
/* WARNING: Removing unreachable block (ram,0x007ba2d6) */
/* WARNING: Removing unreachable block (ram,0x007ba2e0) */
/* WARNING: Removing unreachable block (ram,0x007ba2e9) */
/* WARNING: Removing unreachable block (ram,0x007ba2eb) */

void FUN_007b9fe0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int in_ECX;
  uint uVar8;
  int *piVar9;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937fbe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int **)(in_ECX + 0x40) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 4))(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  FUN_007e0c30(*(undefined4 *)(in_ECX + 0x54));
  FUN_007b8f30();
  local_14 = 0;
  if (*(int *)(in_ECX + 0xa8) - *(int *)(in_ECX + 0xa4) >> 2 != 0) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0xa4) + local_14 * 4);
      iVar3 = *(int *)(iVar2 + 0x34);
      if (iVar3 != 0) {
        FUN_007d7300();
        FUN_0089120c(iVar3);
        *(undefined4 *)(iVar2 + 0x34) = 0;
      }
      if (*(int *)(*(int *)(in_ECX + 0xa4) + local_14 * 4) != 0) {
        iVar2 = *(int *)(*(int *)(in_ECX + 0xa4) + local_14 * 4);
        if (iVar2 != 0) {
          iVar3 = *(int *)(iVar2 + 0x34);
          if (iVar3 != 0) {
            FUN_007d7300();
            FUN_0089120c(iVar3);
            *(undefined4 *)(iVar2 + 0x34) = 0;
          }
          if (0xf < *(uint *)(iVar2 + 0x28)) {
            FUN_0089120c(*(undefined4 *)(iVar2 + 0x14));
          }
          *(undefined4 *)(iVar2 + 0x28) = 0xf;
          *(undefined4 *)(iVar2 + 0x24) = 0;
          *(undefined1 *)(iVar2 + 0x14) = 0;
          FUN_0089120c(iVar2);
        }
        *(undefined4 *)(*(int *)(in_ECX + 0xa4) + local_14 * 4) = 0;
      }
      local_14 = local_14 + 1;
    } while (local_14 < (uint)(*(int *)(in_ECX + 0xa8) - *(int *)(in_ECX + 0xa4) >> 2));
  }
  pvVar4 = *(void **)(in_ECX + 0xa4);
  if (pvVar4 != *(void **)(in_ECX + 0xa8)) {
    FID_conflict__memcpy(pvVar4,*(void **)(in_ECX + 0xa8),0);
    *(void **)(in_ECX + 0xa8) = pvVar4;
  }
  FUN_007e2d40(in_ECX + 0x90);
  uVar8 = 0;
  if (*(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 2 != 0) {
    do {
      if (*(int *)(*(int *)(in_ECX + 0x7c) + uVar8 * 4) != 0) {
        puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x7c) + uVar8 * 4);
        if (puVar7 != (undefined4 *)0x0) {
          if (puVar7[0x16] != 0) {
            FUN_0089120c(puVar7[0x16]);
          }
          puVar7[0x16] = 0;
          puVar7[0x17] = 0;
          puVar7[0x18] = 0;
          if (0xf < (uint)puVar7[5]) {
            FUN_0089120c(*puVar7);
          }
          puVar7[5] = 0xf;
          puVar7[4] = 0;
          *(undefined1 *)puVar7 = 0;
          FUN_0089120c(puVar7);
        }
        *(undefined4 *)(*(int *)(in_ECX + 0x7c) + uVar8 * 4) = 0;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < (uint)(*(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 2));
  }
  pvVar4 = *(void **)(in_ECX + 0x7c);
  if (pvVar4 != *(void **)(in_ECX + 0x80)) {
    FID_conflict__memcpy(pvVar4,*(void **)(in_ECX + 0x80),0);
    *(void **)(in_ECX + 0x80) = pvVar4;
  }
  piVar9 = (int *)**(int **)(in_ECX + 0x70);
  if (piVar9 != *(int **)(in_ECX + 0x70)) {
    do {
      iVar2 = piVar9[10];
      if (iVar2 != 0) {
        FUN_007e32a0(iVar2);
        FUN_0089120c(iVar2);
        piVar9[10] = 0;
      }
      if (*(char *)((int)piVar9 + 0x2d) == '\0') {
        piVar5 = (int *)piVar9[2];
        if (*(char *)((int)piVar5 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar5 + 0x2d);
          piVar9 = piVar5;
          piVar5 = (int *)*piVar5;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar5 + 0x2d);
            piVar9 = piVar5;
            piVar5 = (int *)*piVar5;
          }
        }
        else {
          cVar1 = *(char *)(piVar9[1] + 0x2d);
          piVar6 = (int *)piVar9[1];
          piVar5 = piVar9;
          while ((piVar9 = piVar6, cVar1 == '\0' && (piVar5 == (int *)piVar9[2]))) {
            cVar1 = *(char *)(piVar9[1] + 0x2d);
            piVar6 = (int *)piVar9[1];
            piVar5 = piVar9;
          }
        }
      }
    } while (piVar9 != *(int **)(in_ECX + 0x70));
  }
  FUN_007b7d40(*(undefined4 *)(*(int *)(in_ECX + 0x70) + 4));
  *(int *)(*(int *)(in_ECX + 0x70) + 4) = *(int *)(in_ECX + 0x70);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(in_ECX + 0x70);
  *(int *)(*(int *)(in_ECX + 0x70) + 8) = *(int *)(in_ECX + 0x70);
  *(undefined4 *)(in_ECX + 0x74) = 0;
  FUN_007e2870();
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb7974 != DAT_00fb7978) {
    DAT_00fb7978 = DAT_00fb7974;
  }
  puVar7 = (undefined4 *)FUN_007b88a0();
  cVar1 = *(char *)((int)*(int **)(puVar7[2] + 4) + 0x15);
  piVar9 = *(int **)(puVar7[2] + 4);
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar9[2]);
    piVar5 = (int *)*piVar9;
    FUN_0089120c(piVar9);
    piVar9 = piVar5;
    cVar1 = *(char *)((int)piVar5 + 0x15);
  }
  *(undefined4 *)(puVar7[2] + 4) = puVar7[2];
  *(undefined4 *)puVar7[2] = puVar7[2];
  *(undefined4 *)(puVar7[2] + 8) = puVar7[2];
  puVar7[3] = 0;
  *puVar7 = 0;
  ExceptionList = local_10;
  return;
}

