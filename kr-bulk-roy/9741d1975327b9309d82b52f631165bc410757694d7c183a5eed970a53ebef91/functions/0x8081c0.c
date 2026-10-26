
void FUN_008081c0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  void **ppvVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907452;
  uVar8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_8 = 0;
  puVar2 = *(undefined4 **)(param_1 + 4);
  ppvVar7 = &local_10;
  puVar4 = (undefined4 *)*puVar2;
  local_10 = ExceptionList;
  do {
    do {
      while( true ) {
        do {
          puVar10 = puVar4;
          ExceptionList = ppvVar7;
          if (puVar10 == puVar2) {
            piVar5 = *(int **)(*(int *)(param_1 + 4) + 4);
            cVar1 = *(char *)((int)piVar5 + 0x15);
            while (cVar1 == '\0') {
              FUN_0073eba0(piVar5[2]);
              piVar6 = (int *)*piVar5;
              FUN_0089120c(piVar5);
              piVar5 = piVar6;
              cVar1 = *(char *)((int)piVar6 + 0x15);
            }
            *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
            *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
            *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
            *(undefined4 *)(param_1 + 8) = 0;
            local_8 = 1;
            FUN_005540c0(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
            FUN_0089120c(*(undefined4 *)(param_1 + 4),uVar8);
            ExceptionList = local_10;
            return;
          }
          iVar3 = puVar10[4];
          if (iVar3 != 0) {
            FUN_00809200(iVar3);
            FUN_0089120c(iVar3);
            puVar10[4] = 0;
          }
          ppvVar7 = ExceptionList;
          puVar4 = puVar10;
        } while (*(char *)((int)puVar10 + 0x15) != '\0');
        puVar4 = (undefined4 *)puVar10[2];
        if (*(char *)((int)puVar4 + 0x15) != '\0') break;
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar10 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar10 + 0x15);
          puVar4 = puVar10;
          puVar10 = (undefined4 *)*puVar10;
        }
      }
      puVar4 = (undefined4 *)puVar10[1];
    } while (*(char *)((int)puVar4 + 0x15) != '\0');
    do {
      puVar9 = puVar4;
      puVar4 = puVar9;
      if (puVar10 != (undefined4 *)puVar9[2]) break;
      puVar4 = (undefined4 *)puVar9[1];
      puVar10 = puVar9;
    } while (*(char *)((int)puVar4 + 0x15) == '\0');
  } while( true );
}

