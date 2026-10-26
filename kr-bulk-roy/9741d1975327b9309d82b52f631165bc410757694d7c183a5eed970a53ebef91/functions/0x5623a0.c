
void FUN_005623a0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = (int *)FUN_00713cc0(&DAT_00c059a4);
  if (piVar4 != (int *)0x0) {
    piVar5 = (int *)**(int **)(param_1 + 0x78);
    if (piVar5 != *(int **)(param_1 + 0x78)) {
      do {
        (**(code **)(*piVar4 + 0x14))(piVar5 + 3,4,1);
        if (*(char *)((int)piVar5 + 0x11) == '\0') {
          piVar2 = (int *)piVar5[2];
          if (*(char *)((int)piVar2 + 0x11) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x11);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x11);
              piVar5 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar5[1] + 0x11);
            piVar3 = (int *)piVar5[1];
            piVar2 = piVar5;
            while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
              cVar1 = *(char *)(piVar5[1] + 0x11);
              piVar3 = (int *)piVar5[1];
              piVar2 = piVar5;
            }
          }
        }
      } while (piVar5 != *(int **)(param_1 + 0x78));
    }
    (**(code **)(*piVar4 + 4))();
  }
  return;
}

