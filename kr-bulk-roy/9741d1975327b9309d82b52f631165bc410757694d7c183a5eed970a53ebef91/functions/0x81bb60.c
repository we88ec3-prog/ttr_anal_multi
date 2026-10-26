
/* WARNING: Removing unreachable block (ram,0x0081bc1f) */
/* WARNING: Removing unreachable block (ram,0x0081bcf6) */

void FUN_0081bb60(int *param_1)

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
  piVar9 = (int *)**(int **)(in_EDX + 4);
  local_14 = uVar7;
  if (*(int **)(in_EDX + 4) != piVar9) {
    do {
      piVar8 = *(int **)piVar9[0xd];
      iVar2 = local_24[0];
      iVar4 = local_24[1];
      iVar5 = local_24[2];
      if ((int *)piVar9[0xd] != piVar8) {
        do {
          local_24[2] = iVar5;
          local_24[1] = iVar4;
          local_24[0] = iVar2;
          iVar2 = piVar8[5];
          FUN_004026e0(piVar8 + 6,0,0xffffffff);
          local_8 = 0;
          FUN_004fcd00(local_24,piVar8 + 0xd);
          local_8 = 0xffffffff;
          if (*param_1 == iVar2) {
            if (local_24[0] != 0) {
              FUN_0089120c(local_24[0],uVar7);
            }
            local_24[0] = 0;
            local_24[1] = 0;
            local_24[2] = 0;
            goto LAB_0081bcbc;
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
          if (*(char *)((int)piVar8 + 0x45) == '\0') {
            piVar3 = (int *)piVar8[2];
            if (*(char *)((int)piVar3 + 0x45) == '\0') {
              cVar1 = *(char *)(*piVar3 + 0x45);
              piVar8 = piVar3;
              piVar3 = (int *)*piVar3;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar3 + 0x45);
                piVar8 = piVar3;
                piVar3 = (int *)*piVar3;
              }
            }
            else {
              cVar1 = *(char *)(piVar8[1] + 0x45);
              piVar6 = (int *)piVar8[1];
              piVar3 = piVar8;
              while ((piVar8 = piVar6, cVar1 == '\0' && (piVar3 == (int *)piVar8[2]))) {
                cVar1 = *(char *)(piVar8[1] + 0x45);
                piVar6 = (int *)piVar8[1];
                piVar3 = piVar8;
              }
            }
          }
        } while ((int *)piVar9[0xd] != piVar8);
      }
      if (*(char *)((int)piVar9 + 0x41) == '\0') {
        piVar8 = (int *)piVar9[2];
        if (*(char *)((int)piVar8 + 0x41) == '\0') {
          cVar1 = *(char *)(*piVar8 + 0x41);
          piVar9 = piVar8;
          piVar8 = (int *)*piVar8;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar8 + 0x41);
            piVar9 = piVar8;
            piVar8 = (int *)*piVar8;
          }
        }
        else {
          cVar1 = *(char *)(piVar9[1] + 0x41);
          piVar3 = (int *)piVar9[1];
          piVar8 = piVar9;
          while ((piVar9 = piVar3, cVar1 == '\0' && (piVar8 == (int *)piVar9[2]))) {
            cVar1 = *(char *)(piVar9[1] + 0x41);
            piVar3 = (int *)piVar9[1];
            piVar8 = piVar9;
          }
        }
      }
    } while (*(int **)(in_EDX + 4) != piVar9);
  }
LAB_0081bcbc:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

