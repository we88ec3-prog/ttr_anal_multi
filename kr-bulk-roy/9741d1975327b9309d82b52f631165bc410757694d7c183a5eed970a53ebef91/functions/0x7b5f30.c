
void FUN_007b5f30(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *local_18;
  int *local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba6d0);
  FUN_007b6ce0(&local_18,&stack0x00000004);
  piVar4 = local_18;
  if (local_18 != local_14) {
    do {
      FUN_007b6ce0(&local_10,piVar4 + 4);
      FUN_005540c0(local_10,local_c);
      if (*(char *)((int)piVar4 + 0x15) == '\0') {
        piVar2 = (int *)piVar4[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar4 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar4[1] + 0x15);
          piVar3 = (int *)piVar4[1];
          piVar2 = piVar4;
          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
            cVar1 = *(char *)(piVar4[1] + 0x15);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
          }
        }
      }
    } while (piVar4 != local_14);
  }
  FUN_005540c0(local_18,local_14);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba6d0);
  return;
}

