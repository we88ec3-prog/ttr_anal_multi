
void FUN_007e27b0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int unaff_EDI;
  undefined1 local_8 [4];
  
  *(undefined4 *)(unaff_EDI + 4) = 0;
  piVar5 = (int *)**(int **)(unaff_EDI + 0xc);
  if (piVar5 != *(int **)(unaff_EDI + 0xc)) {
    do {
      if (*(int *)piVar5[10] == 0) {
        (**(code **)(*(int *)((int *)piVar5[10])[1] + 0x10))();
        if (*(undefined4 **)(piVar5[10] + 4) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(piVar5[10] + 4))(1);
          *(undefined4 *)(piVar5[10] + 4) = 0;
        }
        if (piVar5[10] != 0) {
          FUN_0089120c(piVar5[10]);
          piVar5[10] = 0;
        }
        puVar4 = (undefined4 *)FUN_007c2e30(unaff_EDI + 8,local_8,piVar5);
        piVar5 = (int *)*puVar4;
      }
      else if (*(char *)((int)piVar5 + 0x2d) == '\0') {
        piVar2 = (int *)piVar5[2];
        if (*(char *)((int)piVar2 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          piVar5 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x2d);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x2d);
          piVar3 = (int *)piVar5[1];
          piVar2 = piVar5;
          while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
            cVar1 = *(char *)(piVar5[1] + 0x2d);
            piVar3 = (int *)piVar5[1];
            piVar2 = piVar5;
          }
        }
      }
    } while (piVar5 != *(int **)(unaff_EDI + 0xc));
  }
  return;
}

