
void FUN_0079d9c0(int param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  DWORD DVar4;
  DWORD DVar5;
  int *piVar6;
  
  *(undefined4 *)(param_1 + 0x20) = param_2;
  if (*(int *)(param_1 + 0x24) != 0) {
    DVar4 = GetTickCount();
    piVar6 = (int *)**(int **)(param_1 + 0x14);
    if (piVar6 != *(int **)(param_1 + 0x14)) {
      do {
        if (*(int *)(piVar6[10] + 0x54) != 0) {
          FUN_007c5300();
        }
        if (*(char *)((int)piVar6 + 0x31) == '\0') {
          piVar2 = (int *)piVar6[2];
          if (*(char *)((int)piVar2 + 0x31) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x31);
            piVar6 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x31);
              piVar6 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar6[1] + 0x31);
            piVar3 = (int *)piVar6[1];
            piVar2 = piVar6;
            while ((piVar6 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
              cVar1 = *(char *)(piVar6[1] + 0x31);
              piVar3 = (int *)piVar6[1];
              piVar2 = piVar6;
            }
          }
        }
      } while (piVar6 != *(int **)(param_1 + 0x14));
    }
    DVar5 = GetTickCount();
    FID_conflict__wprintf("SetLoadingLevel[%d] : %d ms\n",param_2,DVar5 - DVar4);
  }
  return;
}

