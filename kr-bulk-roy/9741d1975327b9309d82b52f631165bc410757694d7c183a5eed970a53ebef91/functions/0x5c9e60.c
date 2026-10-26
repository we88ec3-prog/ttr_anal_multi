
void FUN_005c9e60(undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  int *piVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091aa58;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (0x38e38e1 < *(uint *)(in_ECX + 8)) {
    local_8 = 0;
    FUN_005c8b80(param_4 + 10);
    local_8 = 0xffffffff;
    if (7 < (uint)param_4[8]) {
      FUN_0089120c(param_4[3],uVar4);
    }
    param_4[8] = 7;
    param_4[7] = 0;
    *(undefined2 *)(param_4 + 3) = 0;
    FUN_0089120c(param_4,uVar4);
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("map/set<T> too long");
  }
  *(uint *)(in_ECX + 8) = *(uint *)(in_ECX + 8) + 1;
  param_4[1] = (int)param_3;
  if (param_3 == *(undefined4 **)(in_ECX + 4)) {
    (*(undefined4 **)(in_ECX + 4))[1] = param_4;
    **(undefined4 **)(in_ECX + 4) = param_4;
    iVar5 = *(int *)(in_ECX + 4);
  }
  else {
    if (param_2 != '\0') {
      *param_3 = param_4;
      if (param_3 == (undefined4 *)**(int **)(in_ECX + 4)) {
        **(int **)(in_ECX + 4) = (int)param_4;
      }
      goto LAB_005c9f25;
    }
    param_3[2] = param_4;
    iVar5 = *(int *)(in_ECX + 4);
    if (param_3 != *(undefined4 **)(iVar5 + 8)) goto LAB_005c9f25;
  }
  *(int **)(iVar5 + 8) = param_4;
LAB_005c9f25:
  cVar1 = *(char *)(param_4[1] + 0x54);
  piVar6 = param_4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x54) = 1;
      *param_1 = param_4;
      ExceptionList = local_10;
      return;
    }
    piVar2 = (int *)piVar6[1];
    piVar3 = (int *)piVar2[1];
    if (piVar2 == (int *)*piVar3) {
      iVar5 = piVar3[2];
      if (*(char *)(iVar5 + 0x54) == '\0') {
LAB_005c9f7e:
        *(undefined1 *)(piVar2 + 0x15) = 1;
        *(undefined1 *)(iVar5 + 0x54) = 1;
        *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x54) = 0;
        piVar6 = *(int **)(piVar6[1] + 4);
      }
      else {
        if (piVar6 == (int *)piVar2[2]) {
          FUN_005c98b0(in_ECX);
          piVar6 = piVar2;
        }
        *(undefined1 *)(piVar6[1] + 0x54) = 1;
        *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x54) = 0;
        FUN_005c9910(in_ECX);
      }
    }
    else {
      iVar5 = *piVar3;
      if (*(char *)(iVar5 + 0x54) == '\0') goto LAB_005c9f7e;
      if (piVar6 == (int *)*piVar2) {
        FUN_005c9910(in_ECX);
        piVar6 = piVar2;
      }
      *(undefined1 *)(piVar6[1] + 0x54) = 1;
      *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x54) = 0;
      iVar5 = *(int *)(piVar6[1] + 4);
      piVar2 = *(int **)(iVar5 + 8);
      *(int *)(iVar5 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x55) == '\0') {
        *(int *)(*piVar2 + 4) = iVar5;
      }
      piVar2[1] = *(int *)(iVar5 + 4);
      if (iVar5 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
        *(int **)(*(int *)(in_ECX + 4) + 4) = piVar2;
      }
      else {
        piVar3 = *(int **)(iVar5 + 4);
        if (iVar5 == *piVar3) {
          *piVar3 = (int)piVar2;
        }
        else {
          piVar3[2] = (int)piVar2;
        }
      }
      *piVar2 = iVar5;
      *(int **)(iVar5 + 4) = piVar2;
    }
    cVar1 = *(char *)(piVar6[1] + 0x54);
  } while( true );
}

