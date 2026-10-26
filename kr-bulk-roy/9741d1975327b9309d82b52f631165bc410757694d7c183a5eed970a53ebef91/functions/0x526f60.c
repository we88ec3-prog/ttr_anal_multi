
undefined4 * FUN_00526f60(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = param_2;
  FUN_008438c0(&param_2);
  if (param_1 != *(int *)(param_1 + 0xc)) {
    return *(undefined4 **)(param_1 + 0x10);
  }
  puVar1 = (undefined4 *)FUN_00891268(0x7c);
  puVar3 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[5] = 0;
    puVar1[6] = 7;
    *(undefined2 *)(puVar1 + 1) = 0;
    puVar1[8] = 0;
    puVar1[0xe] = 7;
    puVar1[0xd] = 0;
    *(undefined2 *)(puVar1 + 9) = 0;
    puVar1[0x10] = 0;
    puVar1[0x11] = 0;
    puVar1[0x12] = 0;
    puVar1[0x19] = 0xf;
    puVar1[0x18] = 0;
    *(undefined1 *)(puVar1 + 0x14) = 0;
    puVar1[0x1b] = 0;
    puVar1[0x1c] = 0;
    puVar1[0x1d] = 0;
    puVar3 = puVar1;
  }
  *puVar3 = uVar2;
  uVar2 = FUN_0057ef20();
  FUN_0057e850(param_1 + 8,uVar2);
  return puVar3;
}

