
undefined4 * FUN_0053ce30(undefined4 param_1)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 uVar2;
  int local_c;
  undefined4 local_8;
  
  local_8 = param_1;
  FUN_008438c0(&local_8);
  if (local_c == *(int *)(in_EAX + 0x5eb0)) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = *(undefined4 **)(local_c + 0x10);
  }
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = CUnionParty::vftable;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[5] = param_1;
      *(undefined2 *)(puVar1 + 6) = 0;
    }
    uVar2 = FUN_0057ef20();
    FUN_0057e850(in_EAX + 0x5eac,uVar2);
  }
  return puVar1;
}

