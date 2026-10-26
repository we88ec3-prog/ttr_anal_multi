
undefined4 * FUN_004f2860(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  
  puVar2 = *(undefined4 **)(param_1 + 0x5ecc);
  if ((puVar2 == (undefined4 *)0x0) || (puVar2[2] != param_2)) {
    uVar1 = *(int *)(param_1 + 0x5ed4) - *(int *)(param_1 + 0x5ed0) >> 2;
    uVar3 = 0;
    if (uVar1 != 0) {
      piVar4 = *(int **)(param_1 + 0x5ed0);
      do {
        if (*(int *)(*piVar4 + 8) == param_2) {
          return *(undefined4 **)(*(int *)(param_1 + 0x5ed0) + uVar3 * 4);
        }
        uVar3 = uVar3 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar3 < uVar1);
    }
    if (param_3 != 0) {
      puVar2 = (undefined4 *)FUN_00891268(0x18);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[2] = 0;
        *(undefined1 *)(puVar2 + 3) = 0;
        *(undefined4 *)((int)puVar2 + 0xe) = 0;
        *(undefined1 *)((int)puVar2 + 0x12) = 10;
        *(undefined2 *)(puVar2 + 5) = 0;
        *(undefined1 *)((int)puVar2 + 0x16) = 3;
      }
      puVar2[2] = param_2;
      if (param_4 == 0) {
        FUN_00443d10();
        return puVar2;
      }
      *(undefined4 **)(param_1 + 0x5ecc) = puVar2;
      return puVar2;
    }
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}

