
/* WARNING: Removing unreachable block (ram,0x0081caa1) */
/* WARNING: Removing unreachable block (ram,0x0081cb8a) */

void FUN_0081c9e0(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int in_EDX;
  int *piVar8;
  int *piVar9;
  int local_24 [4];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ea48;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar8 = (int *)**(int **)(in_EDX + 4);
  local_14 = uVar7;
  if (*(int **)(in_EDX + 4) != piVar8) {
    do {
      piVar9 = *(int **)piVar8[0xd];
      iVar2 = local_24[0];
      iVar4 = local_24[1];
      iVar5 = local_24[2];
      if ((int *)piVar8[0xd] != piVar9) {
        do {
          local_24[2] = iVar5;
          local_24[1] = iVar4;
          local_24[0] = iVar2;
          iVar2 = piVar9[5];
          FUN_004026e0(piVar9 + 6,0,0xffffffff);
          local_8 = 0;
          FUN_004fcd00(local_24,piVar9 + 0xd);
          local_8 = 0xffffffff;
          if (*param_1 == iVar2) {
            if (local_24[0] != 0) {
              FUN_0089120c(local_24[0],uVar7);
            }
            local_24[0] = 0;
            local_24[1] = 0;
            local_24[2] = 0;
            goto LAB_0081cb4d;
          }
          if (local_24[0] != 0) {
            FUN_0089120c(local_24[0],uVar7);
          }
          local_24[0] = 0;
          iVar2 = local_24[0];
          local_24[1] = 0;
          iVar4 = local_24[1];
          local_24[2] = 0;
          iVar5 = local_24[2];
          local_24[2] = 0;
          local_24[1] = 0;
          local_24[0] = 0;
          if (*(char *)((int)piVar9 + 0x45) == '\0') {
            piVar3 = (int *)piVar9[2];
            if (*(char *)((int)piVar3 + 0x45) == '\0') {
              cVar1 = *(char *)(*piVar3 + 0x45);
              piVar9 = piVar3;
              piVar3 = (int *)*piVar3;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar3 + 0x45);
                piVar9 = piVar3;
                piVar3 = (int *)*piVar3;
              }
            }
            else {
              cVar1 = *(char *)(piVar9[1] + 0x45);
              piVar6 = (int *)piVar9[1];
              piVar3 = piVar9;
              while ((piVar9 = piVar6, cVar1 == '\0' && (piVar3 == (int *)piVar9[2]))) {
                cVar1 = *(char *)(piVar9[1] + 0x45);
                piVar6 = (int *)piVar9[1];
                piVar3 = piVar9;
              }
            }
          }
        } while ((int *)piVar8[0xd] != piVar9);
      }
      if (*(char *)((int)piVar8 + 0x41) == '\0') {
        piVar9 = (int *)piVar8[2];
        if (*(char *)((int)piVar9 + 0x41) == '\0') {
          cVar1 = *(char *)(*piVar9 + 0x41);
          piVar8 = piVar9;
          piVar9 = (int *)*piVar9;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar9 + 0x41);
            piVar8 = piVar9;
            piVar9 = (int *)*piVar9;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x41);
          piVar3 = (int *)piVar8[1];
          piVar9 = piVar8;
          while ((piVar8 = piVar3, cVar1 == '\0' && (piVar9 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x41);
            piVar3 = (int *)piVar8[1];
            piVar9 = piVar8;
          }
        }
      }
    } while (*(int **)(in_EDX + 4) != piVar8);
  }
LAB_0081cb4d:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

