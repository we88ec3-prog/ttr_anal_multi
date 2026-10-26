
void FUN_00500a00(int param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  ushort *puVar3;
  int local_c;
  uint local_8;
  
  puVar1 = *(ushort **)(param_1 + 0x5ec4);
  for (puVar3 = *(ushort **)(param_1 + 0x5ec0); puVar3 != puVar1; puVar3 = puVar3 + 1) {
    local_8 = (uint)*puVar3;
    iVar2 = *(int *)(param_1 + 0x5eac);
    FUN_00503d20(&local_8);
    if (local_c == *(int *)(iVar2 + 4)) {
      local_8 = 0;
    }
    else {
      local_8 = local_c + 0x10;
    }
    if (((local_8 != 0) && (*(int *)(local_8 + 0x28) == param_2)) && (*(int *)(local_8 + 4) == 2)) {
      FUN_00443d10();
    }
  }
  return;
}

