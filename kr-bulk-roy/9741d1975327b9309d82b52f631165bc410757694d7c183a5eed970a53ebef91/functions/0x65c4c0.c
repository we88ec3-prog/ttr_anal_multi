
void FUN_0065c4c0(undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  int *piVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917178;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(uint *)(in_ECX + 8) < 0xccccccb) {
    *(uint *)(in_ECX + 8) = *(uint *)(in_ECX + 8) + 1;
    param_4[1] = (int)param_3;
    if (param_3 == *(undefined4 **)(in_ECX + 4)) {
      (*(undefined4 **)(in_ECX + 4))[1] = param_4;
      **(undefined4 **)(in_ECX + 4) = param_4;
      *(int **)(*(int *)(in_ECX + 4) + 8) = param_4;
    }
    else if (param_2 == '\0') {
      param_3[2] = param_4;
      if (param_3 == *(undefined4 **)(*(int *)(in_ECX + 4) + 8)) {
        *(int **)(*(int *)(in_ECX + 4) + 8) = param_4;
      }
    }
    else {
      *param_3 = param_4;
      if (param_3 == (undefined4 *)**(int **)(in_ECX + 4)) {
        **(int **)(in_ECX + 4) = (int)param_4;
      }
    }
    cVar1 = *(char *)(param_4[1] + 0x20);
    piVar6 = param_4;
    while (cVar1 == '\0') {
      piVar2 = (int *)piVar6[1];
      piVar3 = (int *)piVar2[1];
      if (piVar2 == (int *)*piVar3) {
        iVar4 = piVar3[2];
        if (*(char *)(iVar4 + 0x20) == '\0') {
          *(undefined1 *)(piVar2 + 8) = 1;
          *(undefined1 *)(iVar4 + 0x20) = 1;
          *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x20) = 0;
          piVar6 = *(int **)(piVar6[1] + 4);
        }
        else {
          if (piVar6 == (int *)piVar2[2]) {
            FUN_00405150(in_ECX);
            piVar6 = piVar2;
          }
          *(undefined1 *)(piVar6[1] + 0x20) = 1;
          *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x20) = 0;
          FUN_00819bd0(in_ECX);
        }
      }
      else {
        iVar4 = *piVar3;
        if (*(char *)(iVar4 + 0x20) == '\0') {
          *(undefined1 *)(piVar2 + 8) = 1;
          *(undefined1 *)(iVar4 + 0x20) = 1;
          *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x20) = 0;
          piVar6 = *(int **)(piVar6[1] + 4);
        }
        else {
          if (piVar6 == (int *)*piVar2) {
            FUN_00819bd0(in_ECX);
            piVar6 = piVar2;
          }
          *(undefined1 *)(piVar6[1] + 0x20) = 1;
          *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x20) = 0;
          iVar4 = *(int *)(piVar6[1] + 4);
          piVar2 = *(int **)(iVar4 + 8);
          *(int *)(iVar4 + 8) = *piVar2;
          if (*(char *)(*piVar2 + 0x21) == '\0') {
            *(int *)(*piVar2 + 4) = iVar4;
          }
          piVar2[1] = *(int *)(iVar4 + 4);
          if (iVar4 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
            *(int **)(*(int *)(in_ECX + 4) + 4) = piVar2;
          }
          else {
            piVar3 = *(int **)(iVar4 + 4);
            if (iVar4 == *piVar3) {
              *piVar3 = (int)piVar2;
            }
            else {
              piVar3[2] = (int)piVar2;
            }
          }
          *piVar2 = iVar4;
          *(int **)(iVar4 + 4) = piVar2;
        }
      }
      cVar1 = *(char *)(piVar6[1] + 0x20);
    }
    *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x20) = 1;
    *param_1 = param_4;
    ExceptionList = local_10;
    return;
  }
  local_8 = 0;
  FUN_0065b910(*(undefined4 *)param_4[5],(undefined4 *)param_4[5]);
  local_8 = 0xffffffff;
  FUN_0089120c(param_4[5],uVar5);
  FUN_0089120c(param_4);
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("map/set<T> too long");
}

