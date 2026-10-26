
undefined4 FUN_00855790(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 auStack_c [2];
  
  FUN_008447d0(param_1);
  if (in_ECX + 0x1a0 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x1a0,0xc,0);
  }
  if (in_ECX + 0x1ac != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x1ac,0xc,0);
  }
  if (in_ECX + 0x1b8 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x1b8,0xc,0);
  }
  if (in_ECX + 0x194 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x194,0xc,0);
  }
  if (in_ECX + 0x1c4 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x1c4,4,0);
  }
  if (in_ECX + 0x1cc != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x1cc,4,0);
  }
  if (*(int *)(in_ECX + 0x180) == 1) {
    auStack_c[0] = *(undefined4 *)(in_ECX + 0x18c);
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),auStack_c,4,0);
    puVar2 = *(undefined4 **)(in_ECX + 0x188);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      FUN_00868160(param_1);
      if (*(char *)((int)puVar3 + 0x39) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x39) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x39);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x39);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x39);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x39);
            puVar5 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
  }
  return 1;
}

