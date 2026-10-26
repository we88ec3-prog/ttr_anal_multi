
int FUN_007402e0(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int *piVar6;
  int local_8;
  
  piVar6 = (int *)**(int **)(in_ECX + 0x20);
  local_8 = 0;
  if (piVar6 != *(int **)(in_ECX + 0x20)) {
    do {
      iVar5 = (**(code **)(*(int *)piVar6[4] + 8))();
      puVar2 = (undefined4 *)piVar6[4];
      local_8 = local_8 + iVar5;
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FTGlyphCache::vftable;
        FUN_00891d3d(puVar2[5]);
        puVar2[5] = 0;
        FUN_00891d3d(puVar2[0xb]);
        puVar2[0xb] = 0;
        FUN_0089120c(puVar2);
      }
      if (*(char *)((int)piVar6 + 0x15) == '\0') {
        piVar3 = (int *)piVar6[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar6 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar6 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x15);
          piVar4 = (int *)piVar6[1];
          piVar3 = piVar6;
          while ((piVar6 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x15);
            piVar4 = (int *)piVar6[1];
            piVar3 = piVar6;
          }
        }
      }
    } while (piVar6 != *(int **)(in_ECX + 0x20));
  }
  piVar6 = *(int **)(*(int *)(in_ECX + 0x20) + 4);
  cVar1 = *(char *)((int)piVar6 + 0x15);
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar6[2]);
    piVar3 = (int *)*piVar6;
    FUN_0089120c(piVar6);
    piVar6 = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0x15);
  }
  *(int *)(*(int *)(in_ECX + 0x20) + 4) = *(int *)(in_ECX + 0x20);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(in_ECX + 0x20);
  *(int *)(*(int *)(in_ECX + 0x20) + 8) = *(int *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = 0;
  return local_8;
}

