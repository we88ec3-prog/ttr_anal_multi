
void FUN_0055e2e0(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090b5d8;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar6 = (int *)**(int **)(param_1 + 4);
  if (piVar6 != *(int **)(param_1 + 4)) {
    do {
      iVar2 = piVar6[4];
      if (iVar2 != 0) {
        local_8 = 0;
        FUN_0081cd10(**(undefined4 **)(iVar2 + 8),*(undefined4 **)(iVar2 + 8));
        local_8 = 0xffffffff;
        FUN_0089120c(*(undefined4 *)(iVar2 + 8));
        FUN_0089120c(iVar2);
      }
      if (*(char *)((int)piVar6 + 0x15) == '\0') {
        piVar3 = (int *)piVar6[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar6 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar6 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x15);
          piVar4 = (int *)piVar6[1];
          piVar3 = piVar6;
          while ((piVar6 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x15);
            piVar4 = (int *)piVar6[1];
            piVar3 = piVar6;
          }
        }
      }
    } while (piVar6 != *(int **)(param_1 + 4));
  }
  piVar6 = *(int **)(*(int *)(param_1 + 4) + 4);
  cVar1 = *(char *)((int)piVar6 + 0x15);
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar6[2]);
    piVar3 = (int *)*piVar6;
    FUN_0089120c(piVar6,uVar5);
    piVar6 = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0x15);
  }
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  ExceptionList = local_10;
  return;
}

