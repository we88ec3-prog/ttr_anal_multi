
void FUN_0052bd50(int param_1)

{
  char cVar1;
  int iVar2;
  void *_Dst;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  piVar5 = (int *)**(int **)(param_1 + 4);
  if (piVar5 != *(int **)(param_1 + 4)) {
    do {
      iVar2 = piVar5[4];
      if (iVar2 != 0) {
        puVar6 = *(undefined4 **)(iVar2 + 0xc);
        if (puVar6 != *(undefined4 **)(iVar2 + 0x10)) {
          do {
            FUN_0089120c(*puVar6);
            puVar6 = puVar6 + 1;
          } while (puVar6 != *(undefined4 **)(iVar2 + 0x10));
        }
        _Dst = *(void **)(iVar2 + 0xc);
        if (_Dst != *(void **)(iVar2 + 0x10)) {
          FID_conflict__memcpy(_Dst,*(void **)(iVar2 + 0x10),0);
          *(void **)(iVar2 + 0x10) = _Dst;
        }
        if (*(int *)(iVar2 + 0xc) != 0) {
          FUN_0089120c(*(int *)(iVar2 + 0xc));
        }
        *(undefined4 *)(iVar2 + 0xc) = 0;
        *(undefined4 *)(iVar2 + 0x10) = 0;
        *(undefined4 *)(iVar2 + 0x14) = 0;
        FUN_0089120c(iVar2);
      }
      if (*(char *)((int)piVar5 + 0x15) == '\0') {
        piVar3 = (int *)piVar5[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar5 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar5 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x15);
          piVar4 = (int *)piVar5[1];
          piVar3 = piVar5;
          while ((piVar5 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar5[2]))) {
            cVar1 = *(char *)(piVar5[1] + 0x15);
            piVar4 = (int *)piVar5[1];
            piVar3 = piVar5;
          }
        }
      }
    } while (piVar5 != *(int **)(param_1 + 4));
  }
  piVar5 = *(int **)(*(int *)(param_1 + 4) + 4);
  cVar1 = *(char *)((int)piVar5 + 0x15);
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar5[2]);
    piVar3 = (int *)*piVar5;
    FUN_0089120c(piVar5);
    piVar5 = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0x15);
  }
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

