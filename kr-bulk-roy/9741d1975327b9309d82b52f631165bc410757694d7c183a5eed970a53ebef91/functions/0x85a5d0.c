
void FUN_0085a5d0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    iVar6 = (**(code **)(**(int **)(in_ECX + 4) + 0x28))(*(int **)(in_ECX + 4),0,"RESETCALLBACK");
    if ((iVar6 != 0) && (*(int *)(in_ECX + 4) != 0)) {
      (**(code **)(**(int **)(in_ECX + 4) + 0x58))(*(int **)(in_ECX + 4),iVar6,1);
    }
    (**(code **)(**(int **)(in_ECX + 4) + 0x118))(*(int **)(in_ECX + 4));
    puVar2 = *(undefined4 **)(in_ECX + 0x34);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      FUN_00865600();
      (**(code **)(**(int **)(in_ECX + 4) + 0xd0))(*(int **)(in_ECX + 4),puVar3[3],puVar3[4]);
      if (*(char *)((int)puVar3 + 0x45) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x45) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x45);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x45);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x45);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x45);
            puVar5 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    puVar2 = *(undefined4 **)(in_ECX + 0x44);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      FUN_00865970();
      if (*(char *)((int)puVar3 + 0x41) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x41) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x41);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x41);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x41);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x41);
            puVar5 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
  }
  return;
}

