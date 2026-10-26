
void FUN_00477680(void)

{
  code *pcVar1;
  char in_AL;
  int iVar2;
  undefined4 *puVar3;
  int local_c;
  int local_8;
  int iVar4;
  
  if (in_AL == '\0') {
    local_c = 0x1d8;
    iVar2 = FUN_005854b0();
    FUN_005740f0(&local_c);
    iVar4 = local_8;
    if (local_8 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  else if (in_AL == '\x01') {
    local_c = 0x1d9;
    iVar2 = FUN_005854b0();
    FUN_005740f0(&local_c);
    iVar4 = local_8;
    if (local_8 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  else {
    if (in_AL != '\x02') {
      return;
    }
    local_8 = 7;
    iVar2 = FUN_005854b0();
    FUN_005740f0(&local_8);
    iVar4 = local_c;
    if (local_c == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  puVar3 = (undefined4 *)(iVar4 + 0x10);
  if (7 < *(uint *)(iVar4 + 0x24)) {
    puVar3 = (undefined4 *)*puVar3;
  }
  FUN_00404b10(0xca,puVar3,&DAT_00bed1fc,0,0);
  return;
}

