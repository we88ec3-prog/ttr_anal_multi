
undefined1 * FUN_004a0740(undefined4 param_1)

{
  int in_EAX;
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int local_c;
  
  FUN_008438c0(&param_1);
  if (local_c != *(int *)(in_EAX + 0x14)) {
    return *(undefined1 **)(local_c + 0x10);
  }
  puVar1 = (undefined1 *)FUN_00891268(8);
  puVar3 = (undefined1 *)0x0;
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 4) = 0;
    puVar3 = puVar1;
  }
  uVar2 = FUN_0057ef20();
  FUN_0057e850(in_EAX + 0x10,uVar2);
  return puVar3;
}

