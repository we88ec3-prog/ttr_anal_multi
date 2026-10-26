
void FUN_00864660(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  void **ppvVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0090baad;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_8 = 1;
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar10 = (undefined4 *)*puVar2;
  ppvVar5 = &local_10;
  puVar4 = puVar10;
  local_10 = ExceptionList;
  do {
    do {
      while( true ) {
        do {
          ExceptionList = ppvVar5;
          if (puVar10 == puVar2) {
            FUN_007b7d40(*(undefined4 *)(*(int *)(param_1 + 4) + 4));
            *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
            *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
            *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
            *(undefined4 *)(param_1 + 8) = 0;
            local_8 = local_8 & 0xffffff00;
            if (*(int *)(param_1 + 0x30) != 0) {
              FUN_0089120c(*(int *)(param_1 + 0x30),uVar6);
            }
            *(undefined4 *)(param_1 + 0x30) = 0;
            *(undefined4 *)(param_1 + 0x34) = 0;
            *(undefined4 *)(param_1 + 0x38) = 0;
            if (*(int *)(param_1 + 0x20) != 0) {
              FUN_0089120c(*(int *)(param_1 + 0x20),uVar6);
            }
            *(undefined4 *)(param_1 + 0x20) = 0;
            *(undefined4 *)(param_1 + 0x24) = 0;
            *(undefined4 *)(param_1 + 0x28) = 0;
            if (*(int *)(param_1 + 0x10) != 0) {
              FUN_00842540(*(int *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),param_1);
              FUN_0089120c(*(undefined4 *)(param_1 + 0x10));
            }
            *(undefined4 *)(param_1 + 0x10) = 0;
            *(undefined4 *)(param_1 + 0x14) = 0;
            *(undefined4 *)(param_1 + 0x18) = 0;
            local_8 = 2;
            FUN_0057ffd0(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
            FUN_0089120c(*(undefined4 *)(param_1 + 4));
            ExceptionList = local_10;
            return;
          }
          uVar3 = puVar10[10];
          if (((uVar3 == 0) ||
              (uVar8 = uVar3 & 0xffff, puVar10 = puVar4,
              (uint)((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) / 0x11c) <= uVar8)) ||
             (*(uint *)(*(int *)(param_1 + 0x20) + uVar8 * 4) != uVar3 >> 0x10)) {
            iVar9 = 0;
          }
          else {
            iVar9 = uVar8 * 0x11c + *(int *)(param_1 + 0x10);
          }
          FUN_00843650(iVar9);
          ppvVar5 = ExceptionList;
        } while (*(char *)((int)puVar10 + 0x2d) != '\0');
        puVar4 = (undefined4 *)puVar10[2];
        if (*(char *)((int)puVar4 + 0x2d) != '\0') break;
        cVar1 = *(char *)((int)*puVar4 + 0x2d);
        puVar10 = puVar4;
        puVar11 = (undefined4 *)*puVar4;
        while (puVar4 = puVar10, cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar11 + 0x2d);
          puVar10 = puVar11;
          puVar11 = (undefined4 *)*puVar11;
        }
      }
      puVar4 = (undefined4 *)puVar10[1];
      puVar11 = puVar10;
      puVar10 = puVar4;
    } while (*(char *)((int)puVar4 + 0x2d) != '\0');
    do {
      puVar7 = puVar4;
      puVar10 = puVar7;
      puVar4 = puVar7;
      if (puVar11 != (undefined4 *)puVar7[2]) break;
      puVar10 = (undefined4 *)puVar7[1];
      puVar4 = puVar10;
      puVar11 = puVar7;
    } while (*(char *)((int)puVar10 + 0x2d) == '\0');
  } while( true );
}

