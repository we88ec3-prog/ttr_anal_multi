
void FUN_004dfc90(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int in_EAX;
  undefined4 *puVar4;
  int *piVar5;
  undefined1 local_8 [4];
  
  piVar5 = (int *)**(int **)(in_EAX + 0xc);
  if (piVar5 != *(int **)(in_EAX + 0xc)) {
    do {
      if (((int *)piVar5[4])[0x22] == param_1) {
        (**(code **)(*(int *)piVar5[4] + 0x14))();
        if ((undefined4 *)piVar5[4] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)piVar5[4])(1);
          piVar5[4] = 0;
        }
        puVar4 = (undefined4 *)FUN_007b6890(in_EAX + 8,local_8,piVar5);
        piVar5 = (int *)*puVar4;
      }
      else if (*(char *)((int)piVar5 + 0x15) == '\0') {
        piVar2 = (int *)piVar5[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar5 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x15);
          piVar3 = (int *)piVar5[1];
          piVar2 = piVar5;
          while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
            cVar1 = *(char *)(piVar5[1] + 0x15);
            piVar3 = (int *)piVar5[1];
            piVar2 = piVar5;
          }
        }
      }
    } while (piVar5 != *(int **)(in_EAX + 0xc));
  }
  return;
}

