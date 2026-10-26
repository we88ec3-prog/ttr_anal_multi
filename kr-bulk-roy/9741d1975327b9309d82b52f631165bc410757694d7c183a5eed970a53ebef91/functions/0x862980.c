
undefined4 FUN_00862980(undefined4 *param_1)

{
  undefined2 uVar1;
  int in_EAX;
  undefined2 *puVar2;
  int iVar3;
  undefined4 local_c;
  
  iVar3 = (*(int *)(in_EAX + 0x2c) - *(int *)(in_EAX + 0x28)) / 0xc;
  if (iVar3 != 0) {
    puVar2 = (undefined2 *)(*(int *)(in_EAX + 0x28) + 8);
    do {
      local_c = CONCAT22(puVar2[-2],puVar2[-4]);
      uVar1 = *puVar2;
      *param_1 = local_c;
      *(undefined2 *)(param_1 + 1) = uVar1;
      param_1 = (undefined4 *)((int)param_1 + 6);
      puVar2 = puVar2 + 6;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return 1;
}

