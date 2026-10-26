
void FUN_00553420(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined *puVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ae13;
  local_10 = ExceptionList;
  uVar8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar9 = &DAT_00fb7358;
  local_8 = 0;
  do {
    puVar2 = *(undefined4 **)(puVar9 + 4);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      if ((undefined4 *)puVar3[4] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)puVar3[4])(1,uVar8);
        puVar3[4] = 0;
      }
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x15) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x15);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar7 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar7, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x15);
            puVar7 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    cVar1 = *(char *)((int)*(int **)(*(int *)(puVar9 + 4) + 4) + 0x15);
    piVar6 = *(int **)(*(int *)(puVar9 + 4) + 4);
    while (cVar1 == '\0') {
      FUN_0073eba0(piVar6[2]);
      piVar5 = (int *)*piVar6;
      FUN_0089120c(piVar6);
      piVar6 = piVar5;
      cVar1 = *(char *)((int)piVar5 + 0x15);
    }
    *(int *)(*(int *)(puVar9 + 4) + 4) = *(int *)(puVar9 + 4);
    *(undefined4 *)*(undefined4 *)(puVar9 + 4) = *(undefined4 *)(puVar9 + 4);
    *(int *)(*(int *)(puVar9 + 4) + 8) = *(int *)(puVar9 + 4);
    *(undefined4 *)(puVar9 + 8) = 0;
    puVar9 = puVar9 + 0x10;
  } while ((int)puVar9 < 0xfb7398);
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(&DAT_00fb7358,0x10,4,FUN_00843020);
  ExceptionList = local_10;
  return;
}

