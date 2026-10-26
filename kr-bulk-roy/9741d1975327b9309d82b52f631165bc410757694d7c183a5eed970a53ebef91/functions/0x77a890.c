
void FUN_0077a890(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)(in_ECX + 0x14);
  iVar5 = 3;
  do {
    puVar3 = puVar6;
    if (7 < (uint)puVar6[5]) {
      puVar3 = (undefined4 *)*puVar6;
    }
    iVar4 = FUN_00774c30(puVar3);
    if (iVar4 != 0) {
      if ((uint)puVar6[0xc] < 8) {
        puVar3 = puVar6 + 7;
      }
      else {
        puVar3 = (undefined4 *)puVar6[7];
      }
      iVar4 = FUN_00763360(puVar3);
      if (puVar6[-1] != iVar4) {
        if (((iVar4 != 0) && (piVar2 = *(int **)(iVar4 + 8), piVar2 != (int *)0x0)) &&
           (piVar2[0x27] = piVar2[0x27] + 1, piVar2[0x27] == 1)) {
          (**(code **)(*piVar2 + 0x24))();
        }
        if ((puVar6[-1] != 0) && (piVar2 = *(int **)(puVar6[-1] + 8), piVar2 != (int *)0x0)) {
          piVar1 = piVar2 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar2 + 0x28))();
          }
        }
        puVar6[-1] = iVar4;
      }
    }
    puVar6 = puVar6 + 0x10;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}

