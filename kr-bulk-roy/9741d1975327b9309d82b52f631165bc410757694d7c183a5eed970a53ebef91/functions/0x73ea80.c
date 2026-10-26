
void FUN_0073ea80(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)**(int **)(param_1 + 0x1c);
  if (piVar5 != *(int **)(param_1 + 0x1c)) {
    do {
      puVar2 = (undefined4 *)piVar5[4];
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = CFTFace::vftable;
        if (puVar2[1] != 0) {
          FUN_006edb60("CFTFace: refCount != 0");
        }
        if (0xf < (uint)puVar2[0xf]) {
          FUN_0089120c(puVar2[10]);
        }
        puVar2[0xf] = 0xf;
        puVar2[0xe] = 0;
        *(undefined1 *)(puVar2 + 10) = 0;
        if (0xf < (uint)puVar2[8]) {
          FUN_0089120c(puVar2[3]);
        }
        puVar2[8] = 0xf;
        puVar2[7] = 0;
        *(undefined1 *)(puVar2 + 3) = 0;
        FUN_0089120c(puVar2);
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
    } while (piVar5 != *(int **)(param_1 + 0x1c));
  }
  piVar5 = *(int **)(*(int *)(param_1 + 0x1c) + 4);
  cVar1 = *(char *)((int)piVar5 + 0x15);
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar5[2]);
    piVar3 = (int *)*piVar5;
    FUN_0089120c(piVar5);
    piVar5 = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0x15);
  }
  *(int *)(*(int *)(param_1 + 0x1c) + 4) = *(int *)(param_1 + 0x1c);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(int *)(*(int *)(param_1 + 0x1c) + 8) = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}

