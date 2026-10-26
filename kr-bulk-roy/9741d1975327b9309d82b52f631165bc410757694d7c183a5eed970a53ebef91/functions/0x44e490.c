
void FUN_0044e490(void)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int **ppiVar7;
  undefined4 *puVar8;
  int in_ECX;
  int *piVar9;
  undefined4 *puVar10;
  int *piVar11;
  int *local_10;
  int *local_c;
  int local_8;
  
  local_10 = *(int **)(in_ECX + 0x18);
  piVar9 = (int *)*local_10;
  local_8 = in_ECX;
  if (piVar9 != local_10) {
    do {
      piVar6 = (int *)(**(code **)(*(int *)piVar9[4] + 0x10))();
      if (((uint)piVar6[10] >> 0x15 & 1) != 0) {
        FUN_00745680();
        if (((uint)piVar6[10] >> 0xf & 1) != 0) {
          (**(code **)(*piVar6 + 0x120))();
          local_c = (int *)piVar6[0x19];
          piVar11 = (int *)*local_c;
          if (piVar11 != local_c) {
            do {
              FUN_00746b80();
              piVar11 = (int *)*piVar11;
            } while (piVar11 != local_c);
          }
          if ((piVar6[10] & 0x8000U) != 0) {
            piVar6[10] = piVar6[10] ^ 0x8000;
          }
        }
        if ((*(byte *)((int)piVar6 + 0x2a) & 1) != 0) {
          (**(code **)(*piVar6 + 0x11c))();
          local_c = (int *)piVar6[0x19];
          piVar11 = (int *)*local_c;
          if (piVar11 != local_c) {
            do {
              FUN_00746c10();
              piVar11 = (int *)*piVar11;
            } while (piVar11 != local_c);
          }
          if ((piVar6[10] & 0x10000U) != 0) {
            piVar6[10] = piVar6[10] ^ 0x10000;
          }
        }
      }
      if (*(char *)((int)piVar9 + 0x15) == '\0') {
        piVar6 = (int *)piVar9[2];
        if (*(char *)((int)piVar6 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar6 + 0x15);
          piVar9 = piVar6;
          piVar6 = (int *)*piVar6;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar6 + 0x15);
            piVar9 = piVar6;
            piVar6 = (int *)*piVar6;
          }
        }
        else {
          cVar1 = *(char *)(piVar9[1] + 0x15);
          piVar11 = (int *)piVar9[1];
          piVar6 = piVar9;
          while ((piVar9 = piVar11, cVar1 == '\0' && (piVar6 == (int *)piVar9[2]))) {
            cVar1 = *(char *)(piVar9[1] + 0x15);
            piVar11 = (int *)piVar9[1];
            piVar6 = piVar9;
          }
        }
      }
    } while (piVar9 != local_10);
  }
  puVar2 = *(undefined4 **)(local_8 + 8);
  puVar4 = (undefined4 *)*puVar2;
  iVar5 = local_8;
  do {
    do {
      while( true ) {
        do {
          puVar10 = puVar4;
          if (puVar10 == puVar2) {
            piVar9 = *(int **)(*(int *)(iVar5 + 8) + 4);
            cVar1 = *(char *)((int)piVar9 + 0x15);
            while (cVar1 == '\0') {
              FUN_0073eba0(piVar9[2]);
              piVar6 = (int *)*piVar9;
              FUN_0089120c(piVar9);
              piVar9 = piVar6;
              cVar1 = *(char *)((int)piVar6 + 0x15);
            }
            *(int *)(*(int *)(iVar5 + 8) + 4) = *(int *)(iVar5 + 8);
            *(undefined4 *)*(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 8);
            *(int *)(*(int *)(iVar5 + 8) + 8) = *(int *)(iVar5 + 8);
            *(undefined4 *)(iVar5 + 0xc) = 0;
            FUN_0044e720(iVar5 + 0x14);
            return;
          }
          uVar3 = ((int *)puVar10[4])[1];
          piVar9 = (int *)(*(int **)(iVar5 + 0x18))[1];
          cVar1 = *(char *)((int)piVar9 + 0x15);
          local_10 = *(int **)(iVar5 + 0x18);
          while (cVar1 == '\0') {
            if ((uint)piVar9[3] < uVar3) {
              piVar6 = (int *)piVar9[2];
              piVar9 = local_10;
            }
            else {
              piVar6 = (int *)*piVar9;
            }
            local_10 = piVar9;
            piVar9 = piVar6;
            cVar1 = *(char *)((int)piVar6 + 0x15);
          }
          if ((local_10 == *(int **)(iVar5 + 0x18)) || (uVar3 < (uint)local_10[3])) {
            local_c = *(int **)(iVar5 + 0x18);
            ppiVar7 = &local_c;
          }
          else {
            ppiVar7 = &local_10;
          }
          local_8 = iVar5;
          if (*ppiVar7 == *(int **)(iVar5 + 0x18)) {
            (**(code **)(*(int *)puVar10[4] + 0x1c))(1);
          }
          puVar4 = puVar10;
          iVar5 = local_8;
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
      puVar8 = puVar4;
      puVar4 = puVar8;
      if (puVar10 != (undefined4 *)puVar8[2]) break;
      puVar4 = (undefined4 *)puVar8[1];
      puVar10 = puVar8;
    } while (*(char *)((int)puVar4 + 0x15) == '\0');
  } while( true );
}

