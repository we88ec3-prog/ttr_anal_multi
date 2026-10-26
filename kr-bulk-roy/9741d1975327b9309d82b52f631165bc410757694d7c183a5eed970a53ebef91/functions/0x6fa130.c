
int FUN_006fa130(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int local_8;
  
  iVar1 = *(int *)(param_1 + 0x10);
  piVar4 = *(int **)(iVar1 + 0x70);
  piVar5 = (int *)*piVar4;
  local_8 = 0;
  if (piVar5 != (int *)0x0) {
    do {
      if ((((*(byte *)((int)piVar5 + 5) & 3) != 0) || (param_2 != 0)) &&
         ((*(byte *)((int)piVar5 + 5) & 8) == 0)) {
        if (((piVar5[2] == 0) || ((*(byte *)(piVar5[2] + 6) & 4) != 0)) ||
           (iVar3 = FUN_006fea60(2), iVar3 == 0)) {
          *(byte *)((int)piVar5 + 5) = *(byte *)((int)piVar5 + 5) | 8;
        }
        else {
          *(byte *)((int)piVar5 + 5) = *(byte *)((int)piVar5 + 5) | 8;
          local_8 = local_8 + 0x18 + piVar5[4];
          *piVar4 = *piVar5;
          if (*(int **)(iVar1 + 0x30) == (int *)0x0) {
            *piVar5 = (int)piVar5;
          }
          else {
            *piVar5 = **(int **)(iVar1 + 0x30);
            **(undefined4 **)(iVar1 + 0x30) = piVar5;
          }
          *(int **)(iVar1 + 0x30) = piVar5;
          piVar5 = piVar4;
        }
      }
      piVar2 = (int *)*piVar5;
      piVar4 = piVar5;
      piVar5 = piVar2;
    } while (piVar2 != (int *)0x0);
    return local_8;
  }
  return 0;
}

