
void FUN_00556bd0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  undefined1 local_24 [16];
  int local_14;
  undefined4 local_10;
  int *local_c;
  int *local_8;
  
  piVar7 = (int *)**(int **)(param_2 + 4);
  piVar6 = (int *)**(int **)(param_1 + 4);
  local_c = piVar6;
  local_8 = piVar7;
  if (piVar6 != *(int **)(param_1 + 4)) {
    do {
      if (piVar7 == *(int **)(param_2 + 4)) break;
      iVar2 = piVar6[3];
      if (iVar2 == piVar7[3]) {
        if (*(char *)((int)piVar6 + 0x15) == '\0') {
          piVar3 = (int *)piVar6[2];
          if (*(char *)((int)piVar3 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar6 = piVar3;
            piVar3 = (int *)*piVar3;
            while (local_c = piVar6, cVar1 == '\0') {
              cVar1 = *(char *)(*piVar3 + 0x15);
              piVar6 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar1 = *(char *)(piVar6[1] + 0x15);
            piVar4 = (int *)piVar6[1];
            piVar3 = piVar6;
            while ((piVar6 = piVar4, local_c = piVar6, cVar1 == '\0' && (piVar3 == (int *)piVar6[2])
                   )) {
              cVar1 = *(char *)(piVar6[1] + 0x15);
              piVar4 = (int *)piVar6[1];
              piVar3 = piVar6;
            }
          }
        }
        if (*(char *)((int)piVar7 + 0x15) == '\0') {
          piVar3 = (int *)piVar7[2];
          if (*(char *)((int)piVar3 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar7 = piVar3;
            piVar3 = (int *)*piVar3;
            while (local_8 = piVar7, cVar1 == '\0') {
              cVar1 = *(char *)(*piVar3 + 0x15);
              piVar7 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar1 = *(char *)(piVar7[1] + 0x15);
            piVar4 = (int *)piVar7[1];
            piVar3 = piVar7;
            while ((piVar7 = piVar4, local_8 = piVar7, cVar1 == '\0' && (piVar3 == (int *)piVar7[2])
                   )) {
              cVar1 = *(char *)(piVar7[1] + 0x15);
              piVar4 = (int *)piVar7[1];
              piVar3 = piVar7;
            }
          }
        }
      }
      else if (iVar2 - piVar7[3] < 0) {
        local_10 = *(undefined4 *)piVar6[4];
        local_14 = iVar2;
        uVar5 = FUN_0057ef20();
        FUN_0082f200(param_4,uVar5);
        FUN_0049e6a0();
        piVar6 = local_c;
        piVar7 = local_8;
      }
      else {
        FUN_00557c40(local_24);
        FUN_0049e6a0();
        piVar7 = local_8;
      }
    } while (piVar6 != *(int **)(param_1 + 4));
  }
  if (piVar6 != *(int **)(param_1 + 4)) {
    do {
      local_14 = piVar6[3];
      local_10 = *(undefined4 *)piVar6[4];
      uVar5 = FUN_0057ef20();
      FUN_0082f200(param_4,uVar5);
      if (*(char *)((int)piVar6 + 0x15) == '\0') {
        piVar7 = (int *)piVar6[2];
        if (*(char *)((int)piVar7 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar7 + 0x15);
          piVar6 = piVar7;
          piVar7 = (int *)*piVar7;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar7 + 0x15);
            piVar6 = piVar7;
            piVar7 = (int *)*piVar7;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x15);
          piVar3 = (int *)piVar6[1];
          piVar7 = piVar6;
          while ((piVar6 = piVar3, cVar1 == '\0' && (piVar7 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x15);
            piVar3 = (int *)piVar6[1];
            piVar7 = piVar6;
          }
        }
      }
      piVar7 = local_8;
    } while (piVar6 != *(int **)(param_1 + 4));
  }
  if (piVar7 != *(int **)(param_2 + 4)) {
    do {
      FUN_00557c40(local_24);
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar6 = (int *)piVar7[2];
        if (*(char *)((int)piVar6 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar6 + 0x15);
          piVar7 = piVar6;
          piVar6 = (int *)*piVar6;
          while (local_8 = piVar7, cVar1 == '\0') {
            cVar1 = *(char *)(*piVar6 + 0x15);
            piVar7 = piVar6;
            piVar6 = (int *)*piVar6;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x15);
          piVar3 = (int *)piVar7[1];
          piVar6 = piVar7;
          while ((piVar7 = piVar3, local_8 = piVar7, cVar1 == '\0' && (piVar6 == (int *)piVar7[2])))
          {
            cVar1 = *(char *)(piVar7[1] + 0x15);
            piVar3 = (int *)piVar7[1];
            piVar6 = piVar7;
          }
        }
      }
    } while (piVar7 != *(int **)(param_2 + 4));
  }
  return;
}

