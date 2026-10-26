
int FUN_00749e40(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int in_EAX;
  int unaff_ESI;
  
  piVar2 = (int *)**(undefined4 **)(in_EAX + 0x50);
  while( true ) {
    if (piVar2 == *(int **)(in_EAX + 0x50)) {
      return -1;
    }
    if (piVar2[4] == unaff_ESI) break;
    if (*(char *)((int)piVar2 + 0x15) == '\0') {
      piVar3 = (int *)piVar2[2];
      if (*(char *)((int)piVar3 + 0x15) == '\0') {
        cVar1 = *(char *)(*piVar3 + 0x15);
        piVar2 = piVar3;
        piVar3 = (int *)*piVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar2 = piVar3;
          piVar3 = (int *)*piVar3;
        }
      }
      else {
        cVar1 = *(char *)(piVar2[1] + 0x15);
        piVar4 = (int *)piVar2[1];
        piVar3 = piVar2;
        while ((piVar2 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar2[2]))) {
          cVar1 = *(char *)(piVar2[1] + 0x15);
          piVar4 = (int *)piVar2[1];
          piVar3 = piVar2;
        }
      }
    }
  }
  return piVar2[3];
}

